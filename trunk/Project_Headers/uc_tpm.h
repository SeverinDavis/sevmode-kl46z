/*
 * uc_tpm.h
 *
 *  Created on: June 15, 2014
 *      Author: Severin
 */

#ifndef UC_TPM_H_
#define UC_TPM_H_

#include "derivative.h"
#include "gpio.h"
#include "int.h"

typedef enum{
	tpm_chan_0,
	tpm_chan_1,
	tpm_chan_2,
	ttpm_chan_3,
	tpm_chan_4,
	tpm_chan_5
} tpm_chan_t;

void uc_tpm_init();
void uc_tpm_set_callback(tpm_chan_t, callback_t);


#endif /* UC_TPM_H_ */
