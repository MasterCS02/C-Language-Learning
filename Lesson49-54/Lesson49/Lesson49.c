#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//写代码将三个整数按从小到大输出

//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//给定两个数，求这两个数的最大公约数

//方法一
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	scanf("%d %d", &a, &b);
//
//	int min = (a < b) ? a : b;
//	int m = min;
//	while (1)
//	{
//		if (a % m == 0 && b % m == 0)
//		{
//			break;
//		}
//		m--;
//	}
//	printf("%d\n", m);
//	return 0;
//}

//方法二：辗转相除法
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	while (a % b)
//	{
//		int c = a % b;
//		a = b;
//		b = c;
//
//	}
//	printf("%d\n", b);
//	return 0;
//}


//数一下1-100所有整数中出现多少个数字9
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//判断个位是不是9
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	double sum = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum +flag*( 1.0 / i);
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//
//	return 0;
//}

//在屏幕上输出九九乘法表
//int main()
//{
//	int i = 0;
//	//打印9行
//	for (i = 1; i <= 9; i++)
//	{
//		//打印第j行的口诀表
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);//%2d右对齐，%-2d左对齐
//		}
//		printf("\n");
//	}
//}

//数组
//数组的创建
//int main()
//{
//	//不完全初始化，剩余的元素默认初始化为0
//	int arr[10] = { 1,2,3 };
//
//	char ch1[10] = { 'a','b','c' };  //a b c 0 0 0 0...
//	char ch2[10] = "abc";  //a b c \0 0 0 0...
//
//	//完全初始化
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//不指定数组元素个数
//	int arr3[] = { 1,2,3 };
//	char ch3[] = { 'a','b','c' };  //3个元素
//	char ch4[] = "abc";  //4个元素
//
//	return 0;
//}


//一维数组的使用
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i <= sz-1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//一维数组在内存中的存储
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i <= sz - 1; i++)
	{
		printf("&arr[%d]=%p\n", i,&arr[i]);
	}

	return 0;
}