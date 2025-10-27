#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//二维数组的创建

//int main()
//{
//	int arr[3][4];  
//	//创建一个3行4列的整型数组
//
//	//1 2 3 4
//	//2 3 4 5
//	//3 4 5 6
//
//	char arr2[5][10];
//	//创建一个字符类型的数组，可以存放5行数据，每行可以存放10个字符
//	//5行10列
//
//	return 0;
//}

//二维数组的初始化
//int main()
//{
//	//完全初始化
//	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	int arr1[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
//
//	//不完全初始化
//	int arr2[3][4] = { {1,2},{3,4},{5,6} };
//	char arr2[5][10];
//
//	//二维数组初始化中，行可以省略，但是列不能省略
//	int arr3[][4] = { {1,2,3,4},{2,3} };
//
//	return 0;
//}

//二维数组的使用

//打印所有数据;根据数组下标输入数据
//int main()
//{
//	int arr[3][4] = {0};
//	int i = 0;
//
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &arr[i][j]);
//
//		}
//	}
//
//	for (i = 0; i < 3; i++)  //行
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)  //列
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//内存存储
//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{2,3,4,5},{1,2,3,4} };
//
//	int i = 0;
//
//	for (i = 0; i < 3; i++)  //行
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)  //列
//		{
//			printf("&arr[%d][%d]=%p\n",i,j,&arr[i][j]);
//		}
//	}
//
//	return 0;
//}


//冒泡排序函数

//数组传参的形参，形参有2种写法
//1. 数组
//2. 指针

//形参是数组的形式
//void bubble_sort(int arr[],int sz)
//{
//	//确定趟数，趟数=元素个数-1
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)  //设定一共有多少趟冒泡排序
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for (j = 0; j <sz-1-i ; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				//交换
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	//把数组的数据排成升序
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	//0 1 2 3 4 5 6 7 8 9 
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//使用冒泡排序的算法，对数组进行排序
//	bubble_sort(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = {0};
//	printf("%p\n", arr);  //arr就是首元素的地址
//	printf("%p\n", arr+1);  
//	printf("--------------\n");
//
//	printf("%p\n", &arr[0]);  //首元素的地址
//	printf("%p\n", &arr[0]+1);  
//	printf("--------------\n");
//
//
//	printf("%p\n", &arr);  //数组的地址
//	printf("%p\n", &arr+1);
//	printf("--------------\n");
//
//	return 0;
//}


//int main()
//{
//	int arr[3][4];
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
//	//计算有多少行（数组总大小/首行大小=行数）
//
//	printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));
//	//计算有多少列（首行大小/首行内单个元素的大小=列数）
//
//	int sz = sizeof(arr);
//	printf("%d\n", sz);
//
//	arr;//二维数组的数组名也表示数组首元素的地址（即首行地址）
//
//	return 0;
//}

//作业
//字符串逆序排序

//非递归
//void reverse(char arr[],int left, int right)
//{
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//
//		left++;
//		right--;
//	}
//
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = strlen(arr)-1;
//
//	reverse(arr,left,right);
//
//	printf("%s\n", arr);
//
//	return 0;
//
//}

//递归1
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse(char* str)
//{
//	char tmp = *str;  //创建中间变量，把第一个字符给存放进去
//	int len = my_strlen(str);  //计算字符串长度
//	*str = *(str + len - 1);  //让最后一位的字符数据赋值给第一个字符
//	*(str + (len - 1)) = '\0';  //让最后一位字符数据变成\0
//	if (strlen(str + 1) >= 2)  //递归限制条件
//	{
//		reverse(str + 1);
//	}
//	
//	*(str + len - 1) = tmp;
//
//}
//
//int main()
//{
//	char arr[] = "abcdefg";
//	reverse(arr);
//	printf("%s\n", arr);
//
//	return 0;
//}

//递归2

void reverse(char arr[], int left, int right)
{
	if (left < right)
	{
	  char tmp = arr[left];
	  arr[left] = arr[right];
	  arr[right] = tmp;
	  reverse(arr, left + 1, right - 1);
	}
}

int main()
{
	char arr[] = "abcdefg";
	int left = 0;
	int right = strlen(arr) - 1;
	reverse(arr, left, right);

	printf("%s\n", arr);

	return 0;
}



//打印每一位数字之和
//int DigiSum(int n)
//{
//	if (n > 9)
//	{
//		return n % 10 + DigiSum(n/10);
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//
//	int sum = DigiSum(n);
//	printf("%d\n", sum);
//	
//}

//n的k次方,使用递归实现
//double Pow(int n, int k)
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else if(k>1)
//	{
//		if (k-1 != 0)
//		{
//			return n * Pow(n, k-1);
//		}
//	}
//	else if(k<0 && n!=0)
//	{
//		return 1.0 / (Pow(n, -k));
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//
//	printf("%.2lf\n", ret);
//	return 0;
//}

//实现函数init()，初始化数组为全0
//void InitArr(int arr[],int sz)
//{
//	int i = 0;
//	
//	for (i = 0; i<sz; i++)
//	{
//		if (arr[i] != 0)
//		{
//			arr[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	InitArr(arr,sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//实现print(),打印数组的每个元素
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}

//实现reverse()函数完成数组元素的逆置
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//
//		left++;
//		right--;
//	}
//	
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//将数组A中的元素和数组B中的内容进行交换（数组一样大）
void change(int arr1[], int arr2[], int sz1, int sz2)
{
	int k = 0;
	for (k = 0; k < sz1; k++)
	{
		int tmp = arr1[k];
		arr1[k] = arr2[k];
		arr2[k] = tmp;
	}
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6 };
	int arr2[] = { 7,8,9,10,11,12 };

	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);

	change(arr1, arr2, sz1, sz2);

	int i = 0;
	for (i = 0; i < sz1; i++)
	{ 
		printf("%d ", arr1[i]);
	}

	printf("\n");

	int j = 0;
	for (j = 0; j < sz2; j++)
	{
		printf("%d ", arr2[j]);
	}

	return 0;

}