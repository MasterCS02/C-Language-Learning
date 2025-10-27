#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
void menu()  //设计菜单
{
	printf("************************\n");
	printf("********猜数字游戏*******\n");
	printf("*******  1.Play  *******\n");
	printf("*******  0.Exit  *******\n");
	printf("************************\n");
}

void game()  //猜数字游戏的输入逻辑
{
	//1.生成随机数，使用rand函数,0~RAND_MAX(32767)
	//让随机数的范围限定在1-100区间

	int ret = rand() % 100 + 1;//（1）（5）

	//2.猜数字
	int guess = 0;
	while (1)
	{
		printf("请输入你猜的数字（1-100）按回车键提交:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//（2）（3）

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);  //输入1或0

		switch (input)
		{
		case 1:
			game();//猜数字的输入逻辑
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
	} while (input);//当input=0时，条件为假，自动退出程序

	return 0;
}