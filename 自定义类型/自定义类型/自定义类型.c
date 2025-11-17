#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//结构体内存对齐

#include <stddef.h>
//struct S1
//{
//	char c1;  //对齐数为1
//	int i;    //对齐数为4
//	char c2;  //对齐数为1
//
//	//该结构体的大小应为最大对齐数4的整数倍，即12
//};
//
//struct S2
//{
//	char c1;   //对齐数为1
//	char c2;   //对齐数为1
//	int i;     //对齐数为4
//
//	//该结构体的大小应为最大对齐数4的整数倍，即8
//
//};
//
//struct S3
//{
//	double d;  //对齐数为8
//	char c;    //对齐数为1
//	int i;     //对齐数为4
//
//	//该结构体的大小应为最大对齐数8的整数倍，即16
//
//};
//
////嵌套结构体
//struct S4
//{
//	char c1;      //对齐数为1
//	struct S3 s3; //对齐数为8（这个嵌套结构体的最大对齐数为8）
//	double d;     //对齐数为8
//
//	//该结构体的大小应为最大对齐数8的整数倍，即32
//};
//
//
//int main()
//{
//	struct S1 s1;
//	struct S2 s2;
//	struct S3 s3;
//	struct S4 s4;
//
//	printf("%d\n", sizeof(struct S1));  //12
//	printf("%d\n", sizeof(struct S2));  //8
//	printf("%d\n", sizeof(struct S3));  //16
//	printf("%d\n", sizeof(struct S4));  //32
//
//	printf('\n');
//
//	printf("%d\n", offsetof(struct S1, c1));  //0
//	printf("%d\n", offsetof(struct S1, i));   //4
//	printf("%d\n", offsetof(struct S1, c2));  //8
//
//
//	return 0;
//
//}


//#pragma pack(4)   //将默认对齐数改为4
//struct S
//{
//	int i;
//
//	double d;
//};
//#pragma pack()
//
//#pragma pack(1)   //将默认对齐数改为1
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//
//	return 0;
//}

//结构体传参
//struct  S
//{
//	int data[1000];
//	int num;
//};
//
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
//
//void print2(const struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ps->data[i]);
//	}
//	printf("%d\n", ps->num);
//
//}
//
//int main()
//{
//	struct S s = { {1,2,3},100 };
//
//	print1(s);   //传值调用(效率相对较低)
//	print2(&s);  //传址调用（优先）
//
//	return 0;
//}

//位段
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//
//	return 0;
//}

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//
//	return 0;
//
//}


//枚举
//enum Day  //这是一个枚举类型，不会在内存中占空间
//{
//	//枚举常量
//	Mon,  //0
//	Tues, //1
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun,  //6
//};
//
//int main()
//{
//
//	enum Day Wu = Fri;
//
//	printf("%d\n", Mon);  //0
//	printf("%d\n", Tues); //1
//	printf("%d\n", Wed);  //2
//
//	return 0;
//}

//联合
//union Un
//{
//	int i;
//	char c;
//};
//
//int main()
//{
//	union Un un;
//	
//	printf("%p\n", &un);
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//	//这三个地址是完全一模一样的
//
//	return 0;
//}

//int check_sys(void)
//{
//	union Un
//	{
//		int i;
//		char a;
//	}un;
//
//	un.i = 1;
//	return un.a;
//}
//
//int main()
//{
//	int a = 1;
//
//	int ret = check_sys(); 
//
//	if (ret == 1)
//		printf("小端");
//	else
//		printf("大端");
//
//	return 0;
//}

//union Un
//{
//	char arr[5];
//	int i;
//}un;
//
//int main()
//{
//	printf("%d\n", sizeof(union Un));  //8
//
//	printf("%p\n", &un.arr);
//	printf("%p\n", &un.i);
//	//两个变量的起始地址都是一样的
//
//	return 0;
//}

