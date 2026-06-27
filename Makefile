.PHONY: all clean
CC = gcc
CFLAGS = -Wall -Wextra -lm
IFLAGS = -I platform -I hal

all: tests/test_mem_pool tests/test_ring_buffer tests/test_scheduler tests/test_hal tests/test_sensor app/app

test: tests/test_mem_pool tests/test_ring_buffer tests/test_scheduler tests/test_hal tests/test_sensor
	./tests/test_mem_pool 
	./tests/test_ring_buffer 
	./tests/test_scheduler
	./tests/test_hal 
	./tests/test_sensor

run: app/app
	./app/app

tests/test_mem_pool: tests/test_mem_pool.c platform/mem_pool.c platform/mem_pool.h
	$(CC) $(CFLAGS) $< platform/mem_pool.c $(IFLAGS) -o $@

tests/test_ring_buffer: tests/test_ring_buffer.c platform/ring_buffer.c platform/ring_buffer.h
	$(CC) $(CFLAGS) $< platform/ring_buffer.c $(IFLAGS) -o $@

tests/test_scheduler: tests/test_scheduler.c platform/scheduler.c platform/scheduler.h
	$(CC) $(CFLAGS) $< platform/scheduler.c $(IFLAGS) -o $@

tests/test_hal: tests/test_hal.c hal/hal_adc.c hal/hal_adc.h
	$(CC) $(CFLAGS) $< hal/hal_adc.c $(IFLAGS) -o $@

tests/test_sensor: tests/test_sensor.c hal/sensor.c hal/sensor.h hal/hal_adc.c hal/hal_adc.h
	$(CC) $(CFLAGS) $< hal/sensor.c hal/hal_adc.c $(IFLAGS) -o $@

app/app: app/app.c hal/sensor.c hal/sensor.h platform/ring_buffer.c platform/ring_buffer.h platform/scheduler.c platform/scheduler.h platform/mem_pool.c platform/mem_pool.h 
	$(CC) $(CFLAGS) $< hal/sensor.c hal/hal_adc.c platform/ring_buffer.c platform/scheduler.c platform/mem_pool.c $(IFLAGS) -o $@

clean:
	rm -f tests/test_mem_pool tests/test_ring_buffer tests/test_scheduler tests/test_hal tests/test_sensor app/app