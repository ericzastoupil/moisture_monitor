#include "sensor.h"
#include <assert.h>
#include <stdio.h>

int main(){

    //Test reading is within bounds
    float reading = sensor_read_moisture();
    assert(reading >= 0.0f && reading <= 100.0f);

    printf("PASS\n");
    return 0;
}