#include <stdio.h>
#include <assert.h>
#include "hal_adc.h"

int main(){

    //Test return on bad channel
    uint16_t reading = hal_adc_read(1);
    assert(reading == MAX_ADC_RESOLUTION);
    
    //Test return on good channel
    reading = hal_adc_read(0);
    assert(reading >= 1200 && reading <= 3200);

    printf("PASS\n");
    return 0;
}