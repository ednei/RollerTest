#include "Roller.h"
#include "unity_fixture.h"
#include <string.h>

char *expected;

TEST_GROUP(RollerTests);

TEST_SETUP(RollerTests)
{
    expected="";
}

TEST_TEAR_DOWN(RollerTests)
{
}

TEST_GROUP_RUNNER(RollerTests)
{
    RUN_TEST_CASE(RollerTests,TestDisplayEmptyBuffer);
    RUN_TEST_CASE(RollerTests,TestDisplayAddCaracter);
    RUN_TEST_CASE(RollerTests,TestDisplayFullAddCaracter);
    RUN_TEST_CASE(RollerTests,TestDisplaySingleCaracterRollLeft);
    RUN_TEST_CASE(RollerTests,TestDisplaySingleCaracterRollRight);
    RUN_TEST_CASE(RollerTests,TestDisplayNotFullRollLeft);
    RUN_TEST_CASE(RollerTests,TestDisplayNotFullRollRight);
    RUN_TEST_CASE(RollerTests,TestDisplayFullRollLeft);
    RUN_TEST_CASE(RollerTests,TestDisplayFullRollRight);
    RUN_TEST_CASE(RollerTests,testDisplayRolledAddCaracter);
}

static void SetExpectedString(char *value){
    TEST_ASSERT_MESSAGE(strlen(value)<=ROLLER_DYSPLAYLENGHT,"Expected message has a invalid size, this test is not well wrote");
    TEST_ASSERT_MESSAGE(strlen(value)>0,"Expected message has a invalid size, this test is not well wrote");
    expected=value;
}

TEST(RollerTests,TestDisplayEmptyBuffer){
    SetExpectedString("      ");
    Roller_Init();
    TEST_ASSERT_EQUAL_STRING(expected, Roller_GetDisplayData());
}
    
TEST(RollerTests,TestDisplayAddCaracter){
    SetExpectedString("H");
    Roller_AddCaracter("H");
    TEST_ASSERT_EQUAL_STRING(expected, Roller_GetDisplayData());
}

TEST(RollerTests,TestDisplayFullAddCaracter){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplaySingleCaracterRollLeft){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplaySingleCaracterRollRight){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplayNotFullRollLeft){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplayNotFullRollRight){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplayFullRollLeft){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplayFullRollRight){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,testDisplayRolledAddCaracter){
    TEST_FAIL_MESSAGE("TODO");       
}