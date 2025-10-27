#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
void menu()
{
	printf("*******************************\n");
	printf("********1.PLAY 0.EXIT**********\n");
	printf("*******************************\n");
	printf("\n");

}

void game()
{
	char ret = 0;
	//创建棋盘，棋盘相当于是一个3*3的一个二维字符数组
	char board[ROW][COL] = { 0 }; 
	//初始化棋盘
	InitBoard(board, ROW, COL);  
	//打印棋盘
	DisplayBoard(board,ROW,COL);

	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);

		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		printf("\n");


		//电脑下棋
		ComputerMove(board,ROW,COL);

		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		printf("\n");
	}

	if (ret == '*')
	{
		printf("\n玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("\n电脑赢！\n");
	}
	else
	{
		printf("\n平局！\n");
	}
	DisplayBoard(board, ROW, COL);
	printf("\n");


}

int main()
{
	//设计随机数的生成起点
	srand((unsigned int)time(NULL));

	int input = 0;
	do
	{
		menu();
		printf("请选择: ");
		scanf("%d", &input);
		printf("\n");

		switch (input)
		{
		case 1:
			printf("\n游戏开始\n");
			game();
			break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:
			printf("选择错误！\n请重新选择! \n\n");
			break;
		}

	} while (input);

	return 0;
}