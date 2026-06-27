#ifndef SENSOR_H
#define SENSOR_H
#include <stdint.h>

#define SENSOR_DRY_VALUE 3200
#define SENSOR_WET_VALUE 1200

//Returns sensor value, adjusted to be a percentage (0-100)
float sensor_read_moisture();

#endif