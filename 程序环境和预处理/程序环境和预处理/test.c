#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//预定义符号
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("file:%s line=%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//
//
//	return 0;
//}
//
//#define CASE break;case
//
//int main()
//{
//	switch ()
//	{
//	case 1 :
//	CASE 2 :
//	CASE 3 :
//	CASE 4 :
//	}
//	return 0;
//}
//
////等同于
//int main()
//{
//	switch ()
//	{
//	case 1:
//		break;
//	case 2:
//		break;
//	case 3:
//		break;
//	case 4:
//		break;
//	}
//
//	return 0;
//}

//#define SQUARE(X) X*X
//
//int main()
//{
//	int r = SQUARE(5);
//	printf("%d\n", r);
//
//	return 0;
//}

//#define PRINT(N) printf("the value of "#N" is %d\n",N)
////#会把宏的参数加上双引号，转换为字符串
//
//int main()
//{
//	int a = 10;
//	PRINT(a);
//
//	int b = 20;
//	PRINT(b);
//	
//	return 0;
//}

//#define MAX(x,y) ((x)>(y)?(x):(y))
//int main()
//{
//	int a = 5;
//	int b = 4;
//	int m = ((a++) > (b++) ? (a++) : (b++));
//	//  6     5    >  4    ?  6
//	//先使用，后自增
//
//	printf("m=%d ", m);  //6
//	printf("a=%d b=%d\n",a,b);  //7 5
//
//	return 0;
//}

//#define MALLOC(num,type) (type*)malloc((num)*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	int* p = (int*)malloc((10) * sizeof(int));
//
//	return 0;
//}

//#define M 100
//int main()
//{
//	printf("%d\n", M);
//#undef M
//	printf("%d\n", M);
//
//	return 0;
//}
//
//int array[ARRAY_SIZE];
//int i = 0;
//for (i = 0; i < ARRAY_SIZE; i++)
//{
//	array[i] = 0;
//}
//for (i = 0; i < ARRAY_SIZE; i++)
//{
//	printf("%d ",array[i]);
//}
//printf("\n");
//return 0;

//#define __DEBUG__
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__  //如果__DEBUG__有定义，那么编译下面的代码
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}

struct S
{
	char c1;
	int i;
	char c2;
};

#define OFFSETOF(type,m_name) (size_t)&(((type*)0)->m_name)

int main()
{
	struct S s = { 0 };
	printf("%d\n", OFFSETOF(struct S, c2));

	return 0;
}

