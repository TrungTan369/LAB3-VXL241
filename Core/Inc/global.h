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

// --- AUTO --------
#define auto_init 0
#define red 1  // AUTO RED
#define yellow 2  // AUTO YELLOW
#define green 3   // AUTO GREEN
#define stop 4
extern int auto_mode;
extern int STATUS_LINE1;  // LINE 1
extern int STATUS_LINE2;  // LINE 2
//--- MANUAL MODE ------
#define manual_init 0
#define LINE1_GO 1
#define LINE2_GO 2
extern int MANUAL_STATE;
extern int manual_mode;  // FLAG MANUAL
//----SETTING -------
#define setting_init 0
#define setRed 1
#define setYellow 2
#define setGreen 3
#define checkout 4
extern int SETTING_STATE;
extern int setting_mode; //FLAG SETTING

extern int timeRed, timeYellow, timeGreen; // TIME LED ON

#endif /* INC_GLOBAL_H_ */
