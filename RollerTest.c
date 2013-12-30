#include "unity_fixture.h"
#include <string.h>
#include <stdint.h>

#include "Roller.h"

static char displayData[ROLLER_DYSPLAYLENGHT];
static uint8_t verbose;

static void CheckDisplayData(char *expected);
static void AddHelloToRoller();
static void AddHelloWorldToRoller();

TEST_GROUP(RollerTests);

TEST_SETUP(RollerTests)
{
    Roller_Init();
    verbose=0;
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
    RUN_TEST_CASE(RollerTests,TestBufferFullAddCaracter);
}

static void CheckDisplayData(char *expected){
    TEST_ASSERT_MESSAGE(strlen(expected)<=ROLLER_DYSPLAYLENGHT,"Expected message has a invalid size, this test is not well wrote");
    TEST_ASSERT_MESSAGE(strlen(expected)>0,"Expected message has a invalid size, this test is not well wrote");
    Roller_GetDisplayData(displayData);
    TEST_ASSERT_EQUAL_STRING(expected,displayData);
    if(verbose){
        printf("%s \n", displayData);
    }
}

static void AddHelloToRoller(){
    Roller_AddCaracter('H');
    CheckDisplayData("H*****");
    Roller_AddCaracter('E');
    CheckDisplayData("HE****");
    Roller_AddCaracter('L');
    CheckDisplayData("HEL***");
    Roller_AddCaracter('L');
    CheckDisplayData("HELL**");
    Roller_AddCaracter('O');
    CheckDisplayData("HELLO*");
}

static void AddHelloWorldToRoller(){
    AddHelloToRoller();
    Roller_AddCaracter('#');
    CheckDisplayData("HELLO#");
    Roller_AddCaracter('W');
    CheckDisplayData("ELLO#W");
    Roller_AddCaracter('O');
    CheckDisplayData("LLO#WO");
    Roller_AddCaracter('R');
    CheckDisplayData("LO#WOR");
    Roller_AddCaracter('L');
    CheckDisplayData("O#WORL");
    Roller_AddCaracter('D');
    CheckDisplayData("#WORLD");
}

TEST(RollerTests,TestDisplayEmptyBuffer){
    CheckDisplayData("******");
}
    
TEST(RollerTests,TestDisplayAddCaracter){
    AddHelloToRoller();
}

TEST(RollerTests,TestDisplayFullAddCaracter){
    AddHelloWorldToRoller();
}

TEST(RollerTests,TestDisplaySingleCaracterRollLeft){
    Roller_AddCaracter('H');
    CheckDisplayData("H*****");
    Roller_RollLeft();
    CheckDisplayData("*****H");
    Roller_RollLeft();
    CheckDisplayData("****H*");
    Roller_RollLeft();
    CheckDisplayData("***H**");
    Roller_RollLeft();
    CheckDisplayData("**H***");
    Roller_RollLeft();
    CheckDisplayData("*H****");
    Roller_RollLeft();
    CheckDisplayData("H*****");
}

TEST(RollerTests,TestDisplaySingleCaracterRollRight){
    Roller_AddCaracter('H');
    CheckDisplayData("H*****");
    Roller_RollRight();
    CheckDisplayData("*H****");
    Roller_RollRight();
    CheckDisplayData("**H***");
    Roller_RollRight();
    CheckDisplayData("***H**");
    Roller_RollRight();
    CheckDisplayData("****H*");
    Roller_RollRight();
    CheckDisplayData("*****H");
    Roller_RollRight();
    CheckDisplayData("H*****");
}

TEST(RollerTests,TestDisplayNotFullRollLeft){
    //verbose=1;
    AddHelloToRoller();
    Roller_RollLeft();
    CheckDisplayData("ELLO**");
    Roller_RollLeft();
    CheckDisplayData("LLO***");
    Roller_RollLeft();
    CheckDisplayData("LO****");
    Roller_RollLeft();
    CheckDisplayData("O****H");
    Roller_RollLeft();
    CheckDisplayData("****HE");
    Roller_RollLeft();
    CheckDisplayData("***HEL");
    Roller_RollLeft();
    CheckDisplayData("**HELL");
    Roller_RollLeft();
    CheckDisplayData("*HELLO");
    Roller_RollLeft();
    CheckDisplayData("HELLO*");
}

