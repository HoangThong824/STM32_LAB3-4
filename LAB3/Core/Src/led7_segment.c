#include "led7_segment.h"
const unsigned int MAX_LED = 4;
int led_buffer[4] = {1, 2, 3, 4};
//int time_set;

int index = 0;

void updateLedBuffer(int mode) {
	if(mode!=0){
		led_buffer[0] = time_set/10;
		led_buffer[1] = time_set % 10;
		led_buffer[2] = 0;
		led_buffer[3] = mode;
	}else{
		led_buffer[0] = 0;
		led_buffer[1] = time1;
		led_buffer[2] = 0;
		led_buffer[3] = time2;
	}
}
const uint8_t digit[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};
void update7SEG (int index ){
	switch (index) {
		case 0:
			displayDigit(led_buffer[0]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
			break;
		case 1:
			displayDigit(led_buffer[1]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
			break;
		case 2:
			displayDigit(led_buffer[2]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
			break;
		case 3:
			displayDigit(led_buffer[3]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			break;
		default:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
			break;
	}
}
void displayDigit(uint8_t num) {
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, digit[num][0] ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, digit[num][1] ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, digit[num][2] ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, digit[num][3] ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, digit[num][4] ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, digit[num][5] ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, digit[num][6] ? GPIO_PIN_RESET : GPIO_PIN_SET);

}
void LED_scan(){
	if(timer_flag[3] == 1){
		 setTimer(3,250);
		 update7SEG(index);
		 index++;
		 if(index>3){
			 index=0;
		 }
	}
}
void display7SEG(){
	switch (status){
		case AUTO_RED_GREEN:
			if(timer_flag[2] == 1){
				if(time1 && time2>=0){
				updateLedBuffer(0);
				time1--;
				time2--;
				if( (time1 <= 0))	time1=2;
				setTimer(2,1000);
				}else {
				time1=3;
				time2=5;
				}
			}
			break;
		case AUTO_RED_YELLOW:
			if(timer_flag[2] == 1){
				if(time1>=0 && time2>=0){
				updateLedBuffer(0);
				time1--;
				time2--;
				if((time1<=0) &&(time2 <= 0)){
					time2=3;
					time1=5;
				}
				setTimer(2,1000);
				}else{
					time1=2;
					time2=2;
				}
			}
			break;
		case AUTO_GREEN_RED:
			if(timer_flag[2] == 1){
				if(time1>=0 && time2>=0){
				updateLedBuffer(0);
				time1--;
				time2--;
				if(time2<=0){
					time2=2;
				}
				setTimer(2,1000);
				}else{
					time1=5;
					time2=3;
				}
			}
			break;
		case AUTO_YELLOW_RED:
			if(timer_flag[2] == 1){
				if(time1>=0 && time2>=0){
				updateLedBuffer(0);
				time1--;
				time2--;
				if((time1<=0) &&(time2 <= 0)){
					time2=5;
					time1=3;
				}
				setTimer(2,1000);
				}else{
					time1=2;
					time2=2;
				}
			}
			break;
		case SET_RED:
			 updateLedBuffer(1);
			 break;
		case SET_GREEN:
			 updateLedBuffer(2);
			 break;
		case SET_YELLOW:
			 updateLedBuffer(3);
			 break;
		case MAN_RED_GREEN:
			 updateLedBuffer(4);
			 break;
		case MAN_GREEN_RED:
			 updateLedBuffer(4);
			 break;
	}
}
