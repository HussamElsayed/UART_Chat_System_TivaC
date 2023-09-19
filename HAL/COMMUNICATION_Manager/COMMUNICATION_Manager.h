#ifndef HAL_COMMUNICATION_MANAGER_H_
#define HAL_COMMUNICATION_MANAGER_H_

typedef enum
{
    UART,I2C
} Communication_t;

typedef enum
{
    RECIEVING,
    FINISHED

} Recevie_Status_t;

void COMMUNICATION_Init(void);
void sendStringSource1(uint8_t *str, Communication_t source,bool newLine);
void sendStringSource2(uint8_t *str,Communication_t source);
Recevie_Status_t recieveStringSource1NoBlock(uint8_t *str,Communication_t source);
Recevie_Status_t recieveStringSource2NoBlock(uint8_t *str,Communication_t source);

#endif /* HAL_COMMUNICATION_MANAGER_H_ */
