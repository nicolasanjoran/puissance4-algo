/*
File: minimax.h
Author: ANJORAN Nicolas, BRIOT Julien
Description: Function headers for minimax algorithm
*/

#ifndef __MINIMAX_H
#define __MINIMAX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*=============== Prototypes ================*/
int MINIMAX_minimax(char grid[][6], int level);
int MINIMAX_min(char grid[][6], int maxi, int level);
int MINIMAX_max(char grid[][6], int mini, int level);
int MINIMAX_eval(char grid[][6], int currentPlayer, int level);
/*-------------------------------------------*/

#endif
