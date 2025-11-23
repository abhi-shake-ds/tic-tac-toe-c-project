#ifndef TICTACTOE_H
#define TICTACTOE_H

#define SIZE 3

extern char board[SIZE][SIZE];
extern const char PLAYER;
extern const char CPU;

void init_board(void);
void drawBoard(void);
int freeCells(void);
void playerMove(void);
void cpuMove(void);
char check_winner(void);

#endif
