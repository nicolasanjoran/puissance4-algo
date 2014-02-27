/*
# File: game.h
#
*/

#ifndef __GAME_H
#define __GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../h/grid.h"
#include "../h/display.h"

/*=============== Prototypes ================*/
void GAME_init();
int GAME_main(char mode, char level);
char GAME_IsNotFinished();
/*-------------------------------------------*/

#endif