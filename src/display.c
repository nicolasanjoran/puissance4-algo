#include "../h/display.h"

void DISPLAY_DisplayGrid(char grid[][6])
{
	int i,j;
	printf("_________\n");
	for(i=5 ; i>=0 ; i--)
	{
		printf("|");
		for(j=0 ; j<7 ; j++)
		{
			if(grid[j][i] == 1) printf("\033[35m");
			else if (grid[j][i] == 2) printf("\033[36m");
			printf("%d\033[37m|", grid[j][i]);
		}
		printf("\n");
	}
}

int DISPLAY_GetNextColumn()
{
	char lineIn[10];
	while(lineIn[0]<'1' || lineIn[0]>'7')
	{
		
		printf("\nIt's your turn, please select a column.\n");
		printf("COLUMN: ");
		gets(lineIn);
	}
	return (int)(lineIn[0])-48;
}