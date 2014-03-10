#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../h/game.h"

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
			GAME_main(mode,'a');
	}
	printf("\nEnd of Puissance 4\n");
	return 0;
}
