/*
 * setTimeTraffic.h
 *
 *  Created on: Oct 27, 2024
 *      Author: HOME
 */

#ifndef INC_SETTIMETRAFFIC_H_
#define INC_SETTIMETRAFFIC_H_

#include "global.h"

#define begin 0
#define setRed 1
#define setYellow 2
#define setGreen 3
#define checkout 4

extern int key;
void set();
void fsm_setting();

#endif /* INC_SETTIMETRAFFIC_H_ */
