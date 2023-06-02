/*
 * MotorState.c
 *
 *  Created on: May 23, 2022
 *      Author: ADMIN
 */

#include "MotorState.h"
#include "../include.h"


uint32_t Timer = 0 ;

static MotorState_t State = S_MotorOFF;

static const  char *stateName[9]={
                                  "S_MotorOFF", "S_MotorOFF_WAIT1", "S_MotorOFF_WAIT2",
                                  "S_Forward","S_Forward_WAIT1","S_Forward_WAIT2",
                                  "S_Reverse","S_Reverse_WAIT1","S_Reverse_WAIT2"
                                   };


void StateMotorUpdate(void)
{
      switch (State)
      {
          case S_MotorOFF:
                  if (KeyState(42) == PRESSED)
                      {
                          State = S_MotorOFF_WAIT1;
                          Timer = 3000;       //set timer to 3 sec
                          lcd_clear();
                          lcd_gotoxy(0,0);
                          lcd_puts("S_MotorOFF_WAIT1");
                          UARTprintf("%s\n",stateName[State]);
                      }
                  else if (KeyState(35) == PRESSED)
                  {
                      State = S_MotorOFF_WAIT1;
                      Timer = 3000;       //set timer to 3 sec
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts("S_MotorOFF_WAIT1");
                      UARTprintf("%s\n",stateName[State]);
                  }
                  break;
          case S_MotorOFF_WAIT1:
                  if (KeyState(42)&KeyState(35) == RELEASED) //if switch is release before timer counting down to 0
                      {
                          State = S_MotorOFF;       //come back to OFF state
                          lcd_clear();
                          lcd_gotoxy(0,0);
                          lcd_puts("S_MotorOFF");
                          UARTprintf("%s\n",stateName[State]);
                      }
                  else if (Timer==0)
                  {
                      State = S_MotorOFF_WAIT2;
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts("S_MotorOFF_WAIT2");
                      UARTprintf("%s\n",stateName[State]);
                  }
                  break;
          case S_MotorOFF_WAIT2:
                  if (KeyState(35) == RELEASED)
                      {
                          State = S_Forward;
                          lcd_clear();
                          lcd_gotoxy(0,0);
                          lcd_puts("S_Forward");
                          UARTprintf("%s\n",stateName[State]);
                      }
                  else if (KeyState(42) == RELEASED)
                  {
                      State = S_Reverse;
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts("S_Reverse");
                      UARTprintf("%s\n",stateName[State]);
                  }
                  break;

              //S_Forward
          case S_Forward:
                  if (KeyState(0) == PRESSED)
                      {
                          State = S_Forward_WAIT1;
                          Timer = 3000;       //set timer to 3 sec
                          lcd_clear();
                          lcd_gotoxy(0,0);
                          lcd_puts("S_Forward_WAIT1");
                          UARTprintf("%s\n",stateName[State]);
                      }
                  else if (KeyState(35) == PRESSED)
                  {
                      State = S_Forward_WAIT1;
                      Timer = 3000;       //set timer to 3 sec
                      Duty=0;
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts("S_Forward_WAIT1");
                      UARTprintf("%s\n",stateName[State]);
                  }
                  break;
          case S_Forward_WAIT1:
                   if (KeyState(0)&KeyState(35) == RELEASED) //if switch is release before timer counting down to 0
                       {
                           State = S_Forward;       //come back to OFF state
                           lcd_clear();
                           lcd_gotoxy(0,0);
                           lcd_puts("S_Forward");
                           UARTprintf("%s\n",stateName[State]);
                       }
                   else if (Timer==0)
                   {
                       State = S_Forward_WAIT2;
                       lcd_clear();
                       lcd_gotoxy(0,0);
                       lcd_puts("S_Forward_WAIT2");
                       UARTprintf("%s\n",stateName[State]);
                   }
                   break;
           case S_Forward_WAIT2:
               if (KeyState(0) == RELEASED)
                   {
                       State = S_Reverse;
                       lcd_clear();
                       lcd_gotoxy(0,0);
                       lcd_puts("S_Reverse");
                       UARTprintf("%s\n",stateName[State]);
                   }
               else if (KeyState(35) == RELEASED)
               {
                   State = S_MotorOFF;
                   lcd_clear();
                   lcd_gotoxy(0,0);
                   lcd_puts("S_MotorOFF");
                   UARTprintf("%s\n",stateName[State]);
               }
               break;

               //S_Reverse
           case S_Reverse:
                 if (KeyState(0) == PRESSED)
                     {
                         State = S_Reverse_WAIT1;
                         Timer = 3000;       //set timer to 3 sec
                         lcd_clear();
                         lcd_gotoxy(0,0);
                         lcd_puts("S_Reverse_WAIT1");
                         UARTprintf("%s\n",stateName[State]);
                     }
                 else if (KeyState(42) == PRESSED)
                     {
                         State = S_Reverse_WAIT1;
                         Timer = 3000;       //set timer to 3 sec
                         Duty=0;
                         lcd_clear();
                         lcd_gotoxy(0,0);
                         lcd_puts("S_Reverse_WAIT1");
                         UARTprintf("%s\n",stateName[State]);
                     }
                 break;
           case S_Reverse_WAIT1:
                  if (KeyState(0)&KeyState(42) == RELEASED) //if switch is release before timer counting down to 0
                      {
                          State = S_Reverse;       //come back to OFF state
                          lcd_clear();
                          lcd_gotoxy(0,0);
                          lcd_puts("S_Reverse");
                          UARTprintf("%s",stateName[State]);
                      }
                  else if (Timer==0)
                  {
                      State = S_Reverse_WAIT2;
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts("S_Reverse_WAIT2");
                      UARTprintf("%s\n",stateName[State]);
                  }
                  break;
           case S_Reverse_WAIT2:
                  if (KeyState(0) == RELEASED)
                      {
                          State = S_Forward;
                          lcd_clear();
                          lcd_gotoxy(0,0);
                          lcd_puts("S_Forward");
                          UARTprintf("%s\n",stateName[State]);
                      }
                  else if (KeyState(42) == RELEASED)
                  {
                      State = S_MotorOFF;
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts("S_MotorOFF");
                      UARTprintf("%s\n",stateName[State]);
                  }
                  break;
      }
      switch (State)
      {
      case    S_MotorOFF:
      case    S_MotorOFF_WAIT1:
      case    S_MotorOFF_WAIT2:
          PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT , false);
//          PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT , false);
          break;

          //
      case  S_Forward:
      case  S_Forward_WAIT1:
      case  S_Forward_WAIT2:
          GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2 ,GPIO_PIN_2);
          GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3 ,0);
          Control_PWM();
          break;

      case  S_Reverse:
      case  S_Reverse_WAIT1:
      case  S_Reverse_WAIT2:
          GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3 ,GPIO_PIN_3);
          GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2 ,0);
          Control_PWM();
        break;
      }
}



