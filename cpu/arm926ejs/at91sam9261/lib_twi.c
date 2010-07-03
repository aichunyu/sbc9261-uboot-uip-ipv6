/*-----------------------------------------------------------------------------
*      ATMEL Microcontroller Software Support  -  ROUSSET  -
*------------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*------------------------------------------------------------------------------
* File Name         : lib_twi.c
* Object            : Basic TWI function driver
* Translator        :
* 1.0 25/11/02 NL   : Creation
* 1.1 31/Jan/05 JPP : Clean For basic
* 1.1 20/Oct/06 PFi : Twi bus clock parameter added to the AT91F_TWI_Open
*                   : function and in AT91F_SetTwiClock
* 1.1 23/Nov/06 PFi : Twi reset added in TWI Open function
* 1.2 19/Dec/06 PFi : Twi Bus recovery fnuction added.
*                   : configuration of TWD/TWCK in open drain mode
*                   : added in TWI_Open fct.
* 1.3 16/Mar/07 PFi : AT91F_SetTwiClock rewrite to set any clock with automatic
*                   : CKDIV computing.
*                   : All TWI read/write functions rewrite to match the new
*                   : flowcharts
*
* TO DO             : Add checking of (cldiv x 2pow*ckdiv) < 8192 in
*                     AT91F_SetTwiClock function according to errata the errata.
-----------------------------------------------------------------------------*/
#include <config.h>
#include <command.h>
#include <asm/arch/AT91SAM9261.h>
//#include "board.h"	
#include "lib_twi.h"
//#include "init.h"
//#include <math.h>


#define ERROR (AT91C_TWI_NACK)

/* value of the PIT value to have 333ns @ 48 MHz
3 -1 since real time out = PIV + 1 */
#define PIT_PIV_MICRO_SECOND_VALUE  0x2
#define TWI_CLOCK		100000

extern void udelay (unsigned long usec);
/*----------------------------------------------------------------------------
* Wait function with the Periodic Interval Timer (PIT)
* The wait time is from 1us to 999us.
-----------------------------------------------------------------------------*/
void AT91F_TWI_WaitMicroSecond (unsigned int MicroSecond)
{
//   unsigned int PitStatus = 0;     /* Status register of the PIT */
 //  unsigned int PitLoop = 0;    /* Store the number of PIT Loop */

 //  AT91C_BASE_PITC->PITC_PIMR = AT91C_PITC_PITEN|PIT_PIV_MICRO_SECOND_VALUE;

 //  for( PitLoop=0; PitLoop <(MicroSecond);)   /* One PIT loop equals 333ns */
 //  {
    /* Wait for the PIT counter overflow occurs */
 //   while ((AT91C_BASE_PITC->PITC_PISR & AT91C_PITC_PITS)==0);
    /* Read the PIT Interval Value Reg. to clear it for the next overflow */
 //   PitStatus = AT91C_BASE_PITC->PITC_PIVR ;
    /* dummy access to avoid IAR warning */
  //  PitStatus = PitStatus ;
 //   PitLoop++;
//   }
//	unsigned long start = get_timer(0);
	
//	while ( get_timer(start) < MicroSecond*CFG) 
		udelay((unsigned long)(MicroSecond*1000));
	
}


/*----------------------------------------------------------------------------
Function: AT91F_SetTwiClock (int TwiClock)
Arguments: - <TwiClock> TWI bus clock in Hertz
Comments : TO DO:

Return Value: none
-----------------------------------------------------------------------------*/

void AT91F_SetTwiClock(void)
{
  unsigned int cldiv,ckdiv=1 ;

  /* CLDIV = ((Tlow x 2^CKDIV) -3) x Tmck */
  /* CHDIV = ((THigh x 2^CKDIV) -3) x Tmck */
  /* Only CLDIV is computed since CLDIV = CHDIV (50% duty cycle) */

//  while ( ( cldiv = ( (MCK/(2*TwiClock))-3 ) / pow(2,ckdiv)) > 255 )
//   ckdiv++ ;
	/* Calcuate clock dividers */
	cldiv = (AT91C_MASTER_CLOCK / (2 * TWI_CLOCK)) - 3;
	cldiv = cldiv + 1;	/* round up */
	ckdiv = 0;
	while (cldiv > 255) {
		ckdiv++;
		cldiv = cldiv >> 1;
	}

  AT91C_BASE_TWI->TWI_CWGR =(ckdiv<<16)|((unsigned int)cldiv << 8)|(unsigned int)cldiv  ;
}

