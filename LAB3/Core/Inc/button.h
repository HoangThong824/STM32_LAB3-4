
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NUM_BUTTONS 3
int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();


#endif /* INC_BUTTON_H_ */
