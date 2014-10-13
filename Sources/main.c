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
	//set clock to blazing speed of 24Mhz. 
	//Timers won't run at right frequency unless this is called first.
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

void init()
{
	clock_init();
	uc_spi_init(spi_0);
	uc_led_all_init();
}

int main(void)
{
	init();
	/*
	gpio_port_init(port_E, pin_16, alt_1, output);
			gpio_set_pin_state(port_E, pin_16, 1);
		//output enable
		gpio_port_init(port_B, pin_1, alt_1, output);
		gpio_set_pin_state(port_B, pin_1, 0);
		//clear and reset
		gpio_port_init(port_B, pin_0, alt_1, output);
		gpio_set_pin_state(port_B, pin_0, 0);
		gpio_set_pin_state(port_B, pin_0, 1);
		//CS
		gpio_set_pin_state(port_E, pin_16, 0);

			uc_spi_send(spi_0, 0b11111111);
			uc_spi_send(spi_0, 0b00000000);
			uc_spi_send(spi_0, 0b11111111);
			uc_spi_send(spi_0, 0b00000000);
			uc_spi_send(spi_0, 0b11111111);
			

			gpio_set_pin_state(port_E, pin_16, 1);
*/

	
	//testing for RGB LED driver
	//cs
	gpio_port_init(port_E, pin_19, alt_1, output);
		gpio_set_pin_state(port_E, pin_19, 1);
	//output enable
	gpio_port_init(port_B, pin_3, alt_1, output);
	gpio_set_pin_state(port_B, pin_3, 0);
	//clear and reset
	gpio_port_init(port_B, pin_2, alt_1, output);
	gpio_set_pin_state(port_B, pin_2, 0);
	gpio_set_pin_state(port_B, pin_2, 1);
	//CS
	gpio_set_pin_state(port_E, pin_19, 0);
	
		uc_spi_send(spi_0, 0b10000000);
		//first three bits control j15 led.
		uc_spi_send(spi_0, 0b11100000);
		
		uc_spi_send(spi_0, 0b10101010);
	gpio_set_pin_state(port_E, pin_19, 1);
	
	
	uc_led_on(led_green);
	
while(1)
{}
	return 0;
}



