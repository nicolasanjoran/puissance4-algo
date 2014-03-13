/*
# File: game.h
# Author: Anjoran Nicolas & Briot Julien
# Description: Game function headers
*/

#ifndef __GAME_H
#define __GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "../h/grid.h"
#include "../h/display.h"
#include "../h/minimax.h"

/*=============== Prototypes ================*/

/*
Name: GAME_init
Input: -
Output: -
Description: Init the globalGrid with '0' and the gameResult at 0.
*/
void GAME_init();

/*
Name: GAME_main
Input: mode
Output: -
Description: init the game and while gameResult==0 play the round between player (human) and player 2 (human or IA because of the selected mode)
*/
int GAME_main(int mode);

/*
Name: GAME_IsFinished
Input: -
Output: -
Description: Display information if no possibilities in the grid or if there is a winner.
*/
char GAME_IsFinished();
/*-------------------------------------------*/

#endif
