/*
 * timer.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ADMIN
 */

# include "main.h"
#define MAX_COUNTER 10

int timer_flag[MAX_COUNTER];
int timer_counter[MAX_COUNTER];
int TIMER_CYCLE = 10;
void setTimer(int index, int counter){
	timer_flag[index]=0;
	timer_counter[index]=counter/TIMER_CYCLE;
}
void timerRun(){
	for(int i=0; i<MAX_COUNTER; i++){
		timer_counter[i]--;
		if(timer_counter[i]<=0){
			timer_flag[i]=1;
		}
	}
}


