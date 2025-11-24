#include <stdio.h>
#include <stdlib.h>
#include "../include/tictactoe.h"

// define the global board here
char a[3][3];

// initialize board with spaces
void initBoard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[i][j] = ' ';
        }
    }
}

// function to show the board
void display()
{
    printf("\n\n");
    printf("\t  %c |  %c |  %c \n", a[0][0], a[0][1], a[0][2]);
    printf("\t--------------\n");
    printf("\t  %c |  %c |  %c \n", a[1][0], a[1][1], a[1][2]);
    printf("\t--------------\n");
    printf("\t  %c |  %c |  %c \n", a[2][0], a[2][1], a[2][2]);
    printf("\n\n");
}

// logic to check who won
// returns the symbol of winner or space if no one
char check()
{
    int i;
    // rows and cols
    for (i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ')
            return a[i][0];
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ')
            return a[0][i];
    }

    // diagonals
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ')
        return a[0][0];
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != ' ')
        return a[0][2];

    return ' ';
}

// computer just picks a random empty spot and moves there
void computerRandomMove(char cpu, int *moves)
{
    int r, c;
    while (1)
    {
        r = rand() % 3;
        c = rand() % 3;
        if (a[r][c] == ' ')
        {
            a[r][c] = cpu;
            if (moves != NULL)
            {
                (*moves)++;
            }
            break;
        }
    }
    printf("Computer moved...\n");
}
