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

TEST(RollerTests,TestDisplayEmptyBuffer){
    char *expected = "      ";
    char *found = "H";
    TEST_ASSERT_EQUAL_STRING(expected, found);
}
    
TEST(RollerTests,TestDisplayAddCaracter){
    TEST_FAIL_MESSAGE("TODO");
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