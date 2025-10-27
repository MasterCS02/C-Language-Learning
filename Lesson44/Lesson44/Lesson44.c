#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//函数的声明定义

//#include "add.h"
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	//加法
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	return 0;
//}


//函数的递归

//接受一个整型值（无符号），按照顺序打印它的每一位
//例如：输入1234，输出 1 2 3 4


//%d 是打印有符号的整数（会有正负数）
//%u 是打印无符号的整数

//递归的实现
//void print(unsigned int n)
//{
//	if (n > 9)  
//	{
//		print(n / 10);  
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	print(num);  
//
//	return 0;
//}

//递归练习2：
//编写函数不允许创建临时变量，求字符串的长度

//模拟实现strlen

//int my_strlen(char str[]) //参数部分写成数组的形式

//int my_strlen(char* str)  //参数部分写成指针的形式
////传址调用，str是地址
//{
//	int count = 0;  //计数器，临时变量
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//
//		//指针变量++是让指针指向下一个同类型元素的地址，而不是简单＋1
//		//在这里就是去找下一个字符
//	}
//	return count;  //返回统计的字符总个数
//}

//递归求解
//my_strlen("abc");
//1+my_strlen("bc");
//1+1+my_strlen("c");
//1+1+1+my_strlen("");
//1+1+1+0

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str+1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abc";  //[a b c \0]
//	//char*
//	int len = my_strlen(arr);//读取的是字符串的首元素地址
//	printf("%d\n", len);
//
//	return 0;
//}

//递归与迭代

//递归的方式
//long long fac(int n) //最多实现20的阶乘
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}

//迭代的方式
//int fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	long long ret = fac(n);
//	printf("ret=%lld\n", ret);
//
//	return 0;
//}

//求第n个斐波那契数

//递归方法
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//
//	return 0;
//}

//迭代方法
long long Fib(int n)
{
	if (n == 1 || n == 2)
		return 1;

	long long a = 1;
	long long b = 1;
	long long c = 0;

	while (n >= 3)  //一步一步往前算
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int input = 0;
	printf("开始：1\n");
	printf("结束：0\n");

    again:printf("请选择0或1:> ");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case 1:
		  {
			int n = 0;
			printf("请输入你要求的第n个斐波那契数\n--> ");
			scanf("%d", &n);
			long long ret = Fib(n);
			printf("结果为:%lld\n\n", ret);
			
			printf("是否继续？（请输入：0/1）\n--> ");
			scanf("%d", &input);

			while (input != 0 && input != 1)
			{
				printf("输入错误，请重新输入（0/1）\n-->");
				scanf("%d", &input);
			}
			break;
		  }
		case 0:
			printf("Exit\n");
			break;
		default:
			printf("请重新输入\n");
			goto again;
			break;
		}
	} 
	while (input==1);
	printf("已退出程序\n");
	
	return 0;
}