/*----------------------------------------------------------------------------
Function : AT91F_TWI_WriteSingle
Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <data>: Pointer to the data to write
Comments : Write a single data into a slave device without internal
           address.
           Takes into account the NACK errata.

Return Value: AT91C_TWI_NACK if so.
-----------------------------------------------------------------------------*/
int AT91F_TWI_WriteSingle( AT91PS_TWI pTwi,
                        int SlaveAddr,
                        char *data)
{
    unsigned int end = 0, status;
    int error=0;

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  SlaveAddr & ~AT91C_TWI_MREAD;

    /* Write the data to send into THR. Start conditionn DADDR and R/W bit
       are sent automatically */
    pTwi->TWI_THR = *data;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (10) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        error++;
        end=1;
      }
    /*  Wait for the Transmit ready is set */
      if ((status & AT91C_TWI_TXRDY) == AT91C_TWI_TXRDY)
        end=1;
    }

    /* Wait for the Transmit complete is set */
    status = AT91C_BASE_TWI->TWI_SR;
    while (!(status & AT91C_TWI_TXCOMP))
      status = AT91C_BASE_TWI->TWI_SR;

    return error;
}

/*----------------------------------------------------------------------------
Function : AT91F_TWI_WriteSingleIadr
Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <data>: Pointer to the data to write
           <IntAddr>: Internal slave device address. Set to 0 if no.
           <IntAddrSize>: Size of the internal address.Set to 0 if no.
 Comments : Write a single data into a slave device with an internal
            address.
            Takes into account the NACK errata.

Return Value: AT91C_TWI_NACK if so.
-----------------------------------------------------------------------------*/
int AT91F_TWI_WriteSingleIadr( AT91PS_TWI pTwi,
                        int SlaveAddr,
                        int IntAddr,
                        int IntAddrSize,
                        char *data)
{
    unsigned int end = 0, status;
    int error=0;

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  (SlaveAddr | IntAddrSize) & (~AT91C_TWI_MREAD);

    /* Set TWI Internal Address Register if needed */
    pTwi->TWI_IADR = IntAddr;

    /* Write the data to send into THR. Start conditionn DADDR and R/W bit
       are sent automatically */
    pTwi->TWI_THR = *data;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (10) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        error++;
        end=1;
      }
    /*  Wait for the Transmit ready is set */
      if ((status & AT91C_TWI_TXRDY) == AT91C_TWI_TXRDY)
        end=1;
    }

    /* Wait for the Transmit complete is set */
    status = AT91C_BASE_TWI->TWI_SR;
    while (!(status & AT91C_TWI_TXCOMP))
      status = AT91C_BASE_TWI->TWI_SR;

    return error;
}

/*----------------------------------------------------------------------------
Function : AT91F_TWI_WriteMultiple
Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <data>: Pointer to the data to write
           <NumOfBytes>: Number of data to write
Comments : Write multiple data into a slave device without internal address.
           Takes into account the NACK errata.

Return Value: AT91C_TWI_NACK if so.
-----------------------------------------------------------------------------*/
int AT91F_TWI_WriteMultiple( AT91PS_TWI pTwi,
                        int SlaveAddr,
                        char *data,
                        unsigned int NumOfBytes)
{
    unsigned int end = 0, status, Count;
    int error=0;

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

   /* Wait until TXRDY is high to transmit */
   status = AT91C_BASE_TWI->TWI_SR;
   while (!(status & AT91C_TWI_TXRDY))
        status = AT91C_BASE_TWI->TWI_SR;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  SlaveAddr & ~AT91C_TWI_MREAD;

   /* Send the data */
   for ( Count=0; Count < NumOfBytes ;Count++ )
   {
       /* Write the data to send into THR. Start conditionn DADDR and R/W bit
       are sent automatically */
       AT91C_BASE_TWI->TWI_THR = *data++;

       /* NACK errata handling */
       /* Do not poll the TWI_SR */
       /* Wait 3 x 9 TWCK pulse (max) before reading TWI_SR */
       /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
       /* In this example the TWI period is 1/400KHz */
       AT91F_TWI_WaitMicroSecond (10) ;

       while (!end)
       {
           status = AT91C_BASE_TWI->TWI_SR;
           if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
           {
               error++;
               end=1;
           }

           /*  Wait for the Transmit ready is set */
           if ((status & AT91C_TWI_TXRDY) == AT91C_TWI_TXRDY)
            end=1;
        }
    }

    /* Wait for the Transmit complete is set */
    status = AT91C_BASE_TWI->TWI_SR;
    while (!(status & AT91C_TWI_TXCOMP))
      status = AT91C_BASE_TWI->TWI_SR;

    return error;
}

