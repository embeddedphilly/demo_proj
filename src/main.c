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

    DDRD &= ~(0xFF); //B2 is an input
    PORTB &= ~(0x04); //B2 has no pull-up resistor
    DDRF &= ~(0x02); //F1 is an input
    PORTF &= ~(0x02); //F1 has no pull-up resistor
    DDRE &= ~(0x01); //E0 is an input
    PORTE &= ~(0x01); //E0 has no pull-up resistor
    DDRB &= ~(0x80); //B7 is an input
    PORTB &= ~(0x80); //B7 has no pull-up resistor

    DDRC |= 0xFF; //Port D is all set to output
    DDRD |= 0x01;
    //All on except pin 0 and pin 1 gives us an 'A'
    // 0b11101110

    while (1)
    {
      PORTC = ~(0xFF);
    }
    return 0;
}

