#include "../h/display.h"

void DISPLAY_DisplayGrid(char grid[][6])
{
	int i,j;
	printf("_________\n");
	for(i=0 ; i<7 ; i++)
	{
		printf("|");
		for(j=5 ; j>=0 ; j--)
		{
			printf("%d|", grid[i][j]);
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