#include "fsm_automatic.h"
#include "global.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			if(timer_flag[0] == 1){
				status = AUTO_RED_GREEN;
				setTimer(0,3000);
				time1=-1;
				time2=-1;
			}
			break;
		case AUTO_RED_GREEN:
			traffic_light();
			display7SEG();
			LED_scan();
			if(timer_flag[0] == 1){
				setTimer(0,2000);
				status = AUTO_RED_YELLOW;
			}
			if(isButtonPressed(0)){
				status = SET_RED;
				OFF();
				time_set=5;
			}
			break;
		case AUTO_RED_YELLOW:
			traffic_light();
			display7SEG();
			LED_scan();

			if(timer_flag[0]==1){
				setTimer(0,3000);
				status = AUTO_GREEN_RED;
			}

			if(isButtonPressed(0)){
				status = SET_RED;
				OFF();
				time_set=5;
			}
			break;
		case AUTO_GREEN_RED:
			traffic_light();
			display7SEG();
			LED_scan();

			if(timer_flag[0]==1){
				setTimer(0,2000);
				status = AUTO_YELLOW_RED;
			}

			if(isButtonPressed(0)){
				status = SET_RED;
				OFF();
			}
			break;
		case AUTO_YELLOW_RED:
			traffic_light();
			display7SEG();
			LED_scan();

			if(timer_flag[0] == 1){
				setTimer(0,3000);
				status = AUTO_RED_GREEN;
			}

			if(isButtonPressed(0)){
				status = SET_RED;
				OFF();
				time_set=5;
			}
			break;
		default:
			break;
	}
}
