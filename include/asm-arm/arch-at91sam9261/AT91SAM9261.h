/*  ----------------------------------------------------------------------------
 *          ATMEL Microcontroller Software Support  -  ROUSSET  -
 *  ----------------------------------------------------------------------------
 *  DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 *  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  ----------------------------------------------------------------------------
 * File Name           : AT91SAM9261.h
 * Object              : AT91SAM9261 definitions
 * Generated           : AT91 SW Application Group  03/30/2005 (17:05:06)
 *
 *  ----------------------------------------------------------------------------
*/
#ifndef AT91SAM9261_H
#define AT91SAM9261_H

typedef volatile unsigned int AT91_REG;/* Hardware register definition */

/* *****************************************************************************
 *              SOFTWARE API DEFINITION  FOR System Peripherals
 * *****************************************************************************
 */
typedef struct _AT91S_SYS {
	AT91_REG	 SDRAMC_MR; 	/* SDRAM Controller Mode Register */
	AT91_REG	 SDRAMC_TR; 	/* SDRAM Controller Refresh Timer Register */
	AT91_REG	 SDRAMC_CR; 	/* SDRAM Controller Configuration Register */
	AT91_REG	 SDRAMC_HSR; 	/* SDRAM Controller High Speed Register */
	AT91_REG	 SDRAMC_LPR; 	/* SDRAM Controller Low Power Register */
	AT91_REG	 SDRAMC_IER; 	/* SDRAM Controller Interrupt Enable Register */
	AT91_REG	 SDRAMC_IDR; 	/* SDRAM Controller Interrupt Disable Register */
	AT91_REG	 SDRAMC_IMR; 	/* SDRAM Controller Interrupt Mask Register */
	AT91_REG	 SDRAMC_ISR; 	/* SDRAM Controller Interrupt Mask Register */
	AT91_REG	 SDRAMC_MDR; 	/* SDRAM Memory Device Register */
	AT91_REG	 Reserved0[118];
	AT91_REG	 SMC_SETUP0; 	/*  Setup Register for CS 0 */
	AT91_REG	 SMC_PULSE0; 	/*  Pulse Register for CS 0 */
	AT91_REG	 SMC_CYCLE0; 	/*  Cycle Register for CS 0 */
	AT91_REG	 SMC_CTRL0; 	/*  Control Register for CS 0 */
	AT91_REG	 SMC_SETUP1; 	/*  Setup Register for CS 1 */
	AT91_REG	 SMC_PULSE1; 	/*  Pulse Register for CS 1 */
	AT91_REG	 SMC_CYCLE1; 	/*  Cycle Register for CS 1 */
	AT91_REG	 SMC_CTRL1; 	/*  Control Register for CS 1 */
	AT91_REG	 SMC_SETUP2; 	/*  Setup Register for CS 2 */
	AT91_REG	 SMC_PULSE2; 	/*  Pulse Register for CS 2 */
	AT91_REG	 SMC_CYCLE2; 	/*  Cycle Register for CS 2 */
	AT91_REG	 SMC_CTRL2; 	/*  Control Register for CS 2 */
	AT91_REG	 SMC_SETUP3; 	/*  Setup Register for CS 3 */
	AT91_REG	 SMC_PULSE3; 	/*  Pulse Register for CS 3 */
	AT91_REG	 SMC_CYCLE3; 	/*  Cycle Register for CS 3 */
	AT91_REG	 SMC_CTRL3; 	/*  Control Register for CS 3 */
	AT91_REG	 SMC_SETUP4; 	/*  Setup Register for CS 4 */
	AT91_REG	 SMC_PULSE4; 	/*  Pulse Register for CS 4 */
	AT91_REG	 SMC_CYCLE4; 	/*  Cycle Register for CS 4 */
	AT91_REG	 SMC_CTRL4; 	/*  Control Register for CS 4 */
	AT91_REG	 SMC_SETUP5; 	/*  Setup Register for CS 5 */
	AT91_REG	 SMC_PULSE5; 	/*  Pulse Register for CS 5 */
	AT91_REG	 SMC_CYCLE5; 	/*  Cycle Register for CS 5 */
	AT91_REG	 SMC_CTRL5; 	/*  Control Register for CS 5 */
	AT91_REG	 SMC_SETUP6; 	/*  Setup Register for CS 6 */
	AT91_REG	 SMC_PULSE6; 	/*  Pulse Register for CS 6 */
	AT91_REG	 SMC_CYCLE6; 	/*  Cycle Register for CS 6 */
	AT91_REG	 SMC_CTRL6; 	/*  Control Register for CS 6 */
	AT91_REG	 SMC_SETUP7; 	/*  Setup Register for CS 7 */
	AT91_REG	 SMC_PULSE7; 	/*  Pulse Register for CS 7 */
	AT91_REG	 SMC_CYCLE7; 	/*  Cycle Register for CS 7 */
	AT91_REG	 SMC_CTRL7; 	/*  Control Register for CS 7 */
	AT91_REG	 Reserved1[96];
	AT91_REG	 MATRIX_MCFG; 	/*  Master Configuration Register */
	AT91_REG	 MATRIX_SCFG0; 	/*  Slave Configuration Register 0 */
	AT91_REG	 MATRIX_SCFG1; 	/*  Slave Configuration Register 1 */
	AT91_REG	 MATRIX_SCFG2; 	/*  Slave Configuration Register 2 */
	AT91_REG	 MATRIX_SCFG3; 	/*  Slave Configuration Register 3 */
	AT91_REG	 MATRIX_SCFG4; 	/*  Slave Configuration Register 4 */
	AT91_REG	 Reserved2[3];
	AT91_REG	 MATRIX_TCMR; 	/*  Slave 0 Special Function Register */
	AT91_REG	 Reserved3[2];
	AT91_REG	 MATRIX_EBICSA; 	/*  Slave 3 Special Function Register */
	AT91_REG	 MATRIX_USBPCR; 	/*  Slave 4 Special Function Register */
	AT91_REG	 Reserved4[3];
	AT91_REG	 MATRIX_VERSION; 	/*  Version Register */
	AT91_REG	 Reserved5[110];
	AT91_REG	 AIC_SMR[32]; 	/* Source Mode Register */
	AT91_REG	 AIC_SVR[32]; 	/* Source Vector Register */
	AT91_REG	 AIC_IVR; 	/* IRQ Vector Register */
	AT91_REG	 AIC_FVR; 	/* FIQ Vector Register */
	AT91_REG	 AIC_ISR; 	/* Interrupt Status Register */
	AT91_REG	 AIC_IPR; 	/* Interrupt Pending Register */
	AT91_REG	 AIC_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 AIC_CISR; 	/* Core Interrupt Status Register */
	AT91_REG	 Reserved6[2];
	AT91_REG	 AIC_IECR; 	/* Interrupt Enable Command Register */
	AT91_REG	 AIC_IDCR; 	/* Interrupt Disable Command Register */
	AT91_REG	 AIC_ICCR; 	/* Interrupt Clear Command Register */
	AT91_REG	 AIC_ISCR; 	/* Interrupt Set Command Register */
	AT91_REG	 AIC_EOICR; 	/* End of Interrupt Command Register */
	AT91_REG	 AIC_SPU; 	/* Spurious Vector Register */
	AT91_REG	 AIC_DCR; 	/* Debug Control Register (Protect) */
	AT91_REG	 Reserved7[1];
	AT91_REG	 AIC_FFER; 	/* Fast Forcing Enable Register */
	AT91_REG	 AIC_FFDR; 	/* Fast Forcing Disable Register */
	AT91_REG	 AIC_FFSR; 	/* Fast Forcing Status Register */
	AT91_REG	 Reserved8[45];
	AT91_REG	 DBGU_CR; 	/* Control Register */
	AT91_REG	 DBGU_MR; 	/* Mode Register */
	AT91_REG	 DBGU_IER; 	/* Interrupt Enable Register */
	AT91_REG	 DBGU_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 DBGU_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 DBGU_CSR; 	/* Channel Status Register */
	AT91_REG	 DBGU_RHR; 	/* Receiver Holding Register */
	AT91_REG	 DBGU_THR; 	/* Transmitter Holding Register */
	AT91_REG	 DBGU_BRGR; 	/* Baud Rate Generator Register */
	AT91_REG	 Reserved9[7];
	AT91_REG	 DBGU_CIDR; 	/* Chip ID Register */
	AT91_REG	 DBGU_EXID; 	/* Chip ID Extension Register */
	AT91_REG	 DBGU_FNTR; 	/* Force NTRST Register */
	AT91_REG	 Reserved10[45];
	AT91_REG	 DBGU_RPR; 	/* Receive Pointer Register */
	AT91_REG	 DBGU_RCR; 	/* Receive Counter Register */
	AT91_REG	 DBGU_TPR; 	/* Transmit Pointer Register */
	AT91_REG	 DBGU_TCR; 	/* Transmit Counter Register */
	AT91_REG	 DBGU_RNPR; 	/* Receive Next Pointer Register */
	AT91_REG	 DBGU_RNCR; 	/* Receive Next Counter Register */
	AT91_REG	 DBGU_TNPR; 	/* Transmit Next Pointer Register */
	AT91_REG	 DBGU_TNCR; 	/* Transmit Next Counter Register */
	AT91_REG	 DBGU_PTCR; 	/* PDC Transfer Control Register */
	AT91_REG	 DBGU_PTSR; 	/* PDC Transfer Status Register */
	AT91_REG	 Reserved11[54];
	AT91_REG	 PIOA_PER; 	/* PIO Enable Register */
	AT91_REG	 PIOA_PDR; 	/* PIO Disable Register */
	AT91_REG	 PIOA_PSR; 	/* PIO Status Register */
	AT91_REG	 Reserved12[1];
	AT91_REG	 PIOA_OER; 	/* Output Enable Register */
	AT91_REG	 PIOA_ODR; 	/* Output Disable Registerr */
	AT91_REG	 PIOA_OSR; 	/* Output Status Register */
	AT91_REG	 Reserved13[1];
	AT91_REG	 PIOA_IFER; 	/* Input Filter Enable Register */
	AT91_REG	 PIOA_IFDR; 	/* Input Filter Disable Register */
	AT91_REG	 PIOA_IFSR; 	/* Input Filter Status Register */
	AT91_REG	 Reserved14[1];
	AT91_REG	 PIOA_SODR; 	/* Set Output Data Register */
	AT91_REG	 PIOA_CODR; 	/* Clear Output Data Register */
	AT91_REG	 PIOA_ODSR; 	/* Output Data Status Register */
	AT91_REG	 PIOA_PDSR; 	/* Pin Data Status Register */
	AT91_REG	 PIOA_IER; 	/* Interrupt Enable Register */
	AT91_REG	 PIOA_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 PIOA_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 PIOA_ISR; 	/* Interrupt Status Register */
	AT91_REG	 PIOA_MDER; 	/* Multi-driver Enable Register */
	AT91_REG	 PIOA_MDDR; 	/* Multi-driver Disable Register */
	AT91_REG	 PIOA_MDSR; 	/* Multi-driver Status Register */
	AT91_REG	 Reserved15[1];
	AT91_REG	 PIOA_PPUDR; 	/* Pull-up Disable Register */
	AT91_REG	 PIOA_PPUER; 	/* Pull-up Enable Register */
	AT91_REG	 PIOA_PPUSR; 	/* Pull-up Status Register */
	AT91_REG	 Reserved16[1];
	AT91_REG	 PIOA_ASR; 	/* Select A Register */
	AT91_REG	 PIOA_BSR; 	/* Select B Register */
	AT91_REG	 PIOA_ABSR; 	/* AB Select Status Register */
	AT91_REG	 Reserved17[9];
	AT91_REG	 PIOA_OWER; 	/* Output Write Enable Register */
	AT91_REG	 PIOA_OWDR; 	/* Output Write Disable Register */
	AT91_REG	 PIOA_OWSR; 	/* Output Write Status Register */
	AT91_REG	 Reserved18[85];
	AT91_REG	 PIOB_PER; 	/* PIO Enable Register */
	AT91_REG	 PIOB_PDR; 	/* PIO Disable Register */
	AT91_REG	 PIOB_PSR; 	/* PIO Status Register */
	AT91_REG	 Reserved19[1];
	AT91_REG	 PIOB_OER; 	/* Output Enable Register */
	AT91_REG	 PIOB_ODR; 	/* Output Disable Registerr */
	AT91_REG	 PIOB_OSR; 	/* Output Status Register */
	AT91_REG	 Reserved20[1];
	AT91_REG	 PIOB_IFER; 	/* Input Filter Enable Register */
	AT91_REG	 PIOB_IFDR; 	/* Input Filter Disable Register */
	AT91_REG	 PIOB_IFSR; 	/* Input Filter Status Register */
	AT91_REG	 Reserved21[1];
	AT91_REG	 PIOB_SODR; 	/* Set Output Data Register */
	AT91_REG	 PIOB_CODR; 	/* Clear Output Data Register */
	AT91_REG	 PIOB_ODSR; 	/* Output Data Status Register */
	AT91_REG	 PIOB_PDSR; 	/* Pin Data Status Register */
	AT91_REG	 PIOB_IER; 	/* Interrupt Enable Register */
	AT91_REG	 PIOB_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 PIOB_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 PIOB_ISR; 	/* Interrupt Status Register */
	AT91_REG	 PIOB_MDER; 	/* Multi-driver Enable Register */
	AT91_REG	 PIOB_MDDR; 	/* Multi-driver Disable Register */
	AT91_REG	 PIOB_MDSR; 	/* Multi-driver Status Register */
	AT91_REG	 Reserved22[1];
	AT91_REG	 PIOB_PPUDR; 	/* Pull-up Disable Register */
	AT91_REG	 PIOB_PPUER; 	/* Pull-up Enable Register */
	AT91_REG	 PIOB_PPUSR; 	/* Pull-up Status Register */
	AT91_REG	 Reserved23[1];
	AT91_REG	 PIOB_ASR; 	/* Select A Register */
	AT91_REG	 PIOB_BSR; 	/* Select B Register */
	AT91_REG	 PIOB_ABSR; 	/* AB Select Status Register */
	AT91_REG	 Reserved24[9];
	AT91_REG	 PIOB_OWER; 	/* Output Write Enable Register */
	AT91_REG	 PIOB_OWDR; 	/* Output Write Disable Register */
	AT91_REG	 PIOB_OWSR; 	/* Output Write Status Register */
	AT91_REG	 Reserved25[85];
	AT91_REG	 PIOC_PER; 	/* PIO Enable Register */
	AT91_REG	 PIOC_PDR; 	/* PIO Disable Register */
	AT91_REG	 PIOC_PSR; 	/* PIO Status Register */
	AT91_REG	 Reserved26[1];
	AT91_REG	 PIOC_OER; 	/* Output Enable Register */
	AT91_REG	 PIOC_ODR; 	/* Output Disable Registerr */
	AT91_REG	 PIOC_OSR; 	/* Output Status Register */
	AT91_REG	 Reserved27[1];
	AT91_REG	 PIOC_IFER; 	/* Input Filter Enable Register */
	AT91_REG	 PIOC_IFDR; 	/* Input Filter Disable Register */
	AT91_REG	 PIOC_IFSR; 	/* Input Filter Status Register */
	AT91_REG	 Reserved28[1];
	AT91_REG	 PIOC_SODR; 	/* Set Output Data Register */
	AT91_REG	 PIOC_CODR; 	/* Clear Output Data Register */
	AT91_REG	 PIOC_ODSR; 	/* Output Data Status Register */
	AT91_REG	 PIOC_PDSR; 	/* Pin Data Status Register */
	AT91_REG	 PIOC_IER; 	/* Interrupt Enable Register */
	AT91_REG	 PIOC_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 PIOC_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 PIOC_ISR; 	/* Interrupt Status Register */
	AT91_REG	 PIOC_MDER; 	/* Multi-driver Enable Register */
	AT91_REG	 PIOC_MDDR; 	/* Multi-driver Disable Register */
	AT91_REG	 PIOC_MDSR; 	/* Multi-driver Status Register */
	AT91_REG	 Reserved29[1];
	AT91_REG	 PIOC_PPUDR; 	/* Pull-up Disable Register */
	AT91_REG	 PIOC_PPUER; 	/* Pull-up Enable Register */
	AT91_REG	 PIOC_PPUSR; 	/* Pull-up Status Register */
	AT91_REG	 Reserved30[1];
	AT91_REG	 PIOC_ASR; 	/* Select A Register */
	AT91_REG	 PIOC_BSR; 	/* Select B Register */
	AT91_REG	 PIOC_ABSR; 	/* AB Select Status Register */
	AT91_REG	 Reserved31[9];
	AT91_REG	 PIOC_OWER; 	/* Output Write Enable Register */
	AT91_REG	 PIOC_OWDR; 	/* Output Write Disable Register */
	AT91_REG	 PIOC_OWSR; 	/* Output Write Status Register */
	AT91_REG	 Reserved32[213];
	AT91_REG	 PMC_SCER; 	/* System Clock Enable Register */
	AT91_REG	 PMC_SCDR; 	/* System Clock Disable Register */
	AT91_REG	 PMC_SCSR; 	/* System Clock Status Register */
	AT91_REG	 Reserved33[1];
	AT91_REG	 PMC_PCER; 	/* Peripheral Clock Enable Register */
	AT91_REG	 PMC_PCDR; 	/* Peripheral Clock Disable Register */
	AT91_REG	 PMC_PCSR; 	/* Peripheral Clock Status Register */
	AT91_REG	 Reserved34[1];
	AT91_REG	 PMC_MOR; 	/* Main Oscillator Register */
	AT91_REG	 PMC_MCFR; 	/* Main Clock  Frequency Register */
	AT91_REG	 PMC_PLLAR; 	/* PLL A Register */
	AT91_REG	 PMC_PLLBR; 	/* PLL B Register */
	AT91_REG	 PMC_MCKR; 	/* Master Clock Register */
	AT91_REG	 Reserved35[3];
	AT91_REG	 PMC_PCKR[8]; 	/* Programmable Clock Register */
	AT91_REG	 PMC_IER; 	/* Interrupt Enable Register */
	AT91_REG	 PMC_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 PMC_SR; 	/* Status Register */
	AT91_REG	 PMC_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 Reserved36[36];
	AT91_REG	 RSTC_RCR; 	/* Reset Control Register */
	AT91_REG	 RSTC_RSR; 	/* Reset Status Register */
	AT91_REG	 RSTC_RMR; 	/* Reset Mode Register */
	AT91_REG	 Reserved37[1];
	AT91_REG	 SHDWC_SHCR; 	/* Shut Down Control Register */
	AT91_REG	 SHDWC_SHMR; 	/* Shut Down Mode Register */
	AT91_REG	 SHDWC_SHSR; 	/* Shut Down Status Register */
	AT91_REG	 Reserved38[1];
	AT91_REG	 RTTC_RTMR; 	/* Real-time Mode Register */
	AT91_REG	 RTTC_RTAR; 	/* Real-time Alarm Register */
	AT91_REG	 RTTC_RTVR; 	/* Real-time Value Register */
	AT91_REG	 RTTC_RTSR; 	/* Real-time Status Register */
	AT91_REG	 PITC_PIMR; 	/* Period Interval Mode Register */
	AT91_REG	 PITC_PISR; 	/* Period Interval Status Register */
	AT91_REG	 PITC_PIVR; 	/* Period Interval Value Register */
	AT91_REG	 PITC_PIIR; 	/* Period Interval Image Register */
	AT91_REG	 WDTC_WDCR; 	/* Watchdog Control Register */
	AT91_REG	 WDTC_WDMR; 	/* Watchdog Mode Register */
	AT91_REG	 WDTC_WDSR; 	/* Watchdog Status Register */
	AT91_REG	 Reserved39[1];
	AT91_REG	 SYS_GPBR0; 	/* General Purpose Register 0 */
	AT91_REG	 SYS_GPBR1; 	/* General Purpose Register 1 */
	AT91_REG	 SYS_GPBR2; 	/* General Purpose Register 2 */
	AT91_REG	 SYS_GPBR3; 	/* General Purpose Register 3 */
} AT91S_SYS, *AT91PS_SYS;

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Static Memory Controller Interface */
/* ***************************************************************************** */
typedef struct _AT91S_SMC {
	AT91_REG	 SMC_SETUP0; 	/*  Setup Register for CS 0 */
	AT91_REG	 SMC_PULSE0; 	/*  Pulse Register for CS 0 */
	AT91_REG	 SMC_CYCLE0; 	/*  Cycle Register for CS 0 */
	AT91_REG	 SMC_CTRL0; 	/*  Control Register for CS 0 */
	AT91_REG	 SMC_SETUP1; 	/*  Setup Register for CS 1 */
	AT91_REG	 SMC_PULSE1; 	/*  Pulse Register for CS 1 */
	AT91_REG	 SMC_CYCLE1; 	/*  Cycle Register for CS 1 */
	AT91_REG	 SMC_CTRL1; 	/*  Control Register for CS 1 */
	AT91_REG	 SMC_SETUP2; 	/*  Setup Register for CS 2 */
	AT91_REG	 SMC_PULSE2; 	/*  Pulse Register for CS 2 */
	AT91_REG	 SMC_CYCLE2; 	/*  Cycle Register for CS 2 */
	AT91_REG	 SMC_CTRL2; 	/*  Control Register for CS 2 */
	AT91_REG	 SMC_SETUP3; 	/*  Setup Register for CS 3 */
	AT91_REG	 SMC_PULSE3; 	/*  Pulse Register for CS 3 */
	AT91_REG	 SMC_CYCLE3; 	/*  Cycle Register for CS 3 */
	AT91_REG	 SMC_CTRL3; 	/*  Control Register for CS 3 */
	AT91_REG	 SMC_SETUP4; 	/*  Setup Register for CS 4 */
	AT91_REG	 SMC_PULSE4; 	/*  Pulse Register for CS 4 */
	AT91_REG	 SMC_CYCLE4; 	/*  Cycle Register for CS 4 */
	AT91_REG	 SMC_CTRL4; 	/*  Control Register for CS 4 */
	AT91_REG	 SMC_SETUP5; 	/*  Setup Register for CS 5 */
	AT91_REG	 SMC_PULSE5; 	/*  Pulse Register for CS 5 */
	AT91_REG	 SMC_CYCLE5; 	/*  Cycle Register for CS 5 */
	AT91_REG	 SMC_CTRL5; 	/*  Control Register for CS 5 */
	AT91_REG	 SMC_SETUP6; 	/*  Setup Register for CS 6 */
	AT91_REG	 SMC_PULSE6; 	/*  Pulse Register for CS 6 */
	AT91_REG	 SMC_CYCLE6; 	/*  Cycle Register for CS 6 */
	AT91_REG	 SMC_CTRL6; 	/*  Control Register for CS 6 */
	AT91_REG	 SMC_SETUP7; 	/*  Setup Register for CS 7 */
	AT91_REG	 SMC_PULSE7; 	/*  Pulse Register for CS 7 */
	AT91_REG	 SMC_CYCLE7; 	/*  Cycle Register for CS 7 */
	AT91_REG	 SMC_CTRL7; 	/*  Control Register for CS 7 */
} AT91S_SMC, *AT91PS_SMC;

