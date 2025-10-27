#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//int main()
//{
//	int a = 10;  //a是整型变量，占用4个字节的内存空间
//	int* pa = &a;  //pa是一个指针变量，用来存放地址的
//	
//	return 0;
//}

//指针类型的意义

//int main()
//{
//	int a = 0x11223344; //1个十六进制数字需要4个二进制位来存放
//	int* pa = &a;
//	char* pc = (char*)&a;
//
//	printf("pa  =%p\n", pa);
//	printf("pa+1=%p\n", pa+1);
//	//pa是int类型的指针，偏移一位即移动4个字节
//
//	printf("pc  =%p\n", pc);
//	printf("pc+1=%p\n", pc+1);
//	//pc是char类型的指针，偏移一位即移动1个字节
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int* pi = &a;
//	float* pf = &a;
//	//pi和pf这两类指针变量解引用都会访问4个字节，且pi+1和pf+1一样，都会跳过四个字节
//	//但这不代表两类指针变量是通用的
//
//	*pi = 100;
//	*pf = 100.0;
//	//表面上看对两个指针变量解引用存放的都是一样的数据，但实际上在内存中的存储结果是截然不同的，这是因为整型和浮点型数据在内存中的存储机制是有差别的
//
//	return 0;
//}

//int main()
//{
//	int a = 0x11223344;
//	char* pc = (char*)&a;
//	int* pi = &a;
//
//	*pc = 0;
//	*pi = 0;
//
//	return 0;
//}

//int main()
//{
//	int* p;
//	//p没有初始化，就意味着没有明确的指向
//	//一个局部变量不初始化的话，放的是随机值：0xcccccccc
//
//	*p = 10;
//	//此时解引用，即为非法访问内存，这里的p就是野指针
//
//	return 0;
//}


//指针越界访问
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;  //&arr[0]
//	
//	int i = 0;
//	for (i = 0; i <= 10; i++)  //循环11次
//	{
//		*p = i;
//		 p++;
//	}
//	return 0;
//}

//int* test()
//{
//	int a = 10;  
//	//a是一个局部变量，函数调用完成结束之后，a变量销毁
//
//	return &a;
//}
//
//int main()
//{
//	int* p = test();
//	//这样的p指针也是个野指针
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//
//	//错误做法
//	int* p2 = NULL;  //NULL -> 0
//	*p2 = 100;  
//
//	//正确做法
//	int* p3 = NULL;
//	if (p3 != NULL)
//	{
//		*p3 = 100;
//	}
//
//	return 0;
//}

//#define N_VALUES 5
//float values[N_VALUES];  //创建一个以元素个数以N_VALUES为大小的float数组
//float* vp;
//
////指针+-整数；指针的关系运算
//for (vp = &values[0]; vp < &values[N_VALUES];)
//{
//	*vp++ = 0;
//
//	//*vp = 0;  先解引用
//	//vp++;  后指针地址后移一个单位
//
//	//注意要与(*vp)++作区分
//}

////给整型数组中每个下标对应的元素赋值
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//数组下标的写法
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 1;
//	}
//
//	//指针的写法1
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		*p = 1;
//		p++;
//	}
//
//	//指针的写法2
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		*(p + i) = 1;
//	}
//
//	return 0;
//}

//int main()
//{
//	//指针-指针运算
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);//9
//	printf("%d\n", &arr[0] - &arr[9]);//-9
//
//	//下面是错误示范（对指向不同空间的指针进行相减是没有意义的）
//	int arr[10] = { 0 };
//	char ch[5] = { 0 };
//	printf("%d\n", &ch[0] - &arr[5]);
//
//	return 0;
//}

//版本1
//int my_strlen(char* str)
//{
//	int count = 0;
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}

//指针-指针
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//
//	return 0;
//}

////指针的关系运算
//#define N_VALUES 5
//float values[N_VALUES];  
//float* vp;
//
//for (vp = &values[N_VALUES]; vp > &values[0];)
//{
//	*--vp = 0;  //先--，后解引用
//}
//
////上述代码也可以简化成
//
//for (vp = &values[N_VALUES-1]; vp >= &values[0];vp--)
//{
//	*vp = 0;  
//}
//
////但是不推荐这种写法

//指针与数组

//int main()
//{
//	int arr[10] = { 0 };
//	//arr是首元素的地址
//
//	int* p = arr;
//	//通过指针来访问数组
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	for(i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	printf("\n");
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%p ----- %p\n", &arr[i], p + i);  //输出的结果是一模一样的
//	}
//
//	return 0;
//}

//二级指针

//int main()
//{
//	int a = 10;
//	int* pa = &a;  //pa是一个一级指针变量
//	int** ppa = &pa;  //ppa是一个二级指针变量
//
//	**ppa = 20;
//
//	return 0;
//}

//指针数组
//存放指针的数组就是指针数组

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	int arr[10];
//
//	int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;
//
//	int* parr[10] = {&a,&b,&c}; 
//	//数组的元素都是整形指针类型
//	//parr就是存放指针的数组
//
//	int i = 0;
//	for (i = 0; i < 3 ; i++)
//	{
//		printf("%d ",*(parr[i]));  
//		//对指针数组中的每个元素进行解引用并打印
//	}
//
//	return 0;
//
//}

//指针数组模拟二维数组
int main()
{
	//一般的二维数组建构
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };

	//1 2 3 4
	//2 3 4 5
	//3 4 5 6

	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	//指针数组来模拟二维数组
	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4] = { 3,4,5,6 };

	int* parr[3] = { arr1,arr2,arr3 };
	//把三个数组的首元素地址分别传到parr这个指针数组里面

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", parr[i][j]);
			//i代表第几个数组，j代表该数组内的第几个元素
			//在这里，[]操作符就相当于解引用了
		}
		printf("\n");

	}

	return 0;
}