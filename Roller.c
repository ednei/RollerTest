
#include <string.h>
#include <stdint.h>

#include "Roller.h"
#include "CircularBuffer.h"

typedef struct Roller_t{
   char displayData[ROLLER_DYSPLAYLENGHT];
   CircularBuffer circularBuffer;
   uint8_t buffer[ROLLER_MAXCARACTER];
} Roller;

static Roller roller;

void Roller_Init(){
    memset(roller.displayData,' ',ROLLER_DYSPLAYLENGHT);
    CircularBuffer_Init(&roller.circularBuffer,roller.buffer,ROLLER_MAXCARACTER);
}

char* Roller_GetDisplayData(){
    return roller.displayData;
}

void Roller_AddCaracter(char caracter){
    CircularBuffer_Add(&roller.circularBuffer,caracter);
    
}
