#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "MCAL/UART/UART.h"
#include "UTILS/STD_Types.h"
#include "COMMUNICATION_Manager_Config.h"
#include "COMMUNICATION_Manager.h"
#include "COMMUNICATION_Private.h"




void COMMUNICATION_Init(void)
{
    UART_Init();
}


/******************************** SENDING FUNCTION ***************************************/
void sendStringSource1(uint8_t *str, Communication_t source, bool newLine)
{
    uint8_t i;
    for (i = 0; str[i]; ++i)
    {
        UARTCharPut(UART0_BASE, str[i]);
    }

    if (newLine)
    {
        sendNewLine();
    }

}
void sendStringSource2(uint8_t *str, Communication_t source)
{
    uint8_t i;
    for (i = 0; str[i]; ++i)
    {
        UARTCharPut(UART3_BASE, str[i]);
    }
}

/******************************** RECIEVING FUNCTION ***************************************/

Recevie_Status_t recieveStringSource1NoBlock(uint8_t *str,
                                             Communication_t source)
{
    static uint8_t i = 0;
    static Recevie_Status_t status = RECIEVING;
    char recievedChar;
    uint32_t errorValue;
    bool charAvilable;

    if (status == FINISHED)
    {
        status = RECIEVING;
        i = 0;
    }

    if (source == UART)
    {

        charAvilable = UARTCharsAvail(UART0_BASE);
        errorValue = UARTIntStatus(UART0_BASE, false)
                & ( UART_INT_FE | UART_INT_BE);
        if ((charAvilable == true) && !(errorValue))
        {
            recievedChar = UARTCharGetNonBlocking(UART0_BASE);
            if (((recievedChar != 0x7f) && (recievedChar != 0x0D)
                    && (i < BUFFER_SIZE - 2)))
            {
                UARTCharPut(UART0_BASE, recievedChar);
                str[i] = recievedChar;
                i++;
            }
            else if (recievedChar == 0x7f && i > 0)
            {
                UARTCharPut(UART0_BASE, recievedChar);
                i--;
            }
            else if ((recievedChar == 0x0D) || (i >= BUFFER_SIZE - 2))
            {
                str[i] = 0x0D;
                i++;
                str[i] = '\0';
                sendNewLine();
                status = FINISHED;
            }
        }
        else
        {
            UARTCharGetNonBlocking(UART0_BASE);
            UARTIntClear(UART0_BASE, UART_INT_FE | UART_INT_BE);
        }
    }

    return status;
}

Recevie_Status_t recieveStringSource2NoBlock(uint8_t *str,
                                             Communication_t source)
{
    static uint8_t i = 0;
    static Recevie_Status_t status = RECIEVING;
    char recievedChar;
    uint32_t errorValue;

    if (status == FINISHED)
    {
        status = RECIEVING;
        i = 0;
    }
    if (source == UART)
    {
        bool charAvilable = UARTCharsAvail(UART3_BASE);
        errorValue = UARTIntStatus(UART3_BASE, false)
                & ( UART_INT_FE | UART_INT_BE);
        if ((charAvilable == true) && !(errorValue))
        {
            recievedChar = UARTCharGetNonBlocking(UART3_BASE);
            if (recievedChar != 0x0D)
            {
                str[i] = recievedChar;
                i++;
            }
            else
            {
                str[i] = '\0';
                status = FINISHED;
            }
        }
        else if (errorValue)
        {
            UARTCharGetNonBlocking(UART3_BASE);
            UARTIntClear(UART3_BASE, UART_INT_FE | UART_INT_BE);
        }
    }
    return status;
}

/*********************** PRIVATE FUNCTIONS ***********************************/
void sendNewLine(void)
{
    UARTCharPut((uint32_t) UART0_BASE, (unsigned char) '\r');
    UARTCharPut((uint32_t) UART0_BASE, (unsigned char) '\n');
}


