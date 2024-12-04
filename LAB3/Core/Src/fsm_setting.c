#include "fsm_setting.h"
int flag=0;
void fsm_setting_run(){
	switch(status){
		case SET_RED:
			if(isButtonPressed(0)){
				status = SET_GREEN;
				time_set=5;
				OFF();
				flag=0;
			}
			if(isButtonPressed(1)){
				time_set++;
				if(time_set>99) time_set=99;
			}
			if(isButtonPressed(2)){
				flag=1;
			}
			LED_scan();
			display7SEG();
			if(flag==1){
				if(timer_flag[3]==1){
					traffic_light();
					setTimer(3,250);
				}
				if(timer_flag[2]==1){
					setTimer(2,time_set*1000);
					OFF();
					flag=0;
				}
			}
			break;
		case SET_GREEN:
			if(isButtonPressed(0)){
				status = SET_YELLOW;
				time_set=5;
				OFF();
				flag=0;
			}
			if(isButtonPressed(1)){
				time_set++;
				if(time_set>99) time_set=99;
			}
			if(isButtonPressed(2)){
				flag=1;
			}
			LED_scan();
			display7SEG();
			if(flag==1){
				if(timer_flag[3]==1){
					traffic_light();
					setTimer(3,250);
				}
				if(timer_flag[2]==1){
					setTimer(2,time_set*1000);
					OFF();
					flag=0;
				}
			}
			break;
		case SET_YELLOW:
			if(isButtonPressed(0)){
				status = MAN_RED_GREEN;
				time_set=0;
				OFF();
				flag=0;
			}
			if(isButtonPressed(1)){
				time_set++;
				if(time_set>99) time_set=99;
			}
			if(isButtonPressed(2)){
				flag=1;
			}
			LED_scan();
			display7SEG();
			if(flag==1){
				if(timer_flag[3]==1){
					traffic_light();
					setTimer(3,250);
				}
				if(timer_flag[2]==1){
					setTimer(2,time_set*1000);
					OFF();
					flag=0;
				}
			}
			break;
		default:
			break;
	}
}
