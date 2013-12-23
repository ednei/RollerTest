#include "Unity/unity.h"

void TestDisplayEmptyBuffer(void)){
    char *expected = "      ";
    char *found = "H";
    TEST_ASSERT_EQUAL_STRING(expected, found);
}
/*
    
TEST(RollerTests,TestDisplayAddCaracter){
    TEST_FAIL_MESSAGE("TODO");
}

TEST(RollerTests,TestDisplayFullAddCaracter){
    
}

TEST(RollerTests,TestDisplaySingleCaracterRollLeft){
    
    
}

TEST(RollerTests,TestDisplaySingleCaracterRollRight){
    
}

TEST(RollerTests,TestDisplayNotFullRollLeft){
    
}

TEST(RollerTests,TestDisplayNotFullRollRight){
    
}

TEST(RollerTests,TestDisplayFullRollLeft){
    
}

TEST(RollerTests,TestDisplayFullRollRight){
    
}

TEST(RollerTests,testDisplayRolledAddCaracter){
       
}
*/

TEST_GROUP_RUNNER(RollerTests)
{
  RUN_TEST_CASE(RollerTests, TestDisplayEmptyBuffer);
}

TEST_SETUP(RollerTests)
{
  /* do test setup */
}


TEST_TEAR_DOWN(RollerTests)
{
  /* do test tear down */
}