/* -------- SMC_SETUP : (SMC Offset: 0x0) Setup Register for CS x --------  */
#define AT91C_SMC_NWESETUP    ((unsigned int) 0x3F <<  0) /* (SMC) NWE Setup Length */
#define AT91C_SMC_NCSSETUPWR  ((unsigned int) 0x3F <<  8) /* (SMC) NCS Setup Length in WRite Access */
#define AT91C_SMC_NRDSETUP    ((unsigned int) 0x3F << 16) /* (SMC) NRD Setup Length */
#define AT91C_SMC_NCSSETUPRD  ((unsigned int) 0x3F << 24) /* (SMC) NCS Setup Length in ReaD Access */
/* -------- SMC_PULSE : (SMC Offset: 0x4) Pulse Register for CS x --------  */
#define AT91C_SMC_NWEPULSE    ((unsigned int) 0x7F <<  0) /* (SMC) NWE Pulse Length */
#define AT91C_SMC_NCSPULSEWR  ((unsigned int) 0x7F <<  8) /* (SMC) NCS Pulse Length in WRite Access */
#define AT91C_SMC_NRDPULSE    ((unsigned int) 0x7F << 16) /* (SMC) NRD Pulse Length */
#define AT91C_SMC_NCSPULSERD  ((unsigned int) 0x7F << 24) /* (SMC) NCS Pulse Length in ReaD Access */
/* -------- SMC_CYC : (SMC Offset: 0x8) Cycle Register for CS x --------  */
#define AT91C_SMC_NWECYCLE    ((unsigned int) 0x1FF <<  0) /* (SMC) Total Write Cycle Length */
#define AT91C_SMC_NRDCYCLE    ((unsigned int) 0x1FF << 16) /* (SMC) Total Read Cycle Length */
/* -------- SMC_CTRL : (SMC Offset: 0xc) Control Register for CS x --------  */
#define AT91C_SMC_READMODE    ((unsigned int) 0x1 <<  0) /* (SMC) Read Mode */
#define AT91C_SMC_WRITEMODE   ((unsigned int) 0x1 <<  1) /* (SMC) Write Mode */
#define AT91C_SMC_NWAITM      ((unsigned int) 0x3 <<  5) /* (SMC) NWAIT Mode */
#define 	AT91C_SMC_NWAITM_NWAIT_DISABLE        ((unsigned int) 0x0 <<  5) /* (SMC) External NWAIT disabled. */
#define 	AT91C_SMC_NWAITM_NWAIT_ENABLE_FROZEN  ((unsigned int) 0x2 <<  5) /* (SMC) External NWAIT enabled in frozen mode. */
#define 	AT91C_SMC_NWAITM_NWAIT_ENABLE_READY   ((unsigned int) 0x3 <<  5) /* (SMC) External NWAIT enabled in ready mode. */
#define AT91C_SMC_BAT         ((unsigned int) 0x1 <<  8) /* (SMC) Byte Access Type */
#define 	AT91C_SMC_BAT_BYTE_SELECT          ((unsigned int) 0x0 <<  8) /* (SMC) Write controled by ncs, nbs0, nbs1,
nbs2, nbs3. Read controled by ncs, nrd, nbs0, nbs1, nbs2, nbs3 */
#define 	AT91C_SMC_BAT_BYTE_WRITE           ((unsigned int) 0x1 <<  8) /* (SMC) Write controled by ncs, nwe0, nwe1, nwe2, nwe3. Read controled by ncs and nrd. */
#define AT91C_SMC_DBW         ((unsigned int) 0x3 << 12) /* (SMC) Data Bus Width */
#define 	AT91C_SMC_DBW_WIDTH_EIGTH_BITS     ((unsigned int) 0x0 << 12) /* (SMC) 8 bits. */
#define 	AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS   ((unsigned int) 0x1 << 12) /* (SMC) 16 bits. */
#define 	AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS ((unsigned int) 0x2 << 12) /* (SMC) 32 bits. */
#define AT91C_SMC_TDF         ((unsigned int) 0xF << 16) /* (SMC) Data Float Time */
#define AT91C_SMC_TDFEN       ((unsigned int) 0x1 << 20) /* (SMC) TDF Enabled */
#define AT91C_SMC_PMEN        ((unsigned int) 0x1 << 24) /* (SMC) Page Mode Enabled */
#define AT91C_SMC_PS          ((unsigned int) 0x3 << 28) /* (SMC) Page Size */
#define 	AT91C_SMC_PS_SIZE_FOUR_BYTES      ((unsigned int) 0x0 << 28) /* (SMC) 4 bytes */
#define 	AT91C_SMC_PS_SIZE_EIGHT_BYTES     ((unsigned int) 0x1 << 28) /* (SMC) 8 bytes */
#define 	AT91C_SMC_PS_SIZE_SIXTEEN_BYTES   ((unsigned int) 0x2 << 28) /* (SMC) 16 bytes */
#define 	AT91C_SMC_PS_SIZE_THIRTY_TWO_BYTES ((unsigned int) 0x3 << 28) /* (SMC) 32 bytes */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR AHB Matrix Interface */
/* ***************************************************************************** */
typedef struct _AT91S_MATRIX {
	AT91_REG	 MATRIX_MCFG; 	/*  Master Configuration Register */
	AT91_REG	 MATRIX_SCFG0; 	/*  Slave Configuration Register 0 */
	AT91_REG	 MATRIX_SCFG1; 	/*  Slave Configuration Register 1 */
	AT91_REG	 MATRIX_SCFG2; 	/*  Slave Configuration Register 2 */
	AT91_REG	 MATRIX_SCFG3; 	/*  Slave Configuration Register 3 */
	AT91_REG	 MATRIX_SCFG4; 	/*  Slave Configuration Register 4 */
	AT91_REG	 Reserved0[3];
	AT91_REG	 MATRIX_TCMR; 	/*  Slave 0 Special Function Register */
	AT91_REG	 Reserved1[2];
	AT91_REG	 MATRIX_EBICSA; 	/*  Slave 3 Special Function Register */
	AT91_REG	 MATRIX_USBPCR; 	/*  Slave 4 Special Function Register */
	AT91_REG	 Reserved2[3];
	AT91_REG	 MATRIX_VERSION; 	/*  Version Register */
} AT91S_MATRIX, *AT91PS_MATRIX;

#define 	AT91C_MATRIX_CS3A_SM                   ((unsigned int) 0x1 <<  3) /* (MATRIX) Chip Select 3 is assigned to the Static Memory Controller and the SmartMedia Logic is activated. */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Peripheral Data Controller */
/* ***************************************************************************** */
typedef struct _AT91S_PDC {
	AT91_REG	 PDC_RPR; 	/* Receive Pointer Register */
	AT91_REG	 PDC_RCR; 	/* Receive Counter Register */
	AT91_REG	 PDC_TPR; 	/* Transmit Pointer Register */
	AT91_REG	 PDC_TCR; 	/* Transmit Counter Register */
	AT91_REG	 PDC_RNPR; 	/* Receive Next Pointer Register */
	AT91_REG	 PDC_RNCR; 	/* Receive Next Counter Register */
	AT91_REG	 PDC_TNPR; 	/* Transmit Next Pointer Register */
	AT91_REG	 PDC_TNCR; 	/* Transmit Next Counter Register */
	AT91_REG	 PDC_PTCR; 	/* PDC Transfer Control Register */
	AT91_REG	 PDC_PTSR; 	/* PDC Transfer Status Register */
} AT91S_PDC, *AT91PS_PDC;

/* -------- PDC_PTCR : (PDC Offset: 0x20) PDC Transfer Control Register --------  */
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) /* (PDC) Receiver Transfer Enable */
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) /* (PDC) Receiver Transfer Disable */
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) /* (PDC) Transmitter Transfer Enable */
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) /* (PDC) Transmitter Transfer Disable */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Debug Unit */
/* ***************************************************************************** */
typedef struct _AT91S_DBGU {
	AT91_REG	 DBGU_CR; 	/* Control Register */
	AT91_REG	 DBGU_MR; 	/* Mode Register */
	AT91_REG	 DBGU_IER; 	/* Interrupt Enable Register */
	AT91_REG	 DBGU_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 DBGU_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 DBGU_CSR; 	/* Channel Status Register */
	AT91_REG	 DBGU_RHR; 	/* Receiver Holding Register */
	AT91_REG	 DBGU_THR; 	/* Transmitter Holding Register */
	AT91_REG	 DBGU_BRGR; 	/* Baud Rate Generator Register */
	AT91_REG	 Reserved0[7];
	AT91_REG	 DBGU_CIDR; 	/* Chip ID Register */
	AT91_REG	 DBGU_EXID; 	/* Chip ID Extension Register */
	AT91_REG	 DBGU_FNTR; 	/* Force NTRST Register */
	AT91_REG	 Reserved1[45];
	AT91_REG	 DBGU_RPR; 	/* Receive Pointer Register */
	AT91_REG	 DBGU_RCR; 	/* Receive Counter Register */
	AT91_REG	 DBGU_TPR; 	/* Transmit Pointer Register */
	AT91_REG	 DBGU_TCR; 	/* Transmit Counter Register */
	AT91_REG	 DBGU_RNPR; 	/* Receive Next Pointer Register */
	AT91_REG	 DBGU_RNCR; 	/* Receive Next Counter Register */
	AT91_REG	 DBGU_TNPR; 	/* Transmit Next Pointer Register */
	AT91_REG	 DBGU_TNCR; 	/* Transmit Next Counter Register */
	AT91_REG	 DBGU_PTCR; 	/* PDC Transfer Control Register */
	AT91_REG	 DBGU_PTSR; 	/* PDC Transfer Status Register */
} AT91S_DBGU, *AT91PS_DBGU;

