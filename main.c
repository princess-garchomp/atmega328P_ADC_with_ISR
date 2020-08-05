#include "I_O_board.h"
#include "button_state_eval.h"
#include "adc.h"



#define DEBOUNCE_THRESHOLD 50

switch_state g_A_switch_state = WAIT_FOR_PUSH;
switch_state g_E_switch_state = WAIT_FOR_PUSH;

int g_A_switch_debounce =0;
int g_E_switch_debounce =0;


int g_color_1_counter = 0;
int g_color_2_counter = 0;

void color_set_1();
void color_set_2();

int g_ADC_reading=0;



int main(void)
{
	cli();
	all_I_O_config();
	adc_config();
	sei();

	while (1)
	{
			second_rgb_led_color(WHITE);
			first_rgb_led_color(WHITE);
		buton_stae_eval_fsm(&g_A_switch_state, &g_A_switch_debounce, A_is_pressed(), DEBOUNCE_THRESHOLD);
 		buton_stae_eval_fsm(&g_E_switch_state, &g_E_switch_debounce, E_is_pressed(), DEBOUNCE_THRESHOLD);

	}
}

void color_set_1(){
	if((g_A_switch_state==PUSHED)){
		g_color_1_counter = (g_color_1_counter + 1)%8;
		first_rgb_led_color(g_color_1_counter);
	}
	else{}
}

void color_set_2(){
	if((g_E_switch_state==PUSHED)){
		g_color_2_counter = (g_color_2_counter + 1)%8;
		second_rgb_led_color(g_color_2_counter);
	}
	else{}
}
ISR(ADC_vect){
	//int yes=0;
	g_ADC_reading=get_adc_result();
	//yes = ADC;
	if(g_ADC_reading>6){
				first_rgb_led_color(MAGENTA);
				second_rgb_led_color(MAGENTA);
	}

}