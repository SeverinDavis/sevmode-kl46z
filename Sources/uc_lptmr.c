#include "uc_lptmr.h"

void uc_lptmr_init()
{
	SIM_SCGC5 |= 1;
	SIM_SOPT1 = ~(3 << 18);
	LPTMR0_PSR = 0x5;
}
void uc_lptmr_delay(int p_msec)
{
	LPTMR0_CMR = p_msec;
	LPTMR0_CSR |= 1;
	while((LPTMR0_CSR & 0x80) == 0){} //spin while compare isn't equal
	LPTMR0_CSR &= ~1;
}
