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



//A bunch of globals to save states
static char car_motor = 0b00000000;

static volatile CAR_MOTOR_dir_t direction[4] ={0,0,0,0};
static int current_period[4] ={0,0,0,0};
static volatile int target_period[4] ={0,0,0,0};

static int accel_counter[4] = {0,0,0,0};



/*
 * Initializes pins to control shift registers and configures "direction" pins as GPIO
 * SPI needs to be initialized separately
 */
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



/*
 * car debug function initializes PWM pins as GPIO for manual stepping.
 */
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



/*
 *  updates shift register outputs to whatever was set in global setting variable
 */
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



/*
 * sets MD on the LV8727
 */
void CAR_MOTOR_set_MD(CAR_MOTOR_step_size_t p_step_size)
{
	car_motor &= ~(7 << 4);
	car_motor |= p_step_size << 4;
}



/*
 * enables/disables the LV8727
 */
void CAR_MOTOR_set_chip_en(CAR_MOTOR_state p_state)
{
	car_motor &= ~(1 << 7);
	car_motor |= p_state << 7;
}



/*
 * enables/disables LV8727 output
 */
void CAR_MOTOR_set_output_en(CAR_MOTOR_state p_state)
{
	car_motor &= ~(1 << 3);
	car_motor |= p_state << 3;
}



/*
 * sets the reset on the LV8727
 */
void CAR_MOTOR_set_rst(CAR_MOTOR_state p_state)
{
	car_motor &= ~(1 << 2);
	car_motor |= p_state << 2;
}



/*
 * performs a reset cycle on LV8727 automatically
 */
void CAR_MOTOR_set_rst_cycle()
{
	CAR_MOTOR_set_rst(disable);
	CAR_MOTOR_update();
	CAR_MOTOR_set_rst(enable);
	CAR_MOTOR_update();

}



/*
 * enables enables current limiter pin for LV8727 current limiting
 */
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

		//needs tuning
		uc_dac_set_output(500);	
	}
	
	else
	{
		uc_dac_set_output(0);
	}
}



/*
 * Should be called by TPM and performs motor 0 stepping
 */
void CAR_MOTOR_CALLBACK_0()
{

}



/*
 * Should be called by TPM and performs motor 1 stepping
 */
void CAR_MOTOR_CALLBACK_1()
{
	

}



/*
 * Should be called by TPM and performs motor 2 stepping
 */
void CAR_MOTOR_CALLBACK_2()
{
	

}



/*
 * Should be called by TPM and performs motor 3 stepping
 */
void CAR_MOTOR_CALLBACK_3()
{
	

}



/*
 * sets the direction for a specific motor
 */
void CAR_MOTOR_set_direction(CAR_MOTOR_motor_t p_motor, CAR_MOTOR_dir_t p_dir)
{
	direction[p_motor] = p_dir;
}



/*
 * sets new target period
 */
void CAR_MOTOR_set_target(CAR_MOTOR_motor_t p_motor, int p_target)
{
	target_period[p_motor]=p_target;
	accel_counter[p_motor] = 0;
}



/*
 * starts up LV8727s safely.
 */
void CAR_MOTOR_motor_startup()
{
	//motor startup sequence
	//set a md and turn off output. enable chip.
	//update motors
	
	CAR_MOTOR_set_MD(step_2);
	CAR_MOTOR_set_output_en(disable);
	CAR_MOTOR_set_chip_en(enable);
	CAR_MOTOR_update();
	
	//start current limiting analog value
	CAR_MOTOR_set_current_limiter_en(enable);
	
	//reset chip, since it just intitialized
	//rst_cycle() auto-cycles and updates
	CAR_MOTOR_set_rst_cycle();
	
	//enable output
	CAR_MOTOR_set_output_en(enable);
	CAR_MOTOR_update();
}


