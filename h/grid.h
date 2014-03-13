/*
# File: grid.h
# Author: Anjoran Nicolas & Briot Julien
# Description: Grid function headers
*/

#ifndef __GRID_H
#define __GRID_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*=============== Prototypes ================*/

/*
Name: GRID_getColumnCasesLeft
Input: grid, column
Output: number cases left
Description: return the number cases left of column number colNum given
*/
int GRID_getColumnCasesLeft(char grid[][6], int colNum);

/*
Name: GRID_setNextTurn
Input: grid, column, currentPlayer
Output: 0: Success; 1: Fail
Description: Add a joken in the column given and return success or fail if is not possible
*/
int GRID_setNextTurn(char grid[][6], int colNum, char currentPlayer);

/*
Name: GRID_getMaxLenghtRaw
Input: grid, currentPlayer
Output: max lenght raw of currentPlayer token
Description: Search the max lenght raw of currentPlayer token in the grid given 
*/
int GRID_getMaxLengthRaw(char grid[][6], char player);

/*
Name: GRID_isFinished
Input: grid
Output: currentPlayer
Description: Search if there is a game winner in the grid and return the number of winner player
*/
char GRID_isFinished(char grid[][6]);
/*-------------------------------------------*/

#endif
