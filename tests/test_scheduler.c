#include "scheduler.h"
#include <stdio.h>
#include <assert.h>

int task_run_count = 0;
void dummy_task(void){ task_run_count++; }

int main(){
    
    //Testing task_init works as expected
    Task task;
    task_init(&task, dummy_task, 1);
    assert(task.fn == dummy_task);
    assert(task.period == 1);
    assert(task.next_run == 1);

    Task tasks[8];
    tasks[0] = task;
    scheduler_run(tasks, 1, 1000);

    //Testing scheduler_run runs the task and updates next_run
    assert(tasks[0].next_run > 1);
    assert(task_run_count > 0);

    //Testing that a task that shouldn't be run, doesn't
    tasks[0].next_run = 1000000000;
    scheduler_run(tasks, 1, 1000);
    assert(task_run_count == 1);

    printf("PASS\n");
    return 0;
}