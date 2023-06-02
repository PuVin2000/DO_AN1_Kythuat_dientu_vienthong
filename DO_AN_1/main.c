

/**
 * main.c
 */

#include "include.h"
unsigned long val;

void
InitConsole(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTStdioConfig(0, 115200, 16000000);
}


int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    lcd_init();
    InitKeypad();
    Config_PWM();
    Config_SysTick();
    InitConsole();
    lcd_clear();
       // Thiet lap LCD
//    lcd_gotoxy(1,0);
//
//    lcd_puts("nguyen chi linh");
//    lcd_gotoxy(1,1);
//    val = 41001713;
//    lcd_put_num(val,0,0);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2|GPIO_PIN_3);
    while(1)
    {
       S = 2;
       StateMotorUpdate();
    }
}
