# Z Home Assistant Garden Bed Moisture Monitor

## Description
A sensor that measures moisture in the soil of a garden bed or potted plant at Z Casa.
It will record moisture level readings and report them back to HomeAssistant over MQTT.
Automations can be written against the moisture levels in HomeAssistant to tell the Z's when they need to water.

## Hardware
- ESP32 DevKitC
- Capacitive soil moisture sensor v1.2

## Structure
- moisture_monitor
    - platform/
        - mem_pool.h / mem_pool.c
        - ring_buffer.h / ring_buffer.c
        - scheduler.h / scheduler.c
    - tests/
        - test_mem_pool.c
        - test_ring_buffer.c
        - test_scheduler.c
    - Makefile
    - README.md

## Build Instructions

```bash
make 
./tests/test_mem_pool
./tests/test_ring_buffer
./tests/test_scheduler
```

## Roadmap
- [x] Build Memory Pool logic
- [x] Build Ring Buffer logic
- [x] Build Scheduler logic
- [ ] Build Hardware Abstraction Layer (HAL) logic
- [ ] Build ADC
- [ ] Build Moisture Sensor Driver
- [ ] Build MQTT Connection
- [ ] Build MQTT Publisher