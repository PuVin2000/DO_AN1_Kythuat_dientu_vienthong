/*
 * PWM.c
 *
 *  Created on: Apr 23, 2022
 *      Author: ADMIN
 */

#include "PWM.h"
#include "../include.h"

void Config_PWM(void)
{
    Period = SysCtlClockGet();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);// khởi tạo port F
    GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4); // cấu hình chân PF1(Led đỏ) là PWM

    SysCtlPWMClockSet(SYSCTL_PWMDIV_1); //tạo xung pwm với độ chia =1
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);// chân PF1 ứng với module PWM1
    GPIOPinConfigure(GPIO_PE4_M0PWM4);

    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN|PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Period);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    //
    GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); // cấu hình chân PF1(Led đỏ) là PWM

    SysCtlPWMClockSet(SYSCTL_PWMDIV_1); //tạo xung pwm với độ chia =1
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);// chân PF1 ứng với module PWM1
    GPIOPinConfigure(GPIO_PE5_M0PWM5);

    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN|PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Period);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);
}

void Control_PWM(void)
{
    if(Duty==0)
    {
        PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, false);
        UARTprintf("Duty= %d\n",Duty);
    }
    else
    {
        PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, Period*Duty/20);
        PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true);
        lcd_gotoxy(1,1);
        lcd_puts("Toc do:");
        lcd_put_num(Duty*10,0,0);
        lcd_putc(0x25);
        UARTprintf("Duty= %d\n",Duty);
        UARTprintf("S= %d\n",S);
    }
}

void Update_PWM(uint8_t *pNum)
{
    Duty=*pNum;
}

