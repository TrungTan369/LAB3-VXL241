/*
 * timer.h
 *
 *  Created on: Oct 24, 2024
 *      Author: HOME
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int counter[2];   // blink dot 1hz
extern int flag[2];

void setTimer(int, int);
void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *);

#endif /* INC_TIMER_H_ */
