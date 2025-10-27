#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "函数声明.h"

void menu()
{
	printf("*******************************\n");
	printf("*********** 扫雷 **************\n");
	printf("******** 1.开始游戏 ***********\n");
	printf("******** 0.退出游戏 ***********\n");
	printf("*******************************\n");
	printf("\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };  //存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };  //存放排查出的雷的信息

	//初始化数组的内容为指定的数据
	
	InitBoard(mine, ROWS, COLS,'0');  //mine 数组在没有布置雷的时候，都是'0'
	InitBoard(show, ROWS, COLS,'*');  //show 数组在没有排查雷的时候，都是'*'

	SetMine(mine, ROW, COL);  //设置雷

	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	FindMine(mine,show,ROW,COL);  //排查雷
}

int main()
{
	srand((unsigned int) time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择： ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}

	} while (input);

	return 0;
}