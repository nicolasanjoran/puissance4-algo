/*
File: minimax.C
Author: ANJORAN Nicolas, BRIOT Julien
Description: Function headers for minimax algorithm
*/

#include "../h/minimax.h"

int MINIMAX_minimax(char grid[][6], int level){
	int i, tmp;
	int max = INT_MIN, turn = 0;

	char currentPlayer = 2;

	for(i=0;i<7;i++){
		if(isCoupValid(i)){
			GRID_setNextTurn(grid, i, currentPlayer);
			tmp = MINIMAX_min(grid, max, level-1);
			if(tmp>max){
				max = tmp;
				turn = i;
			}
			GRID_annulercoup(grid, i);
		}
	}

	return turn;
}


int MINIMAX_min(char grid[][6], int max, int level){
	int i, tmp;
	int min = INT_MAX;

	char currentPlayer = 1;

	if (!level || GRID_isFinished(grid)){
		return MINIMAX_eval(grid, currentPlayer);
	}

	for(i=0;i<7;i++){
		if(GRID_getColumnCasesLeft(grid, i)){
			GRID_setNextTurn(grid, i, currentPlayer);
			tmp = MINIMAX_max(gridC, min, level-1);
			if(tmp < min){
				min = tmp;
			}
			GRID_annulercoup(grid, i);
		}
	}
	return min;
}


int MINIMAX_max(char grid[][6], int min, int level){
	int i, tmp;
	int max = INT_MIN;

	char currentPlayer = 2;

	if (!level || GRID_isFinished(grid)){
		return MINIMAX_eval(grid, currentPlayer);
	}

	for(i=0;i<7;i++){
		if(GRID_getColumnCasesLeft(grid, i)){
			GRID_setNextTurn(grid, i, currentPlayer);
			tmp = MINIMAX_min(grid, max, level-1);
			if(tmp > max){
				max = tmp;
			}
			GRID_annulerCoup(grid, i);
		}
	}
	return max;
}

int MINIMAX_eval(char grid[][6], int currentPlayer){

	// ICI le currentPlayer est le dernier joueur à avoir fait un coup.
	return 0;



}