/* -------- DBGU_CR : (DBGU Offset: 0x0) Debug Unit Control Register --------  */
#define AT91C_US_RSTRX        ((unsigned int) 0x1 <<  2) /* (DBGU) Reset Receiver */
#define AT91C_US_RSTTX        ((unsigned int) 0x1 <<  3) /* (DBGU) Reset Transmitter */
#define AT91C_US_RXEN         ((unsigned int) 0x1 <<  4) /* (DBGU) Receiver Enable */
#define AT91C_US_RXDIS        ((unsigned int) 0x1 <<  5) /* (DBGU) Receiver Disable */
#define AT91C_US_TXEN         ((unsigned int) 0x1 <<  6) /* (DBGU) Transmitter Enable */
#define AT91C_US_TXDIS        ((unsigned int) 0x1 <<  7) /* (DBGU) Transmitter Disable */
#define AT91C_US_RSTSTA       ((unsigned int) 0x1 <<  8) /* (DBGU) Reset Status Bits */
/* -------- DBGU_MR : (DBGU Offset: 0x4) Debug Unit Mode Register --------  */
#define AT91C_US_PAR          ((unsigned int) 0x7 <<  9) /* (DBGU) Parity type */
#define 	AT91C_US_PAR_EVEN                 ((unsigned int) 0x0 <<  9) /* (DBGU) Even Parity */
#define 	AT91C_US_PAR_ODD                  ((unsigned int) 0x1 <<  9) /* (DBGU) Odd Parity */
#define 	AT91C_US_PAR_SPACE                ((unsigned int) 0x2 <<  9) /* (DBGU) Parity forced to 0 (Space) */
#define 	AT91C_US_PAR_MARK                 ((unsigned int) 0x3 <<  9) /* (DBGU) Parity forced to 1 (Mark) */
#define 	AT91C_US_PAR_NONE                 ((unsigned int) 0x4 <<  9) /* (DBGU) No Parity */
#define 	AT91C_US_PAR_MULTI_DROP           ((unsigned int) 0x6 <<  9) /* (DBGU) Multi-drop mode */
#define AT91C_US_CHMODE       ((unsigned int) 0x3 << 14) /* (DBGU) Channel Mode */
#define 	AT91C_US_CHMODE_NORMAL               ((unsigned int) 0x0 << 14) /* (DBGU) Normal Mode: The USART channel operates as an RX/TX USART. */
#define 	AT91C_US_CHMODE_AUTO                 ((unsigned int) 0x1 << 14) /* (DBGU) Automatic Echo: Receiver Data Input is connected to the TXD pin. */
#define 	AT91C_US_CHMODE_LOCAL                ((unsigned int) 0x2 << 14) /* (DBGU) Local Loopback: Transmitter Output Signal is connected to Receiver Input Signal. */
#define 	AT91C_US_CHMODE_REMOTE               ((unsigned int) 0x3 << 14) /* (DBGU) Remote Loopback: RXD pin is internally connected to TXD pin. */
/* -------- DBGU_IER : (DBGU Offset: 0x8) Debug Unit Interrupt Enable Register --------  */
#define AT91C_US_RXRDY        ((unsigned int) 0x1 <<  0) /* (DBGU) RXRDY Interrupt */
#define AT91C_US_TXRDY        ((unsigned int) 0x1 <<  1) /* (DBGU) TXRDY Interrupt */
#define AT91C_US_ENDRX        ((unsigned int) 0x1 <<  3) /* (DBGU) End of Receive Transfer Interrupt */
#define AT91C_US_ENDTX        ((unsigned int) 0x1 <<  4) /* (DBGU) End of Transmit Interrupt */
#define AT91C_US_OVRE         ((unsigned int) 0x1 <<  5) /* (DBGU) Overrun Interrupt */
#define AT91C_US_FRAME        ((unsigned int) 0x1 <<  6) /* (DBGU) Framing Error Interrupt */
#define AT91C_US_PARE         ((unsigned int) 0x1 <<  7) /* (DBGU) Parity Error Interrupt */
#define AT91C_US_TXEMPTY      ((unsigned int) 0x1 <<  9) /* (DBGU) TXEMPTY Interrupt */
#define AT91C_US_TXBUFE       ((unsigned int) 0x1 << 11) /* (DBGU) TXBUFE Interrupt */
#define AT91C_US_RXBUFF       ((unsigned int) 0x1 << 12) /* (DBGU) RXBUFF Interrupt */
#define AT91C_US_COMM_TX      ((unsigned int) 0x1 << 30) /* (DBGU) COMM_TX Interrupt */
#define AT91C_US_COMM_RX      ((unsigned int) 0x1 << 31) /* (DBGU) COMM_RX Interrupt */
/* -------- DBGU_FNTR : (DBGU Offset: 0x48) Debug Unit FORCE_NTRST Register --------  */
#define AT91C_US_FORCE_NTRST  ((unsigned int) 0x1 <<  0) /* (DBGU) Force NTRST in JTAG */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Parallel Input Output Controler */
/* ***************************************************************************** */
typedef struct _AT91S_PIO {
	AT91_REG	 PIO_PER; 	/* PIO Enable Register */
	AT91_REG	 PIO_PDR; 	/* PIO Disable Register */
	AT91_REG	 PIO_PSR; 	/* PIO Status Register */
	AT91_REG	 Reserved0[1];
	AT91_REG	 PIO_OER; 	/* Output Enable Register */
	AT91_REG	 PIO_ODR; 	/* Output Disable Registerr */
	AT91_REG	 PIO_OSR; 	/* Output Status Register */
	AT91_REG	 Reserved1[1];
	AT91_REG	 PIO_IFER; 	/* Input Filter Enable Register */
	AT91_REG	 PIO_IFDR; 	/* Input Filter Disable Register */
	AT91_REG	 PIO_IFSR; 	/* Input Filter Status Register */
	AT91_REG	 Reserved2[1];
	AT91_REG	 PIO_SODR; 	/* Set Output Data Register */
	AT91_REG	 PIO_CODR; 	/* Clear Output Data Register */
	AT91_REG	 PIO_ODSR; 	/* Output Data Status Register */
	AT91_REG	 PIO_PDSR; 	/* Pin Data Status Register */
	AT91_REG	 PIO_IER; 	/* Interrupt Enable Register */
	AT91_REG	 PIO_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 PIO_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 PIO_ISR; 	/* Interrupt Status Register */
	AT91_REG	 PIO_MDER; 	/* Multi-driver Enable Register */
	AT91_REG	 PIO_MDDR; 	/* Multi-driver Disable Register */
	AT91_REG	 PIO_MDSR; 	/* Multi-driver Status Register */
	AT91_REG	 Reserved3[1];
	AT91_REG	 PIO_PPUDR; 	/* Pull-up Disable Register */
	AT91_REG	 PIO_PPUER; 	/* Pull-up Enable Register */
	AT91_REG	 PIO_PPUSR; 	/* Pull-up Status Register */
	AT91_REG	 Reserved4[1];
	AT91_REG	 PIO_ASR; 	/* Select A Register */
	AT91_REG	 PIO_BSR; 	/* Select B Register */
	AT91_REG	 PIO_ABSR; 	/* AB Select Status Register */
	AT91_REG	 Reserved5[9];
	AT91_REG	 PIO_OWER; 	/* Output Write Enable Register */
	AT91_REG	 PIO_OWDR; 	/* Output Write Disable Register */
	AT91_REG	 PIO_OWSR; 	/* Output Write Status Register */
} AT91S_PIO, *AT91PS_PIO;

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Power Management Controler */
/* ***************************************************************************** */
typedef struct _AT91S_PMC {
	AT91_REG	 PMC_SCER; 	/* System Clock Enable Register */
	AT91_REG	 PMC_SCDR; 	/* System Clock Disable Register */
	AT91_REG	 PMC_SCSR; 	/* System Clock Status Register */
	AT91_REG	 Reserved0[1];
	AT91_REG	 PMC_PCER; 	/* Peripheral Clock Enable Register */
	AT91_REG	 PMC_PCDR; 	/* Peripheral Clock Disable Register */
	AT91_REG	 PMC_PCSR; 	/* Peripheral Clock Status Register */
	AT91_REG	 Reserved1[1];
	AT91_REG	 PMC_MOR; 	/* Main Oscillator Register */
	AT91_REG	 PMC_MCFR; 	/* Main Clock  Frequency Register */
	AT91_REG	 PMC_PLLAR; 	/* PLL A Register */
	AT91_REG	 PMC_PLLBR; 	/* PLL B Register */
	AT91_REG	 PMC_MCKR; 	/* Master Clock Register */
	AT91_REG	 Reserved2[3];
	AT91_REG	 PMC_PCKR[8]; 	/* Programmable Clock Register */
	AT91_REG	 PMC_IER; 	/* Interrupt Enable Register */
	AT91_REG	 PMC_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 PMC_SR; 	/* Status Register */
	AT91_REG	 PMC_IMR; 	/* Interrupt Mask Register */
} AT91S_PMC, *AT91PS_PMC;

/* -------- PMC_SCER : (PMC Offset: 0x0) System Clock Enable Register --------  */
#define AT91C_PMC_PCK         ((unsigned int) 0x1 <<  0) /* (PMC) Processor Clock */
#define AT91C_PMC_UHP         ((unsigned int) 0x1 <<  6) /* (PMC) USB Host Port Clock */
#define AT91C_PMC_UDP         ((unsigned int) 0x1 <<  7) /* (PMC) USB Device Port Clock */
#define AT91C_PMC_PCK0        ((unsigned int) 0x1 <<  8) /* (PMC) Programmable Clock Output */
#define AT91C_PMC_PCK1        ((unsigned int) 0x1 <<  9) /* (PMC) Programmable Clock Output */
#define AT91C_PMC_PCK2        ((unsigned int) 0x1 << 10) /* (PMC) Programmable Clock Output */
#define AT91C_PMC_PCK3        ((unsigned int) 0x1 << 11) /* (PMC) Programmable Clock Output */
#define AT91C_PMC_HCK0        ((unsigned int) 0x1 << 16) /* (PMC) AHB LCDCK Clock Output */
#define AT91C_PMC_HCK1        ((unsigned int) 0x1 << 17) /* (PMC) AHB LCDCK Clock Output */
/* -------- PMC_MCKR : (PMC Offset: 0x30) Master Clock Register --------  */
#define AT91C_PMC_CSS         ((unsigned int) 0x3 <<  0) /* (PMC) Programmable Clock Selection */
#define 	AT91C_PMC_CSS_SLOW_CLK             ((unsigned int) 0x0) /* (PMC) Slow Clock is selected */
#define 	AT91C_PMC_CSS_MAIN_CLK             ((unsigned int) 0x1) /* (PMC) Main Clock is selected */
#define 	AT91C_PMC_CSS_PLLA_CLK             ((unsigned int) 0x2) /* (PMC) Clock from PLL A is selected */
#define 	AT91C_PMC_CSS_PLLB_CLK             ((unsigned int) 0x3) /* (PMC) Clock from PLL B is selected */
#define AT91C_PMC_PRES        ((unsigned int) 0x7 <<  2) /* (PMC) Programmable Clock Prescaler */
#define 	AT91C_PMC_PRES_CLK                  ((unsigned int) 0x0 <<  2) /* (PMC) Selected clock */
#define 	AT91C_PMC_PRES_CLK_2                ((unsigned int) 0x1 <<  2) /* (PMC) Selected clock divided by 2 */
#define 	AT91C_PMC_PRES_CLK_4                ((unsigned int) 0x2 <<  2) /* (PMC) Selected clock divided by 4 */
#define 	AT91C_PMC_PRES_CLK_8                ((unsigned int) 0x3 <<  2) /* (PMC) Selected clock divided by 8 */
#define 	AT91C_PMC_PRES_CLK_16               ((unsigned int) 0x4 <<  2) /* (PMC) Selected clock divided by 16 */
#define 	AT91C_PMC_PRES_CLK_32               ((unsigned int) 0x5 <<  2) /* (PMC) Selected clock divided by 32 */
#define 	AT91C_PMC_PRES_CLK_64               ((unsigned int) 0x6 <<  2) /* (PMC) Selected clock divided by 64 */
#define AT91C_PMC_MDIV        ((unsigned int) 0x3 <<  8) /* (PMC) Master Clock Division */
#define 	AT91C_PMC_MDIV_1                    ((unsigned int) 0x0 <<  8) /* (PMC) The master clock and the processor clock are the same */
#define 	AT91C_PMC_MDIV_2                    ((unsigned int) 0x1 <<  8) /* (PMC) The processor clock is twice as fast as the master clock */
#define 	AT91C_PMC_MDIV_3                    ((unsigned int) 0x2 <<  8) /* (PMC) The processor clock is four times faster than the master clock */
/* -------- PMC_IER : (PMC Offset: 0x60) PMC Interrupt Enable Register --------  */
#define AT91C_PMC_MOSCS       ((unsigned int) 0x1 <<  0) /* (PMC) MOSC Status/Enable/Disable/Mask */
#define AT91C_PMC_LOCKA       ((unsigned int) 0x1 <<  1) /* (PMC) PLL A Status/Enable/Disable/Mask */
#define AT91C_PMC_LOCKB       ((unsigned int) 0x1 <<  2) /* (PMC) PLL B Status/Enable/Disable/Mask */
#define AT91C_PMC_MCKRDY      ((unsigned int) 0x1 <<  3) /* (PMC) Master Clock Status/Enable/Disable/Mask */
#define AT91C_PMC_PCK0RDY     ((unsigned int) 0x1 <<  8) /* (PMC) PCK0_RDY Status/Enable/Disable/Mask */
#define AT91C_PMC_PCK1RDY     ((unsigned int) 0x1 <<  9) /* (PMC) PCK1_RDY Status/Enable/Disable/Mask */
#define AT91C_PMC_PCK2RDY     ((unsigned int) 0x1 << 10) /* (PMC) PCK2_RDY Status/Enable/Disable/Mask */
#define AT91C_PMC_PCK3RDY     ((unsigned int) 0x1 << 11) /* (PMC) PCK3_RDY Status/Enable/Disable/Mask */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Reset Controller Interface */
/* ***************************************************************************** */
typedef struct _AT91S_RSTC {
	AT91_REG	 RSTC_RCR; 	/* Reset Control Register */
	AT91_REG	 RSTC_RSR; 	/* Reset Status Register */
	AT91_REG	 RSTC_RMR; 	/* Reset Mode Register */
} AT91S_RSTC, *AT91PS_RSTC;

/* -------- RSTC_RCR : (RSTC Offset: 0x0) Reset Control Register --------  */
#define AT91C_RSTC_PROCRST    ((unsigned int) 0x1 <<  0) /* (RSTC) Processor Reset */
#define AT91C_RSTC_ICERST     ((unsigned int) 0x1 <<  1) /* (RSTC) ICE Interface Reset */
#define AT91C_RSTC_PERRST     ((unsigned int) 0x1 <<  2) /* (RSTC) Peripheral Reset */
#define AT91C_RSTC_EXTRST     ((unsigned int) 0x1 <<  3) /* (RSTC) External Reset */
#define AT91C_RSTC_KEY        ((unsigned int) 0xFF << 24) /* (RSTC) Password */
/* -------- RSTC_RSR : (RSTC Offset: 0x4) Reset Status Register --------  */
#define AT91C_RSTC_URSTS      ((unsigned int) 0x1 <<  0) /* (RSTC) User Reset Status */
#define AT91C_RSTC_RSTTYP     ((unsigned int) 0x7 <<  8) /* (RSTC) Reset Type */
#define 	AT91C_RSTC_RSTTYP_GENERAL              ((unsigned int) 0x0 <<  8) /* (RSTC) General reset. Both VDDCORE and VDDBU rising. */
#define 	AT91C_RSTC_RSTTYP_WAKEUP               ((unsigned int) 0x1 <<  8) /* (RSTC) WakeUp Reset. VDDCORE rising. */
#define 	AT91C_RSTC_RSTTYP_WATCHDOG             ((unsigned int) 0x2 <<  8) /* (RSTC) Watchdog Reset. Watchdog overflow occured. */
#define 	AT91C_RSTC_RSTTYP_SOFTWARE             ((unsigned int) 0x3 <<  8) /* (RSTC) Software Reset. Processor reset required by the software. */
#define 	AT91C_RSTC_RSTTYP_USER                 ((unsigned int) 0x4 <<  8) /* (RSTC) User Reset. NRST pin detected low. */
#define AT91C_RSTC_NRSTL      ((unsigned int) 0x1 << 16) /* (RSTC) NRST pin level */
#define AT91C_RSTC_SRCMP      ((unsigned int) 0x1 << 17) /* (RSTC) Software Reset Command in Progress. */
/* -------- RSTC_RMR : (RSTC Offset: 0x8) Reset Mode Register --------  */
#define AT91C_RSTC_URSTEN     ((unsigned int) 0x1 <<  0) /* (RSTC) User Reset Enable */
#define AT91C_RSTC_URSTIEN    ((unsigned int) 0x1 <<  4) /* (RSTC) User Reset Interrupt Enable */
#define AT91C_RSTC_ERSTL      ((unsigned int) 0xF <<  8) /* (RSTC) User Reset Enable */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Periodic Interval Timer Controller Interface */
/* ***************************************************************************** */
typedef struct _AT91S_PITC {
	AT91_REG	 PITC_PIMR; 	/* Period Interval Mode Register */
	AT91_REG	 PITC_PISR; 	/* Period Interval Status Register */
	AT91_REG	 PITC_PIVR; 	/* Period Interval Value Register */
	AT91_REG	 PITC_PIIR; 	/* Period Interval Image Register */
} AT91S_PITC, *AT91PS_PITC;

