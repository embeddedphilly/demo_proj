/************************************************************************//** *
 * \file main.c
 *
 * \addtogroup main
 * \{
 *
 * \brief
 *
 * \note
 *
 * \author 
 * \date 
 *
 ****************************************************************************/

/****************************************************************************
 *                              INCLUDE FILES                               *
 ****************************************************************************/
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>

/****************************************************************************
 *                     PRIVATE FUNCTION DECLARATIONS                        *
 ****************************************************************************/

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
int core(void);
/****************************************************************************
 *                              PRIVATE DATA                                *
 ****************************************************************************/



/****************************************************************************
 *                     PRIVATE FUNCTION DEFINITIONS                         *
 ****************************************************************************/

#ifdef __AVR__
int main(void)
{
  core();
}
#endif

int core(void)
{
    GPIO_HANDLE Switch1, Switch2, Switch3, Switch4, Led1, Led2, Led3, Led4;
    CPU_PRESCALE(0x01);
    sei();

    Switch1.port = GPIO_PORTB;
    Switch1.pin = GPIO_PIN2;

    Switch2.port = GPIO_PORTF;
    Switch2.pin = GPIO_PIN1;

    Switch3.port = GPIO_PORTE;
    Switch3.pin = GPIO_PIN0;

    Switch4.port = GPIO_PORTB;
    Switch4.pin = GPIO_PIN7;

    Led1.port = GPIO_PORTD;
    Led1.pin = GPIO_PIN1;

    Led2.port = GPIO_PORTC;
    Led2.pin = GPIO_PIN7;

    Led3.port = GPIO_PORTF;
    Led3.pin = GPIO_PIN5;

    Led4.port = GPIO_PORTB;
    Led4.pin = GPIO_PIN4;

    GPIO_InitInputPin(GPIO_INPUT_FLOAT, &Switch1); //switch 1 is an input float
    GPIO_InitInputPin(GPIO_INPUT_FLOAT, &Switch2); //switch 2 is an input float
    GPIO_InitInputPin(GPIO_INPUT_FLOAT, &Switch3); //switch 3 is an input float
    GPIO_InitInputPin(GPIO_INPUT_FLOAT, &Switch4); //switch 4 is an input float

    GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &Led1); //D1
    GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &Led2); //C7
    GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &Led3); //F5
    GPIO_InitOutputPin(GPIO_OUTPUT_DEFAULT, &Led4); //B4

    while (1)
    {
        //check value of B2
        if (GPIO_GetValue(&Switch1) == GPIO_HIGH)
        {
            GPIO_SetOutput(GPIO_HIGH, &Led4);
        }
        else
        {
            GPIO_SetOutput(GPIO_LOW, &Led4);
        }

        //check value of F1
        if (GPIO_GetValue(&Switch2) == GPIO_HIGH)
        {
            GPIO_SetOutput(GPIO_HIGH, &Led3);
        }
        else
        {
            GPIO_SetOutput(GPIO_LOW, &Led3);
        }

        //check value of E0
        if (GPIO_GetValue(&Switch3) == GPIO_HIGH)
        {
            GPIO_SetOutput(GPIO_HIGH, &Led2);
        }
        else
        {
            GPIO_SetOutput(GPIO_LOW, &Led2);
        }

        //check value of B7
        if (GPIO_GetValue(&Switch4) == GPIO_HIGH)
        {
            GPIO_SetOutput(GPIO_HIGH, &Led1);
        }

        else
        {
            GPIO_SetOutput(GPIO_LOW, &Led1);
        }

    }
    return 0;
}

