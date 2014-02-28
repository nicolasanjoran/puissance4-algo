#include "../h/grid.h"

int GRID_getColumnCasesLeft(char grid[][6], int colNum)
{
	int result = 0;
	int i;

	for(i=0 ; i<6 ; i++)
	{
		if(grid[colNum][i] == 0)
		{
			result++;
		}
	}
	return result;
}

int GRID_setNextTurn(char grid[][6], int colNum, char currentPlayer)
{
	int i;

	for(i=0 ; i<6 ; i++)
	{
		if(grid[colNum][i] == 0)
		{
			grid[colNum][i] = currentPlayer;
			return 0;
		}
	}
	return 1;
}

char GRID_isFinished(char grid[][6])
{
	int col=0;
	int raw=0;
	int i,j;
	int currentPlayerChecking=0;
	int nbCoins=0;
	int gameFinished = 0;

	// Vertical checking
	for(i=0 ; i<7 && nbCoins<4 ; i++)
	{
		currentPlayerChecking = grid[i][0];
		for(j=0 ; j<6 && nbCoins<4 ; j++)
		{	
			if(currentPlayerChecking != 0 && grid[i][j]==currentPlayerChecking)
			{
				nbCoins++;
			}else{
				currentPlayerChecking=grid[i][j];
				nbCoins=0;
			}
		}
	}

	
	// Horizontal checking
	for(i=0 ; i<6 && nbCoins<4 ; i++)
	{
		nbCoins=0;
		currentPlayerChecking = grid[i][0];
		for(j=0 ; j<7 && nbCoins<4 ; j++)
		{	
			if(currentPlayerChecking != 0 && grid[j][i]==currentPlayerChecking)
			{
				nbCoins++;
			}else{
				currentPlayerChecking=grid[j][i];
				nbCoins=0;
			}
		}
	}

	// Diagonal checking n°1
	i=2;
	j=0;
	while(j<3 && nbCoins<4)
	{
		nbCoins=0;
		col=j;
		raw=i;
		currentPlayerChecking = grid[col][raw];
		while(col<7 && raw <6 && nbCoins<4)
		{
			if(currentPlayerChecking != 0 && grid[col][raw]==currentPlayerChecking)
			{
				nbCoins++;
			}else{
				currentPlayerChecking=grid[col][raw];
				nbCoins=0;
			}

			col++;
			raw++;
		}

		if(i>0)
		{
			i--;
		}else{
			j++;
		}
	}

	// Diagonal checking n°2
	i=3;
	j=0;
	while(j<3 && nbCoins<4)
	{
		nbCoins=0;
		col=j;
		raw=i;
		currentPlayerChecking = grid[col][raw];
		while(col<7 && raw >=0 && nbCoins<4)
		{
			if(currentPlayerChecking != 0 && grid[col][raw]==currentPlayerChecking)
			{
				nbCoins++;
			}else{
				currentPlayerChecking=grid[col][raw];
				nbCoins=0;
			}

			col++;
			raw--;
		}

		if(i<6)
		{
			i++;
		}else{
			j++;
		}
	}

	// Check if 4-coins raw is found
	if(nbCoins==4)
	{
		printf("Player %d WON\n", currentPlayerChecking);
		return 1;
	}
	return 0;
}