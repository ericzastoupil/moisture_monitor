#include "sensor.h"
#include "ring_buffer.h"
#include "scheduler.h"
#include <stdio.h>
#include <time.h>

RingBuffer rb;

void task_sample(void){
    float reading = sensor_read_moisture();
    rb_write(&rb, reading);
    printf("Moisture: %.1f\n", reading);
}

void task_publish(void){
    float avg = rb_average(&rb);
    printf("Average: %.1f\n", avg);
}

uint32_t get_time_ms(void){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

int main (){
    rb_init(&rb);

    Task sample;
    task_init(&sample, task_sample, 1000, get_time_ms());

    Task publish;
    task_init(&publish, task_publish, 5000, get_time_ms());

    Task tasks[2] = {sample, publish};

    while(1){
        scheduler_run(tasks, 2, get_time_ms());
    }

    return 0;
}