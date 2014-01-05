#include "unity_fixture.h"
#include "../Roller/src/appLogic/CircularBuffer.h"
#include <string.h>

#define CircularBufferCapacity 4

TEST_GROUP(CircularBufferTests);

TEST_GROUP_RUNNER(CircularBufferTests) {
    RUN_TEST_CASE(CircularBufferTests, TestCircularBuffer_Init);
    RUN_TEST_CASE(CircularBufferTests, TestCircularBuffer_SimpleAdd)
    RUN_TEST_CASE(CircularBufferTests, TestCircularBuffer_AddAfterCycle)
    RUN_TEST_CASE(CircularBufferTests, TestCircularBuffer_FirstAddAfterFull)
            //RUN_TEST_CASE(CircularBuffer,TestDisplaySingleCaracterRollRight);
            //RUN_TEST_CASE(CircularBuffer,TestDisplayNotFullRollLeft);
            //RUN_TEST_CASE(CircularBuffer,TestDisplayNotFullRollRight);
            //RUN_TEST_CASE(CircularBuffer,TestDisplayFullRollLeft);
            //RUN_TEST_CASE(CircularBuffer,TestDisplayFullRollRight);
            //RUN_TEST_CASE(CircularBuffer,testDisplayRolledAddCaracter);
}

static uint8_t buffer[CircularBufferCapacity];
static CircularBuffer circularBuffer;

TEST_SETUP(CircularBufferTests) {
    CircularBuffer_Init(&circularBuffer, buffer, CircularBufferCapacity);
}

TEST_TEAR_DOWN(CircularBufferTests) {
}

TEST(CircularBufferTests, TestCircularBuffer_Init) {
    TEST_ASSERT_EQUAL_UINT16(CircularBufferCapacity, circularBuffer.capacity);
    TEST_ASSERT_NOT_EQUAL(0, circularBuffer.buffer);
    TEST_ASSERT_EQUAL_UINT16(0, circularBuffer.count);
    TEST_ASSERT_EQUAL_UINT16(0, circularBuffer.firstValid);
}

TEST(CircularBufferTests, TestCircularBuffer_SimpleAdd) {
    char *test = "abcd";
    for (int c = 0; c < CircularBufferCapacity; c++) {
        CircularBuffer_Add(&circularBuffer, test[c]);
        TEST_ASSERT_EQUAL_UINT16(test[c], CircularBuffer_Get(&circularBuffer, c));
        TEST_ASSERT_EQUAL_UINT16(c + 1, CircularBuffer_Count(&circularBuffer));
    }
}

TEST(CircularBufferTests, TestCircularBuffer_FirstAddAfterFull) {
    char *test = "abcd";
    
    for (int c = 0; c < CircularBufferCapacity; c++) {
        CircularBuffer_Add(&circularBuffer, test[c]);
    }
    
    //abcd=>ebcd
    CircularBuffer_Add(&circularBuffer, 'e');
    TEST_ASSERT_EQUAL_UINT16(CircularBufferCapacity,
            CircularBuffer_Count(&circularBuffer));
    TEST_ASSERT_EQUAL_UINT16('e',
            CircularBuffer_Get(&circularBuffer, CircularBufferCapacity - 1));
}

TEST(CircularBufferTests, TestCircularBuffer_AddAfterCycle) {
    char *test = "abcd";
    char *test2 = "efgh";

    for (int c = 0; c < CircularBufferCapacity; c++) {
        CircularBuffer_Add(&circularBuffer, test[c]);
    }

    for (int c = 0; c < CircularBufferCapacity; c++) {
        CircularBuffer_Add(&circularBuffer, test2[c]);
        TEST_ASSERT_EQUAL_UINT16(CircularBufferCapacity,
                CircularBuffer_Count(&circularBuffer));
        TEST_ASSERT_EQUAL_UINT16(test2[c],
                CircularBuffer_Get(&circularBuffer, CircularBufferCapacity - 1));
    }
}
