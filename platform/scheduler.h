#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stddef.h>
#include <stdint.h>

//Defines Task struct
typedef struct Task{
    void (*fn)(void);
    uint32_t period;
    uint32_t next_run;
    uint32_t now;
} Task;

//Initializes a task- taking a function pointer and period for execution
void task_init(Task *task, void (*fn)(void), uint32_t period, uint32_t now);

//Runs the scheduler with count of tasks to run and time to run them
void scheduler_run(Task *tasks, uint32_t count, uint32_t time);

#endif