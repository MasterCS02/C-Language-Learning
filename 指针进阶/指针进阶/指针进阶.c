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
//int main()
//{
//	int arr[10] = { 0 };
//
//	char* arr1[5] = { 0 };
//	char* (*pc)[5] = &arr1;
//
//	int* p = arr;
//	int(*p2)[10] = &arr;  //这就是数组指针
//	//int(*)[10]这就是它的类型
//
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr+1);
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int (*p)[10] = &arr;
//	
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(*p+i));
//		//p是指向数组的，*p其实就相当于是数组名，数组名又是数组首元素的地址
//		//所以*p本质上是数组首元素的地址
//	}
//	//这种使用方法行得通，但是太奇怪，不怎么会用
//
//	return 0;
//}

//常见的用法

//void print1(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p) [5], int r, int c)
////二维数组的首元素地址是第一行
////int(*p)[5]这是指向一维数组的指针，即二维数组的行数
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//			printf("%d ", p[i][j]);
//
//			//p+i拿到了每一行的一维数组的起始地址
//			//对其解引用*(p+i)，就相当于拿到了这个一维数组的数组名
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	//注意，每一行的元素如要括起来，需要用花括号{}，而不是括号()
//
//	print2(arr,3,5); 
//
//	return 0;
//}


//数组参数、指针参数

//一维数组传参

//void test(int arr[])  //√
//{}
//
//void test(int arr[10])//√
//{}
//
//void test(int* arr)   //√
//{}
//
//void test2(int* arr2[20])//√
//{}
////arr2是一个存放指针的数组，所以这么写完全没有问题
//
//void test2(int** arr2)   //√
//{}
////arr2代表首元素的地址，而这个首元素存放着一级指针变量
////相当于说，arr2存放着一级指针变量的地址，所以arr2是一个二级指针
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };  //指针数组
//	test(arr);
//	test2(arr2);
//
//	return 0;
//}

//二维数组传参
//void test(int arr[3][5]) //√正确
//{}
//
//void test(int arr[][])   //×错误
//{}
////不可以省略列数
//
//void test(int arr[][5])  //√正确
//{}
//
//
//void test(int* arr)      //×错误
//{}
////二维数组的数组名代表首元素的地址
////二维数组的首元素是第一行，即一个一维数组
////一维数组的地址不能放在一个一级指针变量里面
//
//void test(int* arr[5])   //×错误
//{}
////这个表达形式意思是arr是一个存放指针的数组
////arr先和[5]结合，后和*结合
//
//void test(int (*arr)[5]) //√正确
//{}
////这是正确的二维数组首元素地址的表示形式
////arr是一个指针，指向一个元素个数为5，类型为int的数组
//
//void test(int** arr)     //×错误
//{}
////二级指针变量是专门用来存放一级指针变量的地址的
//
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//
//	return 0;
//}

//一级指针传参
//void print(int* p, int sz)
//{}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[10]);
//
//	//一级指针p，传给函数
//	print(p, sz);
//	return 0;
//}

//二级指针传参
//void test(int** ptr)
//{}
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//
//	test(pp);
//	test(&p);
//
//	return 0;
//}

//函数指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int arr[5] = { 0 };
//	//&数组名 - 取出的是数组的地址
//	int (*p)[5] = &arr;//数组指针
//
//	//&函数名 - 取出的是函数的地址
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	//这两种表示形式效果完全相同
//	//对于函数来说，"&函数名"和"函数名"都是函数的地址
//
//	int(*pf)(int, int) = &Add;
//	//这就是把函数地址给存进一个函数指针变量的表达式
//	//(*pf)说明pf是一个指针，
//	// 往右一看，()是函数调用操作符，说明这是一个函数指针，
//	// ()里面的 "int,int" 说明了这个函数的参数类型，
//	// 最前面的int表示了函数的返回类型
//
//	int ret = (*pf)(2, 3);  //通过对函数指针解引用来调用函数
//	int ret = pf(2, 3);     //这样写也可以
//	printf("%d\n", ret);
//
//	return 0;
//}

//使用"函数指针类型"强制类型转换的例子

//typedef void(*pf_t)(int);  //把void(*)(int)类型重命名pf_t
//int main()
//{
//	( *(void(*)()) 0)();
//
//	//(void(*)())这是一个函数指针类型
//	//0本来是一个整型，但是被这个"函数指针类型"给强制类型转换了
//
//	/*
//	以上代码是一次函数调用，调用的是0作为地址处的函数
//	1.把0强制类型转换为：无参，返回类型是void的函数的地址
//	2.调用0地址处的这个函数
//	*/
//
//	void(*signal(int, void(*)(int)))(int);
//	/*
//	以上代码是一次函数声明
//	1.声明的signal函数的第一个参数的类型是int,第二个参数类型是void(*)(int)，即一个函数指针
//	2.signal函数的返回类型也是一个函数指针，为void(*)(int)
//	3.在函数声明中，只需要声明参数的类型就可以了，不需要参数名
//	*/
//
//	pf_t signal(int, pf_t);
//
//	return 0;
//}

 //函数指针的用途

