#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//例子1
// 
//int main()
//{
//	printf("hehe\n");
//	return 0;
//}

//例子2
// 
//int main()
//{
//	printf("%d\n",100);
//	return 0;
//}

//例子3
// 
//int b=20://全局变量
//
//int main()
//{
//	//int age = 20;//年龄
//	//double price = 66.6;//身高
//	//float weight = 62;//体重
//	int a=10；//局部变量
//	return 0;
//}

//例子4
// 
//写一个代码，计算2个整数的和
//scanf是一个输入函数
//printf是一个输出函数
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;//一开始就赋零，变量初始化
//	//输入2个整数
//	scanf("%d %d", &num1, &num2);
//	//求和
//	int sum = num1 + num2;
//	//输出
//	printf("%d\n", sum);
//	return 0;
//}

//例子5 局部变量的作用域
// 
//int main()
//{
//	int a = 10;
//	{
//		int a = 10;
//		printf("a=%d\n", a);
//	}
//	printf("a=%d\n", a);
//	return 0;
//}

//例子6 全局变量的作用域

//int a = 10;
//
//void test()
//{
//	printf("test-->%d\n", a);
//}
//
//int main()
//{
//	test();
//	{
//		printf("a=%d\n", a);
//	}
//	printf("a=%d\n", a);
//
//	return 0;
//}

//例子7 局部变量的生命周期
//int main()
//{
//	{
//		int a = 100;
//		printf("%d\n", a);
//	}
//	printf("%d\n", a);//a变量已经出了它的作用域，所以这行代码没有存在的意义了
//	return 0;
//}
