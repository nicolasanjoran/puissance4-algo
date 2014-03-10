#include "../h/display.h"

void DISPLAY_DisplayGrid(char grid[][6])
{
	int i,j;
	printf("---------------\n");
	printf("|1|2|3|4|5|6|7|\n");
	printf("---------------\n");
	for(i=5 ; i>=0 ; i--)
	{
		printf("|");
		for(j=0 ; j<7 ; j++)
		{
			if(grid[j][i] == 1) printf("\033[35mø\033[37m|");
			else if (grid[j][i] == 2) printf("\033[36mo\033[37m|");
			else printf(" |");
		}
		printf("\n");
	}
	printf("---------------\n");
}

int DISPLAY_GetNextColumn(int currentPlayer)
{
	int lineIn;
	while(lineIn<1 || lineIn>7)
	{
		if (currentPlayer == 1){
			printf("\nIt's your turn (Player 1 In Pink), please select a column.\n");
			printf("COLUMN: ");
		} else {
			printf("\nIt's your turn (Player 2 In Green), please select a column.\n");
			printf("COLUMN: ");
		}		
		scanf("%d",&lineIn);
	}
	return lineIn - 1;
}

void DISPLAY_menu(){
	printf("\nMenu:\n");
	printf("1 - Human VS Human\n");
	printf("2 - Human VS IA (easy)\n");
	printf("3 - Human VS IA (medium)\n");
	printf("4 - Human VS IA (hard)\n");
	printf("5 - Quit the game\n\n");
}

int DISPLAY_modeSelection(){
	int mode;
	printf("Choose the mode: ");
	scanf("%d",&mode);
	while (mode < 1 || mode > 5){
		printf("Choose the mode (select a number line between 1 and 5): ");	
		scanf("%d",&mode);
	}
	return mode;
}
