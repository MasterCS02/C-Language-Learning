#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

////判断是否为三角形
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (scanf("%d %d %d", &a, &b, &c) == 3)  //实现多组输入数据循环
//	{
//		//判断是不是三角形
//		//条件：任意两条边之和大于第三边
//		if ((a + b > c) && (a + c > b) && (b + c > a))
//		{
//			if ((a == b) && (b == c))  //判断等边三角形
//			{
//				printf("Equilateral triangle!\n");
//			}
//			else if (((a == b) && (b != c)) || ((a == c) && (b != a)) || ((b == c) && (a != c)))  //判断等腰三角形
//			{
//				printf("Isosceles triangle!\n");
//			}
//			else  //普通三角形
//			{
//				printf("Ordinary triangle!\n");
//			}
//		}
//		else  //不是三角形
//		{
//			printf("Not a triangle!\n");
//		}
//	}
//	return 0;
//}

////字符串逆序
//int main()
//{
//	char arr[10001] = { 0 };
//	//scanf("%s", arr);  scanf函数读到空格和\0就会自动停止，所以不使用
//	gets(arr);//输入字符串
//
//	//逆序
//	int left = 0;
//	int right = strlen(arr)-1;
//
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
//	printf("%s\n", arr);
//
//	return 0;
//}

//打印菱形

//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++)  //上半部分打印
//	{
//		//打印行
//
//		int j = 0;
//		//打印*号左边的空格（右边不需要打空格）
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//打印完空格后，开始打印*号
//		//接下来需要确定打印*号的个数
//		for (j = 0; j < 2 * i + 1; j++)  //确定打印*号的个数，即2*i+1
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)  //下半部分打印
//	{
//		//打印*号左边的空格
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//		//打印*号
//		for (j = 0; j < ( (2*line-1) - (2*(i+1)) ); j++)  //确定打印*号的个数
//		{
//			printf("*");
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

//struct stu
//{
//    int num;
//    char name[10];
//    int age;
//};
//
//
//void fun(struct stu* p)
//{
//    printf("%s\n", (*p).name);
//    return;
//}
//
//
//int main()
//{
//    struct stu students[3] = { 
//        {9801,"zhang",20},
//        {9802,"wang",19},
//        {9803,"zhao",18}
//    };
//
//    fun(students + 1);
//    return 0;
//}

//喝汽水问题

////我的版本
//int main()
//{
//	int bottle = 0;
//	int i = 0;
//
//	for (i = 20; i > 0; i--)
//	{
//		bottle++;
//		if (bottle % 2 == 0)
//		{
//			bottle++;
//		}
//	}
//
//	printf("%d\n", bottle);
//
//	return 0;
//}
//
////常规思路版本
//int main()
//{
//	int money = 20;
//	int drink = 0;
//	int empty = 0;
//
//	drink += money;  //喝掉20瓶
//	empty += money;  //有20个空瓶
//
//	int i = 0;
//	while (empty >= 2)
//	{
//		int new_drink = empty / 2;//每两瓶空瓶换到一瓶新汽水
//		drink += new_drink;
//		empty = new_drink + empty % 2;  
//		//本轮喝完之后新的空瓶 = 喝完换到的空瓶 + 上一轮剩下没换掉的空瓶
//	}
//
//	printf("%d\n", drink);
//
//	return 0;
//}

//最小公倍数问题
// 版本1：
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	int m = a > b ? a : b;  
//	//两个整数的最小公倍数至少会是两数较大的那一个
//	
//	while (1)
//	{
//		if (m % a == 0 && m % b == 0)
//		{
//			break;
//		}
//
//		m++;  //不符合条件就自增，直到符合
//	}
//
//	printf("%d\n", m);
//	return 0;
//}

//版本2：
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	int i = 1;
//
//	while (a * i % b)  //当这个表达式不等于0的时候，会一直循环
//	{
//		i++;
//	}
//	
//	printf("%d\n", a*i);
//	return 0;
//}

void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;

		left++;
		right--;
	}

}
int main()
{
	char arr[101] = { 0 };
	gets(arr);

	int len = strlen(arr);

	//把所有的顺序逆置
	reverse(arr, arr + len - 1);

	//找单词
	char* start = arr;
	while (*start)
	{
		char* end = start;

		while (*end != ' ' &&  *end != '\0')
		{
			end++;
		}

		reverse(start, end - 1);//此时end指向的是空格，所以它的前一位才是单词尾

		if(*end !='\0')
			end++;
		start = end;

	}

	printf("%s\n", arr);

	return 0;
}
