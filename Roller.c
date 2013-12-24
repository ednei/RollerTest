
#include <string.h>
#include <stdint.h>

#include "Roller.h"


static char _displayData[ROLLER_DYSPLAYLENGHT];

void Roller_Init(){
    memset(_displayData,' ',ROLLER_DYSPLAYLENGHT);
}

char* ROLLER_GetDisplayData(){
    return _displayData;
}