/* -------- PITC_PIMR : (PITC Offset: 0x0) Periodic Interval Mode Register --------  */
#define AT91C_PITC_PIV        ((unsigned int) 0xFFFFF <<  0) /* (PITC) Periodic Interval Value */
#define AT91C_PITC_PITEN      ((unsigned int) 0x1 << 24) /* (PITC) Periodic Interval Timer Enabled */
#define AT91C_PITC_PITIEN     ((unsigned int) 0x1 << 25) /* (PITC) Periodic Interval Timer Interrupt Enable */
/* -------- PITC_PISR : (PITC Offset: 0x4) Periodic Interval Status Register --------  */
#define AT91C_PITC_PITS       ((unsigned int) 0x1 <<  0) /* (PITC) Periodic Interval Timer Status */
/* -------- PITC_PIVR : (PITC Offset: 0x8) Periodic Interval Value Register --------  */
#define AT91C_PITC_CPIV       ((unsigned int) 0xFFFFF <<  0) /* (PITC) Current Periodic Interval Value */
#define AT91C_PITC_PICNT      ((unsigned int) 0xFFF << 20) /* (PITC) Periodic Interval Counter */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Usart */
/* ***************************************************************************** */
typedef struct _AT91S_USART {
	AT91_REG	 US_CR; 	/* Control Register */
	AT91_REG	 US_MR; 	/* Mode Register */
	AT91_REG	 US_IER; 	/* Interrupt Enable Register */
	AT91_REG	 US_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 US_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 US_CSR; 	/* Channel Status Register */
	AT91_REG	 US_RHR; 	/* Receiver Holding Register */
	AT91_REG	 US_THR; 	/* Transmitter Holding Register */
	AT91_REG	 US_BRGR; 	/* Baud Rate Generator Register */
	AT91_REG	 US_RTOR; 	/* Receiver Time-out Register */
	AT91_REG	 US_TTGR; 	/* Transmitter Time-guard Register */
	AT91_REG	 Reserved0[5];
	AT91_REG	 US_FIDI; 	/* FI_DI_Ratio Register */
	AT91_REG	 US_NER; 	/* Nb Errors Register */
	AT91_REG	 Reserved1[1];
	AT91_REG	 US_IF; 	/* IRDA_FILTER Register */
	AT91_REG	 Reserved2[44];
	AT91_REG	 US_RPR; 	/* Receive Pointer Register */
	AT91_REG	 US_RCR; 	/* Receive Counter Register */
	AT91_REG	 US_TPR; 	/* Transmit Pointer Register */
	AT91_REG	 US_TCR; 	/* Transmit Counter Register */
	AT91_REG	 US_RNPR; 	/* Receive Next Pointer Register */
	AT91_REG	 US_RNCR; 	/* Receive Next Counter Register */
	AT91_REG	 US_TNPR; 	/* Transmit Next Pointer Register */
	AT91_REG	 US_TNCR; 	/* Transmit Next Counter Register */
	AT91_REG	 US_PTCR; 	/* PDC Transfer Control Register */
	AT91_REG	 US_PTSR; 	/* PDC Transfer Status Register */
} AT91S_USART, *AT91PS_USART;

/* -------- US_CR : (USART Offset: 0x0) Debug Unit Control Register --------  */
#define AT91C_US_STTBRK       ((unsigned int) 0x1 <<  9) /* (USART) Start Break */
#define AT91C_US_STPBRK       ((unsigned int) 0x1 << 10) /* (USART) Stop Break */
#define AT91C_US_STTTO        ((unsigned int) 0x1 << 11) /* (USART) Start Time-out */
#define AT91C_US_SENDA        ((unsigned int) 0x1 << 12) /* (USART) Send Address */
#define AT91C_US_RSTIT        ((unsigned int) 0x1 << 13) /* (USART) Reset Iterations */
#define AT91C_US_RSTNACK      ((unsigned int) 0x1 << 14) /* (USART) Reset Non Acknowledge */
#define AT91C_US_RETTO        ((unsigned int) 0x1 << 15) /* (USART) Rearm Time-out */
#define AT91C_US_DTREN        ((unsigned int) 0x1 << 16) /* (USART) Data Terminal ready Enable */
#define AT91C_US_DTRDIS       ((unsigned int) 0x1 << 17) /* (USART) Data Terminal ready Disable */
#define AT91C_US_RTSEN        ((unsigned int) 0x1 << 18) /* (USART) Request to Send enable */
#define AT91C_US_RTSDIS       ((unsigned int) 0x1 << 19) /* (USART) Request to Send Disable */
/* -------- US_MR : (USART Offset: 0x4) Debug Unit Mode Register --------  */
#define AT91C_US_USMODE       ((unsigned int) 0xF <<  0) /* (USART) Usart mode */
#define 	AT91C_US_USMODE_NORMAL               ((unsigned int) 0x0) /* (USART) Normal */
#define 	AT91C_US_USMODE_RS485                ((unsigned int) 0x1) /* (USART) RS485 */
#define 	AT91C_US_USMODE_HWHSH                ((unsigned int) 0x2) /* (USART) Hardware Handshaking */
#define 	AT91C_US_USMODE_MODEM                ((unsigned int) 0x3) /* (USART) Modem */
#define 	AT91C_US_USMODE_ISO7816_0            ((unsigned int) 0x4) /* (USART) ISO7816 protocol: T = 0 */
#define 	AT91C_US_USMODE_ISO7816_1            ((unsigned int) 0x6) /* (USART) ISO7816 protocol: T = 1 */
#define 	AT91C_US_USMODE_IRDA                 ((unsigned int) 0x8) /* (USART) IrDA */
#define 	AT91C_US_USMODE_SWHSH                ((unsigned int) 0xC) /* (USART) Software Handshaking */
#define AT91C_US_CLKS         ((unsigned int) 0x3 <<  4) /* (USART) Clock Selection (Baud Rate generator Input Clock */
#define 	AT91C_US_CLKS_CLOCK                ((unsigned int) 0x0 <<  4) /* (USART) Clock */
#define 	AT91C_US_CLKS_FDIV1                ((unsigned int) 0x1 <<  4) /* (USART) fdiv1 */
#define 	AT91C_US_CLKS_SLOW                 ((unsigned int) 0x2 <<  4) /* (USART) slow_clock (ARM) */
#define 	AT91C_US_CLKS_EXT                  ((unsigned int) 0x3 <<  4) /* (USART) External (SCK) */
#define AT91C_US_CHRL         ((unsigned int) 0x3 <<  6) /* (USART) Clock Selection (Baud Rate generator Input Clock */
#define 	AT91C_US_CHRL_5_BITS               ((unsigned int) 0x0 <<  6) /* (USART) Character Length: 5 bits */
#define 	AT91C_US_CHRL_6_BITS               ((unsigned int) 0x1 <<  6) /* (USART) Character Length: 6 bits */
#define 	AT91C_US_CHRL_7_BITS               ((unsigned int) 0x2 <<  6) /* (USART) Character Length: 7 bits */
#define 	AT91C_US_CHRL_8_BITS               ((unsigned int) 0x3 <<  6) /* (USART) Character Length: 8 bits */
#define AT91C_US_SYNC         ((unsigned int) 0x1 <<  8) /* (USART) Synchronous Mode Select */
#define AT91C_US_NBSTOP       ((unsigned int) 0x3 << 12) /* (USART) Number of Stop bits */
#define 	AT91C_US_NBSTOP_1_BIT                ((unsigned int) 0x0 << 12) /* (USART) 1 stop bit */
#define 	AT91C_US_NBSTOP_15_BIT               ((unsigned int) 0x1 << 12) /* (USART) Asynchronous (SYNC=0) 2 stop bits Synchronous (SYNC=1) 2 stop bits */
#define 	AT91C_US_NBSTOP_2_BIT                ((unsigned int) 0x2 << 12) /* (USART) 2 stop bits */
#define AT91C_US_MSBF         ((unsigned int) 0x1 << 16) /* (USART) Bit Order */
#define AT91C_US_MODE9        ((unsigned int) 0x1 << 17) /* (USART) 9-bit Character length */
#define AT91C_US_CKLO         ((unsigned int) 0x1 << 18) /* (USART) Clock Output Select */
#define AT91C_US_OVER         ((unsigned int) 0x1 << 19) /* (USART) Over Sampling Mode */
#define AT91C_US_INACK        ((unsigned int) 0x1 << 20) /* (USART) Inhibit Non Acknowledge */
#define AT91C_US_DSNACK       ((unsigned int) 0x1 << 21) /* (USART) Disable Successive NACK */
#define AT91C_US_MAX_ITER     ((unsigned int) 0x1 << 24) /* (USART) Number of Repetitions */
#define AT91C_US_FILTER       ((unsigned int) 0x1 << 28) /* (USART) Receive Line Filter */
/* -------- US_IER : (USART Offset: 0x8) Debug Unit Interrupt Enable Register --------  */
#define AT91C_US_RXBRK        ((unsigned int) 0x1 <<  2) /* (USART) Break Received/End of Break */
#define AT91C_US_TIMEOUT      ((unsigned int) 0x1 <<  8) /* (USART) Receiver Time-out */
#define AT91C_US_ITERATION    ((unsigned int) 0x1 << 10) /* (USART) Max number of Repetitions Reached */
#define AT91C_US_NACK         ((unsigned int) 0x1 << 13) /* (USART) Non Acknowledge */
#define AT91C_US_RIIC         ((unsigned int) 0x1 << 16) /* (USART) Ring INdicator Input Change Flag */
#define AT91C_US_DSRIC        ((unsigned int) 0x1 << 17) /* (USART) Data Set Ready Input Change Flag */
#define AT91C_US_DCDIC        ((unsigned int) 0x1 << 18) /* (USART) Data Carrier Flag */
#define AT91C_US_CTSIC        ((unsigned int) 0x1 << 19) /* (USART) Clear To Send Input Change Flag */
/* -------- US_IDR : (USART Offset: 0xc) Debug Unit Interrupt Disable Register --------  */
/* -------- US_IMR : (USART Offset: 0x10) Debug Unit Interrupt Mask Register --------  */
/* -------- US_CSR : (USART Offset: 0x14) Debug Unit Channel Status Register --------  */
#define AT91C_US_RI           ((unsigned int) 0x1 << 20) /* (USART) Image of RI Input */
#define AT91C_US_DSR          ((unsigned int) 0x1 << 21) /* (USART) Image of DSR Input */
#define AT91C_US_DCD          ((unsigned int) 0x1 << 22) /* (USART) Image of DCD Input */
#define AT91C_US_CTS          ((unsigned int) 0x1 << 23) /* (USART) Image of CTS Input */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR Serial Parallel Interface */
/* ***************************************************************************** */
typedef struct _AT91S_SPI {
	AT91_REG	 SPI_CR; 	/* Control Register */
	AT91_REG	 SPI_MR; 	/* Mode Register */
	AT91_REG	 SPI_RDR; 	/* Receive Data Register */
	AT91_REG	 SPI_TDR; 	/* Transmit Data Register */
	AT91_REG	 SPI_SR; 	/* Status Register */
	AT91_REG	 SPI_IER; 	/* Interrupt Enable Register */
	AT91_REG	 SPI_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 SPI_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 Reserved0[4];
	AT91_REG	 SPI_CSR[4]; 	/* Chip Select Register */
	AT91_REG	 Reserved1[48];
	AT91_REG	 SPI_RPR; 	/* Receive Pointer Register */
	AT91_REG	 SPI_RCR; 	/* Receive Counter Register */
	AT91_REG	 SPI_TPR; 	/* Transmit Pointer Register */
	AT91_REG	 SPI_TCR; 	/* Transmit Counter Register */
	AT91_REG	 SPI_RNPR; 	/* Receive Next Pointer Register */
	AT91_REG	 SPI_RNCR; 	/* Receive Next Counter Register */
	AT91_REG	 SPI_TNPR; 	/* Transmit Next Pointer Register */
	AT91_REG	 SPI_TNCR; 	/* Transmit Next Counter Register */
	AT91_REG	 SPI_PTCR; 	/* PDC Transfer Control Register */
	AT91_REG	 SPI_PTSR; 	/* PDC Transfer Status Register */
} AT91S_SPI, *AT91PS_SPI;

/* -------- SPI_CR : (SPI Offset: 0x0) SPI Control Register --------  */
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) /* (SPI) SPI Enable */
#define AT91C_SPI_SPIDIS      ((unsigned int) 0x1 <<  1) /* (SPI) SPI Disable */
#define AT91C_SPI_SWRST       ((unsigned int) 0x1 <<  7) /* (SPI) SPI Software reset */
#define AT91C_SPI_LASTXFER    ((unsigned int) 0x1 << 24) /* (SPI) SPI Last Transfer */
/* -------- SPI_MR : (SPI Offset: 0x4) SPI Mode Register --------  */
#define AT91C_SPI_MSTR        ((unsigned int) 0x1 <<  0) /* (SPI) Master/Slave Mode */
#define AT91C_SPI_PS          ((unsigned int) 0x1 <<  1) /* (SPI) Peripheral Select */
#define 	AT91C_SPI_PS_FIXED                ((unsigned int) 0x0 <<  1) /* (SPI) Fixed Peripheral Select */
#define 	AT91C_SPI_PS_VARIABLE             ((unsigned int) 0x1 <<  1) /* (SPI) Variable Peripheral Select */
#define AT91C_SPI_PCSDEC      ((unsigned int) 0x1 <<  2) /* (SPI) Chip Select Decode */
#define AT91C_SPI_FDIV        ((unsigned int) 0x1 <<  3) /* (SPI) Clock Selection */
#define AT91C_SPI_MODFDIS     ((unsigned int) 0x1 <<  4) /* (SPI) Mode Fault Detection */
#define AT91C_SPI_LLB         ((unsigned int) 0x1 <<  7) /* (SPI) Clock Selection */
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) /* (SPI) Peripheral Chip Select */
#define AT91C_SPI_DLYBCS      ((unsigned int) 0xFF << 24) /* (SPI) Delay Between Chip Selects */
/* -------- SPI_RDR : (SPI Offset: 0x8) Receive Data Register --------  */
#define AT91C_SPI_RD          ((unsigned int) 0xFFFF <<  0) /* (SPI) Receive Data */
#define AT91C_SPI_RPCS        ((unsigned int) 0xF << 16) /* (SPI) Peripheral Chip Select Status */
/* -------- SPI_TDR : (SPI Offset: 0xc) Transmit Data Register --------  */
#define AT91C_SPI_TD          ((unsigned int) 0xFFFF <<  0) /* (SPI) Transmit Data */
#define AT91C_SPI_TPCS        ((unsigned int) 0xF << 16) /* (SPI) Peripheral Chip Select Status */
/* -------- SPI_SR : (SPI Offset: 0x10) Status Register --------  */
#define AT91C_SPI_RDRF        ((unsigned int) 0x1 <<  0) /* (SPI) Receive Data Register Full */
#define AT91C_SPI_TDRE        ((unsigned int) 0x1 <<  1) /* (SPI) Transmit Data Register Empty */
#define AT91C_SPI_MODF        ((unsigned int) 0x1 <<  2) /* (SPI) Mode Fault Error */
#define AT91C_SPI_OVRES       ((unsigned int) 0x1 <<  3) /* (SPI) Overrun Error Status */
#define AT91C_SPI_ENDRX       ((unsigned int) 0x1 <<  4) /* (SPI) End of Receiver Transfer */
#define AT91C_SPI_ENDTX       ((unsigned int) 0x1 <<  5) /* (SPI) End of Receiver Transfer */
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) /* (SPI) RXBUFF Interrupt */
#define AT91C_SPI_TXBUFE      ((unsigned int) 0x1 <<  7) /* (SPI) TXBUFE Interrupt */
#define AT91C_SPI_NSSR        ((unsigned int) 0x1 <<  8) /* (SPI) NSSR Interrupt */
#define AT91C_SPI_TXEMPTY     ((unsigned int) 0x1 <<  9) /* (SPI) TXEMPTY Interrupt */
#define AT91C_SPI_SPIENS      ((unsigned int) 0x1 << 16) /* (SPI) Enable Status */
/* -------- SPI_CSR : (SPI Offset: 0x30) Chip Select Register --------  */
#define AT91C_SPI_CPOL        ((unsigned int) 0x1 <<  0) /* (SPI) Clock Polarity */
#define AT91C_SPI_NCPHA       ((unsigned int) 0x1 <<  1) /* (SPI) Clock Phase */
#define AT91C_SPI_CSAAT       ((unsigned int) 0x1 <<  2) /* (SPI) Chip Select Active After Transfer */
#define AT91C_SPI_BITS        ((unsigned int) 0xF <<  4) /* (SPI) Bits Per Transfer */
#define 	AT91C_SPI_BITS_8                    ((unsigned int) 0x0 <<  4) /* (SPI) 8 Bits Per transfer */
#define 	AT91C_SPI_BITS_9                    ((unsigned int) 0x1 <<  4) /* (SPI) 9 Bits Per transfer */
#define 	AT91C_SPI_BITS_10                   ((unsigned int) 0x2 <<  4) /* (SPI) 10 Bits Per transfer */
#define 	AT91C_SPI_BITS_11                   ((unsigned int) 0x3 <<  4) /* (SPI) 11 Bits Per transfer */
#define 	AT91C_SPI_BITS_12                   ((unsigned int) 0x4 <<  4) /* (SPI) 12 Bits Per transfer */
#define 	AT91C_SPI_BITS_13                   ((unsigned int) 0x5 <<  4) /* (SPI) 13 Bits Per transfer */
#define 	AT91C_SPI_BITS_14                   ((unsigned int) 0x6 <<  4) /* (SPI) 14 Bits Per transfer */
#define 	AT91C_SPI_BITS_15                   ((unsigned int) 0x7 <<  4) /* (SPI) 15 Bits Per transfer */
#define 	AT91C_SPI_BITS_16                   ((unsigned int) 0x8 <<  4) /* (SPI) 16 Bits Per transfer */
#define AT91C_SPI_SCBR        ((unsigned int) 0xFF <<  8) /* (SPI) Serial Clock Baud Rate */
#define AT91C_SPI_DLYBS       ((unsigned int) 0xFF << 16) /* (SPI) Serial Clock Baud Rate */
#define AT91C_SPI_DLYBCT      ((unsigned int) 0xFF << 24) /* (SPI) Delay Between Consecutive Transfers */

