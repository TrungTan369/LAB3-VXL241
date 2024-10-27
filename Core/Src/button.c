/*
 * button.c
 *
 *  Created on: Oct 25, 2024
 *      Author: HOME
 */

#include "button.h"

int key1_temp0 = NORMAL_STATE;
int key1_temp1 = NORMAL_STATE;
int key1_temp2 = NORMAL_STATE;
int key1_temp3 = NORMAL_STATE;

int key2_temp0 = NORMAL_STATE;
int key2_temp1 = NORMAL_STATE;
int key2_temp2 = NORMAL_STATE;
int key2_temp3 = NORMAL_STATE;

int key3_temp0 = NORMAL_STATE;
int key3_temp1 = NORMAL_STATE;
int key3_temp2 = NORMAL_STATE;
int key3_temp3 = NORMAL_STATE;

int timePress = 0;
int buttonFlag1 = 0;
int buttonFlag2 = 0;
int buttonFlag3 = 0;

void getKeyinput(){
	//-----PROCESS BUTTON 1------------
	key1_temp0 = key1_temp1;
	key1_temp1 = key1_temp2;
	key1_temp2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if((key1_temp0 == key1_temp1) && (key1_temp1 == key1_temp2)){
		if(key1_temp3 != key1_temp2){
			key1_temp3 = key1_temp2;
			if(key1_temp2 == PRESS_STATE){
				buttonFlag1 = 1;
				supKeyProcess();
			}
		}
	}
	// ----PROCESS BUTTON 2-----------
	key2_temp0 = key2_temp1;
	key2_temp1 = key2_temp2;
	key2_temp2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	if((key2_temp0 == key2_temp1) && (key2_temp1 == key2_temp2)){
		if(key2_temp3 != key2_temp2){
			key2_temp3 = key2_temp2;
			if(key2_temp2 == PRESS_STATE){
				buttonFlag2 = 2;
				supKeyProcess();
			}
		}
	}
	// ----- PROCESS BUTTON 3 -----------
	key3_temp0 = key3_temp1;
	key3_temp1 = key3_temp2;
	key3_temp2 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
	if((key3_temp0 == key3_temp1) && (key3_temp1 == key3_temp2)){
		if(key3_temp3 != key3_temp2){
			key3_temp3 = key3_temp2;
			if(key3_temp2 == PRESS_STATE){
				buttonFlag3 = 3;
				supKeyProcess();
			}
		}
	}
}
int isButtonPress(){
	if(buttonFlag1 == 1){
		buttonFlag1 = 0;
		return 1;
	}
	if(buttonFlag2 == 2){
		buttonFlag2 = 0;
		return 2;
	}
	if(buttonFlag3 == 3){
		buttonFlag3 = 0;
		return 3;
	}
	return 0;
}
void supKeyProcess(){
	//todo
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
}
