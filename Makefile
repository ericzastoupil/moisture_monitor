all: tests/test_mem_pool tests/test_ring_buffer

tests/test_mem_pool: tests/test_mem_pool.c platform/mem_pool.c platform/mem_pool.h
	gcc -Wall -Wextra tests/test_mem_pool.c platform/mem_pool.c -I platform -lm -o tests/test_mem_pool

tests/test_ring_buffer: tests/test_ring_buffer.c platform/ring_buffer.c platform/ring_buffer.h
	gcc -Wall -Wextra tests/test_ring_buffer.c platform/ring_buffer.c -I platform -lm -o tests/test_ring_buffer

clean:
	rm -f tests/test_mem_pool tests/test_ring_buffer