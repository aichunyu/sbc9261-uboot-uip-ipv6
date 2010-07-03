/*
 * (C) Copyright 2005
 * M Amine SAYA ATEML Rousset, France.
 * include/asm/arch/pio.h contains pio config and management functions
 *
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
 */


#ifndef __ASM_ARCH_PIO_H
#define __ASM_ARCH_PIO_H

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_CfgPeriph */
/* \brief Enable pins to be drived by peripheral */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_CfgPeriph(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller  */
	unsigned int periphAEnable,  /* \arg PERIPH A to enable */
	unsigned int periphBEnable)  /* \arg PERIPH B to enable */
{
	pPio->PIO_ASR = periphAEnable;
	pPio->PIO_BSR = periphBEnable;
	pPio->PIO_PDR = (periphAEnable | periphBEnable); /* Set in Periph mode */
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_CfgOutput */
/* \brief Enable PIO in output mode */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_CfgOutput(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	unsigned int pioEnable)      /* \arg PIO to be enabled */
{
	pPio->PIO_PER = pioEnable; /* Set in PIO mode */
	pPio->PIO_OER = pioEnable; /* Configure in Output */
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_CfgInput */
/* \brief Enable PIO in input mode */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_CfgInput(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	unsigned int inputEnable)      /* \arg PIO to be enabled */
{
	/* Disable output */
	pPio->PIO_ODR  = inputEnable;
	pPio->PIO_PER  = inputEnable;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_GetInput */
/* \brief Return PIO input value */
/*---------------------------------------------------------------------------- */
static unsigned int __inline__ AT91F_PIO_GetInput( /* \return PIO input  */
	AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
	return pPio->PIO_PDSR;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_SetOutput */
/* \brief Set to 1 output PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_SetOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	unsigned int flag) /* \arg  output to be set */
{
	pPio->PIO_SODR = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_ClearOutput */
/* \brief Set to 0 output PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_ClearOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	unsigned int flag) /* \arg  output to be cleared */
{
	pPio->PIO_CODR = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_ForceOutput */
/* \brief Force output when Direct drive option is enabled */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_ForceOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	unsigned int flag) /* \arg  output to be forced */
{
	pPio->PIO_ODSR = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_Enable */
/* \brief Enable PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_Enable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        unsigned int flag) /* \arg  pio to be enabled */
{
        pPio->PIO_PER = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_Disable */
/* \brief Disable PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_Disable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        unsigned int flag) /* \arg  pio to be disabled */
{
        pPio->PIO_PDR = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_GetStatus */
/* \brief Return PIO Status */
/*---------------------------------------------------------------------------- */
static unsigned int __inline__ AT91F_PIO_GetStatus( /* \return PIO Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_PSR;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_OutputEnable */
/* \brief Output Enable PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_OutputEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        unsigned int flag) /* \arg  pio output to be enabled */
{
        pPio->PIO_OER = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_OutputDisable */
/* \brief Output Enable PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_OutputDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        unsigned int flag) /* \arg  pio output to be disabled */
{
        pPio->PIO_ODR = flag;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_GetOutputStatus */
/* \brief Return PIO Output Status */
/*---------------------------------------------------------------------------- */
static unsigned int __inline__ AT91F_PIO_GetOutputStatus( /* \return PIO Output Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_OSR;
}

/*---------------------------------------------------------------------------- */
/* \fn    AT91F_PIO_CfgPullup */
/* \brief Enable pullup on PIO */
/*---------------------------------------------------------------------------- */
static void __inline__ AT91F_PIO_CfgPullup(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	unsigned int pullupEnable)   /* \arg enable pullup on PIO */
{
	/* Connect or not Pullup */
	pPio->PIO_PPUDR = ~pullupEnable;
	pPio->PIO_PPUER = pullupEnable;
}


static void __inline__ AT91F_PIOC_CfgPMC(void) {
  AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_PIOC;
}
#endif
