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

       //PA1 as TPM
       SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
       PORTA_BASE_PTR->PCR[1] = PORT_PCR_MUX(3);
       PTA_BASE_PTR->PDDR = 1<< 1;

       MCG_C1 |= 0b11 << 1;
       MCG_C2 |= 1;

       SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;
       SIM_SOPT2 |= SIM_SOPT2_TPMSRC(3);

       TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) |TPM_SC_PS(6);
       TPM2_BASE_PTR->MOD=0xFFFF;

       TPM2_BASE_PTR->CONTROLS[0].CnSC = 0b1101 << 2;//TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
       TPM2_BASE_PTR->CONTROLS[0].CnV = 1;
       TPM2_BASE_PTR->CONTROLS[0].CnSC |= 1<<6;
}

 

void FTM2_IRQHandler()
{

       TPM2_BASE_PTR->CONTROLS[0].CnV = (TPM2_BASE_PTR->CONTROLS[0].CnV+2);
       TPM2_BASE_PTR->CONTROLS[0].CnSC |= 1 << 7;

}
