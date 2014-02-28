#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../h/game.h"

int main (int argc, char *argv[])
{
	printf("\033[37;40m");
	printf("---------- PUISSANCE 4 ---------\n");
	GAME_main('a','a');
	return 0;
}