#include "Roller.h"
#include "unity_fixture.h"
#include <string.h>

char *expected;
char displayData[ROLLER_DYSPLAYLENGHT];
    

TEST_GROUP(RollerTests);

TEST_SETUP(RollerTests)
{
    Roller_Init();
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
    Roller_GetDisplayData(displayData);
    TEST_ASSERT_EQUAL_STRING(expected,displayData);
}
    
TEST(RollerTests,TestDisplayAddCaracter){
    SetExpectedString("H     ");
    Roller_AddCaracter('H');
    Roller_GetDisplayData(displayData);
    printf("%s \n", displayData);
    for(int c=0;c<ROLLER_DYSPLAYLENGHT;c++){
        Roller_RollRight();
        Roller_GetDisplayData(displayData);
        printf("%s \n", displayData);
    }
    
    TEST_ASSERT_EQUAL_STRING(expected,displayData);
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