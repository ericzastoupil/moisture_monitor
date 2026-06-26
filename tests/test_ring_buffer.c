#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "ring_buffer.h"

int main(){

    RingBuffer rb;
    rb_init(&rb);

    //Testing init works as expected
    assert(rb.head == 0);
    assert(rb.tail == 0);
    for (int i = 0; i < RING_CAPACITY; i++){
        assert(rb.buf[i] == 0.0f);
    }

    //Testing rb_is_empty and rb_is_full work on an empty buf
    assert(rb_is_empty(&rb) == true);
    assert(rb_is_full(&rb) == false);

    //Testing rb_average on an empty buf
    assert(rb_average(&rb) == 0.0f);

    //Testing rb_read works on an empty buf
    float data;
    assert(rb_read(&rb, &data) == false);

    //Testing rb_write returns true and fills the buffer for more testing
    for (int i = 0; i < RING_CAPACITY; i++){
        assert(rb_write(&rb, i) == true);
    }

    //Testing rb_is_full works as expected on a full buffer
    assert(rb_is_full(&rb) == true);

    //Testing rb_write works as expected on a full buf
    assert(rb_write(&rb, 1.0f) == false);

    //Testing rb_read works as expected with data in the buf
    rb_read(&rb, &data);
    assert(data == 0.0f);

    //Testing rb_average works expected with data in the buf
    float avg = rb_average(&rb);
    assert(fabsf(avg- 8.0f) < 0.001f);

    //Testing head and tail wrap around work as expected after reading and writing
    while(!rb_is_empty(&rb)){
        rb_read(&rb, &data);
    }

    rb_write(&rb, 1.0f);
    rb_read(&rb, &data);

    assert(data == 1.0f);

    printf("PASS\n");
}