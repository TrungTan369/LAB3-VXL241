/*
 * fsm_setting.h
 *
 *  Created on: Oct 28, 2024
 *      Author: HOME
 */

#include "fsm_setting.h"



void fsm_setting(){
	if(isButtonPress1() == 1){
		HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
		HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
		HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
		setting_mode = 1;
		updateClockBuffer(0, 0);
		SETTING_STATE++;
	}
	if(setting_mode == 1){
		fsm_setting();
		return;
	}
	switch(SETTING_STATE){
		case setting_init:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
			setTimer(3, 250);
			timeRed = 0;
			timeYellow = 0;
			timeGreen = 0;
			updateClockBuffer(0, 0);
			SETTING_STATE = setRed;

		case setRed:
			if(isButtonPress2() == 1){
				timeRed += 1000;
				updateClockBuffer(timeRed/1000, timeRed/1000);
			}
			if(flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
				HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
				setTimer(3, 250);
			}
			break;
		case setYellow:
			if(isButtonPress2() == 1){
				timeYellow += 1000;
				updateClockBuffer(timeYellow/1000, timeYellow/1000);
			}
			if(flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
				HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
				setTimer(3, 250);
			}
			break;
		case setGreen:
			if(isButtonPress2() == 1){
				timeGreen += 1000;
				updateClockBuffer(timeGreen/1000, timeGreen/1000);
			}
			if(flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(G0_GPIO_Port, G0_Pin);
				HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
				setTimer(3, 250);
			}
			break;
		case checkout:
			if( (timeRed != 0) && (timeRed == timeYellow + timeGreen)){ // -----------AUTO OUTMODE AFTER SETTING ----------
				SETTING_STATE = -1;
				STATUS_LINE1 = auto_init;
				setting_mode = 0;
				return;
			}
			SETTING_STATE = setting_init;
			break;
		default:
			break;
	}
}
