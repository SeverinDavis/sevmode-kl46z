#include <gpio.h>

#define PORTX_PCR_BASE 			PORTA_PCR0 

#define FGPIOX_PDOR_BASE    	FGPIOA_PDOR                    
#define FGPIOX_PSOR_BASE    	FGPIOA_PSOR            
#define FGPIOX_PCOR_BASE    	FGPIOA_PCOR         
#define FGPIOX_PTOR_BASE    	FGPIOA_PTOR                  
#define FGPIOX_PDIR_BASE    	FGPIOA_PDIR                        
#define FGPIOX_PDDR_BASE    	FGPIOA_PDDR


void gpio_pin_set_dir(port_t p_port, pin_t p_pin, dir_t p_dir)
{
	int * custom_PDDR = (int *)(FGPIOX_PDDR_BASE + (p_port * 0x40));
	
	*custom_PDDR &= 1 << p_pin;
	
	*custom_PDDR |= p_dir << p_pin;
}

void gpio_pin_set_alt(port_t p_port, pin_t p_pin, alt_t p_alt)
{
	int test = PORTX_PCR_BASE;
	unsigned int * custom_PCR = (PORTX_PCR_BASE);
	custom_PCR += (p_port * 0x1000);
	custom_PCR += (p_pin * 0x4);
	
	*custom_PCR &= ~0x700;
	
	*custom_PCR |= p_alt << 8;
}

void gpio_port_init(port_t p_port, pin_t p_pin, alt_t p_alt, dir_t p_dir)
{
	SIM_SCGC5 |= 1 << (p_port + 9); // enable clock to port
	
	gpio_pin_set_alt(p_port, p_pin, p_alt);
	
	gpio_pin_set_dir(p_port, p_pin, p_alt);
	
}

int gpio_get_pin_state(port_t p_port, pin_t p_pin)
{
	int * custom_PDOR = (int *)(FGPIOX_PDOR_BASE + (p_port * 0x40));
			
	return (*custom_PDOR >> p_pin) & 1;
}


void gpio_set_pin_state(port_t p_port, pin_t p_pin, int p_state)
{
	if(p_state)
	{
		int * custom_PSOR = (int *)(FGPIOX_PSOR_BASE + (p_port * 0x40));
		
		*custom_PSOR &= 1 << p_pin;	
	}
	
	else
	{
		int * custom_PCOR = (int *)(FGPIOX_PCOR_BASE + (p_port * 0x40));
		
		*custom_PCOR &= 1 << p_pin;	
		
	}
}

void gpio_toggle_pin_state(port_t p_port, pin_t p_pin)
{
	int * custom_PTOR = (int *)(FGPIOX_PTOR_BASE + (p_port * 0x40));
	
	*custom_PTOR &= 1 << p_pin;	
}
