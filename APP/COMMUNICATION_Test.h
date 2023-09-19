

#ifndef APP_COMMUNICATION_TEST_H_
#define APP_COMMUNICATION_TEST_H_
typedef enum {
    OFF_STATE = 0,
    LISTEN_STATE,
    ON_STATE,
}State_t;

typedef enum {
    L_B,
    R_B
}Transision_t;

void COMMUNICATION_Test_Init(void);
void COMMUNICATION_Test_Runnable(void);


/*states functions */
void handleOffState(void);
void handleListenState(void);
void handleOnState(void);
Transision_t getTransition(void);





#endif /* APP_COMMUNICATION_TEST_H_ */