/* ***************************************************************************** */
/*              SOFTWARE API DEFINITION  FOR LCD Controller */
/* ***************************************************************************** */
typedef struct _AT91S_LCDC {
	AT91_REG	 LCDC_BA1; 	/* DMA Base Address Register 1 */
	AT91_REG	 LCDC_BA2; 	/* DMA Base Address Register 2 */
	AT91_REG	 LCDC_FRMP1; 	/* DMA Frame Pointer Register 1 */
	AT91_REG	 LCDC_FRMP2; 	/* DMA Frame Pointer Register 2 */
	AT91_REG	 LCDC_FRMA1; 	/* DMA Frame Address Register 1 */
	AT91_REG	 LCDC_FRMA2; 	/* DMA Frame Address Register 2 */
	AT91_REG	 LCDC_FRMCFG; 	/* DMA Frame Configuration Register */
	AT91_REG	 LCDC_DMACON; 	/* DMA Control Register */
	AT91_REG	 LCDC_DMA2DCFG; 	/* DMA 2D addressing configuration */
	AT91_REG	 Reserved0[503];
	AT91_REG	 LCDC_LCDCON1; 	/* LCD Control 1 Register */
	AT91_REG	 LCDC_LCDCON2; 	/* LCD Control 2 Register */
	AT91_REG	 LCDC_TIM1; 	/* LCD Timing Config 1 Register */
	AT91_REG	 LCDC_TIM2; 	/* LCD Timing Config 2 Register */
	AT91_REG	 LCDC_LCDFRCFG; 	/* LCD Frame Config Register */
	AT91_REG	 LCDC_FIFO; 	/* LCD FIFO Register */
	AT91_REG	 LCDC_MVAL; 	/* LCD Mode Toggle Rate Value Register */
	AT91_REG	 LCDC_DP1_2; 	/* Dithering Pattern DP1_2 Register */
	AT91_REG	 LCDC_DP4_7; 	/* Dithering Pattern DP4_7 Register */
	AT91_REG	 LCDC_DP3_5; 	/* Dithering Pattern DP3_5 Register */
	AT91_REG	 LCDC_DP2_3; 	/* Dithering Pattern DP2_3 Register */
	AT91_REG	 LCDC_DP5_7; 	/* Dithering Pattern DP5_7 Register */
	AT91_REG	 LCDC_DP3_4; 	/* Dithering Pattern DP3_4 Register */
	AT91_REG	 LCDC_DP4_5; 	/* Dithering Pattern DP4_5 Register */
	AT91_REG	 LCDC_DP6_7; 	/* Dithering Pattern DP6_7 Register */
	AT91_REG	 LCDC_PWRCON; 	/* Power Control Register */
	AT91_REG	 LCDC_CTRSTCON; 	/* Contrast Control Register */
	AT91_REG	 LCDC_CTRSTVAL; 	/* Contrast Value Register */
	AT91_REG	 LCDC_IER; 	/* Interrupt Enable Register */
	AT91_REG	 LCDC_IDR; 	/* Interrupt Disable Register */
	AT91_REG	 LCDC_IMR; 	/* Interrupt Mask Register */
	AT91_REG	 LCDC_ISR; 	/* Interrupt Enable Register */
	AT91_REG	 LCDC_ICR; 	/* Interrupt Clear Register */
	AT91_REG	 LCDC_GPR; 	/* General Purpose Register */
	AT91_REG	 LCDC_ITR; 	/* Interrupts Test Register */
	AT91_REG	 LCDC_IRR; 	/* Interrupts Raw Status Register */
	AT91_REG	 Reserved1[230];
	AT91_REG	 LCDC_LUT_ENTRY[256]; 	/* LUT Entries Register */
} AT91S_LCDC, *AT91PS_LCDC;

/* -------- LCDC_FRMP1 : (LCDC Offset: 0x8) DMA Frame Pointer 1 Register --------  */
#define AT91C_LCDC_FRMPT1     ((unsigned int) 0x3FFFFF <<  0) /* (LCDC) Frame Pointer Address 1 */
/* -------- LCDC_FRMP2 : (LCDC Offset: 0xc) DMA Frame Pointer 2 Register --------  */
#define AT91C_LCDC_FRMPT2     ((unsigned int) 0x1FFFFF <<  0) /* (LCDC) Frame Pointer Address 2 */
/* -------- LCDC_FRMCFG : (LCDC Offset: 0x18) DMA Frame Config Register --------  */
#define AT91C_LCDC_FRSIZE     ((unsigned int) 0x3FFFFF <<  0) /* (LCDC) FRAME SIZE */
#define AT91C_LCDC_BLENGTH    ((unsigned int) 0xF << 24) /* (LCDC) BURST LENGTH */
/* -------- LCDC_DMACON : (LCDC Offset: 0x1c) DMA Control Register --------  */
#define AT91C_LCDC_DMAEN      ((unsigned int) 0x1 <<  0) /* (LCDC) DAM Enable */
#define AT91C_LCDC_DMARST     ((unsigned int) 0x1 <<  1) /* (LCDC) DMA Reset (WO) */
#define AT91C_LCDC_DMABUSY    ((unsigned int) 0x1 <<  2) /* (LCDC) DMA Reset (WO) */
/* -------- LCDC_DMA2DCFG : (LCDC Offset: 0x20) DMA 2D addressing configuration Register --------  */
#define AT91C_LCDC_ADDRINC    ((unsigned int) 0xFFFF <<  0) /* (LCDC) Number of 32b words that the DMA must jump when going to the next line */
#define AT91C_LCDC_PIXELOFF   ((unsigned int) 0x1F << 24) /* (LCDC) Offset (in bits) of the first pixel of the screen in the memory word which contain it */
/* -------- LCDC_LCDCON1 : (LCDC Offset: 0x800) LCD Control 1 Register --------  */
#define AT91C_LCDC_BYPASS     ((unsigned int) 0x1 <<  0) /* (LCDC) Bypass lcd_pccklk divider */
#define AT91C_LCDC_CLKVAL     ((unsigned int) 0x1FF << 12) /* (LCDC) 9-bit Divider for pixel clock frequency */
#define AT91C_LCDC_LINCNT     ((unsigned int) 0x7FF << 21) /* (LCDC) Line Counter (RO) */
/* -------- LCDC_LCDCON2 : (LCDC Offset: 0x804) LCD Control 2 Register --------  */
#define AT91C_LCDC_DISTYPE    ((unsigned int) 0x3 <<  0) /* (LCDC) Display Type */
#define 	AT91C_LCDC_DISTYPE_STNMONO              ((unsigned int) 0x0) /* (LCDC) STN Mono */
#define 	AT91C_LCDC_DISTYPE_STNCOLOR             ((unsigned int) 0x1) /* (LCDC) STN Color */
#define 	AT91C_LCDC_DISTYPE_TFT                  ((unsigned int) 0x2) /* (LCDC) TFT */
#define AT91C_LCDC_SCANMOD    ((unsigned int) 0x1 <<  2) /* (LCDC) Scan Mode */
#define 	AT91C_LCDC_SCANMOD_SINGLESCAN           ((unsigned int) 0x0 <<  2) /* (LCDC) Single Scan */
#define 	AT91C_LCDC_SCANMOD_DUALSCAN             ((unsigned int) 0x1 <<  2) /* (LCDC) Dual Scan */
#define AT91C_LCDC_IFWIDTH    ((unsigned int) 0x3 <<  3) /* (LCDC) Interface Width */
#define 	AT91C_LCDC_IFWIDTH_FOURBITSWIDTH        ((unsigned int) 0x0 <<  3) /* (LCDC) 4 Bits */
#define 	AT91C_LCDC_IFWIDTH_EIGTHBITSWIDTH       ((unsigned int) 0x1 <<  3) /* (LCDC) 8 Bits */
#define 	AT91C_LCDC_IFWIDTH_SIXTEENBITSWIDTH     ((unsigned int) 0x2 <<  3) /* (LCDC) 16 Bits */
#define AT91C_LCDC_PIXELSIZE  ((unsigned int) 0x7 <<  5) /* (LCDC) Bits per pixel */
#define 	AT91C_LCDC_PIXELSIZE_ONEBITSPERPIXEL      ((unsigned int) 0x0 <<  5) /* (LCDC) 1 Bits */
#define 	AT91C_LCDC_PIXELSIZE_TWOBITSPERPIXEL      ((unsigned int) 0x1 <<  5) /* (LCDC) 2 Bits */
#define 	AT91C_LCDC_PIXELSIZE_FOURBITSPERPIXEL     ((unsigned int) 0x2 <<  5) /* (LCDC) 4 Bits */
#define 	AT91C_LCDC_PIXELSIZE_EIGTHBITSPERPIXEL    ((unsigned int) 0x3 <<  5) /* (LCDC) 8 Bits */
#define 	AT91C_LCDC_PIXELSIZE_SIXTEENBITSPERPIXEL  ((unsigned int) 0x4 <<  5) /* (LCDC) 16 Bits */
#define 	AT91C_LCDC_PIXELSIZE_TWENTYFOURBITSPERPIXEL ((unsigned int) 0x5 <<  5) /* (LCDC) 24 Bits */
#define AT91C_LCDC_INVVD      ((unsigned int) 0x1 <<  8) /* (LCDC) lcd datas polarity */
#define 	AT91C_LCDC_INVVD_NORMALPOL            ((unsigned int) 0x0 <<  8) /* (LCDC) Normal Polarity */
#define 	AT91C_LCDC_INVVD_INVERTEDPOL          ((unsigned int) 0x1 <<  8) /* (LCDC) Inverted Polarity */
#define AT91C_LCDC_INVFRAME   ((unsigned int) 0x1 <<  9) /* (LCDC) lcd vsync polarity */
#define 	AT91C_LCDC_INVFRAME_NORMALPOL            ((unsigned int) 0x0 <<  9) /* (LCDC) Normal Polarity */
#define 	AT91C_LCDC_INVFRAME_INVERTEDPOL          ((unsigned int) 0x1 <<  9) /* (LCDC) Inverted Polarity */
#define AT91C_LCDC_INVLINE    ((unsigned int) 0x1 << 10) /* (LCDC) lcd hsync polarity */
#define 	AT91C_LCDC_INVLINE_NORMALPOL            ((unsigned int) 0x0 << 10) /* (LCDC) Normal Polarity */
#define 	AT91C_LCDC_INVLINE_INVERTEDPOL          ((unsigned int) 0x1 << 10) /* (LCDC) Inverted Polarity */
#define AT91C_LCDC_INVCLK     ((unsigned int) 0x1 << 11) /* (LCDC) lcd pclk polarity */
#define 	AT91C_LCDC_INVCLK_NORMALPOL            ((unsigned int) 0x0 << 11) /* (LCDC) Normal Polarity */
#define 	AT91C_LCDC_INVCLK_INVERTEDPOL          ((unsigned int) 0x1 << 11) /* (LCDC) Inverted Polarity */
#define AT91C_LCDC_INVDVAL    ((unsigned int) 0x1 << 12) /* (LCDC) lcd dval polarity */
#define 	AT91C_LCDC_INVDVAL_NORMALPOL            ((unsigned int) 0x0 << 12) /* (LCDC) Normal Polarity */
#define 	AT91C_LCDC_INVDVAL_INVERTEDPOL          ((unsigned int) 0x1 << 12) /* (LCDC) Inverted Polarity */
#define AT91C_LCDC_CLKMOD     ((unsigned int) 0x1 << 15) /* (LCDC) lcd pclk Mode */
#define 	AT91C_LCDC_CLKMOD_ACTIVEONLYDISP       ((unsigned int) 0x0 << 15) /* (LCDC) Active during display period */
#define 	AT91C_LCDC_CLKMOD_ALWAYSACTIVE         ((unsigned int) 0x1 << 15) /* (LCDC) Always Active */
#define AT91C_LCDC_MEMOR      ((unsigned int) 0x1 << 31) /* (LCDC) lcd pclk Mode */
#define 	AT91C_LCDC_MEMOR_BIGIND               ((unsigned int) 0x0 << 31) /* (LCDC) Big Endian */
#define 	AT91C_LCDC_MEMOR_LITTLEIND            ((unsigned int) 0x1 << 31) /* (LCDC) Little Endian */
/* -------- LCDC_TIM1 : (LCDC Offset: 0x808) LCDC Timing Config 1 Register --------  */
#define AT91C_LCDC_VFP        ((unsigned int) 0xFF <<  0) /* (LCDC) Vertical Front Porch */
#define AT91C_LCDC_VBP        ((unsigned int) 0xFF <<  8) /* (LCDC) Vertical Back Porch */
#define AT91C_LCDC_VPW        ((unsigned int) 0x3F << 16) /* (LCDC) Vertical Synchronization Pulse Width */
#define AT91C_LCDC_VHDLY      ((unsigned int) 0xF << 24) /* (LCDC) Vertical to Horizontal Delay */
/* -------- LCDC_TIM2 : (LCDC Offset: 0x80c) LCDC Timing Config 2 Register --------  */
#define AT91C_LCDC_HBP        ((unsigned int) 0xFF <<  0) /* (LCDC) Horizontal Back Porch */
#define AT91C_LCDC_HPW        ((unsigned int) 0x3F <<  8) /* (LCDC) Horizontal Synchronization Pulse Width */
#define AT91C_LCDC_HFP        ((unsigned int) 0x3FF << 22) /* (LCDC) Horizontal Front Porch */
/* -------- LCDC_LCDFRCFG : (LCDC Offset: 0x810) LCD Frame Config Register --------  */
#define AT91C_LCDC_LINEVAL    ((unsigned int) 0x7FF <<  0) /* (LCDC) Vertical Size of LCD Module */
#define AT91C_LCDC_HOZVAL     ((unsigned int) 0x7FF << 21) /* (LCDC) Horizontal Size of LCD Module */
/* -------- LCDC_FIFO : (LCDC Offset: 0x814) LCD FIFO Register --------  */
#define AT91C_LCDC_FIFOTH     ((unsigned int) 0xFFFF <<  0) /* (LCDC) FIFO Threshold */
/* -------- LCDC_MVAL : (LCDC Offset: 0x818) LCD Mode Toggle Rate Value Register --------  */
#define AT91C_LCDC_MVALUE     ((unsigned int) 0xFF <<  0) /* (LCDC) Toggle Rate Value */
#define AT91C_LCDC_MMODE      ((unsigned int) 0x1 << 31) /* (LCDC) Toggle Rate Sel */
#define 	AT91C_LCDC_MMODE_EACHFRAME            ((unsigned int) 0x0 << 31) /* (LCDC) Each Frame */
#define 	AT91C_LCDC_MMODE_MVALDEFINED          ((unsigned int) 0x1 << 31) /* (LCDC) Defined by MVAL */
/* -------- LCDC_DP1_2 : (LCDC Offset: 0x81c) Dithering Pattern 1/2 --------  */
#define AT91C_LCDC_DP1_2_FIELD ((unsigned int) 0xFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP4_7 : (LCDC Offset: 0x820) Dithering Pattern 4/7 --------  */
#define AT91C_LCDC_DP4_7_FIELD ((unsigned int) 0xFFFFFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP3_5 : (LCDC Offset: 0x824) Dithering Pattern 3/5 --------  */
#define AT91C_LCDC_DP3_5_FIELD ((unsigned int) 0xFFFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP2_3 : (LCDC Offset: 0x828) Dithering Pattern 2/3 --------  */
#define AT91C_LCDC_DP2_3_FIELD ((unsigned int) 0xFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP5_7 : (LCDC Offset: 0x82c) Dithering Pattern 5/7 --------  */
#define AT91C_LCDC_DP5_7_FIELD ((unsigned int) 0xFFFFFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP3_4 : (LCDC Offset: 0x830) Dithering Pattern 3/4 --------  */
#define AT91C_LCDC_DP3_4_FIELD ((unsigned int) 0xFFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP4_5 : (LCDC Offset: 0x834) Dithering Pattern 4/5 --------  */
#define AT91C_LCDC_DP4_5_FIELD ((unsigned int) 0xFFFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_DP6_7 : (LCDC Offset: 0x838) Dithering Pattern 6/7 --------  */
#define AT91C_LCDC_DP6_7_FIELD ((unsigned int) 0xFFFFFFF <<  0) /* (LCDC) Ratio */
/* -------- LCDC_PWRCON : (LCDC Offset: 0x83c) LCDC Power Control Register --------  */
#define AT91C_LCDC_PWR        ((unsigned int) 0x1 <<  0) /* (LCDC) LCD Module Power Control */
#define AT91C_LCDC_GUARDT     ((unsigned int) 0x7F <<  1) /* (LCDC) Delay in Frame Period */
#define AT91C_LCDC_BUSY       ((unsigned int) 0x1 << 31) /* (LCDC) Read Only : 1 indicates that LCDC is busy */
#define 	AT91C_LCDC_BUSY_LCDNOTBUSY           ((unsigned int) 0x0 << 31) /* (LCDC) LCD is Not Busy */
#define 	AT91C_LCDC_BUSY_LCDBUSY              ((unsigned int) 0x1 << 31) /* (LCDC) LCD is Busy */
/* -------- LCDC_CTRSTCON : (LCDC Offset: 0x840) LCDC Contrast Control Register --------  */
#define AT91C_LCDC_PS         ((unsigned int) 0x3 <<  0) /* (LCDC) LCD Contrast Counter Prescaler */
#define 	AT91C_LCDC_PS_NOTDIVIDED           ((unsigned int) 0x0) /* (LCDC) Counter Freq is System Freq. */
#define 	AT91C_LCDC_PS_DIVIDEDBYTWO         ((unsigned int) 0x1) /* (LCDC) Counter Freq is System Freq divided by 2. */
#define 	AT91C_LCDC_PS_DIVIDEDBYFOUR        ((unsigned int) 0x2) /* (LCDC) Counter Freq is System Freq divided by 4. */
#define 	AT91C_LCDC_PS_DIVIDEDBYEIGHT       ((unsigned int) 0x3) /* (LCDC) Counter Freq is System Freq divided by 8. */
#define AT91C_LCDC_POL        ((unsigned int) 0x1 <<  2) /* (LCDC) Polarity of output Pulse */
#define 	AT91C_LCDC_POL_NEGATIVEPULSE        ((unsigned int) 0x0 <<  2) /* (LCDC) Negative Pulse */
#define 	AT91C_LCDC_POL_POSITIVEPULSE        ((unsigned int) 0x1 <<  2) /* (LCDC) Positive Pulse */
#define AT91C_LCDC_ENA        ((unsigned int) 0x1 <<  3) /* (LCDC) PWM generator Control */
#define 	AT91C_LCDC_ENA_PWMGEMDISABLED       ((unsigned int) 0x0 <<  3) /* (LCDC) PWM Generator Disabled */
#define 	AT91C_LCDC_ENA_PWMGEMENABLED        ((unsigned int) 0x1 <<  3) /* (LCDC) PWM Generator Disabled */
/* -------- LCDC_CTRSTVAL : (LCDC Offset: 0x844) Contrast Value Register --------  */
#define AT91C_LCDC_CVAL       ((unsigned int) 0xFF <<  0) /* (LCDC) PWM Compare Value */
/* -------- LCDC_IER : (LCDC Offset: 0x848) LCDC Interrupt Enable Register --------  */
#define AT91C_LCDC_LNI        ((unsigned int) 0x1 <<  0) /* (LCDC) Line Interrupt */
#define AT91C_LCDC_LSTLNI     ((unsigned int) 0x1 <<  1) /* (LCDC) Last Line Interrupt */
#define AT91C_LCDC_EOFI       ((unsigned int) 0x1 <<  2) /* (LCDC) End Of Frame Interrupt */
#define AT91C_LCDC_UFLWI      ((unsigned int) 0x1 <<  4) /* (LCDC) FIFO Underflow Interrupt */
#define AT91C_LCDC_OWRI       ((unsigned int) 0x1 <<  5) /* (LCDC) Over Write Interrupt */
#define AT91C_LCDC_MERI       ((unsigned int) 0x1 <<  6) /* (LCDC) Memory Error  Interrupt */
/* -------- LCDC_GPR : (LCDC Offset: 0x85c) LCDC General Purpose Register --------  */
#define AT91C_LCDC_GPRBUS     ((unsigned int) 0xFF <<  0) /* (LCDC) 8 bits available */


// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Two-wire Interface
// *****************************************************************************
typedef struct _AT91S_TWI {
	AT91_REG	 TWI_CR; 	// Control Register
	AT91_REG	 TWI_MMR; 	// Master Mode Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 TWI_IADR; 	// Internal Address Register
	AT91_REG	 TWI_CWGR; 	// Clock Waveform Generator Register
	AT91_REG	 Reserved1[3]; 	// 
	AT91_REG	 TWI_SR; 	// Status Register
	AT91_REG	 TWI_IER; 	// Interrupt Enable Register
	AT91_REG	 TWI_IDR; 	// Interrupt Disable Register
	AT91_REG	 TWI_IMR; 	// Interrupt Mask Register
	AT91_REG	 TWI_RHR; 	// Receive Holding Register
	AT91_REG	 TWI_THR; 	// Transmit Holding Register
} AT91S_TWI, *AT91PS_TWI;

// -------- TWI_CR : (TWI Offset: 0x0) TWI Control Register -------- 
#define AT91C_TWI_START       ((unsigned int) 0x1 <<  0) // (TWI) Send a START Condition
#define AT91C_TWI_STOP        ((unsigned int) 0x1 <<  1) // (TWI) Send a STOP Condition
#define AT91C_TWI_MSEN        ((unsigned int) 0x1 <<  2) // (TWI) TWI Master Transfer Enabled
#define AT91C_TWI_MSDIS       ((unsigned int) 0x1 <<  3) // (TWI) TWI Master Transfer Disabled
#define AT91C_TWI_SWRST       ((unsigned int) 0x1 <<  7) // (TWI) Software Reset
// -------- TWI_MMR : (TWI Offset: 0x4) TWI Master Mode Register -------- 
#define AT91C_TWI_IADRSZ      ((unsigned int) 0x3 <<  8) // (TWI) Internal Device Address Size
#define 	AT91C_TWI_IADRSZ_NO                   ((unsigned int) 0x0 <<  8) // (TWI) No internal device address
#define 	AT91C_TWI_IADRSZ_1_BYTE               ((unsigned int) 0x1 <<  8) // (TWI) One-byte internal device address
#define 	AT91C_TWI_IADRSZ_2_BYTE               ((unsigned int) 0x2 <<  8) // (TWI) Two-byte internal device address
#define 	AT91C_TWI_IADRSZ_3_BYTE               ((unsigned int) 0x3 <<  8) // (TWI) Three-byte internal device address
#define AT91C_TWI_MREAD       ((unsigned int) 0x1 << 12) // (TWI) Master Read Direction
#define AT91C_TWI_DADR        ((unsigned int) 0x7F << 16) // (TWI) Device Address
// -------- TWI_CWGR : (TWI Offset: 0x10) TWI Clock Waveform Generator Register -------- 
#define AT91C_TWI_CLDIV       ((unsigned int) 0xFF <<  0) // (TWI) Clock Low Divider
#define AT91C_TWI_CHDIV       ((unsigned int) 0xFF <<  8) // (TWI) Clock High Divider
#define AT91C_TWI_CKDIV       ((unsigned int) 0x7 << 16) // (TWI) Clock Divider
// -------- TWI_SR : (TWI Offset: 0x20) TWI Status Register -------- 
#define AT91C_TWI_TXCOMP      ((unsigned int) 0x1 <<  0) // (TWI) Transmission Completed
#define AT91C_TWI_RXRDY       ((unsigned int) 0x1 <<  1) // (TWI) Receive holding register ReaDY
#define AT91C_TWI_TXRDY       ((unsigned int) 0x1 <<  2) // (TWI) Transmit holding register ReaDY
#define AT91C_TWI_OVRE        ((unsigned int) 0x1 <<  6) // (TWI) Overrun Error
#define AT91C_TWI_UNRE        ((unsigned int) 0x1 <<  7) // (TWI) Underrun Error
#define AT91C_TWI_NACK        ((unsigned int) 0x1 <<  8) // (TWI) Not Acknowledged
// -------- TWI_IER : (TWI Offset: 0x24) TWI Interrupt Enable Register -------- 
// -------- TWI_IDR : (TWI Offset: 0x28) TWI Interrupt Disable Register -------- 
// -------- TWI_IMR : (TWI Offset: 0x2c) TWI Interrupt Mask Register -------- 

