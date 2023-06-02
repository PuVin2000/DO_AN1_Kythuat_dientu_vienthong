/*
 * KeyPad.h
 *
 *  Created on: Apr 16, 2022
 *      Author: ADMIN
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include <stdint.h>

#define RowA    GPIO_PIN_4
#define RowB    GPIO_PIN_5
#define RowC    GPIO_PIN_6
#define RowD    GPIO_PIN_7

#define Col_1   GPIO_PIN_1
#define Col_2   GPIO_PIN_2
#define Col_3   GPIO_PIN_3

extern void InitKeypad(void);
int READ_KEY(void);
int READ_STATE(void);



typedef     enum {PRESSED,RELEASED}  sw_key;
sw_key KeyState(int S_Key);

#endif /* KEYPAD_KEYPAD_H_ */
