#include "hal_adc.h"
#include <stdlib.h>

//Takes a channel number and returns a raw ADC value
uint16_t hal_adc_read(uint8_t channel){
    uint16_t min = 1200;
    uint16_t max = 3200;

    if (channel > HAL_ADC_CHANNEL_COUNT - 1){
        return MAX_ADC_RESOLUTION;
    }

    return min + ((uint16_t)rand() % (max - min));
}