/* ***************************************************************************** */
/*               REGISTER ADDRESS DEFINITION FOR AT91SAM9261 */
/* ***************************************************************************** */
/* ========== Register definition for SMC peripheral ==========  */
#define AT91C_SMC_CTRL1 ((AT91_REG *) 	0xFFFFEC1C) /* (SMC)  Control Register for CS 1 */
#define AT91C_SMC_PULSE7 ((AT91_REG *) 	0xFFFFEC74) /* (SMC)  Pulse Register for CS 7 */
#define AT91C_SMC_PULSE6 ((AT91_REG *) 	0xFFFFEC64) /* (SMC)  Pulse Register for CS 6 */
#define AT91C_SMC_SETUP4 ((AT91_REG *) 	0xFFFFEC40) /* (SMC)  Setup Register for CS 4 */
#define AT91C_SMC_PULSE3 ((AT91_REG *) 	0xFFFFEC34) /* (SMC)  Pulse Register for CS 3 */
#define AT91C_SMC_CYCLE5 ((AT91_REG *) 	0xFFFFEC58) /* (SMC)  Cycle Register for CS 5 */
#define AT91C_SMC_CYCLE2 ((AT91_REG *) 	0xFFFFEC28) /* (SMC)  Cycle Register for CS 2 */
#define AT91C_SMC_CTRL2 ((AT91_REG *) 	0xFFFFEC2C) /* (SMC)  Control Register for CS 2 */
#define AT91C_SMC_CTRL0 ((AT91_REG *) 	0xFFFFEC0C) /* (SMC)  Control Register for CS 0 */
#define AT91C_SMC_PULSE5 ((AT91_REG *) 	0xFFFFEC54) /* (SMC)  Pulse Register for CS 5 */
#define AT91C_SMC_PULSE1 ((AT91_REG *) 	0xFFFFEC14) /* (SMC)  Pulse Register for CS 1 */
#define AT91C_SMC_PULSE0 ((AT91_REG *) 	0xFFFFEC04) /* (SMC)  Pulse Register for CS 0 */
#define AT91C_SMC_CYCLE7 ((AT91_REG *) 	0xFFFFEC78) /* (SMC)  Cycle Register for CS 7 */
#define AT91C_SMC_CTRL4 ((AT91_REG *) 	0xFFFFEC4C) /* (SMC)  Control Register for CS 4 */
#define AT91C_SMC_CTRL3 ((AT91_REG *) 	0xFFFFEC3C) /* (SMC)  Control Register for CS 3 */
#define AT91C_SMC_SETUP7 ((AT91_REG *) 	0xFFFFEC70) /* (SMC)  Setup Register for CS 7 */
#define AT91C_SMC_CTRL7 ((AT91_REG *) 	0xFFFFEC7C) /* (SMC)  Control Register for CS 7 */
#define AT91C_SMC_SETUP1 ((AT91_REG *) 	0xFFFFEC10) /* (SMC)  Setup Register for CS 1 */
#define AT91C_SMC_CYCLE0 ((AT91_REG *) 	0xFFFFEC08) /* (SMC)  Cycle Register for CS 0 */
#define AT91C_SMC_CTRL5 ((AT91_REG *) 	0xFFFFEC5C) /* (SMC)  Control Register for CS 5 */
#define AT91C_SMC_CYCLE1 ((AT91_REG *) 	0xFFFFEC18) /* (SMC)  Cycle Register for CS 1 */
#define AT91C_SMC_CTRL6 ((AT91_REG *) 	0xFFFFEC6C) /* (SMC)  Control Register for CS 6 */
#define AT91C_SMC_SETUP0 ((AT91_REG *) 	0xFFFFEC00) /* (SMC)  Setup Register for CS 0 */
#define AT91C_SMC_PULSE4 ((AT91_REG *) 	0xFFFFEC44) /* (SMC)  Pulse Register for CS 4 */
#define AT91C_SMC_SETUP5 ((AT91_REG *) 	0xFFFFEC50) /* (SMC)  Setup Register for CS 5 */
#define AT91C_SMC_SETUP2 ((AT91_REG *) 	0xFFFFEC20) /* (SMC)  Setup Register for CS 2 */
#define AT91C_SMC_CYCLE3 ((AT91_REG *) 	0xFFFFEC38) /* (SMC)  Cycle Register for CS 3 */
#define AT91C_SMC_CYCLE6 ((AT91_REG *) 	0xFFFFEC68) /* (SMC)  Cycle Register for CS 6 */
#define AT91C_SMC_SETUP6 ((AT91_REG *) 	0xFFFFEC60) /* (SMC)  Setup Register for CS 6 */
#define AT91C_SMC_CYCLE4 ((AT91_REG *) 	0xFFFFEC48) /* (SMC)  Cycle Register for CS 4 */
#define AT91C_SMC_PULSE2 ((AT91_REG *) 	0xFFFFEC24) /* (SMC)  Pulse Register for CS 2 */
#define AT91C_SMC_SETUP3 ((AT91_REG *) 	0xFFFFEC30) /* (SMC)  Setup Register for CS 3 */
/* ========== Register definition for MATRIX peripheral ==========  */
#define AT91C_MATRIX_SCFG3 ((AT91_REG *) 	0xFFFFEE10) /* (MATRIX)  Slave Configuration Register 3 */
/* ========== Register definition for PIOA peripheral ========== */
#define AT91C_PIOA_PDR  ((AT91_REG *) 	0xFFFFF404) /* (PIOA) PIO Disable Register */
#define AT91C_PIOA_SODR ((AT91_REG *) 	0xFFFFF430) /* (PIOA) Set Output Data Register */
#define AT91C_PIOA_CODR ((AT91_REG *) 	0xFFFFF434) /* (PIOA) Clear Output Data Register */
#define AT91C_PIOA_PDSR ((AT91_REG *) 	0xFFFFF43C) /* (PIOA) Pin Data Status Register */
/* ========== Register definition for PIOC peripheral ==========  */
#define AT91C_PIOC_SODR ((AT91_REG *) 	0xFFFFF830) /* (PIOC) Set Output Data Register */
#define AT91C_PIOC_CODR ((AT91_REG *) 	0xFFFFF834) /* (PIOC) Clear Output Data Register */
#define AT91C_PIOC_PDSR ((AT91_REG *) 	0xFFFFF83C) /* (PIOC) Pin Data Status Register */
/* ========== Register definition for PMC peripheral ========== */
#define AT91C_PMC_PCER  ((AT91_REG *) 	0xFFFFFC10) /* (PMC) Peripheral Clock Enable Register */
#define AT91C_PMC_PCKR  ((AT91_REG *) 	0xFFFFFC40) /* (PMC) Programmable Clock Register */
#define AT91C_PMC_MCKR  ((AT91_REG *) 	0xFFFFFC30) /* (PMC) Master Clock Register */
#define AT91C_PMC_PLLAR ((AT91_REG *) 	0xFFFFFC28) /* (PMC) PLL A Register */
#define AT91C_PMC_PCDR  ((AT91_REG *) 	0xFFFFFC14) /* (PMC) Peripheral Clock Disable Register */
#define AT91C_PMC_SCSR  ((AT91_REG *) 	0xFFFFFC08) /* (PMC) System Clock Status Register */
#define AT91C_PMC_MCFR  ((AT91_REG *) 	0xFFFFFC24) /* (PMC) Main Clock  Frequency Register */
#define AT91C_PMC_IMR   ((AT91_REG *) 	0xFFFFFC6C) /* (PMC) Interrupt Mask Register */
#define AT91C_PMC_IER   ((AT91_REG *) 	0xFFFFFC60) /* (PMC) Interrupt Enable Register */
#define AT91C_PMC_MOR   ((AT91_REG *) 	0xFFFFFC20) /* (PMC) Main Oscillator Register */
#define AT91C_PMC_IDR   ((AT91_REG *) 	0xFFFFFC64) /* (PMC) Interrupt Disable Register */
#define AT91C_PMC_PLLBR ((AT91_REG *) 	0xFFFFFC2C) /* (PMC) PLL B Register */
#define AT91C_PMC_SCDR  ((AT91_REG *) 	0xFFFFFC04) /* (PMC) System Clock Disable Register */
#define AT91C_PMC_PCSR  ((AT91_REG *) 	0xFFFFFC18) /* (PMC) Peripheral Clock Status Register */
#define AT91C_PMC_SCER  ((AT91_REG *) 	0xFFFFFC00) /* (PMC) System Clock Enable Register */
#define AT91C_PMC_SR    ((AT91_REG *) 	0xFFFFFC68) /* (PMC) Status Register */
/* ========== Register definition for PITC peripheral ==========  */
#define AT91C_PITC_PIVR ((AT91_REG *) 	0xFFFFFD38) /* (PITC) Period Interval Value Register */
#define AT91C_PITC_PISR ((AT91_REG *) 	0xFFFFFD34) /* (PITC) Period Interval Status Register */
#define AT91C_PITC_PIIR ((AT91_REG *) 	0xFFFFFD3C) /* (PITC) Period Interval Image Register */
#define AT91C_PITC_PIMR ((AT91_REG *) 	0xFFFFFD30) /* (PITC) Period Interval Mode Register */
/* ========== Register definition for PDC_SPI0 peripheral ========== */
#define AT91C_SPI0_PTCR ((AT91_REG *) 	0xFFFC8120) /* (PDC_SPI0) PDC Transfer Control Register */
#define AT91C_SPI0_TCR  ((AT91_REG *) 	0xFFFC810C) /* (PDC_SPI0) Transmit Counter Register */
#define AT91C_SPI0_RPR  ((AT91_REG *) 	0xFFFC8100) /* (PDC_SPI0) Receive Pointer Register */
#define AT91C_SPI0_TPR  ((AT91_REG *) 	0xFFFC8108) /* (PDC_SPI0) Transmit Pointer Register */
#define AT91C_SPI0_PTSR ((AT91_REG *) 	0xFFFC8124) /* (PDC_SPI0) PDC Transfer Status Register */
#define AT91C_SPI0_RNCR ((AT91_REG *) 	0xFFFC8114) /* (PDC_SPI0) Receive Next Counter Register */
#define AT91C_SPI0_TNPR ((AT91_REG *) 	0xFFFC8118) /* (PDC_SPI0) Transmit Next Pointer Register */
#define AT91C_SPI0_RCR  ((AT91_REG *) 	0xFFFC8104) /* (PDC_SPI0) Receive Counter Register */
#define AT91C_SPI0_RNPR ((AT91_REG *) 	0xFFFC8110) /* (PDC_SPI0) Receive Next Pointer Register */
#define AT91C_SPI0_TNCR ((AT91_REG *) 	0xFFFC811C) /* (PDC_SPI0) Transmit Next Counter Register */
/* ========== Register definition for SPI0 peripheral ==========  */
#define AT91C_SPI0_IDR  ((AT91_REG *) 	0xFFFC8018) /* (SPI0) Interrupt Disable Register */
#define AT91C_SPI0_TDR  ((AT91_REG *) 	0xFFFC800C) /* (SPI0) Transmit Data Register */
#define AT91C_SPI0_SR   ((AT91_REG *) 	0xFFFC8010) /* (SPI0) Status Register */
#define AT91C_SPI0_CR   ((AT91_REG *) 	0xFFFC8000) /* (SPI0) Control Register */
#define AT91C_SPI0_CSR  ((AT91_REG *) 	0xFFFC8030) /* (SPI0) Chip Select Register */
#define AT91C_SPI0_RDR  ((AT91_REG *) 	0xFFFC8008) /* (SPI0) Receive Data Register */
#define AT91C_SPI0_MR   ((AT91_REG *) 	0xFFFC8004) /* (SPI0) Mode Register */
#define AT91C_SPI0_IER  ((AT91_REG *) 	0xFFFC8014) /* (SPI0) Interrupt Enable Register */
#define AT91C_SPI0_IMR  ((AT91_REG *) 	0xFFFC801C) /* (SPI0) Interrupt Mask Register */
/* ========== Register definition for PDC_SPI1 peripheral ==========  */
#define AT91C_SPI1_PTCR ((AT91_REG *) 	0xFFFCC120) /* (PDC_SPI1) PDC Transfer Control Register */
#define AT91C_SPI1_RNPR ((AT91_REG *) 	0xFFFCC110) /* (PDC_SPI1) Receive Next Pointer Register */
#define AT91C_SPI1_RCR  ((AT91_REG *) 	0xFFFCC104) /* (PDC_SPI1) Receive Counter Register */
#define AT91C_SPI1_TPR  ((AT91_REG *) 	0xFFFCC108) /* (PDC_SPI1) Transmit Pointer Register */
#define AT91C_SPI1_PTSR ((AT91_REG *) 	0xFFFCC124) /* (PDC_SPI1) PDC Transfer Status Register */
#define AT91C_SPI1_TNCR ((AT91_REG *) 	0xFFFCC11C) /* (PDC_SPI1) Transmit Next Counter Register */
#define AT91C_SPI1_RPR  ((AT91_REG *) 	0xFFFCC100) /* (PDC_SPI1) Receive Pointer Register */
#define AT91C_SPI1_TCR  ((AT91_REG *) 	0xFFFCC10C) /* (PDC_SPI1) Transmit Counter Register */
#define AT91C_SPI1_RNCR ((AT91_REG *) 	0xFFFCC114) /* (PDC_SPI1) Receive Next Counter Register */
#define AT91C_SPI1_TNPR ((AT91_REG *) 	0xFFFCC118) /* (PDC_SPI1) Transmit Next Pointer Register */
/* ========== Register definition for SPI1 peripheral ==========  */
#define AT91C_SPI1_IER  ((AT91_REG *) 	0xFFFCC014) /* (SPI1) Interrupt Enable Register */
#define AT91C_SPI1_RDR  ((AT91_REG *) 	0xFFFCC008) /* (SPI1) Receive Data Register */
#define AT91C_SPI1_SR   ((AT91_REG *) 	0xFFFCC010) /* (SPI1) Status Register */
#define AT91C_SPI1_IMR  ((AT91_REG *) 	0xFFFCC01C) /* (SPI1) Interrupt Mask Register */
#define AT91C_SPI1_TDR  ((AT91_REG *) 	0xFFFCC00C) /* (SPI1) Transmit Data Register */
#define AT91C_SPI1_IDR  ((AT91_REG *) 	0xFFFCC018) /* (SPI1) Interrupt Disable Register */
#define AT91C_SPI1_CSR  ((AT91_REG *) 	0xFFFCC030) /* (SPI1) Chip Select Register */
#define AT91C_SPI1_CR   ((AT91_REG *) 	0xFFFCC000) /* (SPI1) Control Register */
#define AT91C_SPI1_MR   ((AT91_REG *) 	0xFFFCC004) /* (SPI1) Mode Register */

/* ***************************************************************************** */
/*               PIO DEFINITIONS FOR AT91SAM9261 */
/* ***************************************************************************** */
#define AT91C_PIO_PA0        ((unsigned int) 1 <<  0) /* Pin Controlled by PA0 */
#define AT91C_PA0_MISO0    ((unsigned int) AT91C_PIO_PA0) /*  SPI0 Master In Slave */
#define AT91C_PIO_PA1        ((unsigned int) 1 <<  1) /* Pin Controlled by PA1 */
#define AT91C_PA1_MOSI0    ((unsigned int) AT91C_PIO_PA1) /*  SPI0 Master Out Slave */
#define AT91C_PIO_PA10       ((unsigned int) 1 << 10) /* Pin Controlled by PA10 */
#define AT91C_PA10_DTXD     ((unsigned int) AT91C_PIO_PA10) /*  DBGU Debug Transmit Data */
#define AT91C_PIO_PA12       ((unsigned int) 1 << 12) /* Pin Controlled by PA12 */
#define AT91C_PIO_PA22       ((unsigned int) 1 << 22) /* Pin Controlled by PA22 */
#define AT91C_PIO_PA16       ((unsigned int) 1 << 16) /* Pin Controlled by PA16 */
#define AT91C_PIO_PA2        ((unsigned int) 1 <<  2) /* Pin Controlled by PA2 */
#define AT91C_PA2_SPCK0    ((unsigned int) AT91C_PIO_PA2) /*  SPI0 Serial Clock */
#define AT91C_PIO_PA3        ((unsigned int) 1 <<  3) /* Pin Controlled by PA3 */
#define AT91C_PA3_NPCS00   ((unsigned int) AT91C_PIO_PA3) /*  SPI0 Peripheral Chip Select 0 */
#define AT91C_PIO_PA4        ((unsigned int) 1 <<  4) /* Pin Controlled by PA4 */
#define AT91C_PA4_NPCS01   ((unsigned int) AT91C_PIO_PA4) /*  SPI0 Peripheral Chip Select 1 */
#define AT91C_PIO_PA5        ((unsigned int) 1 <<  5) /* Pin Controlled by PA5 */
#define AT91C_PA5_NPCS02   ((unsigned int) AT91C_PIO_PA5) /*  SPI0 Peripheral Chip Select 2 */
#define AT91C_PIO_PA6        ((unsigned int) 1 <<  6) /* Pin Controlled by PA6 */
#define AT91C_PA6_NPCS03   ((unsigned int) AT91C_PIO_PA6) /*  SPI0 Peripheral Chip Select 3 */
#define AT91C_PIO_PA7        ((unsigned int) 1 <<  7) /* Pin Controlled by PA7 */
#define AT91C_PIO_PA9        ((unsigned int) 1 <<  9) /* Pin Controlled by PA9  */
#define AT91C_PA9_DRXD     ((unsigned int) AT91C_PIO_PA9) /*  DBGU Debug Receive Data */
#define AT91C_PIO_PB0        ((unsigned int) 1 <<  0) /* Pin Controlled by PB0 */
#define AT91C_PB0_LCDVSYNC ((unsigned int) AT91C_PIO_PB0) /*  LCD Vertical Synchronization */
#define AT91C_PIO_PB1        ((unsigned int) 1 <<  1) /* Pin Controlled by PB1 */
#define AT91C_PB1_LCDHSYNC ((unsigned int) AT91C_PIO_PB1) /*  LCD Horizontal Synchronization */
#define AT91C_PIO_PB10       ((unsigned int) 1 << 10) /* Pin Controlled by PB10 */
#define AT91C_PB10_LCDD5    ((unsigned int) AT91C_PIO_PB10) /*  LCD Data Bus Bit 5 */
#define AT91C_PB10_LCDD10   ((unsigned int) AT91C_PIO_PB10) /*  LCD Data Bus Bit 10 */
#define AT91C_PIO_PB11       ((unsigned int) 1 << 11) /* Pin Controlled by PB11 */
#define AT91C_PB11_LCDD6    ((unsigned int) AT91C_PIO_PB11) /*  LCD Data Bus Bit 6 */
#define AT91C_PB11_LCDD11   ((unsigned int) AT91C_PIO_PB11) /*  LCD Data Bus Bit 11 */
#define AT91C_PIO_PB12       ((unsigned int) 1 << 12) /* Pin Controlled by PB12 */
#define AT91C_PB12_LCDD7    ((unsigned int) AT91C_PIO_PB12) /*  LCD Data Bus Bit 7 */
#define AT91C_PB12_LCDD12   ((unsigned int) AT91C_PIO_PB12) /*  LCD Data Bus Bit 12 */
#define AT91C_PIO_PB13       ((unsigned int) 1 << 13) /* Pin Controlled by PB13 */
#define AT91C_PB13_LCDD8    ((unsigned int) AT91C_PIO_PB13) /*  LCD Data Bus Bit 8 */
#define AT91C_PB13_LCDD13   ((unsigned int) AT91C_PIO_PB13) /*  LCD Data Bus Bit 13 */
#define AT91C_PIO_PB14       ((unsigned int) 1 << 14) /* Pin Controlled by PB14 */
#define AT91C_PB14_LCDD9    ((unsigned int) AT91C_PIO_PB14) /*  LCD Data Bus Bit 9 */
#define AT91C_PB14_LCDD14   ((unsigned int) AT91C_PIO_PB14) /*  LCD Data Bus Bit 14 */
#define AT91C_PIO_PB15       ((unsigned int) 1 << 15) /* Pin Controlled by PB15 */
#define AT91C_PB15_LCDD10   ((unsigned int) AT91C_PIO_PB15) /*  LCD Data Bus Bit 10 */
#define AT91C_PB15_LCDD15   ((unsigned int) AT91C_PIO_PB15) /*  LCD Data Bus Bit 15 */
#define AT91C_PIO_PB16       ((unsigned int) 1 << 16) /* Pin Controlled by PB16 */
#define AT91C_PB16_LCDD11   ((unsigned int) AT91C_PIO_PB16) /*  LCD Data Bus Bit 11 */
#define AT91C_PB16_LCDD19   ((unsigned int) AT91C_PIO_PB16) /*  LCD Data Bus Bit 19 */
#define AT91C_PIO_PB17       ((unsigned int) 1 << 17) /* Pin Controlled by PB17 */
#define AT91C_PB17_LCDD12   ((unsigned int) AT91C_PIO_PB17) /*  LCD Data Bus Bit 12 */
#define AT91C_PB17_LCDD20   ((unsigned int) AT91C_PIO_PB17) /*  LCD Data Bus Bit 20 */
#define AT91C_PIO_PB18       ((unsigned int) 1 << 18) /* Pin Controlled by PB18 */
#define AT91C_PB18_LCDD13   ((unsigned int) AT91C_PIO_PB18) /*  LCD Data Bus Bit 13 */
#define AT91C_PB18_LCDD21   ((unsigned int) AT91C_PIO_PB18) /*  LCD Data Bus Bit 21 */
#define AT91C_PIO_PB19       ((unsigned int) 1 << 19) /* Pin Controlled by PB19 */
#define AT91C_PB19_LCDD14   ((unsigned int) AT91C_PIO_PB19) /*  LCD Data Bus Bit 14 */
#define AT91C_PB19_LCDD22   ((unsigned int) AT91C_PIO_PB19) /*  LCD Data Bus Bit 22 */
#define AT91C_PIO_PB2        ((unsigned int) 1 <<  2) /* Pin Controlled by PB2 */
#define AT91C_PB2_LCDDOTCK ((unsigned int) AT91C_PIO_PB2) /*  LCD Dot Clock */
#define AT91C_PB2_PCK0     ((unsigned int) AT91C_PIO_PB2) /*  PMC Programmable clock Output 0 */
#define AT91C_PIO_PB20       ((unsigned int) 1 << 20) /* Pin Controlled by PB20 */
#define AT91C_PB20_LCDD15   ((unsigned int) AT91C_PIO_PB20) /*  LCD Data Bus Bit 15 */
#define AT91C_PB20_LCDD23   ((unsigned int) AT91C_PIO_PB20) /*  LCD Data Bus Bit 23 */
#define AT91C_PIO_PB21       ((unsigned int) 1 << 21) /* Pin Controlled by PB21 */
#define AT91C_PB21_TF0      ((unsigned int) AT91C_PIO_PB21) /*  SSC0 Transmit Frame Sync */
#define AT91C_PB21_LCDD16   ((unsigned int) AT91C_PIO_PB21) /*  LCD Data Bus Bit 16 */
#define AT91C_PIO_PB22       ((unsigned int) 1 << 22) /* Pin Controlled by PB22 */
#define AT91C_PB22_TK0      ((unsigned int) AT91C_PIO_PB22) /*  SSC0 Transmit Clock */
#define AT91C_PB22_LCDD17   ((unsigned int) AT91C_PIO_PB22) /*  LCD Data Bus Bit 17 */
#define AT91C_PIO_PB23       ((unsigned int) 1 << 23) /* Pin Controlled by PB23 */
#define AT91C_PB23_TD0      ((unsigned int) AT91C_PIO_PB23) /*  SSC0 Transmit Data */
#define AT91C_PB23_LCDD18   ((unsigned int) AT91C_PIO_PB23) /*  LCD Data Bus Bit 18 */
#define AT91C_PIO_PB24       ((unsigned int) 1 << 24) /* Pin Controlled by PB24 */
#define AT91C_PB24_RD0      ((unsigned int) AT91C_PIO_PB24) /*  SSC0 Receive Data */
#define AT91C_PB24_LCDD19   ((unsigned int) AT91C_PIO_PB24) /*  LCD Data Bus Bit 19 */
#define AT91C_PIO_PB25       ((unsigned int) 1 << 25) /* Pin Controlled by PB25 */
#define AT91C_PB25_RK0      ((unsigned int) AT91C_PIO_PB25) /*  SSC0 Receive Clock */
#define AT91C_PB25_LCDD20   ((unsigned int) AT91C_PIO_PB25) /*  LCD Data Bus Bit 20 */
#define AT91C_PIO_PB26       ((unsigned int) 1 << 26) /* Pin Controlled by PB26 */
#define AT91C_PB26_RF0      ((unsigned int) AT91C_PIO_PB26) /*  SSC0 Receive Frame Sync */
#define AT91C_PB26_LCDD21   ((unsigned int) AT91C_PIO_PB26) /*  LCD Data Bus Bit 21 */
#define AT91C_PIO_PB27       ((unsigned int) 1 << 27) /* Pin Controlled by PB27 */
#define AT91C_PB27_NPCS11   ((unsigned int) AT91C_PIO_PB27) /*  SPI1 Peripheral Chip Select 1 */
#define AT91C_PB27_LCDD22   ((unsigned int) AT91C_PIO_PB27) /*  LCD Data Bus Bit 22 */
#define AT91C_PIO_PB28       ((unsigned int) 1 << 28) /* Pin Controlled by PB28 */
#define AT91C_PB28_NPCS10   ((unsigned int) AT91C_PIO_PB28) /*  SPI1 Peripheral Chip Select 0 */
#define AT91C_PB28_LCDD23   ((unsigned int) AT91C_PIO_PB28) /*  LCD Data Bus Bit 23 */
#define AT91C_PIO_PB29       ((unsigned int) 1 << 29) /* Pin Controlled by PB29 */
#define AT91C_PB29_SPCK1    ((unsigned int) AT91C_PIO_PB29) /*  SPI1 Serial Clock */
#define AT91C_PB29_IRQ2     ((unsigned int) AT91C_PIO_PB29) /*  Interrupt input 2 */
#define AT91C_PIO_PB3        ((unsigned int) 1 <<  3) /* Pin Controlled by PB3 */
#define AT91C_PB3_LCDDEN   ((unsigned int) AT91C_PIO_PB3) /*  LCD Data Enable */
#define AT91C_PIO_PB30       ((unsigned int) 1 << 30) /* Pin Controlled by PB30 */
#define AT91C_PB30_MISO1    ((unsigned int) AT91C_PIO_PB30) /*  SPI1 Master In Slave */
#define AT91C_PB30_IRQ1     ((unsigned int) AT91C_PIO_PB30) /*  Interrupt input 1 */
#define AT91C_PIO_PB31       ((unsigned int) 1 << 31) /* Pin Controlled by PB31 */
#define AT91C_PB31_MOSI1    ((unsigned int) AT91C_PIO_PB31) /*  SPI1 Master Out Slave */
#define AT91C_PB31_PCK2     ((unsigned int) AT91C_PIO_PB31) /*  PMC Programmable clock Output 2 */
#define AT91C_PIO_PB4        ((unsigned int) 1 <<  4) /* Pin Controlled by PB4 */
#define AT91C_PB4_LCDCC    ((unsigned int) AT91C_PIO_PB4) /*  LCD Contrast Control */
#define AT91C_PB4_LCDD2    ((unsigned int) AT91C_PIO_PB4) /*  LCD Data Bus Bit 2 */
#define AT91C_PIO_PB5        ((unsigned int) 1 <<  5) /* Pin Controlled by PB5 */
#define AT91C_PB5_LCDD0    ((unsigned int) AT91C_PIO_PB5) /*  LCD Data Bus Bit 0 */
#define AT91C_PB5_LCDD3    ((unsigned int) AT91C_PIO_PB5) /*  LCD Data Bus Bit 3 */
#define AT91C_PIO_PB6        ((unsigned int) 1 <<  6) /* Pin Controlled by PB6 */
#define AT91C_PB6_LCDD1    ((unsigned int) AT91C_PIO_PB6) /*  LCD Data Bus Bit 1 */
#define AT91C_PB6_LCDD4    ((unsigned int) AT91C_PIO_PB6) /*  LCD Data Bus Bit 4 */
#define AT91C_PIO_PB7        ((unsigned int) 1 <<  7) /* Pin Controlled by PB7 */
#define AT91C_PB7_LCDD2    ((unsigned int) AT91C_PIO_PB7) /*  LCD Data Bus Bit 2 */
#define AT91C_PB7_LCDD5    ((unsigned int) AT91C_PIO_PB7) /*  LCD Data Bus Bit 5 */
#define AT91C_PIO_PB8        ((unsigned int) 1 <<  8) /* Pin Controlled by PB8 */
#define AT91C_PB8_LCDD3    ((unsigned int) AT91C_PIO_PB8) /*  LCD Data Bus Bit 3 */
#define AT91C_PB8_LCDD6    ((unsigned int) AT91C_PIO_PB8) /*  LCD Data Bus Bit 6 */
#define AT91C_PIO_PB9        ((unsigned int) 1 <<  9) /* Pin Controlled by PB9 */
#define AT91C_PB9_LCDD4    ((unsigned int) AT91C_PIO_PB9) /*  LCD Data Bus Bit 4 */
#define AT91C_PB9_LCDD7    ((unsigned int) AT91C_PIO_PB9) /*  LCD Data Bus Bit 7 */
#define AT91C_PIO_PC0        ((unsigned int) 1 <<  0) /* Pin Controlled by PC0 */
#define AT91C_PC0_SMOE     ((unsigned int) AT91C_PIO_PC0) /*  SmartMedia Output Enable */
#define AT91C_PIO_PC1        ((unsigned int) 1 <<  1) /* Pin Controlled by PC1 */
#define AT91C_PC1_SMWE     ((unsigned int) AT91C_PIO_PC1) /*  SmartMedia Write Enable */
#define AT91C_PIO_PC10       ((unsigned int) 1 << 10) /* Pin Controlled by PC10 */
#define AT91C_PIO_PC14       ((unsigned int) 1 << 14) /* Pin Controlled by PC14 */
#define AT91C_PIO_PC15       ((unsigned int) 1 << 15) /* Pin Controlled by PC15 */