//写一个计算器
//实现加法、减法、乘法、除法


//冗余的写法
//void menu()
//{
//	printf("***************************\n");
//	printf("*******1.add    2.sub******\n");
//	printf("*******3.multi  4.div******\n");
//	printf("**********0. exit*********\n");
//	printf("***************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Multi(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//
//	do
//	{
//		menu();
//
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1://加法
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//
//			ret = Add(x, y);
//
//			printf("%d\n", ret);
//			break;
//
//		case 2://减法
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//
//			ret = Sub(x, y);
//
//			printf("%d\n", ret);
//
//			break;
//
//		case 3://乘法
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//
//			ret = Multi(x, y);
//
//			printf("%d\n", ret);
//
//			break;
//
//		case 4://除法
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//
//			ret = Div(x, y);
//
//			printf("%d\n", ret);
//
//			break;
//
//		case 0:
//			printf("退出计算器\n");
//			break;
//
//		default:
//			printf("选择错误\n");
//			break;
//
//		}
//
//	} while (input);
//
//	return 0;
//}



//实现一个计算器
//回调函数
//void menu()
//{
//	printf("***************************\n");
//	printf("*******1.add    2.sub******\n");
//	printf("*******3.multi  4.div******\n");
//	printf("**********0. exit*********\n");
//	printf("***************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Multi(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//
//	printf("请输入2个操作数:>");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);
//	printf("%d\n", ret);
//
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1://加法
//			calc(Add);
//			break;
//
//		case 2://减法
//			calc(Sub);
//			break;
//
//		case 3://乘法
//			calc(Multi);
//			break;
//
//		case 4://除法
//			calc(Div);
//			break;
//
//		case 0:
//			printf("退出计算器\n");
//			break;
//
//		default:
//			printf("选择错误\n");
//			break;
//
//		}
//
//	} while (input);
//
//	return 0;
//}

//函数指针数组
//void menu()
//{
//	printf("***************************\n");
//	printf("*******1.add    2.sub******\n");
//	printf("*******3.multi  4.div******\n");
//	printf("**********0. exit*********\n");
//	printf("***************************\n");
//}
//
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Multi(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}
//
//int main()
//{
//	int(*pf)(int, int) = Add;
//	int(*arr[4])(int, int) = { Add,Sub,Multi,Div };  //这就是函数指针数组
//
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", arr[i](8, 4));
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//
//	int(*pfarr[5])(int, int) = {0,Add,Sub,Multi,Div};
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			break;
//		}
//		else if ((input >= 1) && (input <= 4))
//		{
//			printf("请输入两个操作数:>\n");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("请重新输入！\n");
//		}
//	} while (input);
//
//	return 0;
//}

//int main()
//{
//	int(*pfArr[])(int, int) = { 0,Add,Sub,Multi,Div };
//
//	//指向【函数指针数组】的指针
//	int(*(*ppfArr)[5])(int, int) = &pfArr;
//	//ppfArr是一个指针，指向一个元素个数为5的数组，这个数组的元素类型为函数指针
//	
//	return 0;
//}

//回调函数
//冒泡排序
//void bubble_sort(int* arr, int sz)
//{
//	int i = 0;
//
//	//冒泡排序趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//假设数组是已经排好序的
//
//		//过程
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;  
//				//进行了排序的过程，说明假设是错误的；没有进行过，那就还是真的
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	//把数组排成升序
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//使用qsort进行整型排序

//void sort_int()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//}

//使用qsort进行结构体排序
struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1, const void* e2)
{
	//strcmp -->   >0 ==0 <0
	return (strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name));
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	//strcmp -->   >0 ==0 <0
	return (((struct Stu*)e1)->age-((struct Stu*)e2)->age);
}

void sort_struct()
{
	//使用qsort来排序结构体数据
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };  //一个结构体数据要用花括号括起来
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}

//改造冒泡排序（按照qsort逻辑重新实现）

//比较函数
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1) - (*(int*)e2);
}

//交换函数
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//冒泡排序函数体(通用版)
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;

	//冒泡排序趟数
	for (i = 0; i < sz - 1; i++)  //不变
	{
		//过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)  //不变
		{
			int flag = 1;
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)  //升序
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
			//base是一个void指针，必须要先强制类型转换才能解引用
			//使用char*进行强制类型转换，可以保证base的偏移量最小移动1个字节，不会移动太多
			//j*width 为base指针的偏移量，width为需要比较的元素的大小
			//通过j*width，可以精准地实现base指针，按照需要比较的不同元素类型的大小，来进行相应的偏移操作

			if (flag == 1)
			{
				break;
			}
		}
	}
}

void sort_bs_int()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

}

int main()
{
	//sort_int();
	sort_struct();
	sort_bs_int();

	return 0;
}