TEST(RollerTests,TestDisplayNotFullRollRight){
    //verbose=1;
    AddHelloToRoller();
    Roller_RollRight();
    CheckDisplayData("*HELLO");
    Roller_RollRight();
    CheckDisplayData("**HELL");
    Roller_RollRight();
    CheckDisplayData("***HEL");
    Roller_RollRight();
    CheckDisplayData("****HE");
    Roller_RollRight();
    CheckDisplayData("O****H");
    Roller_RollRight();
    CheckDisplayData("LO****");
    Roller_RollRight();
    CheckDisplayData("LLO***");
    Roller_RollRight();
    CheckDisplayData("ELLO**");
    Roller_RollRight();
    CheckDisplayData("HELLO*");
}

TEST(RollerTests,TestDisplayFullRollLeft){
    //verbose=1;
    AddHelloWorldToRoller();
    //printf("Full Left Roll step by step stating: \n");
    Roller_RollLeft();
    CheckDisplayData("WORLD*");
    Roller_RollLeft();
    CheckDisplayData("ORLD**");
    Roller_RollLeft();
    CheckDisplayData("RLD***");
    Roller_RollLeft();
    CheckDisplayData("LD****");
    Roller_RollLeft();
    CheckDisplayData("D****H");
    Roller_RollLeft();
    CheckDisplayData("****HE");
    Roller_RollLeft();
    CheckDisplayData("***HEL");
    Roller_RollLeft();
    CheckDisplayData("**HELL");
    Roller_RollLeft();
    CheckDisplayData("*HELLO");
    Roller_RollLeft();
    CheckDisplayData("HELLO#");
    Roller_RollLeft();
    CheckDisplayData("ELLO#W");
    Roller_RollLeft();
    CheckDisplayData("LLO#WO");
    Roller_RollLeft();
    CheckDisplayData("LO#WOR");
    Roller_RollLeft();
    CheckDisplayData("O#WORL");
    Roller_RollLeft();
    CheckDisplayData("#WORLD");
}

TEST(RollerTests,TestDisplayFullRollRight){
    //verbose=1;
    AddHelloWorldToRoller();
    //printf("Full Right Roll step by step starting: \n");
    Roller_RollRight();
    CheckDisplayData("O#WORL");
    Roller_RollRight();
    CheckDisplayData("LO#WOR");
    Roller_RollRight();
    CheckDisplayData("LLO#WO");
    Roller_RollRight();
    CheckDisplayData("ELLO#W");
    Roller_RollRight();
    CheckDisplayData("HELLO#");
    Roller_RollRight();
    CheckDisplayData("*HELLO");
    Roller_RollRight();
    CheckDisplayData("**HELL");
    Roller_RollRight();
    CheckDisplayData("***HEL");
    Roller_RollRight();
    CheckDisplayData("****HE");
    Roller_RollRight();
    CheckDisplayData("D****H");
    Roller_RollRight();
    CheckDisplayData("LD****");
    Roller_RollRight();
    CheckDisplayData("RLD***");
    Roller_RollRight();
    CheckDisplayData("ORLD**");
    Roller_RollRight();
    CheckDisplayData("WORLD*");
    Roller_RollRight();
    CheckDisplayData("#WORLD");
}

TEST(RollerTests,testDisplayRolledAddCaracter){
    //verbose =1;
    AddHelloWorldToRoller();
    Roller_RollRight();
    CheckDisplayData("O#WORL");
    Roller_RollRight();
    CheckDisplayData("LO#WOR");
    Roller_RollRight();
    CheckDisplayData("LLO#WO");
    Roller_RollRight();
    CheckDisplayData("ELLO#W");
    Roller_RollRight();
    CheckDisplayData("HELLO#");
    //must display the last caracter added even if rolled
    Roller_AddCaracter('.');
    CheckDisplayData("WORLD.");
    Roller_AddCaracter('T');
    CheckDisplayData("ORLD.T");
}

TEST(RollerTests,TestBufferFullAddCaracter){
    TEST_FAIL_MESSAGE("TODO");
}
