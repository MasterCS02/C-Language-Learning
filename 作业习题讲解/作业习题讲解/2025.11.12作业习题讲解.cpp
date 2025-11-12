#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//小乐乐改数字

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	
//	int tmp = n;
//	int count = 0;
//	int sum = 0;
//	
//	while (tmp != 0)
//	{
//		//if ((tmp % 10) % 2 == 1)
//		//{
//		//	sum += 1 * pow(10, count);
//		//	count++;
//		//	
//		//}
//		//else if ((tmp % 10) % 2 == 0)
//		//{
//		//	sum += 0 * pow(10, count);
//		//	count++;
//		//}
//
//		sum += ((tmp % 10) % 2) * pow(10, count);
//		count++;
//		tmp /= 10;
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}

//打印直角三角形

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 0;
//	//先打印空格
//	for (i = 1; i <= n; i++)
//	{
//		int j = n * 2 - i * 2;
//		for (j = n * 2 - i * 2; j > 0; j--)
//		{
//			printf(" ");
//		}
//
//		//在打印"* "
//		int k = i;
//		for (k = i; k > 0; k--)
//		{
//			printf("* ");
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

//课堂版本
//int main()
//{
//	int n = 0;
//
//	//多组输入
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0; 
//		int j = 0;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i + j < n - 1)
//				{
//					printf("  ");  //每2个空格一打
//				}
//				else
//				{
//					printf("* ");
//				}
//			}
//			printf("\n");
//		} 
//	}
//	return 0;
//}

//网购问题
//int main()
//{
//	float price = 0.0f;
//	int month = 0;
//	int date = 0;
//	int coupon = 0;
//
//	scanf("%f %d %d %d", &price, &month, &date, &coupon);
//
//	if ((month == 11) && (date == 11))
//	{
//		price = price * 0.7;
//		if (coupon == 1)
//		{
//			price -= 50;
//		}
//	}
//	else if ((month == 12) && (date == 12))
//	{
//		price = price * 0.8;
//		if (coupon == 1)
//		{
//			price -= 50;
//		}
//	}
//
//	//花的钱不能是负数（商家不会倒找钱）
//	if (price < 0.0)
//	{
//		printf("%.2f\n", 0);
//	}
//	else
//	{
//		printf("%.2f\n", price);
//	}
//	
//	return 0;
//}

//猜名次
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	//穷举每一位选手的排名情况
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						//将穷举出来的结果根据选手猜的结果一一比对
//						//因为所有选手都只猜对了一半
//						//所以每个选手的说的两个表达式的真值之和恒为1
//						//如果都为真，那么和为2；如果都为假，那么和为0
//						if (   (b == 2) + (a == 3) == 1
//							&& (b == 2) + (e == 4) == 1
//							&& (c == 1) + (d == 2) == 1
//							&& (c == 5) + (d == 3) == 1
//							&& (e == 4) + (a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);
//							}
//						}
//						
//					}
//
//				}
//			}
//		}
//	}
//	return 0;
//}

//猜凶手
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//
//	int i = 0;
//
//	for (a = 0; a <= 1; a++)
//	{
//		for (b = 0; b <= 1; b++)
//		{
//			for (c = 0; c <= 1; c++)
//			{
//				for (d = 0; d <= 1; d++)
//				{
//					if ((a == 0) + (c == 1) + (d == 1) + (d == 0) == 3)
//					{
//						if (a + b + c + d == 1)
//						{
//							int arr1[] = { a,b,c,d };
//							char arr2[] = { 'A','B','C','D','\0' };
//							for (i = 0; i < 4; i++)
//							{
//								if (arr1[i] % 2 == 1)
//								{
//									printf("%c是凶手！\n", arr2[i]);
//								}
//							}
//							//printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	return 0;
//}

//杨辉三角

//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//
//	//初始化元素
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

