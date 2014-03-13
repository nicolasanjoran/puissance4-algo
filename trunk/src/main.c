/*
File: main.c
Author: ANJORAN Nicolas, BRIOT Julien
Description: main function
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../h/game.h"

/*
Name: main
Input: -
Output: -
Description: while the player wants to play, display the menu, the mode selection and launch a round
*/
int main (int argc, char *argv[])
{
	int mode = -1;
	system("clear");
	printf("\033[37;40m");
	printf("---------- PUISSANCE 4 ---------\n");
	while (mode != 5){
		DISPLAY_menu();
		mode = DISPLAY_modeSelection();
		if (mode != 5)
			GAME_main(mode);
	}
	printf("\nEnd of Puissance 4\n");
	return 0;
}
