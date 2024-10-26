/*
 * fsm.c
 *
 *  Created on: Oct 25, 2024
 *      Author: HOME
 */
#include "fsm_auto.h"

//int timeRed = 5, timeYellow = 2, timeGreen = 3;


void fsm_auto_run(){
//				if(flag[0] == 1){
//					setTimer(0, 3000);
//					status = green;
//					HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin );
//					HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin );
//					HAL_GPIO_TogglePin(G0_GPIO_Port, G0_Pin);
//				}
	switch (status) {
		case init:
			// to do
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			status = red;
			setTimer(0, 5000);
			break;
		case red:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			if(flag[0] == 1){
				setTimer(0, 3000);
				status = green;
			}
			break;
		case green:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
			if(flag[0] == 1){
				setTimer(0, 2000);
				status = yellow;
			}
			break;
		case yellow:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			if(flag[0] == 1){
				setTimer(0, 5000);
				status = red;
			}
			break;
		default:
			break;
	}
}

