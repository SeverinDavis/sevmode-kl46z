/*
 * CAR_MOTOR.c
 *
 *  Created on: October 13, 2014
 *      Author: Severin
 */

#include "CAR_MOTOR.h"

static char car_motor = 0xF0;

void CAR_MOTOR_init()
{
	//set up current-limiting digital - analog converter. still needs separate call to set specific voltage
	uc_dac_init();
	
	//CS/RCLK
	gpio_port_init(port_E, pin_16, alt_1, output);
	gpio_set_pin_state(port_E, pin_16, 1);
	
	//output enable
	gpio_port_init(port_B, pin_1, alt_1, output);
	gpio_set_pin_state(port_B, pin_1, 0);
		
	//clear and reset
	gpio_port_init(port_B, pin_2, alt_1, output);
	gpio_set_pin_state(port_B, pin_0, 0);
	gpio_set_pin_state(port_B, pin_0, 1);
	
	//direction
	gpio_port_init(port_E, pin_0, alt_1, output); 
	gpio_port_init(port_E, pin_1, alt_1, output);
	gpio_port_init(port_E, pin_2, alt_1, output);
	gpio_port_init(port_E, pin_3, alt_1, output);
	
	//MOTORS NEED TO BE CONFIGURED FOR PWM/TPM FUNCTION HERE. LEFT OUT UNTIL EVERYTHING ELSE WORKING****************************************************************************************Asterisk line for attention
	
}


void CAR_MOTOR_manual_debug_init()
{
	//set up current-limiting digital - analog converter. still needs separate call to set specific voltage
	uc_dac_init();
	
	//CS/RCLK
	gpio_port_init(port_E, pin_16, alt_1, output);
	gpio_set_pin_state(port_E, pin_16, 1);
	
	//output enable
	gpio_port_init(port_B, pin_1, alt_1, output);
	gpio_set_pin_state(port_B, pin_1, 0);
		
	//clear and reset
	gpio_port_init(port_B, pin_0, alt_1, output);
	gpio_set_pin_state(port_B, pin_0, 0);
	gpio_set_pin_state(port_B, pin_0, 1);
	
	//direction
	gpio_port_init(port_E, pin_0, alt_1, output); //m0
	gpio_port_init(port_E, pin_1, alt_1, output);
	gpio_port_init(port_E, pin_2, alt_1, output);
	gpio_port_init(port_E, pin_3, alt_1, output);//m3
	
	//temporary GPIO motor config
	gpio_port_init(port_D, pin_2, alt_1, output); //m0
	gpio_port_init(port_D, pin_3, alt_1, output);//m1
	gpio_port_init(port_D, pin_4, alt_1, output);//m2
	gpio_port_init(port_D, pin_5, alt_1, output);//m3
}


void CAR_MOTOR_update()
{
	//CS/RCLK low
	gpio_set_pin_state(port_E, pin_16, 0);
		
	//send four times to update all motors
	uc_spi_send(spi_0, car_motor);
	uc_spi_send(spi_0, car_motor);
	uc_spi_send(spi_0, car_motor);
	uc_spi_send(spi_0, car_motor);

	//CS/RCLK back up
	gpio_set_pin_state(port_E, pin_16, 1);	
}