/*----------------------------------------------------------------------------
Function : AT91F_TWI_WriteMultipleIadr
Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <data>: Pointer to the data to write
           <NumOfBytes>: Number of data to write

Comments : Write multiple data into a slave device with internal address.
           Takes into account the NACK errata.

Return Value: AT91C_TWI_NACK if so.
-----------------------------------------------------------------------------*/
int AT91F_TWI_WriteMultipleIadr( AT91PS_TWI pTwi,
                        int SlaveAddr,
                        int IntAddr,
                        int IntAddrSize,
                        char *data,
                        unsigned int NumOfBytes)
{
    unsigned int end = 0, status,  Count;
    int error=0;

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  (SlaveAddr | IntAddrSize) & (~AT91C_TWI_MREAD);

    /* Set TWI Internal Address Register if needed */
    pTwi->TWI_IADR = IntAddr;

   /* Wait until TXRDY is high to transmit */
   status = AT91C_BASE_TWI->TWI_SR;
   while (!(status & AT91C_TWI_TXRDY))
        status = AT91C_BASE_TWI->TWI_SR;

   /* Send the data */
   for ( Count=0; Count < NumOfBytes ;Count++ )
   {
       /* Write the data to send into THR. Start conditionn DADDR and R/W bit
       are sent automatically */
       AT91C_BASE_TWI->TWI_THR = *data++;

       /* NACK errata handling */
       /* Do not poll the TWI_SR */
       /* Wait 3 x 9 TWCK pulse (max) before reading TWI_SR */
       /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
       /* In this example the TWI period is 1/400KHz */
       AT91F_TWI_WaitMicroSecond (10) ;

       while (!end)
       {
           status = AT91C_BASE_TWI->TWI_SR;
           if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
           {
               error++;
               end=1;
           }

           /*  Wait for the Transmit ready is set */
           if ((status & AT91C_TWI_TXRDY) == AT91C_TWI_TXRDY)
            end=1;
        }
    }

    /* Wait for the Transmit complete is set */
    status = AT91C_BASE_TWI->TWI_SR;
    while (!(status & AT91C_TWI_TXCOMP))
      status = AT91C_BASE_TWI->TWI_SR;

    return error;
}


/*-----------------------------------------------------------------------------
Function: AT91F_TWI_ReadSingle

Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <data>: Pointer to the data to read

Comments : Read single data from a slave device without internal address.
           Takes into account the NACK errata.


Return Value: <data>: Data read via a pointer.
-----------------------------------------------------------------------------*/
int AT91F_TWI_ReadSingle( AT91PS_TWI pTwi,
                       int SlaveAddr,
                       char *data)
{
    unsigned int status, end=0;
    int error=0;

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  SlaveAddr | AT91C_TWI_MREAD;

    pTwi->TWI_CR = AT91C_TWI_START | AT91C_TWI_STOP;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (10) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        error++;
        end=1;
      }
    /*  Wait for the receive ready is set */
      if ((status & AT91C_TWI_RXRDY) == AT91C_TWI_RXRDY)
        end=1;
    }

    *(data) = pTwi->TWI_RHR;

   /* Wait for the Transmit complete is set */
   status = AT91C_BASE_TWI->TWI_SR;
   while (!(status & AT91C_TWI_TXCOMP))
     status = AT91C_BASE_TWI->TWI_SR;

    return 0;
}

/*-----------------------------------------------------------------------------
Function: AT91F_TWI_ReadSingleIadr

Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <IntAddr>: Internal slave device address. Set to 0 if no.
           <IntAddrSize>: Size of the internal address.Set to 0 if no.
           <data>: Pointer to the data to read

Comments : Read single data from a slave device with internal address.
           Takes into account the NACK errata.

Return Value: <data>: Data read via a pointer.
-----------------------------------------------------------------------------*/
int AT91F_TWI_ReadSingleIadr( AT91PS_TWI pTwi,
                       int SlaveAddr,
                       int IntAddr,
                       int IntAddrSize,
                       char *data)
{
    unsigned int status,error=0, end=0;

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  SlaveAddr | IntAddrSize | AT91C_TWI_MREAD;

    /* Set TWI Internal Address Register if needed */
    pTwi->TWI_IADR = IntAddr;

    pTwi->TWI_CR = AT91C_TWI_START | AT91C_TWI_STOP;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (10) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        error++;
        end=1;
      }
    /*  Wait for the receive ready is set */
      if ((status & AT91C_TWI_RXRDY) == AT91C_TWI_RXRDY)
        end=1;
    }

    *(data) = pTwi->TWI_RHR;

   /* Wait for the Transmit complete is set */
   status = AT91C_BASE_TWI->TWI_SR;
   while (!(status & AT91C_TWI_TXCOMP))
     status = AT91C_BASE_TWI->TWI_SR;

    return 0;
}

