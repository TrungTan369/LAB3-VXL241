/*
 * setTimeTraffic.c
 *
 *  Created on: Oct 27, 2024
 *      Author: HOME
 */

#include "setTimeTraffic.h"

int key = -1;
void set(){
	if(isButtonPress() == 1){
		setting = 1;
	}
}
void fsm_setting(){
	if(isButtonPress() == 1){
		HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
		HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
		HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
		setting = 1;
		updateClockBuffer(0, 0);
		key++;
	}
	switch (key) {
		case begin:
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
			key = setRed;

		case setRed:
			if(isButtonPress() == 2){
				timeRed += 1000;
				updateClockBuffer(timeRed/1000, timeRed/1000);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); // DEBUG
			}
			if(flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
				HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
				setTimer(3, 250);
			}
			break;
		case setYellow:
			if(isButtonPress() == 2){
				timeYellow += 1000;
				updateClockBuffer(timeYellow/1000, timeYellow/1000);
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); // DEBUG
			}
			if(flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
				HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
				setTimer(3, 250);
			}
			break;
		case setGreen:
			if(isButtonPress() == 2){
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
			if( (timeRed != 0) && (timeRed == timeYellow + timeGreen)){
				key = -1;
				status_0 = init;
				setting = 0;
				return;
			}
			key = begin;
			break;
		default:
			break;
	}
}
