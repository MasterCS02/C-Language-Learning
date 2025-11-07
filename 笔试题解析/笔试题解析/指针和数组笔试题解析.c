#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//int main()
//{
//	int a[] = { 1,2,3,4 };
//
//	printf("%d\n", sizeof(a));
//	//16  数组大小
//
//	printf("%d\n", sizeof(a + 0));
//	//4 or 8,这是一个首元素地址的大小
//	//a+0  <==> &a[0]+0
//
//	printf("%d\n", sizeof(*a));  
//	//4  int类型元素的大小
//	//*a <==> *&a[0] <==> a[0]
//
//	printf("%d\n", sizeof(a + 1));
//	//4 or 8 这依然是一个地址的大小
//
//	printf("%d\n", sizeof(a[1]));
//	//4  这计算的是第二个元素在内存中所占空间的大小（单位是字节）
//
//	printf("%d\n", sizeof(&a));
//	//4 or 8
//	//&a取出的是数组的地址，数组的地址，也就是个地址，而地址的大小，就是4 or 8
//	//在部分非常早期的编译器中，算出来的结果可能会是16，但这是一个bug，不代表是正确的结果
//
//	printf("%d\n", sizeof(*&a));
//	//16
//	//&a ---> int(*)[4]
//	//对数组的地址进行解引用，就相当于访问整个数组，也就是计算整个数组的大小
//
//	printf("%d\n", sizeof(&a + 1));
//	//4 or 8
//	//&a+1是从数组a的地址跳过了一个数组的大小，在这里是跳过了4个整型元素
//	//它本身还是一个地址
//
//	printf("%d\n", sizeof(&a[0]));
//	//4 or 8
//	//这是第一个元素地址的大小
//
//	printf("%d\n", sizeof(&a[0] + 1));
//	//4 or 8
//	//这是第二个元素地址的大小
//
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//里面只有6个元素
//	//如果是 char arr[]="abcdef"，那么就会有7个元素了，最后还要加上\0
//
//	printf("%d\n", sizeof(arr));
//	//6
//
//	printf("%d\n", sizeof(arr + 0));
//	//4 or 8
//	//这是数组首元素的地址
//
//	printf("%d\n", sizeof(*arr));
//	//1
//	//这是数组首元素的大小
//
//	printf("%d\n", sizeof(arr[1]));
//	//1
//	//这是数组中第二个元素的大小
//
//	printf("%d\n", sizeof(&arr));
//	//4 or 8
//	//这是计算数组地址的大小，地址的大小就是4 or 8
//
//	printf("%d\n", sizeof(&arr + 1));
//	//4 or 8
//	//&arr+1,就相当于指针跳过整个数组之后指向的地址，它本质上还是一个地址
//
//	printf("%d\n", sizeof(&arr[0]+1));
//	//4 or 8
//	//这是计算数组中第二个元素的地址的大小
//
//	printf("%d\n", strlen(arr));
//	//算不出结果，只会是随机值
//	//因为该字符数组中没有\0，这就导致strlen找不到结束标志
//
//	printf("%d\n", strlen(arr + 0));
//	//依然是随机值
//
//	printf("%d\n", strlen(*arr));
//	//strlen(*arr) --> strlen('a') --> strlen(97)
//	//这是一个野指针的问题
//	//strlen函数接收的是字符类型的指针
//
//	printf("%d\n", strlen(arr[1]));
//	//strlen(arr[1]) --> strlen('b') --> strlen(98)
//	//这依然是一个野指针的问题
//
//	printf("%d\n", strlen(&arr));
//	//这依然是一个随机值
//	//本质上和strlen(arr)的问题一样
//
//	printf("%d\n", strlen(&arr + 1));
//	//随机值-6
//
//	printf("%d\n", strlen(&arr[0] + 1));
//	//随机值-1
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//
//	printf("%d\n", sizeof(arr));
//	//7
//	//该字符数组包含\0
//
//	printf("%d\n", sizeof(arr + 0));
//	//4 or 8
//	//计算的是首元素地址的大小
//
//	printf("%d\n", sizeof(*arr));
//	//1
//	//计算的是首元素的大小
//
//	printf("%d\n", sizeof(arr[1]));
//	//1
//	//计算的是数组中第二个元素的大小
//
//	printf("%d\n", sizeof(&arr));
//	//4 or 8
//	//计算的是数组地址的大小
//
//	printf("%d\n", sizeof(&arr + 1));
//	//4 or 8
//
//	printf("%d\n", sizeof(&arr[0] + 1));
//	//4 or 8
//	//计算的是数组中第二个元素的地址的大小
//
//	printf("%d\n", strlen(arr));
//	//6
//
//	printf("%d\n", strlen(arr + 0));
//	//6
//
//	printf("%d\n", strlen(*arr));
//	//err
//
//	printf("%d\n", strlen(arr[1]));
//	//err
//
//	printf("%d\n", strlen(&arr));
//	//6
//
//	printf("%d\n", strlen(&arr + 1));
//	//随机值
//
//	printf("%d\n", strlen(&arr[0] + 1));
//	//5
//
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	//字符串"abcdef"把首字符a的地址传到了p
//
//	printf("%d\n", sizeof(p));
//	//4 or 8
//
//	printf("%d\n", sizeof(p + 1));
//	//4 or 8
//	//计算的是字符串中第二个字符的地址的大小
//
//	printf("%d\n", sizeof(*p));
//	//1
//	//计算的是字符串中第一个字符的大小
//
//	printf("%d\n", sizeof(p[0]));
//	//1
//	//计算的是字符串中第一个字符的大小
//
//	printf("%d\n", sizeof(&p));
//	//4 or 8
//	//计算的是二级指针的地址的大小
//
//	printf("%d\n", sizeof(&p+1));
//	//4 or 8
//	//&p+1，这个地址是跳过了这个字符串地址的地址
//
//	printf("%d\n", sizeof(&p[0] + 1));
//	//4 or 8
//	//计算的是第二个字符的地址的大小
//
//	printf("%d\n", strlen(p));
//	//6
//
//	printf("%d\n", strlen(p+1));
//	//5
//	//从字符串中第二个字符开始计数
//
//	printf("%d\n", strlen(*p));
//	//err
//
//	printf("%d\n", strlen(p[0]));
//	//err
//
//	printf("%d\n", strlen(&p));
//	//随机值
//	//strlen会把p的地址当成字符串来求大小，结果当然就是错误的
//
//	printf("%d\n", strlen(&p+1));
//	//随机值
//
//	printf("%d\n", strlen(&p[0] + 1));
//	//随机值
//
//	return 0;
//}

