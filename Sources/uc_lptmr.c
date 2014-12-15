#include "uc_lptmr.h"



/*
 * initializes the low power timer
 * Timer is still wonky. Only works consistently with a hard board power cycle
 */
void uc_lptmr_init()
{
	SIM_SCGC5 |= 1;
	SIM_SOPT1 = ~(3 << 18);
	LPTMR0_PSR = 0x5;
}



/*
 * busy delay in milliseconds
 */
void uc_lptmr_delay(int p_msec)
{
	LPTMR0_CMR = p_msec;
	LPTMR0_CSR |= 1;
	while((LPTMR0_CSR & 0x80) == 0){} //spin while compare isn't equal
	LPTMR0_CSR &= ~1;
}
