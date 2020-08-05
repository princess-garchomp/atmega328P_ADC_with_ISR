#ifndef ADC_H
#define ADC_H
#include <avr/interrupt.h>
// #include <stdint.h>

void adc_config();
int get_adc_result();

#endif