#include "traffic_light.h"
 void traffic_light(){
	 switch(status){
	 		case AUTO_RED_GREEN:
	 			//RED_ON
	 			HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, SET);
	 			HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, SET);
	 			//GREEN_ON
	 			HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, SET);
	 			HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, SET);
	 			//OFF
	 			HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
	 			break;
	 		case AUTO_RED_YELLOW:
				//RED_ON
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, SET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, SET);
				//YELLOW_ON
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, SET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, SET);
				//OFF
				HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
	 			break;
	 		case AUTO_GREEN_RED:
				//GREEN_ON
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, SET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, SET);
				//RED_ON
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, SET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, SET);
				//OFF
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);

				break;
	 		case AUTO_YELLOW_RED:
				//YELLOW_ON
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, SET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, SET);
				//RED_ON
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, SET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, SET);
				//OFF
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
	 			break;
	 		case SET_RED:
	 			//RED_BLINK
	 			HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	 			HAL_GPIO_TogglePin(LED7_GPIO_Port,LED7_Pin);
	 			HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
	 			HAL_GPIO_TogglePin(LED9_GPIO_Port,LED9_Pin);
	 			//OFF
	 			HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
	 			break;
	 		case SET_GREEN:
	 			//GREEN_BLINK
				HAL_GPIO_TogglePin(LED12_GPIO_Port,LED12_Pin);
				HAL_GPIO_TogglePin(LED6_GPIO_Port,LED6_Pin);
				HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
				HAL_GPIO_TogglePin(LED8_GPIO_Port,LED8_Pin);
				//OFF
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
	 			break;
	 		case SET_YELLOW:
	 			//YELLOW_BINK
				HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
				HAL_GPIO_TogglePin(LED5_GPIO_Port,LED5_Pin);
				HAL_GPIO_TogglePin(LED10_GPIO_Port,LED10_Pin);
				HAL_GPIO_TogglePin(LED11_GPIO_Port,LED11_Pin);
				//OFF
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
	 			break;
	 		case MAN_RED_GREEN:
				//RED_ON
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, SET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, SET);
				//GREEN_ON
				HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, SET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, SET);
				//OFF
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
				break;
	 		case MAN_GREEN_RED:
				//GREEN_ON
				HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, SET);
				HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, SET);
				//RED_ON
				HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, SET);
				HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, SET);
				//OFF
				HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
				break;
	 		default:
	 			break;
	 	}
 }
 void OFF(){
		HAL_GPIO_WritePin(LED12_GPIO_Port,LED12_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port,LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port,LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port,LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port,LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port,LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port,LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port,LED11_Pin, RESET);
	}
