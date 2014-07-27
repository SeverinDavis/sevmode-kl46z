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
	uc_tpm_init();
	/*
	int_all_mask();
	clock_init();
	uc_dac_init();
	uc_led_all_init();
	uc_lptmr_init();
	
	pit_init(pit_0, priority_1, 1000000, PIT0_CALLBACK);
	pit_init(pit_1, priority_1, 500000, PIT1_CALLBACK);
	pit_enable(pit_0);
	pit_enable(pit_1);
	int_all_unmask();
	*/
	uc_spi_init(spi_1);


	
	while(1)
	{

		uc_spi_send(spi_1, 'w');
		uc_spi_send(spi_1, 'a');
		uc_spi_send(spi_1, 'f');
		uc_spi_send(spi_1, 'l');
		uc_spi_send(spi_1, 'c');
		uc_spi_send(spi_1, 'o');
		uc_spi_send(spi_1, 'p');
		uc_spi_send(spi_1, 't');
		uc_spi_send(spi_1, 'e');
		uc_spi_send(spi_1, 'r');
	}
	return 0;
}


