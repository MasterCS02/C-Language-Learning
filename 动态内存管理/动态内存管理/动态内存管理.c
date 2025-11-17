#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

//动态内存管理

//int main()
//{
//	int arr[10] = { 0 };
//
//	int* p = (int*)malloc(40);
//
//	//对malloc的返回值必须要进行一个判断
//	//防止传回来的是一个空指针又对其进行使用
//
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;  //程序异常，返回1
//	}
//
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", * (p + i));
//	}
//
//	free(p);  
//
//	//释放p指向的内存空间，将其还给操作系统
//	//这个时候p的内存空间不再属于使用者了
//	//此时再继续访问p的内存空间，将会是一个野指针
//	//所以必须要把p变成一个空指针
//
//	p = NULL; 
//
//	return 0;  //程序运行正常，返回0
//}

//int main()
//{
//	while (1)
//	{
//		malloc(1);
//	}
//	return 0;
//}

//calloc
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//0 0 0 0 0 0 0 0 0 0
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

int main()
{

	int* p = (int*)malloc(40);

	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;  
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i + 1;
	}

	int* ptr = (int*)realloc(p, 80);

	//将原来开辟的空间从40个字节扩容到80个字节
	//不能直接把realloc的返回值返回给原指针
	//因为当realloc开辟新空间失败的时候，会返回空指针

	if (ptr != NULL)
	{
		p = ptr;
	}

	//所以必须用一个新的指针变量来接受realloc的返回值
	//并对其进行空指针的判断
	//如果不是空指针，那么再将其赋值到原先的p指针去
	//否则，就不可以

	return 0;
}
