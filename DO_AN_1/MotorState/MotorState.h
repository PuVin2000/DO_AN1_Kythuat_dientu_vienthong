/*
 * Motor.h
 *
 *  Created on: May 24, 2022
 *      Author: ADMIN
 */

#ifndef MOTORSTATE_MOTORSTATE_H_
#define MOTORSTATE_MOTORSTATE_H_

#include <stdint.h>

void StateMotorUpdate(void);

typedef     enum {  S_MotorOFF=0, S_MotorOFF_WAIT1, S_MotorOFF_WAIT2,
                    S_Forward, S_Forward_WAIT1,S_Forward_WAIT2,
                    S_Reverse, S_Reverse_WAIT1,S_Reverse_WAIT2}  MotorState_t;

extern MotorState_t State ;
extern uint32_t Timer ;

#endif /* MOTORSTATE_MOTORSTATE_H_ */
