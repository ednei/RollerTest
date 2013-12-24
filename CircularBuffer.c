#include "CircularBuffer.h"

void CircularBuffer_Init(CircularBuffer* this,uint8_t* buffer,uint16_t capacity){
    this->capacity = capacity;
    this->buffer = buffer;
    this->currentIndex = 0;
}

