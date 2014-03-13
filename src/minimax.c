/*
File: minimax.c
Author: ANJORAN Nicolas, BRIOT Julien
Description: Functions used for handle the minimax algorithm
*/

#include "../h/minimax.h"

//#define DEBUG
int nbEval = 0;

int MINIMAX_minimax(char globalGrid[][6], int level){
	nbEval = 0;
	int i, j, tmp;
	int max = INT_MIN, turn = 0;
	char grid[7][6];

	char currentPlayer = 2;

	for(i=0 ; i<7 ; i++)
	{
		for(j=0 ; j<6 ; j++)
		{
			grid[i][j] = globalGrid[i][j];
		}
	}

	for(i=0;i<7;i++){
		if(GRID_getColumnCasesLeft(grid, i)){
			GRID_setNextTurn(grid, i, currentPlayer);
			tmp = MINIMAX_min(grid, level-1);
			if(tmp>max || ( (tmp == max) && (rand()%3==0) )){
				max = tmp;
				turn = i;
			}
//			GRID_annulercoup(grid, i);
			grid[i][5-GRID_getColumnCasesLeft(grid,i)] = 0;
		}
	}

	return turn;
}


int MINIMAX_min(char grid[][6], int level){
	int i, tmp;
	int min = INT_MAX;

	char currentPlayer = 1;

	if (!level || GRID_isFinished(grid)){
		return MINIMAX_eval(grid, currentPlayer, level);
	}

	for(i=0;i<7;i++){
		if(GRID_getColumnCasesLeft(grid, i)){
			GRID_setNextTurn(grid, i, currentPlayer);
			tmp = MINIMAX_max(grid, level-1);
			if(tmp < min || ( (tmp == min) && (rand()%3==0) )){
				min = tmp;
			}
//			GRID_annulercoup(grid, i);
			grid[i][5-GRID_getColumnCasesLeft(grid,i)] = 0;
		}
	}
	return min;
}


int MINIMAX_max(char grid[][6], int level){
	int i, tmp;
	int max = INT_MIN;

	char currentPlayer = 2;

	if (!level || GRID_isFinished(grid)){
		return MINIMAX_eval(grid, currentPlayer, level);
	}

	for(i=0;i<7;i++){
		if(GRID_getColumnCasesLeft(grid, i)){
			GRID_setNextTurn(grid, i, currentPlayer);
			tmp = MINIMAX_min(grid, level-1);
			if(tmp > max || ( (tmp == max) && (rand()%3==0) )){
				max = tmp;
			}
//			GRID_annulerCoup(grid, i);
			grid[i][5-GRID_getColumnCasesLeft(grid,i)] = 0;
		}
	}
	return max;
}

int MINIMAX_eval(char grid[][6], int currentPlayer, int level){

	// ICI le currentPlayer est le dernier joueur à avoir fait un coup.
	nbEval++;

	#ifdef DEBUG
		system("clear");
		printf("%d\n", nbEval);
		DISPLAY_DisplayGrid(grid);
	#endif
	if (GRID_isFinished(grid) == 1)
		return (-500-level);
	if (GRID_isFinished(grid) == 2)
		return (500+level);
	if (currentPlayer == 2)
		return - GRID_getMaxLengthRaw(grid,1)*50 - level;
	else
		return GRID_getMaxLengthRaw(grid,2)*50 + level;
}












