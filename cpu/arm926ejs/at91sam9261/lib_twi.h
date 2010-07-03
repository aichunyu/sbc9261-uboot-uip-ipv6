/*-----------------------------------------------------------------------------
*      ATMEL Microcontroller Software Support  -  ROUSSET  -
*------------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*------------------------------------------------------------------------------
* File Name           : lib_twi.h
* Object
* 1.1 31/Jan/05 JPP   : Clean For basic:
*----------------------------------------------------------------------------*/
#ifndef lib_twi_h
#define lib_twi_h
#include <asm/arch/AT91SAM9261.h>
/* Global declarations */

/* TWI Init functions */
extern void AT91F_TWI_Open(void);


extern int AT91F_TWI_WriteSingle( AT91PS_TWI pTwi,			\
                        int SlaveAddr,							\
                        char *data);

extern int AT91F_TWI_WriteSingleIadr(AT91PS_TWI pTwi,		\
                        int SlaveAddr,							\
                        int IntAddr,							\
                        int IntAddrSize,						\
                        char *data);

extern int AT91F_TWI_WriteMultiple(AT91PS_TWI pTwi,		\
                        int SlaveAddr,							\
                        char *data,								\
                        unsigned int NumOfBytes);

extern int AT91F_TWI_WriteMultipleIadr(AT91PS_TWI pTwi,		\
                        int SlaveAddr,							\
                        int IntAddr,							\
                        int IntAddrSize,						\
                        char *data,								\
                        unsigned int NumOfBytes);

extern int AT91F_TWI_ReadSingle(AT91PS_TWI pTwi,			\
                       int SlaveAddr,							\
                       char *data);

extern int AT91F_TWI_ReadSingleIadr(AT91PS_TWI pTwi,	\
                       int SlaveAddr,	\
                       int IntAddr,	\
                       int IntAddrSize,	\
                       char *data);

extern int AT91F_TWI_ReadMultiple( AT91PS_TWI pTwi,	\
                       int SlaveAddr,	\
                       unsigned int NumOfBytes,	\
                       char *data);

extern int AT91F_TWI_ReadMultipleIadr(AT91PS_TWI pTwi,	\
                       int SlaveAddr,	\
                       unsigned int NumOfBytes,	\
                       int IntAddr,	\
                       int IntAddrSize,	\
                       char *data);

extern void AT91F_TWI_BusRecovery (AT91PS_PIO pPio,	\
                            int PioID,	\
                            int Twck,	\
                            int Twd);

extern void AT91F_TWI_WaitMicroSecond (unsigned int MicroSecond);


extern int AT91F_TWI_ProbeDevices( AT91PS_TWI pTwi, int SlaveAddr);


#endif

