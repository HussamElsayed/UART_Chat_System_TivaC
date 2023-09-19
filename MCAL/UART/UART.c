#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "UART.h"



void UART_Init(void){

    /*initializing UART0 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)));
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
    UARTEnable(UART0_BASE);

    /*initializing UART3 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_UART3)));
    UARTClockSourceSet(UART3_BASE, UART_CLOCK_PIOSC);
    UARTConfigSetExpClk(UART3_BASE, SysCtlClockGet(), 9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
    UARTEnable(UART3_BASE);

}




