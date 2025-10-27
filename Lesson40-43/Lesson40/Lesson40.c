#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//函数
//void Swap1(int x, int y) 
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//
//void Swap2(int* px, int* py)
//{
//	int z = *px; //z=a
//	*px = *py;   //a=b
//	*py = z;     //b=a
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前:a=%d b=%d\n", a, b);
//
//	Swap1(a, b);   //传值调用
//	Swap2(&a, &b); //传址调用
//	printf("交换后:a=%d b=%d\n", a, b);
//
//	return 0;
//}

//写一个函数：判断一个数是不是素数

//打印100-200之间的素数
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否为素数
//		//是素数就打印
//		//拿2~i-1之间的数字去试除i
//		// 如果这个数是素数，那么就不能被这个区间内的数字整除
//
//		int flag = 1;  //flag是1，表示是素数
//		int j = 0;
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//
//		if (flag == 1)
//		{
//			count++;
//			printf("%d ", i);
//
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}

//优化
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)  //偶数不可能是素数，所以直接生成奇数就可以了
//	{
//		int flag = 1;  //flag是1，表示是素数
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//
//		if (flag == 1)
//		{
//			count++;
//			printf("%d ", i);
//
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}


//写一个函数：判断一个数是不是素数

//是素数返回1
//不是素数返回0
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}

//打印1000-2000年之间的闰年
// 
//闰年判断的规则
//1.能被4整除，并且不能被100整除的是闰年
//2.能被400整除的是闰年

//分支与循环语句的方法
//方法一：
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//判断year是不是闰年
//		if (year % 4 == 0)  //第一个条件
//		{
//			if (year % 100 != 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//		}
//
//		if (year % 400 == 0)  //第二个条件
//		{
//			printf("%d ", year);
//			count++;
//
//		}
//	}
//
//	printf("\ncount:%d\n", count);
//	return 0;
//}

//方法二：
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//
//	printf("\ncount:%d\n", count);
//	return 0;
//}

//函数的方法

// 是闰年，返回1；否则，返回0
//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount:%d\n", count);
//	return 0;
//}


//写一个函数，实现一个整型有序数组的二分查找
// 
//int binary_search(int arr[], int k, int sz)  
////形参arr本质上是一个指针变量，并不是一个数组
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;  //找到了，返回下标值
//		}
//	}
//	return -1;  //找不到，返回-1
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int k = 0;
//	scanf("%d", &k);  //定义查找的数字
//	
//	int sz = sizeof(arr) / sizeof(arr[0]);  //计算数组元素的个数
//
//	int ret = binary_search(arr,k,sz);
//	//找到了，返回下标
//	//找不到，返回-1
//
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是:%d\n",ret);
//	}
//	return 0;
//}


//布尔类型

//#include <stdbool.h>
//bool is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}


//写一个函数，每调用一次这个函数，就会将num的值增加1

//void Add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num = 0;
//
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//
//	return 0;
//}

//函数的调用
//void new_line()
//{
//	printf("hehe\n");
//}
//
//void three_line()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//
//int main()
//{
//	three_line();
//	return 0;
//}

//链式访问
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);
//
//	//链式访问
//	printf("%d\n", strlen("abcdef"));
//	//将strlen函数的返回值作为printf函数的一个参数
//
//	return 0;
//}

//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43))); 
//	//4321
//
//	return 0;
//}

//main函数有3个参数
//int main(int argc, char* argv[], char* envp[])
//{
//	return 0;
//}