/* ***************************************************************************** */
/*               PERIPHERAL ID DEFINITIONS FOR AT91SAM9261 */
/* ***************************************************************************** */
#define AT91C_ID_FIQ    ((unsigned int)  0) /* Advanced Interrupt Controller (FIQ) */
#define AT91C_ID_SYS    ((unsigned int)  1) /* System Interrupt */
#define AT91C_ID_PIOA   ((unsigned int)  2) /* Parallel IO Controller A */
#define AT91C_ID_PIOB   ((unsigned int)  3) /* Parallel IO Controller B */
#define AT91C_ID_PIOC   ((unsigned int)  4) /* Parallel IO Controller C */
#define AT91C_ID_US0    ((unsigned int)  6) /* USART 0 */
#define AT91C_ID_US1    ((unsigned int)  7) /* USART 1 */
#define AT91C_ID_US2    ((unsigned int)  8) /* USART 2 */
#define AT91C_ID_MCI    ((unsigned int)  9) /* Multimedia Card Interface */
#define AT91C_ID_UDP    ((unsigned int) 10) /* USB Device Port */
#define AT91C_ID_TWI    ((unsigned int) 11) /* Two-Wire Interface */
#define AT91C_ID_SPI0   ((unsigned int) 12) /* Serial Peripheral Interface 0 */
#define AT91C_ID_SPI1   ((unsigned int) 13) /* Serial Peripheral Interface 1 */
#define AT91C_ID_SSC0   ((unsigned int) 14) /* Serial Synchronous Controller 0 */
#define AT91C_ID_SSC1   ((unsigned int) 15) /* Serial Synchronous Controller 1 */
#define AT91C_ID_SSC2   ((unsigned int) 16) /* Serial Synchronous Controller 2 */
#define AT91C_ID_TC0    ((unsigned int) 17) /* Timer Counter 0 */
#define AT91C_ID_TC1    ((unsigned int) 18) /* Timer Counter 1 */
#define AT91C_ID_TC2    ((unsigned int) 19) /* Timer Counter 2 */
#define AT91C_ID_UHP    ((unsigned int) 20) /* USB Host Port */
#define AT91C_ID_LCDC   ((unsigned int) 21) /* LCD Controller */
#define AT91C_ID_IRQ0   ((unsigned int) 29) /* Advanced Interrupt Controller (IRQ0) */
#define AT91C_ID_IRQ1   ((unsigned int) 30) /* Advanced Interrupt Controller (IRQ1) */
#define AT91C_ID_IRQ2   ((unsigned int) 31) /* Advanced Interrupt Controller (IRQ2) */

/* ***************************************************************************** */
/*               BASE ADDRESS DEFINITIONS FOR AT91SAM9261 */
/* ***************************************************************************** */
#define AT91C_BASE_SYS       ((AT91PS_SYS) 	0xFFFFEA00) /* (SYS) Base Address */
#define AT91C_BASE_SDRAMC    ((AT91PS_SDRAMC) 	0xFFFFEA00) /* (SDRAMC) Base Address */
#define AT91C_BASE_SMC       ((AT91PS_SMC) 	0xFFFFEC00) /* (SMC) Base Address */
#define AT91C_BASE_MATRIX    ((AT91PS_MATRIX) 	0xFFFFEE00) /* (MATRIX) Base Address */
#define AT91C_BASE_AIC       ((AT91PS_AIC) 	0xFFFFF000) /* (AIC) Base Address */
#define AT91C_BASE_PDC_DBGU  ((AT91PS_PDC) 	0xFFFFF300) /* (PDC_DBGU) Base Address */
#define AT91C_BASE_DBGU      ((AT91PS_DBGU) 	0xFFFFF200) /* (DBGU) Base Address */
#define AT91C_BASE_PIOA      ((AT91PS_PIO) 	0xFFFFF400) /* (PIOA) Base Address */
#define AT91C_BASE_PIOB      ((AT91PS_PIO) 	0xFFFFF600) /* (PIOB) Base Address */
#define AT91C_BASE_PIOC      ((AT91PS_PIO) 	0xFFFFF800) /* (PIOC) Base Address */
#define AT91C_BASE_CKGR      ((AT91PS_CKGR) 	0xFFFFFC20) /* (CKGR) Base Address */
#define AT91C_BASE_PMC       ((AT91PS_PMC) 	0xFFFFFC00) /* (PMC) Base Address */
#define AT91C_BASE_RSTC      ((AT91PS_RSTC) 	0xFFFFFD00) /* (RSTC) Base Address */
#define AT91C_BASE_SHDWC     ((AT91PS_SHDWC) 	0xFFFFFD10) /* (SHDWC) Base Address */
#define AT91C_BASE_RTTC      ((AT91PS_RTTC) 	0xFFFFFD20) /* (RTTC) Base Address */
#define AT91C_BASE_PITC      ((AT91PS_PITC) 	0xFFFFFD30) /* (PITC) Base Address */
#define AT91C_BASE_WDTC      ((AT91PS_WDTC) 	0xFFFFFD40) /* (WDTC) Base Address */
#define AT91C_BASE_TC0       ((AT91PS_TC) 	0xFFFA0000) /* (TC0) Base Address */
#define AT91C_BASE_TC1       ((AT91PS_TC) 	0xFFFA0040) /* (TC1) Base Address */
#define AT91C_BASE_TC2       ((AT91PS_TC) 	0xFFFA0080) /* (TC2) Base Address */
#define AT91C_BASE_TCB0      ((AT91PS_TCB) 	0xFFFA0000) /* (TCB0) Base Address */
#define AT91C_BASE_UDP       ((AT91PS_UDP) 	0xFFFA4000) /* (UDP) Base Address */
#define AT91C_BASE_PDC_MCI   ((AT91PS_PDC) 	0xFFFA8100) /* (PDC_MCI) Base Address */
#define AT91C_BASE_MCI       ((AT91PS_MCI) 	0xFFFA8000) /* (MCI) Base Address */
#define AT91C_BASE_TWI       ((AT91PS_TWI) 	0xFFFAC000) /* (TWI) Base Address */
#define AT91C_BASE_PDC_US0   ((AT91PS_PDC) 	0xFFFB0100) /* (PDC_US0) Base Address */
#define AT91C_BASE_US0       ((AT91PS_USART) 	0xFFFB0000) /* (US0) Base Address */
#define AT91C_BASE_PDC_US1   ((AT91PS_PDC) 	0xFFFB4100) /* (PDC_US1) Base Address */
#define AT91C_BASE_US1       ((AT91PS_USART) 	0xFFFB4000) /* (US1) Base Address */
#define AT91C_BASE_PDC_US2   ((AT91PS_PDC) 	0xFFFB8100) /* (PDC_US2) Base Address */
#define AT91C_BASE_US2       ((AT91PS_USART) 	0xFFFB8000) /* (US2) Base Address */
#define AT91C_BASE_PDC_SSC0  ((AT91PS_PDC) 	0xFFFBC100) /* (PDC_SSC0) Base Address */
#define AT91C_BASE_SSC0      ((AT91PS_SSC) 	0xFFFBC000) /* (SSC0) Base Address */
#define AT91C_BASE_PDC_SSC1  ((AT91PS_PDC) 	0xFFFC0100) /* (PDC_SSC1) Base Address */
#define AT91C_BASE_SSC1      ((AT91PS_SSC) 	0xFFFC0000) /* (SSC1) Base Address */
#define AT91C_BASE_PDC_SSC2  ((AT91PS_PDC) 	0xFFFC4100) /* (PDC_SSC2) Base Address */
#define AT91C_BASE_SSC2      ((AT91PS_SSC) 	0xFFFC4000) /* (SSC2) Base Address */
#define AT91C_BASE_PDC_SPI0  ((AT91PS_PDC) 	0xFFFC8100) /* (PDC_SPI0) Base Address */
#define AT91C_BASE_SPI0      ((AT91PS_SPI) 	0xFFFC8000) /* (SPI0) Base Address */
#define AT91C_BASE_PDC_SPI1  ((AT91PS_PDC) 	0xFFFCC100) /* (PDC_SPI1) Base Address */
#define AT91C_BASE_SPI1      ((AT91PS_SPI) 	0xFFFCC000) /* (SPI1) Base Address */
#define AT91C_BASE_UHP       ((AT91PS_UHP) 	0x00500000) /* (UHP) Base Address */
#define AT91C_BASE_LCDC      ((AT91PS_LCDC) 	0x00600000) /* (LCDC) Base Address */
#define AT91C_BASE_LCDC_16B_TFT ((AT91PS_LCDC) 	0x00600000) /* (LCDC_16B_TFT) Base Address  */

/* ***************************************************************************** */
/*               MEMORY MAPPING DEFINITIONS FOR AT91SAM9261 */
/* ***************************************************************************** */
#define AT91C_IRAM 	 ((char *) 	0x00300000) /* Maximum Internal SRAM base address */

#endif
