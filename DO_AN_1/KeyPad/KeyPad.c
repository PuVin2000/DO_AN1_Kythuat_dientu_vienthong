/*
 * KeyPad.c
 *
 *  Created on: Apr 16, 2022
 *      Author: ADMIN
 */

#include "KeyPad.h"
#include "../include.h"

int i,j,col,m,STATE;
static uint8_t num;

int keypad[3][4] = {{42,7,4,1},
                    {0,8,5,2},
                    {35,9,6,3}};

static void SWITCH_ISR(void);

void InitKeypad(void)
{
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
   GPIOPinTypeGPIOInput(GPIO_PORTC_BASE,RowA|RowB|RowC|RowD);
//#define RowA    GPIO_PIN_4
//#define RowB    GPIO_PIN_5
//#define RowC    GPIO_PIN_6
//#define RowD    GPIO_PIN_7
   GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE,Col_1|Col_2|Col_3);
   //pin c4,c5,c6,c7 is input ;
   //pin e1,e2,e3 is output

   GPIOIntTypeSet(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_RISING_EDGE);
   GPIOIntRegister(GPIO_PORTC_BASE, &SWITCH_ISR);
   GPIOIntEnable(GPIO_PORTC_BASE, GPIO_INT_PIN_4|GPIO_INT_PIN_5|GPIO_INT_PIN_6|GPIO_INT_PIN_7);
   IntEnable(INT_GPIOC);
   IntMasterEnable();
}

int READ_STATE(void)
{
    for (m=0;m<3;m++)
    {
        GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0);
        GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1 << m , GPIO_PIN_1 << m );
        //SysCtlDelay(150000);
        if(GPIOPinRead(GPIO_PORTC_BASE,GPIO_PIN_6) == GPIO_PIN_6)
        {
            return keypad[m][0];
        }
    }
    //return 0;
}

int READ_KEY(void)
{
    for(i=0 ; i<3 ; i++)
    {
        GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0);
        GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1 << i, GPIO_PIN_1 << i);
        SysCtlDelay(150000);
        for (j=0 ; j<4 ; j++)
        {
            col = GPIOPinRead(GPIO_PORTC_BASE,GPIO_PIN_7 >> j);
            if(col == GPIO_PIN_7 >> j)
            {
                a=keypad[i][j];
                return keypad[i][j];
            }
        }
    }
}

sw_key KeyState(int S_Key)
{
    Key=READ_KEY();
    switch (S_Key)
    {
    case 0:
        if (Key==0) return PRESSED;
        else return RELEASED;
    case 42:
        if (Key==42) return PRESSED;
        else return RELEASED;
    case 35:
        if (Key==35) return PRESSED;
        else return RELEASED;
    }
}

static void SWITCH_ISR(void)
{
    if(GPIOIntStatus(GPIO_PORTC_BASE, true)==GPIO_PIN_7)
    {num=0;}
    else num=a;
    Update_PWM(&num);
    GPIOIntClear(GPIO_PORTC_BASE, GPIOIntStatus(GPIO_PORTC_BASE, true));
}

