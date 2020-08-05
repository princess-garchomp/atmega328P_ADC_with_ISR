#include "adc.h"

void adc_config(){
	ADMUX|=(1ul<<(REFS0))|(1ul<<(MUX0));
	//avcc is voltage reference
	//set adc input channel to adc1
	ADCSRA|=(1ul<<(ADEN))|(1ul<<(ADSC))|(1ul<<(ADATE))|(1ul<<(ADIE))|(1ul<<(ADPS2))|(1ul<<(ADPS1))|(1ul<<(ADPS0));
	//enable the thing
	//set it to free runnig mode continuous conversions
	//enable the interrupt
	//then set the presecaler to 125 (16khz/125=125khz)
	//ADCSRA|=(1ul<<(ADSC));
}
int get_adc_result(){
// 	int adc_value;
// 	adc_value = ADC;
// 	return adc_value;
	return ADC;
	//my pwm will be expecting an 8 bit number so no need for the two bits in the lowwer register
	
	//could make this an int 
	//int high,low;
	//low=ADCL
	//high=ADCH
	//return (high << 8) | low;
}