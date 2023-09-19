#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "MCAL/GPIO/GPIO.h"
#include "driverlib/gpio.h"

void LEDS_Init(void)
{

}
void RedLedON(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,GPIO_PIN_1 & ~GPIO_PIN_2 & ~GPIO_PIN_3);
}
void RedLedOFF(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,~GPIO_PIN_1 & ~GPIO_PIN_2 & ~GPIO_PIN_3);
}

void BlueLedON(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, ~GPIO_PIN_1 & GPIO_PIN_2 & ~GPIO_PIN_3);
}
void BlueLedOFF(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,~GPIO_PIN_1 | ~GPIO_PIN_2 | ~GPIO_PIN_3);
}

void WhiteLedON(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
}
void WhiteLedOFF(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,~GPIO_PIN_1 | ~GPIO_PIN_2 | ~GPIO_PIN_3);
}

