/*
 * I2C.c
 *
 *  Created on: Sep 5, 2023
 *      Author: LENOVO
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"
#include "I2C.h"


void I2C_Init(void){

    /*initializing I2C0 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_I2C0)));
    I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), true);
    I2CMasterSlaveAddrSet(I2C0_BASE, 0x3B, false);

}

