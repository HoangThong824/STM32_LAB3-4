/*
 * global.h
 *
 *  Created on: Nov 4, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "timer.h"
#include "led7_segment.h"
#include "traffic_light.h"

extern int status;
extern int time_set;
extern int time1;
extern int time2;
#define INIT 1
//AUTOMATIC
#define AUTO_RED_GREEN 2
#define AUTO_RED_YELLOW 3
#define AUTO_GREEN_RED 4
#define AUTO_YELLOW_RED 5
//SETTING
#define SET_RED 11
#define SET_GREEN 12
#define SET_YELLOW 13
//MANUAL
#define MAN_RED_GREEN 21
#define MAN_GREEN_RED 22


#endif /* INC_GLOBAL_H_ */
