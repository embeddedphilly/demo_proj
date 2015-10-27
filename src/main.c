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
    CPU_PRESCALE(0x01);
    sei();

    DDRB &= ~(0x04); //B2 is an input
    PORTB &= ~(0x04); //B2 has no pull-up resistor
    DDRF &= ~(0x02); //F1 is an input
    PORTF &= ~(0x02); //F1 has no pull-up resistor
    DDRE &= ~(0x01); //E0 is an input
    PORTE &= ~(0x01); //E0 has no pull-up resistor
    DDRB &= ~(0x80); //B7 is an input
    PORTB &= ~(0x80); //B7 has no pull-up resistor

    DDRD |= 0x02; //D1 is an output
    DDRC |= 0x80; //C7 is an output
    DDRF |= 0x20; //F5 is an output
    DDRB |= 0x10; //B4 is an output

    while (1)
    {
        //check value of B2
        if (PINB & 0x04)
        {
            PORTB |= 0x10; //set B4 to HIGH
        }
        else
        {
            PORTB &= ~(0x10); //set B4 to LOW
        }

        //check value of F1
        if (PINF & 0x02)
        {
            PORTF |= 0x20; //set F5 to HIGH
        }
        else
        {
            PORTF &= ~(0x20); //set F5 to LOW
        }

        //check value of E0
        if (PINE & 0x01)
        {
            PORTC |= 0x80; //set C7 to HIGH
        }
        else
        {
            PORTC &= ~(0x80); //set C7 to LOW
        }

        //check value of B7
        if (PINB & 0x80)
        {
            PORTD |= 0x02; //set D1 to HIGH
        }

        else
        {
            PORTD &= ~(0x02); //set D1 to LOW
        }

    }
    return 0;
}

