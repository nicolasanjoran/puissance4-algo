/*
# File: game.h
#
*/

#ifndef __GAME_H
#define __GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../h/grid.h"
#include "../h/display.h"
#include "../h/minimax.h"

/*=============== Prototypes ================*/
void GAME_init();
int GAME_main(int mode, char level);
char GAME_IsFinished();
/*-------------------------------------------*/

#endif
