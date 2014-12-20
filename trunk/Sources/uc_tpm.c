/*
 * uc_tpm.c
 *
 *  Created on: June 15, 2014
 *      Author: Severin
 */

#include "uc_tpm.h"

#define TPM_MOD_VAL 0xFFFE
#define TPM_MOD_VAL_OFF 0xFFFF

static callback_t tpm_callback[6] ={0,0,0,0,0,0};
static int locked_counter[4] = {0,0,0,0};

void uc_tpm_init()
{
		//motors are driven off D2-D4 outputs with TPM function (alt4)
		gpio_port_init(port_D, pin_2, alt_4, 1);
		gpio_port_init(port_D, pin_3, alt_4, 1);
		gpio_port_init(port_D, pin_4, alt_4, 1);
		gpio_port_init(port_D, pin_5, alt_4, 1);

		//internal clock selected for FLL and MCGIRCLK active
		MCG_C1 |= MCG_C1_IRCLKEN_MASK | MCG_C1_IREFS_MASK;
		//choose fast internal reference clock
		MCG_C2 |= MCG_C2_IRCS_MASK;

		//enable clock to tpm 
		SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
		//choose MCGIRCLK as TPM clk source
		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(3);

		//CMOD set increment on each incoming clock pulse
		//divide incoming clock by prescaler. 0b000 = 1, 0b111 = 128
		TPM0_SC = TPM_SC_CMOD(1) |TPM_SC_PS(6);
		
		// set to 0xFFFE to leave non-triggering value at 0xFFFF
		TPM0_MOD = TPM_MOD_VAL;
		
		//setup interrupt
		int_init(INT_TPM0, priority_1);
		
		int n;
		for(n = 2; n < 3; n++)
		{
			//configd for output compare
			TPM0_CnSC(n) = TPM_CnSC_MSB_MASK | TPM_CnSC_MSA_MASK | TPM_CnSC_ELSA_MASK;
		
			//initialized to "safe" off value at 0xFFFF
			//TPM0_CnV(0) = TPM_MOD_VAL_OFF;
			//temporary
			TPM0_CnV(n) = 1;
		
			//ACTIVATE INTERRUPT. 3. 2. 1. GOOOOOOOOOOOOOOOOOOOOO
			TPM0_CnSC(n) |= TPM_CnSC_CHIE_MASK;
		}
}

void uc_tpm_set_callback(tpm_chan_t p_tpm_chan, callback_t p_callback)
{
	tpm_callback[p_tpm_chan] = p_callback;
}

void uc_tpm_set_compare_val(tpm_chan_t p_tpm_chan, int p_value)
{
	if(p_value == 0)
	{
		TPM0_CnV(p_tpm_chan) = TPM_MOD_VAL_OFF;
	}
	TPM0_CnV(p_tpm_chan) = ((locked_counter[p_tpm_chan]+p_value)%TPM_MOD_VAL);
}


void TPM0_IRQHandler()
{
	//grab counter value to lock counter value when interrupt occurred
	int uber_locked_counter = TPM0_CNT;
	int n = 2;
	// loop through all used tpm channels
	for(n = 2; n < 3; n++)
		//check if interrupt occurred in that channel 
		if((TPM0_CnSC(n) & TPM_CnSC_CHF_MASK) == TPM_CnSC_CHF_MASK)
		{
			TPM0_CnSC(n) |= TPM_CnSC_CHF_MASK;
			locked_counter[n] = uber_locked_counter;
			

			if(tpm_callback[n])
			{
				tpm_callback[n]();
			}
			
			//uc_tpm_set_compare_val(tpm_chan_2, 100);
		}
		


}
