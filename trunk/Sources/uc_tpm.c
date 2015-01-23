/*
 * uc_tpm.c
 *
 *  Created on: June 15, 2014
 *      Author: Severin
 */

#include "uc_tpm.h"
#include "uc_led.h"

#define TPM_MOD_VAL 0xFFFE
#define TPM_MOD_VAL_OFF 0xFFFF

#define MIN_TIME 50

static callback_t tpm_callback[6] ={0,0,0,0,0,0};

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
		for(n = 1; n < 6; n++)
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
	


	//set compare value to "OFF" state
	if(p_value == TPM_MOD_VAL_OFF)
	{
		
		TPM0_CnV(p_tpm_chan) = TPM_MOD_VAL_OFF;
	}
	else
	{
		//if counter is currently in OFF state, wakeup channel
		if(TPM0_CnV(p_tpm_chan) == TPM_MOD_VAL_OFF)
		{
			TPM0_CnV(p_tpm_chan) = ((TPM0_CNT+2)%TPM_MOD_VAL_OFF);
		}
		else
		{
			TPM0_CnV(p_tpm_chan) = ((TPM0_CnV(p_tpm_chan)+p_value)%TPM_MOD_VAL_OFF);
		}
		
	}

}


void TPM0_IRQHandler()
{
	
	//grab counter value to lock counter value when interrupt occurred
	int n;
	// loop through all used tpm channels
	for(n = 5; n > 0; n--)
		//check if interrupt occurred in that channel 
		if((TPM0_CnSC(n) & TPM_CnSC_CHF_MASK) == TPM_CnSC_CHF_MASK)
		{
			TPM0_CnSC(n) |= TPM_CnSC_CHF_MASK;

			//callback time!
			if(tpm_callback[n])
			{
				tpm_callback[n]();
			}
		}
	

}


void uc_tpm_mask_int()
{
	int_mask(INT_TPM0);
}

void uc_tpm_unmask_int()
{
	int_unmask(INT_TPM0);
}

int uc_tpm_enough_time(tpm_chan_t p_tpm_chan)
{
	unsigned int counter = TPM0_CNT;
	unsigned int c_val = TPM0_CnV(p_tpm_chan);
	
	if(c_val < counter)
	{
		if(((counter - 65534) + c_val) > MIN_TIME)
		{
			return 1;
		}
	}
	
	else if(counter < c_val)
	{
		if((c_val - counter) > MIN_TIME)
		{
			return 1;
		}
	}
	
	return 0;
	
}

void uc_tpm_try_to_preempt(tpm_chan_t p_tpm_chan, unsigned int old_period, unsigned int new_period)
{
	unsigned int current_CnV = TPM0_CnV(p_tpm_chan);
	unsigned int old_CnV = 0;
	

	//we're passing 0 on this
	if(current_CnV < old_period)
	{
		old_period = old_period - current_CnV;
		old_CnV = TPM_MOD_VAL - old_period;
	}
	//0 not passed 
	else
	{
		old_CnV = current_CnV - old_period;
	}
	
	unsigned int new_CnV = (old_CnV + new_period)%TPM_MOD_VAL;
	
	unsigned int comparison_CnV = adjust_for_comparison(old_CnV, new_CnV);
	unsigned int counter = TPM0_CNT;
	unsigned int comparison_CNT = adjust_for_comparison(old_CnV, counter);

	if(comparison_CnV > comparison_CNT + 5)
	{
		
	}
}

unsigned int adjust_for_comparison(unsigned int adjust, unsigned int value)
{
	if(adjust > value)
	{
		unsigned int temp_val = adjust - value;
		return (TPM_MOD_VAL - temp_val);
	}
	return (value - adjust);
}

unsigned int uc_tpm_time_left(tpm_chan_t p_tpm_chan)
{
	//get counter and written value
	unsigned int counter = TPM0_CNT;
	unsigned int c_val = TPM0_CnV(p_tpm_chan);
		
	if(c_val >= counter)
	{
		return c_val-counter;
	}
		
	else 
	{
		unsigned int temp = TPM_MOD_VAL - counter;
		return c_val + temp;
	}
}

void uc_tpm_pulse_asap(tpm_chan_t p_tpm_chan)
{
        
                
        TPM0_CnV(p_tpm_chan) = (TPM0_CNT + 2)%TPM_MOD_VAL_OFF;


}

void uc_tpm_set_neg_compare_value(tpm_chan_t p_tpm_chan, unsigned neg_value)
{
		//passing 0 if neg value is greater
        if(neg_value > TPM0_CnV(p_tpm_chan))
        {
 			neg_value = TPM0_CnV(p_tpm_chan) - neg_value;
 			TPM0_CnV(p_tpm_chan) =  TPM_MOD_VAL - neg_value;

        }
        else
        {
        	TPM0_CnV(p_tpm_chan) =  TPM0_CnV(p_tpm_chan) - neg_value;
        }


}

