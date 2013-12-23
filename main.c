/* 
 * File:   main.c
 * Author: ednei
 *
 * Created on December 23, 2013, 9:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Unity/unity.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    RUN_TEST_GROUP(RollerTests);
    return (EXIT_SUCCESS);
}

