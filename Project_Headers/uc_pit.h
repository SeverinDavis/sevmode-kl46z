/*
 * uc_pit.h
 *
 *  Created on: Jan 18, 2014
 *      Author: Severin
 */

#ifndef UC_PIT_H_
#define UC_PIT_H_

#include "derivative.h"
#include "global.h"

typedef enum{
	pit0,
	pit1
} pit_t;

void pit_enable(pit_t timer);
void pit_disable(pit_t timer);
void pit_init(pit_t timer, int us_freq);
void pit_set_callback(pit_t p_timer, callback p_callback);

#endif /* UC_PIT_H_ */
