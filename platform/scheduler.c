#include "scheduler.h"

//Initializes a task- taking a function pointer and period for execution
void task_init(Task *task, void (*fn)(void), uint32_t period, uint32_t now){
    task->fn = fn;
    task->period = period;
    task->next_run = now + period;
}

//Loops through all the tasks provided and checks to see if they need to be run
void scheduler_run(Task *tasks, uint32_t count, uint32_t time){
    for (uint32_t i = 0; i < count; i++){
        if (time >= tasks[i].next_run){
            tasks[i].fn();
            tasks[i].next_run = tasks[i].next_run + tasks[i].period; 
        }
    }
}