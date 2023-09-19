#include <stdint.h>
#include <stdbool.h>
#include "MCAL/GPIO/GPIO.h"
#include "APP/COMMUNICATION_Test.h"

int main(void)
{
    COMMUNICATION_Test_Init();
    while (1)
    {
        COMMUNICATION_Test_Runnable();
    }
}
