
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "Roller.h"
#include "CircularBuffer.h"

#define MAX_DISPLAY_RANGE (2*ROLLER_DYSPLAYLENGHT-2)

uint16_t displayPosition;
//char displayData[ROLLER_DYSPLAYLENGHT];
CircularBuffer circularBuffer;
uint8_t buffer[ROLLER_MAXCARACTER];

static uint16_t GetMaxDisplayRange(void);

void Roller_Init() {
    //memset(displayData, ' ', ROLLER_DYSPLAYLENGHT);
    displayPosition = 0;
    CircularBuffer_Init(&circularBuffer, buffer, ROLLER_MAXCARACTER);
}

void Roller_GetDisplayData(char *displayData) {
    //strcpy(destination, displayData);
    uint16_t copyPosition;
    uint16_t maxDisplayRange = GetMaxDisplayRange();
    for (int c = 0; c < ROLLER_DYSPLAYLENGHT; c++) {
        copyPosition = displayPosition + c;
        printf("[%u,%u]", copyPosition, displayPosition);
        /*
        if (copyPosition < CircularBuffer_Count(&circularBuffer)) {
            displayData[c] = CircularBuffer_Get(&circularBuffer,
                    copyPosition);
        } else {
            if (copyPosition < MAX_DISPLAY_RANGE) {
                displayData[c] = '*';
            } else {
                copyPosition = copyPosition - MAX_DISPLAY_RANGE;
                displayData[c] = CircularBuffer_Get(&circularBuffer,
                        copyPosition);
            }
        }
         */
        if (copyPosition >= maxDisplayRange) {
            copyPosition = copyPosition - maxDisplayRange;
        }
        if (copyPosition < CircularBuffer_Count(&circularBuffer)) {
            displayData[c] = CircularBuffer_Get(&circularBuffer,
                    copyPosition);
        } else {
            displayData[c] = '*';
        }
    }
}

void Roller_AddCaracter(char caracter) {
    CircularBuffer_Add(&circularBuffer, caracter);
}

static uint16_t GetMaxDisplayRange(void){
    uint16_t bufferCount= CircularBuffer_Count(&circularBuffer);
    if(bufferCount<ROLLER_DYSPLAYLENGHT){
        return ROLLER_DYSPLAYLENGHT;
    }else{
        return bufferCount+ROLLER_DYSPLAYLENGHT;
    }
}

void Roller_RollLeft(void) {
    if (displayPosition < GetMaxDisplayRange()) {
        displayPosition++;
    } else {
        displayPosition = 0;
    }
}

void Roller_RollRight(void) {
    if (displayPosition == 0) {
        displayPosition = GetMaxDisplayRange() - 1;
    } else {
        displayPosition--;
    }
    //printf("[%u,%u]", displayPosition, MAX_DISPLAY_RANGE);
}

