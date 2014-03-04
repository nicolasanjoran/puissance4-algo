#include "../h/game.h"

/*=============== Global vars ===============*/
char globalGrid[7][6]; // 7 columns, 6 rows
char gameResult = 0; // 0 => Playing, 1 => Player 1 won, 2 => Player 2 won, 3 => Game aborted.
char currentPlayer = 0;
/*-------------------------------------------*/

void GAME_Init()
{
	int i,j;

	for(i=0 ; i<7 ; i++)
	{
		for(j=0 ; j<6 ; j++)
		{
			globalGrid[i][j]=0;
		}
	}
}

int GAME_main(char mode, char level)
{
	GAME_Init();
	printf("START OF GAME\n");
	DISPLAY_DisplayGrid(globalGrid);
	srand(time(NULL));
	currentPlayer = (rand()%2 +1);
	while(gameResult == 0)
	{
		if(currentPlayer == 1)
		{
			int nextColumn = 0;
			// Interaction with player (console mode first)
			// **Display grid for user.
			do{
				system("clear");
				DISPLAY_DisplayGrid(globalGrid);
				nextColumn = DISPLAY_GetNextColumn();
			}while(GRID_setNextTurn(globalGrid, nextColumn, currentPlayer));
			currentPlayer=2;
			
		}else if(currentPlayer == 2){
			// PC IA Processing...
			srand(time(NULL));
			int randomColumn = (rand()%8);
			//GRID_setNextTurn(globalGrid, randomColumn, currentPlayer);
			GRID_setNextTurn(globalGrid, MINIMAX_minimax(globalGrid,4), currentPlayer);
			currentPlayer = 1;
		}else{
			// End of Game, no current player set.
			gameResult = 3;
		}
		gameResult = GAME_IsFinished();	
	}
	printf("END OF GAME\n");
	return 0;

}

char GAME_IsFinished()
{
	int i=0;
	int total=0;
	int gameResult = 0;
	for(i=0 ; i<7 ; i++)
	{
		total += GRID_getColumnCasesLeft(globalGrid, i);
	}
	gameResult = GRID_isFinished(globalGrid);
	if(gameResult)
	{
		system("clear");
		DISPLAY_DisplayGrid(globalGrid);
		printf("PLAYER %d WON\n", gameResult);
		return gameResult;
	}
	else if(total == 0)
	{
		printf("No cell left...\n");
		return 3;
	}

	return 0;
}