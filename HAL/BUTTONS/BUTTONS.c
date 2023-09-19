#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "MCAL/GPIO/GPIO.h"
#include "driverlib/gpio.h"

#ifndef HAL_BUTTONS_BUTTONS_C_
#define HAL_BUTTONS_BUTTONS_C_


void BUTTONS_Init(void){

}

bool getRightButtonPressed(void){
    return !(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0));
}

bool getLeftButtonPressed(void){
    return !(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4));
}

#endif /* HAL_BUTTONS_BUTTONS_C_ */
