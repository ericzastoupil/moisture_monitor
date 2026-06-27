#ifndef HAL_ADC_H
#define HAL_ADC_H
#include <stdint.h>

#define MAX_ADC_RESOLUTION 4095
#define HAL_ADC_CHANNEL_COUNT 1

//Takes a channel number and returns a raw ADC value
uint16_t hal_adc_read(uint8_t channel);

#endif