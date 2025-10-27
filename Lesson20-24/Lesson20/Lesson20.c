#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//typedef

//typedef unsigned int uint;//使用typedef关键字将unsigned关键字给重命名为uint
//
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
////将struct Node这个结构体直接重命名简化为Node
//
//int main()
//{
//	unsigned int num = 0;//unsigned int表示无符号整数：只能表示0或正数，该类型下能表示的最大值会更大
//	uint num2 = 1;
//	struct Node n;
//	Node n2;
//
//	return 0;
//}

//static修饰局部变量

//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)//循环10次,决定了test函数打印结果的次数
//	{
//		test();
//		i++;
//	}
//
//	return 0;
//}


//static修饰全部变量

//声明外部符号
//extern int g_val;//g_val变量来自于外部文件
//
//int main()
//{
//	printf("%d\n", g_val);
//
//	return 0;
//}
//static修饰全局变量的时候，全局变量的外部链接属性，就变成了内部链接属性，其他源文件（.c）就不能再使用到该全局变量了


//static修饰函数

//extern int Add(int x, int y);//引用外部函数；但如果外部函数被static时，就不可以调用了
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int z = Add(a, b);
//	printf("%d\n", z);
//
//	return 0;
//}

//retgister寄存器

//int main()
//{
//	register int num = 10;//建议10存放在寄存器中
//	return 0;
//}

//define 定义标识符常量
//#define NUM 100

//int main()
//{
//	printf("%d\n", NUM);
//	int n = NUM;
//	printf("%d\n", n);
//	int arr[NUM] = { 0 };
//	//define定义常量，NUM就是常量
//
//	return 0;
//}

//define 定义宏
//宏有参数

//#define ADD(x,y) ((x)+(y))
//ADD是宏名，x和y是参数，参数是无类型的，((x)+(y))是宏体

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = ADD(a, b);
//
//	printf("%d\n", c);
//
//	return 0;
//}


//指针变量

//int main()
//{
//	int a = 10;//向内存申请4个字节，存储10
//
//	printf("%p\n", &a);//%p用于打印地址
//	int* p=&a;//&是取地址操作符，取出a的地址
//	//p就是指针变量，int*是变量类型：*说明p是指针变量，int说明p指向的对象是int类型的
//
//	*p=20;
//	//解引用操作符，意思就是通过p中存放的地址，找到p所指向的对象，即*p就是p指向的对象，也就是a，所以*p=20意思就是，给p所指向的对象a赋值20
//	printf("%d\n", a);
//
//
//	char ch = 'w';
//	char* pc = &ch;
//	printf("%p\n", pc);
//
//	return 0;
//}

//指针变量的大小

//int main()
//{

//	printf("%zu\n", sizeof(char*));//8
//	printf("%zu\n", sizeof(short*));//8
//	printf("%zu\n", sizeof(int*));//8
//	printf("%zu\n", sizeof(float*));//8
//	printf("%zu\n", sizeof(double*));//8
//
//	return 0;
//}

//结构体

//struct Stu//这就是定义了一个结构体类型，可以用它来创建一个变量
//{
//	//结构体的成员
//	char name[20];
//	int age;
//	char gender[10];
//	char tele[12];
//};
//
//void print(struct Stu* ps)//ps是一个指针变量
//{
//	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).gender, (*ps).tele);
//	printf("%s %d %s %s\n", ps->name, ps->age, ps->gender, ps->tele);
//	//->
//	//结构体指针变量->成员名，找到每个结构体成员的地址，然后读取出各自地址中存储的数据进行输出
//}
//
//int main()
//{
//	struct Stu s = { "张三",20,"男","12345678901" };
//	printf("%s %d %s %s\n", s.name, s.age, s.gender, s.tele);
//	// 结构体对象.成员名
//
//	print(&s);
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a = 0;
    scanf("%d", &a);
    if (a % 5 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}