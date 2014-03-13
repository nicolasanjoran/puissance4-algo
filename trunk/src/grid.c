/*
# File: grid.c
# Author: Anjoran Nicolas & Briot Julien
# Description: Functions used for handle a grid
*/

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

int GRID_getMaxLengthRaw(char grid[][6], char player)
{
	int col=0;
	int raw=0;
	int i,j;
	int currentPlayerChecking=0;
	int nbCoins=0;
	int gameFinished = 0;
	int maxLength = 0;

	// Vertical checking
	for(i=0 ; i<7 && nbCoins<4 ; i++)
	{
		nbCoins=0;
		currentPlayerChecking = grid[i][0];
		for(j=0 ; j<6 && nbCoins<4 ; j++)
		{	
			if(grid[i][j] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[i][j] == player)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[i][j];
		}
		if(nbCoins > maxLength) maxLength = nbCoins;
	}
	
	// Horizontal checking
	for(i=0 ; i<6 && nbCoins<4 ; i++)
	{
		nbCoins=0;
		currentPlayerChecking = grid[i][0];
		for(j=0 ; j<7 && nbCoins<4 ; j++)
		{	
			if(grid[j][i] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[j][i] == player)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[j][i];
		}
		if(nbCoins > maxLength) maxLength = nbCoins;
	}

	// Diagonal checking n°1
	i=2;
	j=0;
	while(j<4 && nbCoins<4)
	{
		nbCoins=0;
		col=j;
		raw=i;
		currentPlayerChecking = grid[col][raw];
		while(col<7 && raw <6 && nbCoins<4)
		{
			if(grid[col][raw] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[col][raw] == player)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[col][raw];

			col++;
			raw++;
		}

		if(i>0)
		{
			i--;
		}else{
			j++;
		}
		if(nbCoins > maxLength) maxLength = nbCoins;
	}

	// Diagonal checking n°2
	i=3;
	j=0;
	while(j<4 && nbCoins<4)
	{
		nbCoins=0;
		col=j;
		raw=i;
		currentPlayerChecking = grid[col][raw];
		while(col<7 && raw >=0 && nbCoins<4)
		{
			if(currentPlayerChecking != 0 && grid[col][raw]==player)
			{
				nbCoins++;
			}else{
				currentPlayerChecking=grid[col][raw];
				nbCoins=0;
			}

			col++;
			raw--;
		}

		if(i<5)
		{
			i++;
		}else{
			j++;
		}
		if(nbCoins > maxLength) maxLength = nbCoins;
	}
	return maxLength;
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
		nbCoins=0;
		currentPlayerChecking = grid[i][0];
		for(j=0 ; j<6 && nbCoins<4 ; j++)
		{	
			if(grid[i][j] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[i][j] != 0)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[i][j];
		}
	}

	
	// Horizontal checking
	for(i=0 ; i<6 && nbCoins<4 ; i++)
	{
		nbCoins=0;
		currentPlayerChecking = grid[j][0];
		for(j=0 ; j<7 && nbCoins<4 ; j++)
		{	
			if(grid[j][i] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[j][i] != 0)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[j][i];
		}
	}

	// Diagonal checking n°1
	i=2;
	j=0;
	while(j<4 && nbCoins<4)
	{
		nbCoins=0;
		col=j;
		raw=i;
		currentPlayerChecking = grid[col][raw];
		while(col<7 && raw <6 && nbCoins<4)
		{
			if(grid[col][raw] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[col][raw] != 0)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[col][raw];

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
	while(j<4 && nbCoins<4)
	{
		nbCoins=0;
		col=j;
		raw=i;
		currentPlayerChecking = grid[col][raw];
		while(col<7 && raw >=0 && nbCoins<4)
		{
			if(grid[col][raw] != currentPlayerChecking)
			{
				nbCoins=0;
			}
			if(grid[col][raw] != 0)
			{
				nbCoins++;
			}
			currentPlayerChecking=grid[col][raw];

			col++;
			raw--;
		}

		if(i<5)
		{
			i++;
		}else{
			j++;
		}
	}

	// Check if 4-coins raw is found
	if(nbCoins==4)
	{
		//printf("Player %d WON\n", currentPlayerChecking);
		return currentPlayerChecking;
	}
	return 0;
}
