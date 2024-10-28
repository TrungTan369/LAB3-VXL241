/*
 * fsm_manual.c
 *
 *  Created on: Oct 28, 2024
 *      Author: HOME
 */

#include "fsm_manual.h"

void fsm_manual(){
	switch (MANUAL_STATE) {
		case LINE1_GO:
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			if(isButtonPress3() == 1){
				MANUAL_STATE = LINE2_GO;
			}
			break;
		case LINE2_GO:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			if(isButtonPress3() == 1){
				MANUAL_STATE = LINE1_GO;
			}
			break;
		default:
			break;
	}
	if(manual_mode != 1){
		if((isButtonPress3() == 1)){ // BEGIN MODE MANUAL
			manual_mode = 1;
			STATUS_LINE1 = -1;
			STATUS_LINE2 = -1;
			MANUAL_STATE = LINE1_GO;
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			return;
		}
	}
	if(manual_mode == 1){
		if((isButtonPress1() == 1)){  // OUT MODE MANUAL
			manual_mode = 0;
			STATUS_LINE1 = auto_init;
			STATUS_LINE2 = auto_init;
			MANUAL_STATE = -1;
		}
	}

}
