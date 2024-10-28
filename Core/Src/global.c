/*
 * global.c
 *
 *  Created on: Oct 26, 2024
 *      Author: HOME
 */
#include "global.h"

int STATUS_LINE1 = auto_init; // BEGIN WITH AUTO MODE
int STATUS_LINE2 = auto_init;  // BEGIN WITH AUTO MODE

int SETTING_STATE = -1; // BEGIN WITHOUT SETTING
int setting_mode = 0;  // FLAG SETTING

int MANUAL_STATE = -1; // BEGIN WITHOUT MANUAL MODE
int manual_mode = 0; // FLAG MANUAL

int timeRed = 15000;	//-- TIME LED RED ON WHEN BEGIN----
int timeYellow = 5000;  //-- TIME LED YELLOW ON WHEN BEGIN----
int timeGreen = 10000;  //-- TIME LED GREEN ON WHEN BEGIN----


