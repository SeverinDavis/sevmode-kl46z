/*
 * CAR_MOTOR.c
 *
 *  Created on: October 13, 2014
 *      Author: Severin
 */

#include "CAR_MOTOR.h"



/*MOTOR SETTING FIELDS
 * 
 * 
 * |ST			|MD1	|MD2	|MD3	|OE				|RST	|unused	|unused|
 * 1 active			check manual for MD	 1 active		0 reset
 * 														1 normal
 * 										
 * 
 */

static char car_motor = 0b00000000;

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
	
	gpio_set_pin_state(port_E, pin_0, 0);
	gpio_set_pin_state(port_E, pin_1, 0);
	gpio_set_pin_state(port_E, pin_2, 0);
	gpio_set_pin_state(port_E, pin_3, 0);
	
	//temporary GPIO motor config
	gpio_port_init(port_D, pin_2, alt_1, output); //m0
	gpio_port_init(port_D, pin_3, alt_1, output);//m1
	gpio_port_init(port_D, pin_4, alt_1, output);//m2
	gpio_port_init(port_D, pin_5, alt_1, output);//m3
	
	gpio_set_pin_state(port_D, pin_2, 0);
	gpio_set_pin_state(port_D, pin_3, 0);
	gpio_set_pin_state(port_D, pin_4, 0);
	gpio_set_pin_state(port_D, pin_5, 0);
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


void CAR_MOTOR_set_MD(CAR_MOTOR_step_size_t p_step_size)
{
	car_motor &= ~(7 << 4);
	car_motor |= p_step_size << 4;
}

void CAR_MOTOR_set_chip_en(CAR_MOTOR_state p_state)
{
	car_motor &= ~(1 << 7);
	car_motor |= p_state << 7;
}

void CAR_MOTOR_set_output_en(CAR_MOTOR_state p_state)
{
	car_motor &= ~(1 << 3);
	car_motor |= p_state << 3;
}

void CAR_MOTOR_set_rst(CAR_MOTOR_state p_state)
{
	car_motor &= ~(1 << 2);
	car_motor |= p_state << 2;
}

void CAR_MOTOR_set_rst_cycle()
{
	CAR_MOTOR_set_rst(disable);
	CAR_MOTOR_update();
	CAR_MOTOR_set_rst(enable);
	CAR_MOTOR_update();

}

void CAR_MOTOR_set_current_limiter_en(CAR_MOTOR_state p_state)
{
	
	if(p_state)
	{
		//TEMP HARDCODED!!!!!
		//DO NOT EXCEED 1200
		
		/*
		dac param	voltage (V)		output current (A)
		0			0.000805664		0.000994647
		200			0.161938477		0.199924045
		400			0.323071289		0.398853443
		600			0.484204102		0.597782841
		800			0.645336914		0.79671224
		1000		0.806469727		0.995641638
		1200		0.967602539		1.194571036
		1400		1.128735352		1.393500434
		1600		1.289868164		1.592429832
		 */

		uc_dac_set_output(1000);	
	}
	
	else
	{
		uc_dac_set_output(0);
	}


}


