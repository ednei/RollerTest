#include "unity_fixture.h"

TEST_GROUP(RollerTests);

TEST_SETUP(RollerTests)
{
}

TEST_TEAR_DOWN(RollerTests)
{
}

TEST_GROUP_RUNNER(RollerTests)
{
    RUN_TEST_CASE(RollerTests, TestDisplayEmptyBuffer);
}

TEST(RollerTests,TestDisplayEmptyBuffer){
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