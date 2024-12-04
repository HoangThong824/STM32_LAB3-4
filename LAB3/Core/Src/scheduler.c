
#include <scheduler.h>

void SCH_Init(void) {
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
      SCH_Delete_Task(i);
    }
}
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].pTask == 0) {
            SCH_tasks_G[i].pTask = pFunction;
            SCH_tasks_G[i].Delay = DELAY;
            SCH_tasks_G[i].Period = PERIOD;
            SCH_tasks_G[i].RunMe = 0;
            SCH_tasks_G[i].TaskID = i + 1;
            return SCH_tasks_G[i].TaskID;
        }
    }
    return NO_TASK_ID;
}

void SCH_Update(void) {
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].pTask) {
            if (SCH_tasks_G[i].Delay > 0) {
                SCH_tasks_G[i].Delay --;
            } else {
                SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
                SCH_tasks_G[i].RunMe++;
            }
        }
    }
}


void SCH_Dispatch_Tasks(void) {
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].RunMe > 0) {
            (*SCH_tasks_G[i].pTask)();
            SCH_tasks_G[i].RunMe--;
            if (SCH_tasks_G[i].Period == 0) {
                SCH_Delete_Task(SCH_tasks_G[i].TaskID);
            }
        }
    }
}

uint8_t SCH_Delete_Task(uint32_t taskID) {
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].TaskID == taskID) {
            SCH_tasks_G[i].pTask = 0;
            SCH_tasks_G[i].Delay = 0;
            SCH_tasks_G[i].Period = 0;
            SCH_tasks_G[i].RunMe = 0;
            SCH_tasks_G[i].TaskID = 0;
            return 1;
        }
    }
    return 0;
}
