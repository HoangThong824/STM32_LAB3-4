

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>
typedef struct {
		// Pointer to the task (must be a ’ void (void) ’ function )
		void ( * pTask) ( void ) ;
		// Delay (ticks ) until the function w ill ( next ) be run
		uint32_t Delay ;
		// Interval (ticks) between subsequent runs .
		uint32_t Period ;
		// Incremented ( by scheduler ) when task i s due to execute
		uint8_t RunMe;
		// This i s a hint to solve the question below .
		uint32_t TaskID ;
} sTask ;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS] ;

void SCH_INIT(void);
uint32_t SCH_Add_Task( void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Task(uint32_t taskID);



#endif /* INC_SCHEDULER_H_ */