/*-----------------------------------------------------------------------------
Function: AT91F_TWI_ReadMultiple

Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <NumOfBytes>: Number of data to read
           <data>: Pointer to the data to read

Comments : Read multiple data from a slave device without internal address.
           Takes into account the NACK errata.


Return Value: <data>: Data read via a pointer.
-----------------------------------------------------------------------------*/
int AT91F_TWI_ReadMultiple( AT91PS_TWI pTwi,
                       int SlaveAddr,
                       unsigned int NumOfBytes,
                       char *data)
{
    unsigned int status,error=0, ReadCount, end=0;

   /* Enable Master Mode of the TWI */
   AT91C_BASE_TWI->TWI_CR = AT91C_TWI_MSEN ;

   /* Set the TWI Master Mode Register */
   AT91C_BASE_TWI->TWI_MMR =  SlaveAddr | AT91C_TWI_MREAD ;

   /* Send the Start + slave address */
   AT91C_BASE_TWI->TWI_CR = AT91C_TWI_START;

   /* Read and store it into the buffer */
   for ( ReadCount=0; ReadCount <NumOfBytes; ReadCount++ )
   {
    /* if next-lo-last data send the stop */
    if (ReadCount == (NumOfBytes -1) )
      AT91C_BASE_TWI->TWI_CR = AT91C_TWI_STOP;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (10) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        error++;
        end=1;
      }
      /* Wait until RXRDY is high to read the next data */
      if ((status & AT91C_TWI_RXRDY) == AT91C_TWI_RXRDY)
        end=1;
    }

    /*  Read the char received */
    *data++ = AT91C_BASE_TWI->TWI_RHR;

   }

   /* Wait for the Transmit complete is set */
   status = AT91C_BASE_TWI->TWI_SR;
   while (!(status & AT91C_TWI_TXCOMP))
     status = AT91C_BASE_TWI->TWI_SR;

   return 0;
}

/*-----------------------------------------------------------------------------
Function: AT91F_TWI_ReadMultipleIadr

Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to read from.
           <IntAddr>: Internal slave device address. Set to 0 if no.
           <IntAddrSize>: Size of the internal address.Set to 0 if no.
           <NumOfBytes>: Number of data to read
           <data>: Pointer to the data to read

Comments : Read multiple data from a slave device with internal address.
           Takes into account the NACK errata.


Return Value: <data>: Data read via a pointer.
-----------------------------------------------------------------------------*/
int AT91F_TWI_ReadMultipleIadr( AT91PS_TWI pTwi,
                       int SlaveAddr,
                       unsigned int NumOfBytes,
                       int IntAddr,
                       int IntAddrSize,
                       char *data)
{
    unsigned int status,error=0, ReadCount, end=0;

   /* Enable Master Mode of the TWI */
   AT91C_BASE_TWI->TWI_CR = AT91C_TWI_MSEN ;


   /* Set the TWI Master Mode Register */
   pTwi->TWI_MMR =  SlaveAddr | IntAddrSize | AT91C_TWI_MREAD;

   /* Set TWI Internal Address Register if needed */
   pTwi->TWI_IADR = IntAddr;

   /* Send the Start + slave address */
   AT91C_BASE_TWI->TWI_CR = AT91C_TWI_START;

   /* Read and store it into the buffer */
   for ( ReadCount=0; ReadCount <NumOfBytes; ReadCount++ )
   {
    /* if next-lo-last data send the stop */
    if (ReadCount == (NumOfBytes -1) )
      AT91C_BASE_TWI->TWI_CR = AT91C_TWI_STOP;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (10) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        error++;
        end=1;
      }
      /* Wait until RXRDY is high to read the next data */
      if ((status & AT91C_TWI_RXRDY) == AT91C_TWI_RXRDY)
        end=1;
    }
    /*  Read the char received */
    *data = AT91C_BASE_TWI->TWI_RHR;
    data++;
   }

   /* Wait for the Transmit complete is set */
   status = AT91C_BASE_TWI->TWI_SR;
   while (!(status & AT91C_TWI_TXCOMP))
     status = AT91C_BASE_TWI->TWI_SR;

   return 0;
}

