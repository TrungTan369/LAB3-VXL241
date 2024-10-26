/*
 * button.c
 *
 *  Created on: Oct 25, 2024
 *      Author: HOME
 */

#include "button.h"

int temp0 = NORMAL_STATE;
int temp1 = NORMAL_STATE;
int temp2 = NORMAL_STATE;

int temp3 = NORMAL_STATE;
int timePress = 200;
void getKeyinput(){
	temp0 = temp1;
	temp1 = temp2;
	temp2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if((temp0 == temp1) && (temp1 == temp2)){
		if(temp3 != temp2){
			temp3 = temp2;
			if(temp2 == PRESS_STATE){
				supKeyProcess();
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress == 0){
				//todo
				if(temp2 == PRESS_STATE){
					supKeyProcess();
				}
				timePress = 200;
			}
		}
	}
}
void supKeyProcess(){
	//todo
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
}
