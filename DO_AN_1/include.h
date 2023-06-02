/*
 * include.h
 *
 *  Created on: Apr 14, 2022
 *      Author: ADMIN
 */

#ifndef INCLUDE_H_
#define INCLUDE_H_

//thu vien ho tro ve bool, int, string va toan hoc math
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

//thu vien driver API

#include "driverlib/gpio.h"
#include "driverlib/can.h"
#include "driverlib/eeprom.h"
#include "driverlib/i2c.h"
#include "driverlib/lcd.h"
//#include "driverlib/lcd16x2.h"
#include "driverlib/mpu.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "driverlib/adc.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"
#include "driverlib/fpu.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"

//thu vien ho tro phan cung
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"

#include "LCD/LCD.h"
#include "KeyPad/KeyPad.h"
#include "PWM/PWM.h"
#include "SysTick/SysTick.h"
#include "MotorState//MotorState.h"


static   uint32_t Period;
static uint8_t Key,a,S,Duty,key;




#endif /* INCLUDE_H_ */
