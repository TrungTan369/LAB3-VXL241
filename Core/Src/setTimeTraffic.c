/*
 * setTimeTraffic.c
 *
 *  Created on: Oct 27, 2024
 *      Author: HOME
 */

#include "setTimeTraffic.h"

int key = 0;
void set(){
	if(isButtonPress() == 1){
		setting = 1;
	}
}
void fsm_setting(){
	if(isButtonPress() == 1){
			setting = 1;
			key++;
			if(key >=4 ){
				setting = 0;
				status_0 = init;
				key = 0;
				return;
			}
			setTimer(3, 250);
	}
	switch (key) {
		case setRed:
			if(flag[3] == 1){
				HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
				HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
			}
			if(1)
			break;
		case setYellow:

			break;
		case setGreen:

			break;
		default:
			break;
	}
}
