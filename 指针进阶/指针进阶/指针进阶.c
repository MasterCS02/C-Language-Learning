#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//int main()
//{
//	char p1 = "abcdef";
//	//这种写法是错误的，不能将字符串常量赋值到char类型中
//	//char只接受字符常量
//
//	char* p2 = "abcdef";
//
//	printf("%s\n", p1);
//	printf("%s\n", p2);
//
//	return 0;
//}

//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
//
//	//字符串常量在内存中是存放在只读数据区，在C语言中，允许相同的字符串在内存中只存一份
//	//这就导致了，p1和p2指向了同一个字符串地址
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	//而数组不一样，数组只要创建，就需要在内存中开辟出一块属于自己的空间来存放数据，是互相独立的
//
//	if (p1 == p2)
//	{
//		printf("p1==p2\n");//✔
//	}
//	else
//	{
//		printf("p1!=p2\n");
//	}
//	if (arr1 == arr2)
//	{
//		printf("arr1==arr2\n");
//	}
//	else
//	{
//		printf("arr1!=arr2\n");//✔
//	}
//
//	return 0;
//
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[] = { arr1,arr2,arr3 };
//
//	int i = 0;
//
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//数组名
int main()
{
	int arr[10] = { 0 };

	int* p = arr;
	int(*p2)[10] = &arr;  //这就是数组指针
	//int(*)[10]这就是它的类型

	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]+1);
	printf("%p\n", &arr+1);

	return 0;
}

