#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "GPIO.h"

void GPIO_Init(void)
{
    /*initialize port F for Push-Buttons and LEDs */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)));
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    /*initialize port C for UART3 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC)));
    GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
    GPIOPinConfigure(GPIO_PC6_U3RX);
    GPIOPinConfigure(GPIO_PC7_U3TX);

    /*initialize port A for UART0 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)));
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);


    /*initialize port B for I2C0 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)));
    GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_2 | GPIO_PIN_3);
    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);
}

