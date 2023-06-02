/*
 * SysTick.c
 *
 *  Created on: Apr 24, 2022
 *      Author: ADMIN
 */
#include "../include.h"
#include "SysTick.h"


void Config_SysTick(void)
{
    SysTickPeriodSet(SysCtlClockGet()/1000);
    SysTickEnable();
    SysTickIntEnable();
    IntMasterEnable();
}

void SysTickInt_ISR(void)
{
    if (Timer>0)    Timer--;
}
