#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/tictactoe.h"

int main(void)
{
    int mode;
    int r, c;
    char p1, cpu;
    char win = ' ';
    int moves = 0;

    // seeding for random
    srand((unsigned int)time(NULL));

    printf("TIC TAC TOE GAME\n");
    printf("1. Play with Computer\n");
    printf("2. Play with Friend\n");
    printf("Enter choice: ");
    if (scanf("%d", &mode) != 1)
    {
        printf("Invalid choice.\n");
        return 0;
    }

    // setting up symbols
    printf("Choose X or O: ");
    scanf(" %c", &p1);

    // simple fix for lowercase
    if (p1 == 'x')
        p1 = 'X';
    if (p1 == 'o')
        p1 = 'O';

    // if user typed something else, just default to X
    if (p1 != 'X' && p1 != 'O')
    {
        printf("Invalid symbol, using X by default.\n");
        p1 = 'X';
    }

    if (p1 == 'X')
        cpu = 'O';
    else
        cpu = 'X';

    // initialize board
    initBoard();

    // main loop
    while (1)
    {
        display();

        // Player input logic
    input_label:
        printf("Your Turn (%c). Enter row and col (1-3): ", p1);
        if (scanf("%d %d", &r, &c) != 2) // <-- FIXED HERE
        {
            // bad input – clear buffer and retry
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
            printf("Invalid input, try again.\n");
            goto input_label;
        }

        r--;
        c--; // convert to 0-based

        if (r >= 0 && r < 3 && c >= 0 && c < 3 && a[r][c] == ' ')
        {
            a[r][c] = p1;
            moves++;
        }
        else
        {
            printf("Wrong move, try again.\n");
            goto input_label;
        }

        // check if player won
        win = check();
        if (win == p1)
        {
            display();
            printf("You Won!!\n");
            break;
        }
        if (moves == 9)
        {
            display();
            printf("Draw match.\n");
            break;
        }

        // Opponent Logic
        if (mode == 1)
        {
            // computer move
            computerRandomMove(cpu, &moves);
        }
        else
        {
            // 2nd player logic
        p2_label:
            display();
            printf("Player 2 (%c) turn. Enter row and col (1-3): ", cpu);
            if (scanf("%d %d", &r, &c) != 2) // <-- AND FIXED HERE
            {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                {
                }
                printf("Invalid input, try again.\n");
                goto p2_label;
            }
            r--;
            c--;

            if (r >= 0 && r < 3 && c >= 0 && c < 3 && a[r][c] == ' ')
            {
                a[r][c] = cpu;
                moves++;
            }
            else
            {
                printf("Invalid. ");
                goto p2_label;
            }
        }

        win = check();
        if (win == cpu)
        {
            display();
            if (mode == 1)
                printf("Computer Won.\n");
            else
                printf("Player 2 Won.\n");
            break;
        }
        if (moves == 9)
        {
            display();
            printf("Draw match.\n");
            break;
        }
    }

    return 0;
}
