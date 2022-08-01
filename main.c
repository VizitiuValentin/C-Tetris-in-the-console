#include "tetris_header.h"
// int score = 0; // Made it global because I realised too late that I need score and I'm not changeing 200 billiom functions..

int main()
{
    char board[22][13];
    char menu_option = 10, move_control, menu_position = 0;
    int i ,initial_i, j, full_line=0, first_empty_line=0, to_delete=0,to_delete_vertical=0, want_to_exit=0, piece_number;
    int flip = 1;
    srand(time(0)); // Uses the current time as seed for the rand function

//*********************************************************************************************************************/

    for (;;) // Main loop of the program
    {
        printFancyMenu(menu_position);
        menu_option = toupper(getch());

        if (menu_option == 'S') menu_position++;
        if (menu_option == 'W') menu_position--;

        if (menu_position == 4) menu_position = 0;
        if (menu_position == -1) menu_position = 3;

        if (menu_position == 0 && menu_option == 0xd) menu_option = 1;
        if (menu_position == 1 && menu_option == 0xd) menu_option = 2;
        if (menu_position == 2 && menu_option == 0xd) menu_option = 3;
        if (menu_position == 3 && menu_option == 0xd) menu_option = 4;

        switch(menu_option)
        {

//*********** - CASE 1 - ***************************************************************************************************/

        case 1:
            system("cls");
            initilizeBoard(board);
            printBoard(board, score);
            printf("\nPress any key to start the game!!!\nPress ESC to exit the game\n");
            getch();

            for ( ; ; )
            {
                system("cls");
                printBoard(board, score);

                while (1)
                {
                    system("cls");
                    printBoard(board, score);
                    if (want_to_exit == 1) break;

                    piece_number = randomNr();

                    if (piece_number > 0 ) // FOR L shape
                    {

                        for (int i=0,j = randomNr(); ; )
                        {
                            if (j==10) j = 9;

                            delay(0.2);
                            if ( _kbhit() ) // If a key is pressed it does a move according to the key presses, otherwise it ignores this if statement
                            {
                                move_control = toupper(getch());

                                fflush(stdin);

                                switch  (move_control)
                                {
                                case 'W':
                                    flip *= -1;
                                    if (flip == -1)
                                    {

                                        board[i-1][j] = ' ';
                                        board[i][j] = ' ';
                                        if (j==1) j=2;
                                    }
                                    if (flip == 1)
                                    {

                                        board[i][j+1] = ' ';

                                        board[i+1][j-1] = ' ';
                                    }
                                    break;

                                case 'A':

                                    if (flip == -1)
                                    {
                                        if (board[i+2][j-2] == ' ')
                                        {
                                            j--;
                                            to_delete++;
                                        }
                                    }

                                    if (flip == 1)
                                    {
                                        if (board[i+2][j-1] == ' ' && board[i+1][j-1] == ' ' && board[i][j-1] == ' ')
                                        {
                                            j--;
                                            to_delete++;
                                        }
                                    }
                                    break;

                                case 'D':
                                    if (flip == -1)
                                    {
                                        if (board[i+2][j+2] == ' ' && board[i+1][j+2] == ' ')
                                        {
                                            j++;
                                            to_delete--;

                                        }
                                    }

                                    if (flip == 1)
                                    {

                                        if (board[i+2][j+2] == ' ')
                                        {
                                            j++;
                                            to_delete--;
                                        }

                                    }
                                    break;

                                case 'S':
                                    if (flip < 0)
                                    {
                                        if (board[i+3][j] == ' ' && board[i+3][j+1] == ' ')
                                        {
                                            i++;
                                            to_delete_vertical++;
                                        }
                                    }
                                    if (flip > 0)
                                    {
                                        if (board[i+3][j] == ' ' && board[i+3][j+1] == ' ')
                                        {
                                            i++;
                                            to_delete_vertical++;
                                        }


                                    }
                                    break;
                                case 27:
                                    want_to_exit = 1;
                                    break;
                                default:
                                    break;
                                }
                            }

                            if  (want_to_exit == 1) break;
// FLIP -1 ---------------------------------------------------------------------------------------------------
                            if (flip < 0)
                            {
                                fflush(stdin);
                                board[i+2][j-1] = CUB_TITLE;
                                board[i+2][j] = CUB_TITLE;
                                board[i+2][j+1] = CUB_TITLE;
                                board[i+1][j+1] = CUB_TITLE;

                                board[i+1][j] = ' ';
                                board[i+1][j-1] = ' ';
                                board[i][j+1] = ' ';

                                // >1 , a -------------------------
                                if (to_delete > 0)
                                {
                                    board[i][j+2] = ' ';
                                    board[i+1][j+2] = ' ';
                                    board[i+1][j-1] = ' ';
                                }

                                // <1 , d -------------------------
                                if (to_delete < 0)
                                {
                                    board[i][j] = ' ';
                                    board[i+1][j-2] = ' ';
                                }
                                // vertical
                                if (to_delete_vertical > 0)
                                {
                                    board[i][j] = ' ';
                                    board[i][j-1] = ' ';
                                    board[i-1][j+1] = ' ';
                                }

                                to_delete = 0;
                                i++;

                                to_delete_vertical = 0;

                                if (board[i+2][j] != ' ' || board[i+2][j+1] != ' ' || board[i+2][j-1] != ' ' )
                                {
                                    flip = 1;
                                    printBoard(board, score);
                                    break;
                                }

                            }

// FLIP 1 ---------------------------------------------------------------------------------------------------
                            if (flip > 0)
                            {
                                fflush(stdin);
                                board[i][j] = CUB_TITLE;
                                board[i+1][j] = CUB_TITLE;
                                board[i+2][j] = CUB_TITLE;
                                board[i+2][j+1] = CUB_TITLE;

                                board[i-1][j+to_delete] = ' ';
                                board[i-1-to_delete_vertical][j+to_delete] = ' ';
                                board[i+1-to_delete_vertical][j+to_delete+1] = ' ';

                                // >1 , a -------------------------
                                if (to_delete > 0)
                                {
                                    board[i+1-to_delete_vertical][j+to_delete] = ' ';
                                    board[i-to_delete_vertical][j+to_delete] = ' ';
                                }

                                // <1 , d-------------------------
                                if (to_delete < 0)
                                {
                                    board [i-1][j-1] = ' ';
                                    board [i+1][j] = CUB_TITLE;
                                    board [i+1][j-1] = ' ';
                                    board [i][j-1] = ' ';
                                }

                                to_delete = 0;
                                i++;

                                to_delete_vertical = 0;

                                if (board[i+2][j] != ' ' || board[i+2][j+1] != ' ' )
                                {
                                    flip = 1;
                                    printBoard(board, score);
                                    break;
                                }

                            }
                            system("cls");
                            printBoard(board, score);
                        }

                    }

                    if (piece_number > 5) // FOR SIMPLE CUBE
                    {

                        for (int i=0,j = randomNr(); ; )
                        {

                            delay(0.2);
                            if ( _kbhit() ) // If a key is pressed it does a move according to the key presses, otherwise it ignores this if statement
                            {


                                move_control = toupper(getch());

                                fflush(stdin);

                                switch  (move_control)
                                {
                                case 'A':

                                    if (board[i][j-1] == ' ')
                                    {
                                        j--;
                                        to_delete++;
                                    }
                                    break;

                                case 'D':
                                    if (board[i][j+1] == ' ')
                                    {
                                        j++;
                                        to_delete--;
                                    }
                                    break;
                                case 'S':
                                    if (board[i+1][j] == ' ')
                                    {
                                        i++;
                                        to_delete_vertical++;
                                    }
                                    break;
                                case 27:
                                    want_to_exit = 1;
                                    break;
                                default:
                                    break;
                                }
                            }

                            if  (want_to_exit == 1) break;
                            fflush(stdin);
                            board[i][j] = CUB_TITLE;
                            board[i-1-to_delete_vertical][j+to_delete] = ' ';

                            to_delete = 0;
                            i++;

                            to_delete_vertical = 0;

                            if (board[i][j] != ' ')
                            {
                                printBoard(board, score);
                                break;
                            }
                            system("cls");
                            printBoard(board, score);
                        }



                    }
                     if (board[0][1] == CUB_TITLE || board[0][2] == CUB_TITLE ||
                    board[0][3] == CUB_TITLE || board[0][4] == CUB_TITLE ||
                    board[0][5] == CUB_TITLE || board[0][6] == CUB_TITLE ||
                    board[0][7] == CUB_TITLE || board[0][8] == CUB_TITLE ||
                    board[0][9] == CUB_TITLE || board[0][10] == CUB_TITLE )
                {
                    printf("\nYOU LOST!!! SCORE: %d\nPress any key to return to the main menu...", score);
                    getch();
                    want_to_exit = 1;
                    break;
                }

// Checks every line one by one to see if any of it is full, starts from bottom

                    for (int i=19, initial_i=19; initial_i-1 != 0 ; initial_i--)
                    {
                        if  (want_to_exit == 1) break;
                        i = initial_i;

                        full_line = checkIfFullLine(board, initial_i);
                        if (full_line == 1)
                        {
                            score += 100; // adds 100 to the score
                            for (int q = i-1; q>0 ; q--)
                            {
                                // Goes from bottom to see the first empty line above the full one
                                // So the game does NOT replace the lines above because all of them are the same, empty
                                first_empty_line = checkIfEmptyLine(board, q);
                                if (first_empty_line)
                                {
                                    first_empty_line = q;
                                    break;
                                }
                            }

                            flickerFullLine(board, i); // Flickers the full line to look cool

// If a line was full, deletes it and replaces it by the one above it until it reached the first empty line above it
                            while (i>=first_empty_line)
                            {

                                strcpy(board[i], board[i-1]); // Copies every line with  the one above it
                                strcpy(board[i-1], board[0]); // Makes the line that will be copies by the one above empty
                                i--;
                                system("cls");
                                printBoard(board, score);
                                delay(0.3);
                            }
                            full_line = 0 ;
                            first_empty_line = 0;
                        }

                    }



                }
                if  (want_to_exit == 1)
                {

                    want_to_exit = 0;
                    score = 0;
                    break;
                }
            }  // END OF GAMEPLAY 'FOR' LOOP
            system("cls");
            break;
//* - CASE 2 - **************************************************************************************************************/

        case 2:
            system("cls");
            initilizeBoard(board);
            printBoard(board, score);
            printf("\nTODO: I could add options to chance the color of the walls, of the game pieces, change the controls around, et cetera.\nWhile having a preview of the whole board...\n"
                   "Abandoned the project due to lack of time\n\n"
                   "Press any key to return to the main menu...\n");
            getch();
            break;

//* - CASE 3, 4 - ********************************************************************************************************/

        case 3:
            system("cls");
            printf("TETRIS IN CONSOLE version 1.0\nCreated by Vizitiu Valentin Iulian on 4 and 5 December 2021, about 15 hours of coding, 700 lines of code\n\n"
                   "Use WASD to move around, ESC to exit the game while playing, ENTER to select the highlighted choise\n\n"
                   "This is just a proof of concept, it has 2 game pieces implemented but with some minor bugs to them\n"
                   "I could make it work perfectly but at this point in time im too inexperienced so it will take an unreasonable amount of time to do...\n"
                   "But I can do it (didnt even learn about pointers yet);\n"
                   "My favorite part is the main menu, its just beatifiul\n"
                   "\nApasa orice tasta ca sa te intorci la meniul principal...\n\n");

            getch();
            system("cls");
            break;

        case 4:
            system("cls");
            return 0;
        } // MENU SWITCH END
    } // END OF MAIN WHILE
} // END MAIN



