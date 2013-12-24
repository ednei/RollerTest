#include "unity_fixture.h"
#include "CircularBuffer.h"
#include <string.h>

char *expected;

TEST_GROUP(CircularBufferTests);

TEST_SETUP(CircularBufferTests)
{
    expected="";
}

TEST_TEAR_DOWN(CircularBufferTests)
{
}

TEST_GROUP_RUNNER(CircularBufferTests)
{
    RUN_TEST_CASE(CircularBufferTests,TestCircularBuffer_Init);
    //RUN_TEST_CASE(CircularBuffer,TestDisplayAddCaracter);
    //RUN_TEST_CASE(CircularBuffer,TestDisplayFullAddCaracter);
    //RUN_TEST_CASE(CircularBuffer,TestDisplaySingleCaracterRollLeft);
    //RUN_TEST_CASE(CircularBuffer,TestDisplaySingleCaracterRollRight);
    //RUN_TEST_CASE(CircularBuffer,TestDisplayNotFullRollLeft);
    //RUN_TEST_CASE(CircularBuffer,TestDisplayNotFullRollRight);
    //RUN_TEST_CASE(CircularBuffer,TestDisplayFullRollLeft);
    //RUN_TEST_CASE(CircularBuffer,TestDisplayFullRollRight);
    //RUN_TEST_CASE(CircularBuffer,testDisplayRolledAddCaracter);
}

TEST(CircularBufferTests,TestCircularBuffer_Init){
    uint8_t buffer[8];
    CircularBuffer circularBuffer;
    CircularBuffer_Init(&circularBuffer,buffer,8);
    TEST_ASSERT_EQUAL_UINT16(8,circularBuffer.capacity);
    TEST_ASSERT_NOT_EQUAL(0,circularBuffer.buffer);
    TEST_ASSERT_EQUAL_UINT16(0,circularBuffer.currentIndex);
}

