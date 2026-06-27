all: tests/test_mem_pool tests/test_ring_buffer tests/test_scheduler tests/test_hal tests/test_sensor

tests/test_mem_pool: tests/test_mem_pool.c platform/mem_pool.c platform/mem_pool.h
	gcc -Wall -Wextra tests/test_mem_pool.c platform/mem_pool.c -I platform -lm -o tests/test_mem_pool

tests/test_ring_buffer: tests/test_ring_buffer.c platform/ring_buffer.c platform/ring_buffer.h
	gcc -Wall -Wextra tests/test_ring_buffer.c platform/ring_buffer.c -I platform -lm -o tests/test_ring_buffer

tests/test_scheduler: tests/test_scheduler.c platform/scheduler.c platform/scheduler.h
	gcc -Wall -Wextra tests/test_scheduler.c platform/scheduler.c -I platform -lm -o tests/test_scheduler

tests/test_hal: tests/test_hal.c hal/hal_adc.c hal/hal_adc.h
	gcc -Wall -Wextra tests/test_hal.c hal/hal_adc.c -I hal -lm -o tests/test_hal

tests/test_sensor: tests/test_sensor.c hal/sensor.c hal/sensor.h hal/hal_adc.c hal/hal_adc.h
	gcc -Wall -Wextra tests/test_sensor.c hal/sensor.c hal/hal_adc.c hal/hal_adc.h -I hal -lm -o tests/test_sensor

clean:
	rm -f tests/test_mem_pool tests/test_ring_buffer tests/test_scheduler tests/test_hal tests/test_sensor