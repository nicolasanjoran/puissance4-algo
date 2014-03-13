/*
# File: minimax.h
# Author: Anjoran Nicolas & Briot Julien
# Description: Minimax function headers
*/

#ifndef __MINIMAX_H
#define __MINIMAX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../h/grid.h"
#include "../h/display.h"

/*=============== Prototypes ================*/

/*
Name: MINIMAX_minimax
Input: grid, level(how many strocke simulate)
Output: a column number
Description: Simulate the different possibilities for IA and for each, call MINIMAX_min with level-1 and return the best for IA
			 If level == 0, call MINIMAX_eval function
*/
int MINIMAX_minimax(char grid[][6], int level);

/*
Name: MINIMAX_min
Input: grid, level
Output: Result of the worst possibility
Description: Simulate the different possibility for Human and for each, call MINIMAX_max with level-1 and return the worst for IA
			 If level == 0, call MINIMAX_eval function
*/
int MINIMAX_min(char grid[][6], int level);

/*
Name: MINIMAX_max
Input: grid, level
Output: Result of the best possibility
Description: Simulate the different possibility for IA and for each, call MINIMAX_min with level-1 and return the best for IA
			 If level == 0, call MINIMAX_eval function
*/
int MINIMAX_max(char grid[][6], int level);

/*
Name: MINIMAX_eval
Input: grid, currentPlayer, level
Output: degree which say if the grid is good or bad for IA
Description: Calcul if the grid configuration is a good or a bad situation for IA
*/
int MINIMAX_eval(char grid[][6], int currentPlayer, int level);
/*-------------------------------------------*/

#endif
