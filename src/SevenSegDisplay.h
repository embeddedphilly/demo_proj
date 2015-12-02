/************************************************************************//**
 *
 * \file <FILENAME>
 *
 * \addtogroup <SevenSegDisplay> <SevenSegDisplay>
 * \{
 *
 * \brief
 *
 * \note
 *
 * \author Gabrielle Trotter
 * \date 12.1.15
 *
 ****************************************************************************/

#ifndef SevenSegDisplay_H
#define SevenSegDisplay_H

/****************************************************************************
 *                              INCLUDE FILES                               *
 ****************************************************************************/
#include "types.h"

/****************************************************************************
 *                     EXPORTED TYPES and DEFINITIONS                       *
 ****************************************************************************/
#define SEGMENT_A 0x80
#define SEGMENT_B 0x40
#define SEGMENT_C 0x20
#define SEGMENT_D 0x10
#define SEGMENT_E 0x08
#define SEGMENT_F 0x04
#define SEGMENT_G 0x02
#define SEGMENT_DP 0x01


//Digit 2 Port / Pin Definitions
#define D2_SEG_A_PIN GPIO_PIN5
#define D1_SEG_B_PIN GPIO_PIN0
#define D1_SEG_C_PIN GPIO_PIN7
#define D1_SEG_D_PIN GPIO_PIN4
#define D1_SEG_E_PIN GPIO_PIN3
#define D1_SEG_F_PIN GPIO_PIN1
#define D1_SEG_G_PIN GPIO_PIN2
#define D1_SEG_DP_PIN GPIO_PIN6

#define D1_SEG_A_PORT GPIO_PORTD
#define D1_SEG_B_PORT GPIO_PORTD
#define D1_SEG_C_PORT GPIO_PORTD
#define D1_SEG_D_PORT GPIO_PORTD
#define D1_SEG_E_PORT GPIO_PORTD
#define D1_SEG_F_PORT GPIO_PORTD
#define D1_SEG_G_PORT GPIO_PORTD
#define D1_SEG_DP_PORT GPIO_PORTD

typedef enum
{
    SSD_STATE_IDLE,
    //more states should be added...
} SSD_STATE;

/****************************************************************************
 *                              EXPORTED DATA                               *
 ****************************************************************************/

/****************************************************************************
 *                     EXPORTED FUNCTION DECLARATIONS                       *
 ****************************************************************************/
void SSD_Init(void);
void SSD_Tick(void);
void SSD_SetDisplay(uint8_t id, uint8_t data);


#endif // SevenSegDisplay_H

/** \}*/
