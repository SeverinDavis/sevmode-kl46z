
#include "uc_dac.h"

void uc_dac_init()
{
	gpio_port_init(port_E, pin_30, alt_0, output);
	SIM_SCGC6  |= 1 << 31;
	DAC0_C0 |= 1 << 6;
	DAC0_C0 |= 1 << 7;
}

void uc_dac_set_output(int p_numerator)
{
	DAC0_DAT0L = p_numerator;
	DAC0_DAT0H = (p_numerator >> 8);
}
