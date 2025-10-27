#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "函数声明.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------MineSweeper-------\n\n");

	for (j = 0; j <= col; j++)  //打印列编号
	{
		printf("%d ", j);
	}

	printf("\n");
	printf("————————————————————\n");

	for (i = 1; i <= row; i++) 
	{
		printf("%d|", i);      //打印行编号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n-------MineSweeper-------\n\n");

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	//x:1~9
	//y:1~9
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] = '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y] + 
		    board[x - 1][y - 1]+ 
		    board[x][y-1] + 
		    board[x + 1][y - 1] + 
		    board[x + 1][y] + 
		    board[x + 1][y + 1] + 
		    board[x][y + 1] + 
		    board[x - 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//找到非雷的个数
	int markcount = EASY_COUNT;

	int playtime = 0;  //游玩次数

	while (win<row*col-EASY_COUNT)  //第一个
	{
		while (playtime >= 1)  //第二个
		{
			int select1 = 0;

			printf("你需要标记雷吗？1.是的，0.不用\n");

			printf("请输入：");
			scanf("%d", &select1);

			while (select1 == 1)  //第三个
			{

				printf("请输入你要标记的坐标：");
				scanf("%d%d", &x, &y);

				if (x >= 1 && x <= row && y >= 1 && y <= col)
				{
					if (show[x][y] == '*')
					{
						show[x][y] = '#';

						DisplayBoard(show, ROW, COL); 
						markcount--;
						printf("你的标记次数还剩下：%d 次\n\n", markcount);

						break; //跳第三个
					}
					else if (show[x][y] == "#")
					{
						printf("这个坐标已经被标记过了！\n");
					}
					else if (show[x][y] != '*' && show[x][y] != '#')
					{
						printf("坐标选择错误，请重新输入！\n");
					}
				}
				else
				{
					printf("输入的坐标非法，请重新输入！\n");
				}

			}

			break; //跳第二个

		}


		again:printf("请输入要排查的坐标: ");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已经排查过了，不能重复排查!\n\n");
				goto again;
			}
			else
			{
				//如果是雷
				if (mine[x][y] == '1')
				{
					printf("\n你被炸死了！\n");
					printf("最终结果\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				//如果不是雷
				else
				{
					win++;
					int count = get_mine_count(mine, x, y);  //统计mine数组中x,y坐标周围有几个雷
					show[x][y] = '0' + count;//转换成数字字符
					DisplayBoard(show, ROW, COL);
					playtime++;
				}

			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入！\n");
		}
		
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		printf("最终结果\n");
		DisplayBoard(show, ROW, COL);
	}
}