/*
 * timer.c
 *
 *  Created on: Oct 24, 2024
 *      Author: HOME
 */

#include "timer.h"

int counter[2] = {0,0};
int flag[2] = {0,0};
void setTimer(int timer, int duration){
	counter[timer] = duration / 10;
	flag[timer] = 0;
}

void timer_run(){
	if(counter[0] > 0){
		counter[0]--;
		if(counter[0] == 0)
			flag[0] = 1;
	}
	if(counter[1] > 0){
		counter[1]--;
		if(counter[1] == 0)
			flag[1] = 1;
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	timer_run();
}