//int main()
//{
//	int a[3][4] = { 0 };
//
//	printf("%d\n", sizeof(a));
//	//12*4=48
//	//计算整个二维数组的大小
//
//	printf("%d\n", sizeof(a[0][0]));
//	//4
//	//计算第一行第一列的元素大小
//
//	printf("%d\n", sizeof(a[0]));
//	//16
//	//计算该二维数组中第一行所有元素的大小
//	//a[0]就是这个二维数组第一行所有的一维数组的数组名
//	//sizeof(a[0])就相当于求这个一维数组内所有元素的大小
//
//	printf("%d\n", sizeof(a[0] + 1));
//	//4 or 8
//	//这里的a[0]没有单独出现，所以指代的是数组中首元素的地址
//	// a[0]就是作为第一行所在的一维数组的数组名，这个数组的首元素就是a[0][0]
//	//所以a[0]+1 <==> &a[0][0]+1,就相当于是第一行第二列元素的地址
//
//	printf("%d\n", sizeof(*(a[0] + 1)));
//	//4
//	//计算的是第一行第二列的元素的大小
//
//	printf("%d\n", sizeof(a + 1));
//	//4 or 8
//	//这里的a表示首元素的地址，二维数组的首元素就是它的第一行，即a是第一行的地址
//	//所以a+1指代的是第二行所在的地址
//
//	printf("%d\n", sizeof(*(a + 1)));
//	//4*4=16
//	//计算的是第二行所有元素的大小
//
//	printf("%d\n", sizeof(&a[0] + 1));
//	//4 or 8
//	//&a[0]相当于是&数组名，取的是第一行所在的一维数组的地址
//	//计算的是第二行地址的大小
//
//	printf("%d\n", sizeof(*(&a[0] + 1)));
//	//4*4=16
//	//计算该二维数组中第二行所有元素的大小
//
//	printf("%d\n", sizeof(*a));
//	//4*4=16
//	//计算的是二维数组中首元素的大小
//	//二维数组的首元素就是首行
//
//	printf("%d\n", sizeof(a[3]));
//	//16
//	//a[3]如果存在的话，它的类型也肯定还是int[]，也肯定存在4个整型元素
//	//所以答案就是16
//	//类比sizeof(int) == 4
//
//	return 0;
//
//}

