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

#ifdef CONFIG_HAS_DATAFLASH
#include <dataflash.h>

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiInit                                                       */
/* \brief SPI Init                  			                      */
/*----------------------------------------------------------------------------*/
extern void AT91F_SpiInit(void);

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiEnable                                                     */
/* \brief SPI Enable                  			                      */
/*----------------------------------------------------------------------------*/
extern void AT91F_SpiEnable(int cs);

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiDisablePDC                                                 */
/* \brief Disable PDC registers                  			      */
/*----------------------------------------------------------------------------*/
extern void __inline__ AT91F_SpiDisablePDC(AT91PS_SPI spi_ptr);

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiEnablePDC                                                 */
/* \brief Enable PDC registers                  			      */
/*----------------------------------------------------------------------------*/
extern void __inline__ AT91F_SpiEnablePDC(AT91PS_SPI spi_ptr);

/*----------------------------------------------------------------------------*/
/* \fn    AT91F_SpiWrite						      */
/* \brief Set the PDC registers for a transfert				      */
/*----------------------------------------------------------------------------*/
extern unsigned int AT91F_SpiWrite ( AT91PS_DataflashDesc pDesc );

#endif
