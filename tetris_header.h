#include <stdio.h>
#include <stdlib.h>
#include <time.h>>
#include <string.h>
#include <conio.h>

int score = 0; // Made it global because I realised too late that I need score and I'm not changeing 200 billiom functions..

void delay(double number_of_seconds);
void printBoard(char board[22][13], int score_points);
void initilizeBoard(char board[22][13]);
int  randomNr(void);
int  checkIfFullLine(char board[][13], int line_number);
int  checkIfEmptyLine(char board[22][13], int line_number);
void flickerFullLine(char board[22][13], int line_number);
void printFancyMenu( int position );

#define BOARD_TITLE 178
#define CUB_TITLE 219
#define DFFICULTY 0


