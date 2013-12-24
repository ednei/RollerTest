/* 
 * File:   CircularBuffer.h
 * Author: ednei
 *
 * Created on December 23, 2013, 8:02 PM
 */

#ifndef CIRCULARBUFFER_H
#define	CIRCULARBUFFER_H

#include <stdint.h>

typedef struct CircularBuffer_t{
    uint16_t capacity;
    uint16_t currentIndex;
    uint8_t* buffer;
} CircularBuffer;

/*
#define CircularBuffer_Create(name,capacity)     \
        uint8_t #name_buffer[capacity];          \
        CircularBuffer name;                     \
        CircularBuffer_Init(&name,#name_buffer); \            
*/

void CircularBuffer_Init(CircularBuffer* this,uint8_t* buffer,uint16_t capacity);

#endif	/* CIRCULARBUFFER_H */

