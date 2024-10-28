/*
 * fsm.c
 *
 *  Created on: Oct 25, 2024
 *      Author: HOME
 */
#include "fsm_auto.h"

int count0 = 0;
int count1= 0;

void fsm_auto_run(){
	// ---------- CHECK MANUAL ---------------
	if(manual_mode == 1) return;
	// ------ CHECK SETTING -------------
	if(setting_mode == 1) return;
	// ---------- AUTO RUN ---------------------
	switch (STATUS_LINE1) {   // LINE 1
		case auto_init:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);

			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);

			STATUS_LINE1 = red;
			count0 = timeRed/1000;
			STATUS_LINE2 = green;
			count1 = timeGreen/1000;
			updateClockBuffer(count0, count1);
			setTimer(0, timeRed);
			setTimer(1, timeGreen);
			setTimer(2, 1000);
			setTimer(3, 250);
			return;
		case red:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			if(flag[0] == 1){
				STATUS_LINE1 = green;
				count0 = timeGreen/1000;
				updateClockBuffer(count0, count1);
				setTimer(0, timeGreen);
			}
			break;
		case green:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
			if(flag[0] == 1){
				STATUS_LINE1 = yellow;
				count0 = timeYellow/1000;
				updateClockBuffer(count0, count1);
				setTimer(0, timeYellow);
			}
			break;
		case yellow:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			if(flag[0] == 1){
				STATUS_LINE1 = red;
				count0 = timeRed/1000;
				updateClockBuffer(count0, count1);
				setTimer(0, timeRed);
			}
			break;
		default:
			break;
	}
	switch (STATUS_LINE2) {  // LINE 2
		case red:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
			if(flag[1] == 1){
				STATUS_LINE2 = green;
				count1 = timeGreen/1000;
				updateClockBuffer(count0, count1);
				setTimer(1, timeGreen);
			}
			break;
		case green:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			if(flag[1] == 1){
				STATUS_LINE2 = yellow;
				count1 = timeYellow/1000;
				updateClockBuffer(count0, count1);
				setTimer(1, timeYellow);
			}
			break;
		case yellow:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
			if(flag[1] == 1){
				STATUS_LINE2 = red;
				count1 = timeRed/1000;
				updateClockBuffer(count0, count1);
				setTimer(1, timeRed);
			}
			break;
		default:
			break;
	}
	if(flag[2] == 1){
		setTimer(2, 1000);
		count0 --; count1 --;
		updateClockBuffer(count0, count1);
	}
	if(flag[3] == 1){
		setTimer(3, 250);
		Scan7SEG();
	}
}

