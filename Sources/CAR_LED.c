/*
 * CAR_LED.c
 *
 *  Created on: September 12, 2014
 *      Author: Severin
 */

#include "CAR_LED.h"

static char car_led_0_1 = 0;
static char car_led_2_3 = 0;

void CAR_LED_init()
{
	//CS/RCLK
	gpio_port_init(port_E, pin_19, alt_1, output);
	gpio_set_pin_state(port_E, pin_19, 1);
	//output enable
	gpio_port_init(port_B, pin_3, alt_1, output);
	gpio_set_pin_state(port_B, pin_3, 0);
	//clear and reset
	gpio_port_init(port_B, pin_2, alt_1, output);
	gpio_set_pin_state(port_B, pin_2, 0);
	gpio_set_pin_state(port_B, pin_2, 1);
}

void CAR_LED_update()
{
	//CS/RCLK low
	gpio_set_pin_state(port_E, pin_19, 0);
	
		uc_spi_send(spi_0, car_led_2_3);
		//first three bits control j15 led.
		uc_spi_send(spi_0, car_led_0_1);
		
		//dummy send because it won't work otherwise. Something weird is going on.
		uc_spi_send(spi_0, 0b00000000);
		
	//CS/RCLK back up, yo
	gpio_set_pin_state(port_E, pin_19, 1);	
}

void CAR_LED_set_color(car_led_t p_car_led, car_led_color_t p_car_led_color)
{
	if(car_led_t == car_led_0 | car_led_t == car_led_1)
	{
		car_led_0_1 &= (~0b111) << (2 + (p_car_led * 3));
		car_led_0_1 |= (p_car_led_color) << (2 + (p_car_led * 3));
	}
	
	else
	{
		car_led_2_3 &= (~0b111) << (2 + ((p_car_led - 2) * 3));
		car_led_2_3 |= (p_car_led_color) << (2 + ((p_car_led - 2) * 3));
	}
	
}
