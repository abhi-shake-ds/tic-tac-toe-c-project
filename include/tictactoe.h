#ifndef TICTACTOE_H
#define TICTACTOE_H

// global 3x3 board
extern char a[3][3];

// show the board
void display();

// check who has won, returns 'X', 'O' or ' '
char check();

// set all cells to space
void initBoard();

// random move by computer, also increases moves count
void computerRandomMove(char cpu, int *moves);

#endif
