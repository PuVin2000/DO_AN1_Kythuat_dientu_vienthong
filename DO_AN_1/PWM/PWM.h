/*
 * PWM.h
 *
 *  Created on: Apr 23, 2022
 *      Author: ADMIN
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

#include <stdint.h>

void Config_PWM(void);
void Control_PWM(void);

void Update_PWM(uint8_t *pNum);

#endif /* PWM_PWM_H_ */
