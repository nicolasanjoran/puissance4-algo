/*
# File: grid.h
#
*/

#ifndef __GRID_H
#define __GRID_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*=============== Prototypes ================*/
int GRID_getColumnCasesLeft(char grid[][6], int colNum);
int GRID_setNextTurn(char grid[][6], int colNum, char currentPlayer);
int GRID_getMaxLengthRaw(char grid[][6], char player);
char GRID_isFinished(char grid[][6]);
/*-------------------------------------------*/

#endif