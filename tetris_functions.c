#include <stdio.h>
#include <stdlib.h>
#include <time.h>>
#include <string.h>
#include <conio.h>
#define BOARD_TITLE 178
#define CUB_TITLE 219
#define DFFICULTY 0

/*********************************************************************************************************************/

int checkIfFullLine(char board[22][13], int line_number)
{
    int wasFullLine = 0;

    if (    board[line_number][1] != ' ' &&
            board[line_number][2] != ' ' &&
            board[line_number][3] != ' ' &&
            board[line_number][4] != ' ' &&
            board[line_number][5] != ' ' &&
            board[line_number][6] != ' ' &&
            board[line_number][7] != ' ' &&
            board[line_number][8] != ' ' &&
            board[line_number][9] != ' ' &&
            board[line_number][10] != ' ' )
    {
        wasFullLine = 1;
    }
    return wasFullLine;
}

/*********************************************************************************************************************/

int checkIfEmptyLine(char board[22][13], int line_number)
{
    int wasEmptyLine = 0;

    if (    board[line_number][1] == ' ' &&
            board[line_number][2] == ' ' &&
            board[line_number][3] == ' ' &&
            board[line_number][4] == ' ' &&
            board[line_number][5] == ' ' &&
            board[line_number][6] == ' ' &&
            board[line_number][7] == ' ' &&
            board[line_number][8] == ' ' &&
            board[line_number][9] == ' ' &&
            board[line_number][10] == ' ')
    {
        wasEmptyLine = 1;
    }

    return wasEmptyLine;
}

/*********************************************************************************************************************/
int randomNr(void) // Return random number from 1 to 10
{
    int random_number;
    // srand(time(0)); DONT PUT IT INSIDE THE FUNCTION!!!!
    random_number = rand() % 10;
    random_number++; // So it cant be 0
    return random_number;
}
/*********************************************************************************************************************/

void printBoard(char board[22][13], int score_points)
{
    printf("%s%d", board[0], 0);
    printf("\033[0;32m");
    printf("     SCORE: %d\n", score_points);
    printf("\033[0m");

    for (int  i=1; i<21; i++ )
    {
        printf("%s%d\n", board[i],i );
    }
}

/*********************************************************************************************************************/

void delay(double number_of_seconds)
{
    // Converting time into milli_seconds
    double milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

/*********************************************************************************************************************/

void initilizeBoard(char board[22][13])
{
    int i;

    for (i=0; i<20; )
    {
        board[i][0] =  BOARD_TITLE;
        board[i][1] =  ' ';
        board[i][2] =  ' ';
        board[i][3] =  ' ';
        board[i][4] =  ' ';
        board[i][5] =  ' ';
        board[i][6] =  ' ';
        board[i][7] =  ' ';
        board[i][8] =  ' ';
        board[i][9] =  ' ';
        board[i][10] = ' ';
        board[i][11] = BOARD_TITLE;
        board[i][12] = '\0';
        i++;
    }
    board[20][0] =  BOARD_TITLE;
    board[20][1] =  BOARD_TITLE;
    board[20][2] =  BOARD_TITLE;
    board[20][3] =  BOARD_TITLE;
    board[20][4] =  BOARD_TITLE;
    board[20][5] =  BOARD_TITLE;
    board[20][6] =  BOARD_TITLE;
    board[20][7] =  BOARD_TITLE;
    board[20][8] =  BOARD_TITLE;
    board[20][9] =  BOARD_TITLE;
    board[20][10] = BOARD_TITLE;
    board[20][11] = BOARD_TITLE;
    board[20][12] = '\0';
}

/*********************************************************************************************************************/

void flickerFullLine(char board[22][13], int line_number)
{
    for (int i = 0; i<3 ; i++)
    {
        board[line_number][1] =  ' ';
        board[line_number][2] =  ' ';
        board[line_number][3] =  ' ';
        board[line_number][4] =  ' ';
        board[line_number][5] =  ' ';
        board[line_number][6] =  ' ';
        board[line_number][7] =  ' ';
        board[line_number][8] =  ' ';
        board[line_number][9] =  ' ';
        board[line_number][10] = ' ';

        system("cls");
        printBoard(board, score);
        delay(0.1);

        board[line_number][1] =  CUB_TITLE;
        board[line_number][2] =  CUB_TITLE;
        board[line_number][3] =  CUB_TITLE;
        board[line_number][4] =  CUB_TITLE;
        board[line_number][5] =  CUB_TITLE;
        board[line_number][6] =  CUB_TITLE;
        board[line_number][7] =  CUB_TITLE;
        board[line_number][8] =  CUB_TITLE;
        board[line_number][9] =  CUB_TITLE;
        board[line_number][10] = CUB_TITLE;

        system("cls");
        printBoard(board, score);
        delay(0.1);
    }

    board[line_number][1] =  ' ';
    board[line_number][2] =  ' ';
    board[line_number][3] =  ' ';
    board[line_number][4] =  ' ';
    board[line_number][5] =  ' ';
    board[line_number][6] =  ' ';
    board[line_number][7] =  ' ';
    board[line_number][8] =  ' ';
    board[line_number][9] =  ' ';
    board[line_number][10] = ' ';
    system("cls");
    printBoard(board, score);
    delay(0.1);
}

/*********************************************************************************************************************/

void printFancyMenu( int position )
{
    if (position == 0)
    {
        system("cls");
        printf("TETRIS IN CONSOLE v1.0\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>1. START  <%c\n", CUB_TITLE, CUB_TITLE);
        printf("\033[0m");

        printf("%c 2. OPTIONS %c\n", CUB_TITLE, CUB_TITLE);
        printf("%c 3. INFO    %c\n", CUB_TITLE,CUB_TITLE);

        printf("%c 4. EXIT    %c\n"
               "%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to move the blocks and choose an option in the menu\n");
        fflush(stdin);
    }

    if (position == 1)
    {
        system("cls");
        printf("TETRIS IN CONSOLE v1.0\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("%c 1. START   %c\n", CUB_TITLE, CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>2. OPTIONS<%c\n", CUB_TITLE,CUB_TITLE);
        printf("\033[0m");
        printf("%c 3. INFO    %c\n", CUB_TITLE,CUB_TITLE);

        printf("%c 4. EXIT    %c\n"
               "%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to move the blocks and choose an option in the menu\n");
        fflush(stdin);
    }

    if (position == 2) // INFO
    {
        system("cls");
        printf("TETRIS IN CONSOLE v1.0\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("%c 1. START   %c\n", CUB_TITLE, CUB_TITLE);


        printf("%c 2. OPTIONS %c\n", CUB_TITLE,CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>3. INFO   <%c\n", CUB_TITLE,CUB_TITLE);
        printf("\033[0m");

        printf("%c 4. EXIT    %c\n", CUB_TITLE,CUB_TITLE);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to move the blocks and choose an option in the menu\n");
        fflush(stdin);
    }

    if (position == 3)
    {
        system("cls");
        printf("TETRIS IN CONSOLE v1.0\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("%c 1. START   %c\n", CUB_TITLE, CUB_TITLE);


        printf("%c 2. OPTIONS %c\n", CUB_TITLE,CUB_TITLE);
        printf("%c 3. INFO    %c\n", CUB_TITLE,CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>4. EXIT   <%c\n", CUB_TITLE,CUB_TITLE);
        printf("\033[0m");

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to move the blocks and choose an option in the menu\n");
        fflush(stdin);
    }

}
