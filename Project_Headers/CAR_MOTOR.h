/*
 * CAR_MOTOR.h
 *
 *  Created on: October 13, 2014
 *      Author: Severin
 */

#ifndef CAR_MOTOR_H
#define CAR_MOTOR_H

#include "derivative.h"
#include "uc_spi.h"
#include "uc_tpm.h"
#include "uc_dac.h"
#include "gpio.h"

void CAR_MOTOR_init();
void CAR_MOTOR_manual_debug_init();
void CAR_MOTOR_update();

#endif
