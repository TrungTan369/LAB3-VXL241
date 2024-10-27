/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: HOME
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"
#include "led_display.h"

#define init 0
#define red 1
#define yellow 2
#define green 3
#define stop 4

extern int setting; //mode setting
extern int preStatus;
extern int status_0;
extern int status_1;

#endif /* INC_GLOBAL_H_ */
