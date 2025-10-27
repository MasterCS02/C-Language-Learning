#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


// 折半查找
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
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
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//		if (left > right)
//		{
//			printf("找不到\n");
//		}
//	}
//
//	return 0;
//}

//练习4（编写代码，演示多个字符从两端移动，向中间汇聚）

//效果示意图
//welcome to bit!
// 
//###############
//w#############!
//we###########t!
//wel#########it!
//...
//welcome to bit!

#include<windows.h> //Sleep函数的头文件
#include<stdlib.h>  //system库函数的头文件
//int main()
//{
//	char arr1[] = { "welcome to bit!!!!" };
//	char arr2[] = { "##################" };
//
//	int left = 0;
//	int right = strlen(arr1)-1;  //strlen可以求字符串中字符元素的个数，\0不会被算在内
//
//	//上式也等于
//	//int right=sizeof(arr1)/sizeof(arr[0])-2
//
//	while (left<=right)
//	{
//		//将arr1的元素相应地赋值到arr2中的元素
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//
//		printf("%s\n", arr2);
//
//		//形成动画效果
//		Sleep(500);  //暂缓执行程序的函数，单位是毫秒
//
//		//清空屏幕
//		system("cls");  //system是一个库函数，可以执行系统命令
//
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}

//练习5（编写代码实现，模拟用户登录情景，并且只能登陆三次）
//int main()
//{
//	int i = 0;
//
//	//假设密码是字符串
//	char password[20] = {0};
//
//	for (i = 0; i < 3; i++)  //只有3次登录机会
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//
//		//比较2个字符串是否相等，不能使用==，而应该使用一个库函数strcmp
//		//如果返回值为0，则说明2个字符串相等
//		if (strcmp(password, "ll64126412") == 0) 
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均输入错误，退出程序\n");
//	}
//
//	return 0;
//}

//猜数字游戏

//#include<time.h>
//void menu()  //设计菜单
//{
//	printf("************************\n");
//	printf("********猜数字游戏*******\n");
//	printf("*******  1.Play  *******\n");
//	printf("*******  0.Exit  *******\n");
//	printf("************************\n");
//}
//
//void game()  //猜数字游戏的输入逻辑
//{
//	//1.生成随机数，使用rand函数,0~RAND_MAX(32767)
//	//让随机数的范围限定在1-100区间
//
//	int ret = rand()%100+1;//（1）（5）
//
//	//2.猜数字
//	int guess = 0;
//	while(1)  //无限循环，直到玩家猜对为止
//	{
//		printf("请输入你猜的数字（1-100）:>");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜小了\n\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了！\n\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//（2）（3）
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);  //输入1或0
//
//		switch (input)
//		{
//		case 1:
//			game();//猜数字的输入逻辑
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新输入！\n");
//			break;
//		}
//	} 
//	while(input);//当input=0时，条件为假，自动退出程序
//
//	return 0;
//}

//goto语句
//int main()
//{
//again:
//	printf("hehe\n");
//	printf("haha\n");
//	goto again;
//	return 0;
//}

//关机程序
//1.电脑运行起来后，1分钟内关机
//2.如果输入：我是猪，就取消关机

//goto版本
//int main()
//{
//	system("shutdown -s -t 60");
//
//again:
//	printf("请注意，你的电脑在60s内关机，如果输入：我是猪，就取消关机\n");
//
//	char input[20] = { 0 };
//
//	scanf("%s", input);
//
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//
//	return 0;
//}

//while版本
//int main()
//{
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("请注意，你的电脑在60s内关机，如果输入：我是猪，就取消关机\n");
//
//		char input[20] = { 0 };
//
//		scanf("%s", input);
//
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}


//函数
//库函数
//int main()
//{
//	char arr[20] = "hello world";
//	memset(arr, 'x', 5);
//
//	printf("%s\n", arr);
//	return 0;
//}

//自定义函数

//方法一
//int get_max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_max(a,b);
//
//	printf("%d\n", m);
//	return 0;
//}

//方法二
//int get_max(int x, int y)  //函数的定义
//{
//	return(x > y ? x : y);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	//函数的调用
//	int m = get_max(a, b);
//
//	printf("%d\n", m);
//	return 0;
//}


//写一个函数可以交换两个整型变量的内容
//错误示例
//void Swap(int x, int y)  //x和y是形式参数
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
////
////当实参传递给形参的时候，形参是实参的一份临时拷贝
////对形参的修改不会影响实参
////
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前:a=%d b=%d\n", a, b);
//
//	//交换
//	Swap(a,b);  //a和b叫实参
//	printf("交换后:a=%d b=%d\n", a, b);
//
//	return 0;
//}

//思路
//int main()
//{
//	int a = 10;
//	int* p = &a;
//
//	a = 20;
//	*p = 30;
//
//	return 0;
//}

//正确示例
void Swap(int *px, int *py)  
{
	int z = *px; //z=a
	*px = *py;   //a=b
	*py = z;     //b=a
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前:a=%d b=%d\n", a, b);

	
	Swap(&a, &b);  
	printf("交换后:a=%d b=%d\n", a, b);

	return 0;
}
