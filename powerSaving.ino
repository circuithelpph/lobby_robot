// pre processor directives
// conserve power especially on camera mode
#include <avr/power.h>

void conservePower(){
	// save power
	power_adc_disable();
	power_spi_disable();
	power_timer1_disable();
	power_timer2_disable();
	power_twi_disable();
}

void restorePower(){
	// restore power
	power_adc_enable();
	power_spi_enable();
	power_timer1_enable();
	power_timer2_enable();
	power_twi_enable();
}