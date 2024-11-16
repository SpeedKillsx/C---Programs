#include<iostream>
#include<string>
#ifndef __GAME__
#define __GAME__
void drawGrill(char *positions);
void playerMove(char *positions, char player);
void computerMove(char *positions, char player);
char checkDiagonals(char *positions);
char checkRows(char *positions);
char checkCols(char *positions);
bool winner(char * position);
#endif