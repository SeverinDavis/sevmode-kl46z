#include <gpio.h>

#define PORTX_PCR_BASE 			0x40049000

#define FGPIOX_PDOR_BASE    	0xF80FF000                    
#define FGPIOX_PSOR_BASE    	0xF80FF004            
#define FGPIOX_PCOR_BASE    	0xF80FF008        
#define FGPIOX_PTOR_BASE    	0xF80FF00C                  
#define FGPIOX_PDIR_BASE    	0xF80FF010                       
#define FGPIOX_PDDR_BASE    	0xF80FF014


void gpio_pin_set_dir(port_t p_port, pin_t p_pin, dir_t p_dir)
{
	unsigned int * custom_PDDR = (unsigned int *)(FGPIOX_PDDR_BASE + (p_port * 0x40));
	
	*custom_PDDR &= 1 << p_pin;
	
	*custom_PDDR |= p_dir << p_pin;
}

void gpio_pin_set_alt(port_t p_port, pin_t p_pin, alt_t p_alt)
{
    unsigned int * custom_PCR = (unsigned int *)(PORTX_PCR_BASE + p_port * 0x1000 + p_pin * 0x4);

    
    *custom_PCR &= ~0x700;
    
    *custom_PCR |= p_alt << 8;
}

void gpio_port_init(port_t p_port, pin_t p_pin, alt_t p_alt, dir_t p_dir)
{
	SIM_SCGC5 |= 1 << (p_port + 9); // enable clock to port
	
	gpio_pin_set_alt(p_port, p_pin, p_alt);
	
	gpio_pin_set_dir(p_port, p_pin, p_dir);
	
}

int gpio_get_pin_state(port_t p_port, pin_t p_pin)
{
	unsigned int * custom_PDOR = (unsigned int *)(FGPIOX_PDOR_BASE + (p_port * 0x40));
			
	return (*custom_PDOR >> p_pin) & 1;
}


void gpio_set_pin_state(port_t p_port, pin_t p_pin, int p_state)
{
	if(p_state)
	{
		unsigned int * custom_PSOR = (unsigned int *)(FGPIOX_PSOR_BASE + (p_port * 0x40));
		
		*custom_PSOR = 1 << p_pin;	
	}
	
	else
	{
		unsigned int * custom_PCOR = (unsigned int *)(FGPIOX_PCOR_BASE + (p_port * 0x40));
		
		*custom_PCOR = 1 << p_pin;	
		
	}
}

void gpio_toggle_pin_state(port_t p_port, pin_t p_pin)
{
	unsigned int * custom_PTOR = (unsigned int *)(FGPIOX_PTOR_BASE + (p_port * 0x40));
	
	*custom_PTOR = 1 << p_pin;	
}
