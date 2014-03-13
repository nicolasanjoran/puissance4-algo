/*
# File: display.h
# Author: Anjoran Nicolas & Briot Julien
# Description: Display function headers
*/

#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*=============== Prototypes ================*/
/*
Name: DISPLAY_DisplayGrid
Input: grid
Output: -
Description: Display the grid in a structured way
*/
void DISPLAY_DisplayGrid(char grid[][6]);

/*
Name: DISPLAY_GetNextColumn
Input: currentPlayer
Output: A column number
Description: The currentPlayer must select a valid column (between 1 and 7) and his choice is return.
*/
int DISPLAY_GetNextColumn(int currentPlayer);

/*
Name: DISPLAY_menu
Input: -
Output: -
Description: Display the menu 
*/
void DISPLAY_menu();

/*
Name: DISPLAY_modeSelection
Input: -
Output: mode selected
Description: The currentPlayer must selected a valid mode (between 1 and 5) and his choice is return.
*/
int DISPLAY_modeSelection();
/*-------------------------------------------*/

#endif
