#pragma once

#define ROW 3
#define COL 3
//define定义的标识符常量


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//函数一共有3个参数

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
//找没有下棋的位置随机下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢

//玩家赢 - *
//电脑赢 - #
//平局 - T
//继续 - C

char IsWin(char board[ROW][COL], int row, int col);