/* 
 * File:   main.c
 * Author: ednei
 *
 * Created on December 23, 2013, 9:22 AM
 */
#include "unity_fixture.h"

static void runAllTests()
{
    RUN_TEST_GROUP(RollerTests);
}


int main(int argc, char** argv) {
    return UnityMain(argc, argv, runAllTests);    
}

