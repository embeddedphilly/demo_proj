/************************************************************************//** *
 * \file SevenSegDisplay.c
 *
 * \addtogroup SevenSegDisplay
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
#include "SevenSegDisplay.h"
#include "GPIOHAL.h"
#include "types.h"

/****************************************************************************
 *                     PRIVATE FUNCTION DECLARATIONS                        *
 ****************************************************************************/

/****************************************************************************
 *                              PRIVATE DATA                                *
 ****************************************************************************/
SSD_STATE MyState;

/****************************************************************************
 *                             EXTERNAL DATA                                *
 ****************************************************************************/

/****************************************************************************
 *                            EXPORTED FUNCTION DEFINITIONS                 *
 ****************************************************************************/

/************************************************************************//**
 * \brief Init Function - Initializes the module for use in the project.
 *        Sets up all variables, initializes all hardware peripherals necessary,
 *        etc.
 * \param none
 * \return none
 ****************************************************************************/

void SSD_Init(void)
{
    MyState = SSD_STATE_IDLE;
}

/************************************************************************//**
 * \brief 'ticks' the module through its internal state machine. This
 *        function should be called in the main loop of the program.
 * \param none
 * \return none
 ****************************************************************************/
void SSD_Tick(void)
{
    switch(MyState)
    {
      case SSD_STATE_IDLE:
        break;
    }
}

/************************************************************************//**
 * \brief Set the display to of the given number of the display to the correct output
 * \param id - the ID of the display character (for displays with multiple characters)
 *        data - bitfield of the data to be displayed on the device
 * \return
 ****************************************************************************/

void SSD_SetDisplay(uint8_t id, uint8_t data)
{

}


/****************************************************************************
 *                     PRIVATE FUNCTION DEFINITIONS                         *
 ****************************************************************************/

/************************************************************************//**
 * \brief
 * \param
 * \return
 ****************************************************************************/

/** \}*/
