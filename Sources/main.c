/*
 * main.c
 *
 *  Created on: May 7, 2014
 *      Author: Severin
 */





#include "derivative.h" /* include peripheral declarations */
#include "uc_led.h"
#include "gpio.h"
#include "uc_lptmr.h"
#include "uc_dac.h"
#include "uc_pit.h"
#include "int.h"
#include "uc_spi.h"
#include "uc_tpm.h"
#include "uc_sw.h"

void PIT0_CALLBACK()
{
	uc_led_toggle(led_green);
}

void PIT1_CALLBACK()
{
	uc_led_toggle(led_red);
}

void clock_init()
{
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

int main(void)
{
	uc_led_all_init();
	
	uc_sw_init(switch_1);
	while(1)
	{
		if(uc_sw_poll_switch1())
		{
			uc_led_on(led_red);
			uc_led_off(led_green);
		}
		else
		{
			uc_led_on(led_green);
			uc_led_off(led_red);			
			
		}
		
	}
	return 0;
}



