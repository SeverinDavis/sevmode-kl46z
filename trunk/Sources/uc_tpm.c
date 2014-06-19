/*
 * uc_tpm.c
 *
 *  Created on: June 15, 2014
 *      Author: Severin
 */

#include "uc_tpm.h"

#define TPM_SC_BASE 	0x40038000
#define TPM_CNT_BASE	0x40038004
#define TPM_MOD_BASE	0x40038008
#define TPM_CNSC_BASE	0x4003800C
#define TPM_CNV_BASE	0x40038010
#define TPM_STATUS_BASE	0x40038050
#define TPM_CONF_BASE	0x40038084

void uc_tpm_init()
{
	MCG_C1 |= 1 << 2;
	MCG_C1 |= 1 << 1;
	MCG_C2 &= ~1;
	
	SIM_SOPT2 |= 1<< 24;
	
	SIM_SCGC6 |= 1 << 26;
	SIM_SCGC6 |= 1 << 25;
	SIM_SCGC6 |= 1 << 24;
	
	//TPM0_C0SC |= 3 << 4;
	TPM0_C0SC |= 0b1101 << 2;
	TPM0_C0V = 100;
	
}
