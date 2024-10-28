/*
 * button.h
 *
 *  Created on: Oct 25, 2024
 *      Author: HOME
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESS_STATE 0

extern int buttonFlag1;
extern int buttonFlag2;
extern int buttonFlag3;

void getKeyinput();
int isButtonPress1();
int isButtonPress2();
int isButtonPress3();

#endif /* INC_BUTTON_H_ */
