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
	char lineIn[0];
	while(lineIn[0]<'1' || lineIn[0]>'7')
	{
		if (currentPlayer == 1){
			printf("\nIt's your turn (Player 1 In Pink), please select a column.\n");
			printf("COLUMN: ");
		} else {
			printf("\nIt's your turn (Player 2 In Green), please select a column.\n");
			printf("COLUMN: ");
		}		
		//scanf("%d",&lineIn);
		gets(lineIn);
		//printf("GETS:%d\n", lineIn);
	}
	return (int)(lineIn[0]) - 49;
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
	char mode[10];
	printf("Choose the mode: ");
	//scanf("%d",&mode);
	gets(mode);
	while (mode[0] < '1'|| mode[0] > '5'){
		printf("Choose the mode (select a number line between 1 and 5): ");	
		gets(mode);
	}
	return (int)(mode[0]-48);
}
