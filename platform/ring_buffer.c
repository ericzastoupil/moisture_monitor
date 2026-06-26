#include <string.h>
#include "ring_buffer.h"

//Tells if RingBuffer is empty
bool rb_is_empty(const RingBuffer *rb){return (rb->head - rb->tail) == 0;}

//Tells if RingBuffer is full
bool rb_is_full(const RingBuffer *rb){return (rb->head - rb->tail) == RING_CAPACITY;}

//Initializes the RingBuffer
void rb_init(RingBuffer *rb){
    rb->head = 0;
    rb->tail = 0;
    memset(rb->buf, 0, sizeof(rb->buf));
}

//Writes data to the RingBuffer
bool rb_write(RingBuffer *rb, float data){
    if (rb_is_full(rb)) return false;
    
    rb->buf[rb->head & (RING_CAPACITY - 1)] = data;
    rb->head++;
    
    return true;
}

//Reads data from the RingBuffer
bool rb_read(RingBuffer *rb, float* data){
    if (rb_is_empty(rb)) return false;
    
    *data = rb->buf[rb->tail & (RING_CAPACITY - 1)];
    rb->tail++;
    
    return true;
}

//Takes an average of the data in the RingBuffer
float rb_average(const RingBuffer *rb){
    float sum = 0.0f;
    if (rb_is_empty(rb)) return 0.0f;

    for (size_t i = rb->tail; i < rb->head; i++){
        sum = sum + rb->buf[i & (RING_CAPACITY - 1)];
    }

    return sum/(float)(rb->head - rb->tail);
}