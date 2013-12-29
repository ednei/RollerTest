/* 
 * File:   Roller.h
 * Author: ednei
 *
 * Created on December 23, 2013, 11:21 AM
 */

#ifndef ROLLER_H
#define	ROLLER_H

#define ROLLER_DYSPLAYLENGHT 6
#define ROLLER_MAXCARACTER 1000


void Roller_Init();
void Roller_GetDisplayData(char *displayData);
void Roller_AddCaracter(char caracter);
void Roller_RollLeft(void);
void Roller_RollRight(void);


#endif	/* ROLLER_H */

