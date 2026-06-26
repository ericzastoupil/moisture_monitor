#ifndef RING_BUF_H
#define RING_BUF_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define RING_CAPACITY 16

typedef struct RingBuffer{
    size_t head;
    size_t tail;
    float buf[RING_CAPACITY];
} RingBuffer;

//Tells if RingBuffer is empty
bool rb_is_empty(const RingBuffer *rb);

//Tells if RingBuffer is full
bool rb_is_full(const RingBuffer *rb);

//Initializes the RingBuffer
void rb_init(RingBuffer *rb);

//Writes data to the RingBuffer
bool rb_write(RingBuffer *rb, float data);

//Reads data from the RingBuffer
bool rb_read(RingBuffer *rb, float* data);

//Takes an average of the data in the RingBuffer
float rb_average(const RingBuffer *rb);

#endif