/*----------------------------------------------------------------------------
Function : AT91F_TWI_ProbeDevices
Arguments: <AT91PS_TWI pTwi> : Pointer to the TWI structure.
           <SlaveAddr>: Address of the slave device to probe.

Comments : Write a single data into a slave device to see if it is connected
           Takes into account the NACK errata.

Return Value: AT91C_TWI_NACK if so, SlaveAddress otherwise.
-----------------------------------------------------------------------------*/
int AT91F_TWI_ProbeDevices(AT91PS_TWI pTwi, int SlaveAddr)
{
    unsigned int end = 0, status;
    int Return=0; 

    /* Enable Master Mode */
    pTwi->TWI_CR = AT91C_TWI_MSEN ;

    /* Set the TWI Master Mode Register */
    pTwi->TWI_MMR =  SlaveAddr & ~AT91C_TWI_MREAD;

    /* Write the data to send into THR. Start conditionn DADDR and R/W bit
       are sent automatically */
    pTwi->TWI_THR = 0x55;

    /* NACK errata handling */
    /* Do not poll the TWI_SR */
    /* Wait 3 x 9 TWCK pulse (max) 2 if IADRR not used, before reading TWI_SR */
    /* From 400Khz down to 1Khz, the time to wait will be in 탎 range.*/
    /* In this example the TWI period is 1/400KHz */
    AT91F_TWI_WaitMicroSecond (50) ;

    while (!end)
    {
      status = AT91C_BASE_TWI->TWI_SR;
      if ((status & AT91C_TWI_NACK) == AT91C_TWI_NACK)
      {
        Return = AT91C_TWI_NACK ;
        end=1;
      }
      /*  Wait for the Transmit ready is set */
      else if ((status & AT91C_TWI_TXRDY) == AT91C_TWI_TXRDY)
      {
        end=1;
        Return = SlaveAddr>>16;
      }
    }

    /* Wait for the Transmit complete is set */
    status = AT91C_BASE_TWI->TWI_SR;
    while (!(status & AT91C_TWI_TXCOMP))
      status = AT91C_BASE_TWI->TWI_SR;

    return (Return);
}

/*-----------------------------------------------------------------------------
* \fn    AT91F_TWI_Open
* \brief Initializes TWI device
-----------------------------------------------------------------------------*/
#define AT91C_PIO_PA7        ((unsigned int) 1 <<  7) // Pin Controlled by PA7
#define AT91C_PA7_TWD      ((unsigned int) AT91C_PIO_PA7) //  TWI Two-wire Serial Data
#define AT91C_PA7_PCK0     ((unsigned int) AT91C_PIO_PA7) //  PMC Programmable clock Output 0

#define AT91C_PIO_PA8        ((unsigned int) 1 <<  8) // Pin Controlled by PA8
#define AT91C_PA8_TWCK     ((unsigned int) AT91C_PIO_PA8) //  TWI Two-wire Serial Clock
#define AT91C_PA8_PCK1     ((unsigned int) AT91C_PIO_PA8) //  PMC Programmable clock Output 1

void AT91F_TWI_Open(void)
{
    /* Configure TWI PIOs */
	AT91C_BASE_PIOA->PIO_ASR = AT91C_PA7_TWD|AT91C_PA8_TWCK;
	AT91C_BASE_PIOA->PIO_BSR = 0;
	AT91C_BASE_PIOA->PIO_PDR = (AT91C_PA7_TWD|AT91C_PA8_TWCK); // Set in Periph mode
   
    /* Configure PMC by enabling TWI clock */
	AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_TWI);
 //   AT91F_TWI_CfgPMC ();

    /* Reset the TWI */
    AT91C_BASE_TWI->TWI_CR = AT91C_TWI_SWRST;

    /* Configure TWI in master mode */
	//* Disable interrupts
	AT91C_BASE_TWI->TWI_IDR = (unsigned int) -1;

    //* Reset peripheral
	AT91C_BASE_TWI->TWI_CR = AT91C_TWI_SWRST;

	//* Set Master mode
	AT91C_BASE_TWI->TWI_CR = AT91C_TWI_MSEN;
  //  AT91F_TWI_Configure (AT91C_BASE_TWI);

    /* Set TWI Clock Waveform Generator Register */
    AT91F_SetTwiClock();
}

