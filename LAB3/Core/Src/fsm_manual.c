#include "fsm_manual.h"

void fsm_manual_run(){

	switch(status){
			case MAN_RED_GREEN:
				traffic_light();
				display7SEG();
				LED_scan();
				if(isButtonPressed(0)){
					status=INIT;
				}
				if(isButtonPressed(1)){
					status=MAN_GREEN_RED;
				}
				break;
			case MAN_GREEN_RED:
				traffic_light();
				display7SEG();
				LED_scan();
				if(isButtonPressed(0)){
					status=INIT;
				}
				if(isButtonPressed(1)){
					status=MAN_RED_GREEN;
				}
				break;
			default:
				break;
	}
}

