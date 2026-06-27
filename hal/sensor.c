#include "sensor.h"
#include "hal_adc.h"

//Returns sensor value, adjusted to be a percentage (0-100)
float sensor_read_moisture(){
    uint16_t reading = hal_adc_read(0);

    //Calculates percentage
    float moisture = (1.0f - ((float)(reading - SENSOR_WET_VALUE)/(float)(SENSOR_DRY_VALUE - SENSOR_WET_VALUE))) * 100.0f;

    //Return only within the max or min allowed percentage inclusively
    if (moisture > 100.0f) return 100.0f;
    if (moisture < 0.f) return 0.0f;
    return moisture;
}