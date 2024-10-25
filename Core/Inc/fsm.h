/*
 * fsm.h
 *
 *  Created on: Oct 25, 2024
 *      Author: HOME
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
#include "button.h"
#include "led_display.h"
#include "timer.h"

extern int timeRed, timeYellow, timeGreen;

void fsm_setting();
void fsm_auto();
void fsm_manual();
#endif /* INC_FSM_H_ */
