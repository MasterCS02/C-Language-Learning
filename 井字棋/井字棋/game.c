#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"

//棋盘初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//版本1
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//打印分割信息
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//}


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);

		int j = 0;
		for (j = 0; j < col; j++)  //每一行的打印
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		//打印分割信息
		// ---|---|---
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");

		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
    printf("玩家下棋\n\n");

	while (1)
	{
		printf("请输入坐标:> ");
		scanf("%d %d", &x, &y);

		//坐标范围合法的判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，不能下棋，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}

	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n\n");

	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;//如果 mod 3，那么余数一定在0-2之间
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断输赢

//如果棋盘满了返回1；不满返回0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; //有空格，就说明没满，返回0
			}
		}
	}
	return 1;//满了，返回1
}

char IsWin(char board[ROW][COL], int row, int col)
{
	//判断行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	//判断列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}

	//判断对角线
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '))
	{
		return board[1][1];
	}

	//没有人赢，就要平局
	if (IsFull(board,row,col))
	{
		return 'T';
	}

	//游戏继续
	return 'C';
}