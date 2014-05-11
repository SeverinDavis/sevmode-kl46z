/*
 * int.c
 *
 *  Created on: May 10, 2014
 *      Author: Severin
 */

#include "int.h"

void int_init(intsrc_t p_intsrc, priority_t p_priority)
{
	NVIC_IP(p_intsrc % 4) &= ~(3 << ((8 * (p_intsrc % 4)) + 6));
	NVIC_IP(p_intsrc % 4) |= (p_priority << ((8 * (p_intsrc % 4)) + 6));
}
