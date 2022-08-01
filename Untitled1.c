/*
 int i=0,j=0;

    for (i = j = 0; ; ) // maks the outline of the board
    {
        board[i][j] = 178;
        j++; // So it goes to the next char on the first string
        if (j>11) // If it hit the last char in the first string it goes back to the 1st on but on the next str
        {
            j=0;
            i++;
        }
        if (i>21) break; // If it hit the last char in the string it strops
    }

    for (i=j=0; ; )
    {
        if (i!=21 && j!=0 && j!=11) board[i][j] = ' ';
        j++;
        if (j>11)
        {
            j=0;
            i++;
        }
        if (i>21) break;
    }
*/
