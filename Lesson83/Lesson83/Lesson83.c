#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


//人


////第二种
//struct Peo
//{
//	char name[20];
//	char tele[12]; //11位电话号码+\0
//	char sex[5];  //男 女 保密（1个汉字占2个字符）
//	int  height;
//}p1, p2;
////p1,p2是使用struck Peo结构类型创建的2个全局的结构体变量

//struct Peo  
//{
//	char name[20];
//	char tele[12]; 
//	char sex[5];  
//	int  height;
//};
//
//struct Stu
//{
//	struct Peo p;
//	int num;
//	float f;
//};
//
//void print1(struct Peo p)  //接受结构体变量的数据进行打印
//{
//	printf("%s %s %s %d\n", p.name, p.tele, p.sex, p.height);
//	//结构体变量.成员变量
//}
//
//void print2(struct Peo* tp)  //接受结构体变量的地址进行打印
//{
//	printf("%s %s %s %d\n", tp->name, tp->tele, tp->sex, tp->height);
//	//结构体指针->成员变量
//}
//
//int main()
//{
//	struct Peo p1 = {"张三","12345678901","男",181};
//	struct Stu s = { {"李四","12345687910","女",165},100,3.14f };
//
//	printf("%s %s %s %d\n", p1.name, p1.tele, p1.sex, p1.height);
//	printf("%s %s %s %d %d %f\n", s.p.name, s.p.tele, s.p.sex, s.p.height,s.num,s.f);
//
//	print1(p1);
//	print2(&p1);
//
//	return 0;
//}

//练习

//汉明权重（新思路）
//int count_num_of_1(int n)
//{
//	int count = 0;
//	while (n)  //当1全都被按位与消掉了以后，就变成了0
//	{
//		n = n & (n - 1);//每按位与一次之后，二进制序列都会少1个1
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int n = count_num_of_1(num);
//	printf("%d\n", n);
//	return 0;
//}

//判断一个数是不是2的n次方（n>=1）
//int main()
//{
//	int num = 0;
//	int count = 0;
//	int i = 0;
//	scanf("%d", &num);
//	if ((num & (num - 1)) == 0)
//	{
//		for (i = 0; ((num >> i) & 1) == 0; i++)
//		{
//			count++;
//		}
//		printf("这个数一定是2的%d次方\n", count);
//
//	}
//	else
//	{
//		printf("这个数不是2的n次方\n");
//	}
//	return 0;
//}

//获取一个整数二进制序列中所有的偶数位和奇数位，并分别打印出二进制序列
//int main()
//{
//	int i = 0;
//	int num = 0;
//	scanf("%d", &num);
//
//	//获取奇数位的数字
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", ((num >> i) & 1));
//	}
//
//	printf("\n");
//
//	//获取偶数位的数字
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", ((num >> i)& 1));
//	}
//	return 0;
//}

//X型图案
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (i == j)
//			{
//				printf("*");
//			}
//			else if (i + j == n - 1)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//获得月份天数
int main()
{
	int year = 0;
	int month = 0;
	int days_normal[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int days_leap[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	//确保月份数值与数组下标一一对应

	scanf("%d %d", &year, &month);

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))//判断闰年
	{
		printf("%d\n", days_leap[month]);
	}
	else  //平年
	{
		printf("%d\n", days_normal[month]);
	}

	return 0;
}