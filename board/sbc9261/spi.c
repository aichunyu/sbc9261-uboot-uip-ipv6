/*
 * (c) Copyright 2005
 * M. Amine SAYA, ATMEL Rousset, France.
 * Driver for AT91SAM9261 SPI
 * Based on at91rm9200 spi driver from H. Ikdoumi, ATMEL Rousset.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 */

#include <config.h>
#include <common.h>

#ifdef CONFIG_HAS_DATAFLASH
#include <dataflash.h>
#include <asm/arch/pio.h>

#define AT91C_SPI_CS0_CLK	33000000        /* Dataflash clock when master clock is 99300000 */
#define AT91C_SPI_CS3_CLK	8000000

#define AT91C_SPI_PCS0_DATAFLASH_CARD		0xE     /* Chip Select 0 : NPCS0 %1110 */
#define AT91C_SPI_PCS3_DATAFLASH_CARD		0x7     /* Chip Select 3 : NPCS3 %0111 */

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiInit                                                       */
/* \brief SPI Init                  			                      */
/*----------------------------------------------------------------------------*/
void AT91F_SpiInit(void) {

  volatile unsigned int dummy;

  /* Configure PIOs for SPI0 */
  AT91F_PIO_CfgPeriph(AT91C_BASE_PIOA,
		      (AT91C_PA0_MISO0 | AT91C_PA1_MOSI0 |
		       AT91C_PA2_SPCK0 | AT91C_PA3_NPCS00 |
		       AT91C_PA4_NPCS01 | AT91C_PA5_NPCS02 |
		       AT91C_PA6_NPCS03),
		      0);

  /* Enable Clock */
  AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_SPI0;

  /* Reset the SPI */
  AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SWRST;

  /* Configure SPI in Master Mode with No CS selected !!! */
  AT91C_BASE_SPI0->SPI_MR = AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PCS;

  /* Configure CS0 Mode 0 */
  /* to avoid pb with DataFlash AT45DB642D */
  AT91C_BASE_SPI0->SPI_CSR[0] = (AT91C_SPI_NCPHA | (AT91C_SPI_DLYBS & DATAFLASH_TCSS) |
				 (AT91C_SPI_DLYBCT & DATAFLASH_TCHS) |
				 (AT91C_MASTER_CLOCK / AT91C_SPI_CS0_CLK) << 8);

  AT91C_BASE_SPI0->SPI_CSR[3] = (AT91C_SPI_NCPHA | (AT91C_SPI_DLYBS & DATAFLASH_TCSS) |
				 (AT91C_SPI_DLYBCT & DATAFLASH_TCHS) |
				 (AT91C_MASTER_CLOCK / AT91C_SPI_CS3_CLK) << 8);

  /* SPI_Enable */
  AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;

  while(!(AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_SPIENS));

  /* Add tempo to get SPI in a safe state. */
  /* Should be removed for new silicon (Rev B) */
  udelay(500000);
  dummy = AT91C_BASE_SPI0->SPI_SR;
  dummy = AT91C_BASE_SPI0->SPI_RDR;
}

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiEnable                                                     */
/* \brief SPI Enable                  			                      */
/*----------------------------------------------------------------------------*/
void AT91F_SpiEnable(int cs) {
  switch(cs) {
  case 0:
    /* Configure SPI CS0 for DataFlash card AT45DBxx */
    AT91C_BASE_SPI0->SPI_MR &= 0xFFF0FFFF;
    AT91C_BASE_SPI0->SPI_MR |= ((AT91C_SPI_PCS0_DATAFLASH_CARD<<16) & AT91C_SPI_PCS);
    break;
  case 1:
  case 2:
  case 3:
    /* Configure SPI CS3 for dataflash card AT45DBxx */
    AT91C_BASE_SPI0->SPI_MR &= 0xFFF0FFFF;
    AT91C_BASE_SPI0->SPI_MR |= ((AT91C_SPI_PCS3_DATAFLASH_CARD<<16) & AT91C_SPI_PCS);
    break;
  default:
    /* Configure PCS */
    AT91C_BASE_SPI0->SPI_MR &= 0xFFF0FFFF;
    AT91C_BASE_SPI0->SPI_MR |= ((AT91C_SPI_PCS0_DATAFLASH_CARD<<16) & AT91C_SPI_PCS);
    break;
  }

  /* SPI_Enable */
  AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;
}

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiDisablePDC                                                 */
/* \brief Disable PDC registers                  			      */
/*----------------------------------------------------------------------------*/
void __inline__ AT91F_SpiDisablePDC(AT91PS_SPI spi_ptr)
{
  spi_ptr->SPI_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
}

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiEnablePDC                                                 */
/* \brief Enable PDC registers                  			      */
/*----------------------------------------------------------------------------*/
void __inline__ AT91F_SpiEnablePDC(AT91PS_SPI spi_ptr)
{
  spi_ptr->SPI_PTCR = AT91C_PDC_RXTEN | AT91C_PDC_TXTEN;
}

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiWrite						      */
/* \brief Set the PDC registers for a transfert				      */
/*----------------------------------------------------------------------------*/
unsigned int AT91F_SpiWrite ( AT91PS_DataflashDesc pDesc )
{
  unsigned int timeout;

  pDesc->state = BUSY;

  /* Disable PDC TX and RX channels */
  AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS + AT91C_PDC_RXTDIS;

  /* Initialize the Transmit and Receive Pointer */
  AT91C_BASE_SPI0->SPI_RPR = (unsigned int)pDesc->rx_cmd_pt ;
  AT91C_BASE_SPI0->SPI_TPR = (unsigned int)pDesc->tx_cmd_pt ;

  /* Intialize the Transmit and Receive Counters */
  AT91C_BASE_SPI0->SPI_RCR = pDesc->rx_cmd_size;
  AT91C_BASE_SPI0->SPI_TCR = pDesc->tx_cmd_size;

  /* If there is another transfer to perform */
  if(pDesc->tx_data_size){
    /* Initialize the Next Transmit and Next Receive Pointer */
    AT91C_BASE_SPI0->SPI_RNPR = (unsigned int)pDesc->rx_data_pt ;
    AT91C_BASE_SPI0->SPI_TNPR = (unsigned int)pDesc->tx_data_pt ;

    /* Intialize the Next Transmit and Next Receive Counters */
    AT91C_BASE_SPI0->SPI_RNCR = pDesc->rx_data_size ;
    AT91C_BASE_SPI0->SPI_TNCR = pDesc->tx_data_size ;
  }

  /* arm simple, non interrupt dependent timer */
  reset_timer_masked();
  timeout = 0;

  AT91F_SpiEnablePDC(AT91C_BASE_SPI0);

  while(!(AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_RXBUFF) && ((timeout = get_timer_masked() ) < CFG_SPI_WRITE_TOUT));

  /* Disable PDC TX and RX channels */
  AT91F_SpiDisablePDC(AT91C_BASE_SPI0);

  pDesc->state = IDLE;

  if (timeout >= CFG_SPI_WRITE_TOUT){
    printf("AT91F_SpiWrite : Error Timeout\n\r");
    return DATAFLASH_ERROR;
  }

  return DATAFLASH_OK;
}

#endif
