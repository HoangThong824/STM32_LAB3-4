
#include "button.h"

int KeyReg0[NUM_BUTTONS];
int KeyReg1[NUM_BUTTONS];
int KeyReg2[NUM_BUTTONS];
int KeyReg3[NUM_BUTTONS];

int TimeOutForKeyPress[NUM_BUTTONS]=  {200,200,200};
int button_pressed[NUM_BUTTONS] = {0,0,0};
int button_long_pressed[NUM_BUTTONS] = {0,0,0};


int isButtonPressed(int index){
	if(button_pressed[index] == 1){
		button_pressed[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	button_pressed[index] = 1;
}

void getKeyInput(){
for(int i=0; i<NUM_BUTTONS;i++){
  KeyReg0[i] = KeyReg1[i];
  KeyReg1[i] = KeyReg2[i];
  // Add your key
  if(i==0)
  {
	  KeyReg2[0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
  }
  else if(i==1){
	  KeyReg2[1] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
  }
  else if(i==2){
	  KeyReg2[2] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
  }

  if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
              if (KeyReg3[i] != KeyReg2[i]) {
                  KeyReg3[i] = KeyReg2[i];
                  if (KeyReg2[i] == PRESSED_STATE) {
                      TimeOutForKeyPress[i] = 200;
                      subKeyProcess(i);
                  }
              } else {
                  TimeOutForKeyPress[i]--;
                  if (TimeOutForKeyPress[i] == 0) {
                      TimeOutForKeyPress[i] = 200;
                      if (KeyReg2[i] == PRESSED_STATE) {
                    	  subKeyProcess(i);
                      }
                  }
              }
          }
      }
  }
