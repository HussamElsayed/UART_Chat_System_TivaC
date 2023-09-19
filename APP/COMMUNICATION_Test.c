#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "MCAL/GPIO/GPIO.h"
#include "HAL/BUTTONS/BUTTONS.h"
#include "HAL/LEDS/LEDS.h"
#include "HAL/COMMUNICATION_Manager/COMMUNICATION_Manager.h"
#include "HAL/COMMUNICATION_Manager/COMMUNICATION_Manager_Config.h"
#include "COMMUNICATION_Test.h"

static uint8_t str[BUFFER_SIZE]; /*string buffer on source1*/
static uint8_t str2[BUFFER_SIZE]; /*string buffer on source2*/
static State_t currentState;    /*this variable determine current state of the app*/
static bool isInitialEntery;

static bool rightButtonPressed = false;
static bool leftButtonPressed = false;

void checkButtonsPressed(void);

void COMMUNICATION_Test_Init(void)
{

    /*INIT PERIPHERALS AND HARDWARE*/
    GPIO_Init();
    COMMUNICATION_Init();
    BUTTONS_Init();
    LEDS_Init();

    /*INIT APP INITIAL STATE*/
    currentState = OFF_STATE;
    isInitialEntery = true;

}
void COMMUNICATION_Test_Runnable(void)
{
    switch (currentState)
    {
    case OFF_STATE:
        handleOffState();
        break;
    case ON_STATE:
        handleOnState();
        break;
    case LISTEN_STATE:
        handleListenState();
        break;
    default:
        break;
    }
    checkButtonsPressed();
}

/*this function handle OFF state*/

void handleOffState(void)
{
    if (isInitialEntery == true)
    {
        RedLedON();
        isInitialEntery = false;
    }
    recieveStringSource1NoBlock(str, UART);
    recieveStringSource2NoBlock(str2, UART);
}

/*this function handle ON state*/

void handleOnState(void)
{
    if (isInitialEntery == true)
    {
        WhiteLedON();
        isInitialEntery = false;
    }

    if (recieveStringSource1NoBlock(str, UART) == FINISHED)
    {
        sendStringSource2(str, UART);
        sendStringSource1("- Sent String: ", UART, false);
        sendStringSource1(str, UART, true);
    }
    if (recieveStringSource2NoBlock(str2,UART) == FINISHED)
    {
        sendStringSource1("- Received String: ", UART, false);
        sendStringSource1(str2, UART, true);
    }
}

/*this function handle Listen state*/
void handleListenState(void)
{
    if (isInitialEntery == true)
    {
        BlueLedON();
        isInitialEntery = false;
    }

    recieveStringSource1NoBlock(str, UART);
    if (recieveStringSource2NoBlock(str2, UART) == FINISHED)
    {
        sendStringSource1("Received String: ", UART, false);
        sendStringSource1(str2, UART, true);
    }
}

void checkButtonsPressed(void)
{
    /*right button pressed*/
    if (getRightButtonPressed() == true)
    {
        if (rightButtonPressed == false)
        {
            isInitialEntery = true;
            if (currentState == ON_STATE)
            {
                currentState = OFF_STATE;
            }
            else
            {
                currentState = (State_t) ((uint32_t) currentState + 1);
            }
            rightButtonPressed = true;
        }
    }
    else
    {
        rightButtonPressed = false;
    }

    /*left button pressed*/
    if (getLeftButtonPressed() == true)
    {
        if (leftButtonPressed == false)
        {
            isInitialEntery = true;
            if (currentState == OFF_STATE)
            {
                currentState = ON_STATE;
            }
            else
            {
                currentState = (State_t) ((uint32_t) currentState - (uint32_t)1);
            }
            leftButtonPressed = true;
        }
    }
    else
    {
        leftButtonPressed = false;
    }
}
