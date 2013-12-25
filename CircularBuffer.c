#include "CircularBuffer.h"
#include "CException.h"
#include <string.h>
#include <stdio.h>

void CircularBuffer_Init(CircularBuffer* this, uint8_t* buffer, uint16_t capacity) {
    memset(buffer, 0, capacity);
    this->capacity = capacity;
    this->buffer = buffer;
    this->firstAvaliable = 0;
    this->firstValid = CIRCULAR_BUFFER_EMPTY;
}

void CircularBuffer_Add(CircularBuffer* this, uint8_t data) {
    this->buffer[this->firstAvaliable] = data;
    if (this->firstValid == CIRCULAR_BUFFER_EMPTY) {
        this->firstValid = 0;
        this->firstAvaliable=1;
    } else {
        if (this->firstAvaliable == this->firstValid) {
            //we are full now, avaliable and valid index walks together
            this->firstAvaliable++;
            if (this->firstAvaliable < this->capacity) {
                this->firstValid++;
            } else {
                this->firstAvaliable = 0;
                this->firstValid = 0;
            }
        } else {
            this->firstAvaliable++;
            if (this->firstAvaliable >= this->capacity) {
                this->firstAvaliable = 0;
            } 
        }
    }
}

uint8_t CircularBuffer_Get(CircularBuffer* this, uint16_t index) {
    //TODO what happens if the index doesn't exist 
    uint16_t realIndex = this->firstValid + index;
    if (realIndex < this->capacity) {
        printf("<%u,%u,%u>",realIndex,index,this->firstValid);
        return this->buffer[realIndex];
    } else {
        return this->buffer[realIndex - this->capacity];
    }
}

uint16_t CircularBuffer_Count(CircularBuffer* this) {
    //TODO ADD save guard to this pointer
    if (this->firstValid == CIRCULAR_BUFFER_EMPTY) {
        return 0;
    }

    if (this->firstAvaliable == this->firstValid) {
        return this->capacity;
    }

    if (this->firstValid > this->firstAvaliable) {
        return (this->capacity - this->firstValid) +this->firstAvaliable;
    } else {
        return (this->firstAvaliable - this->firstValid);
    }
}
