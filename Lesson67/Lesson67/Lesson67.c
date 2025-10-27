#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 移位操作符
// 
// 左移操作符
//int main()
//{
//	int a = 7;
//	int b = a << 1;  //a自身不变
//
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//
//	return 0;
//
//}

//int main()
//{
//	int a = -7;
//	int b = a << 1;  //-14
//
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//
//	return 0;
//}

// 右移操作符
//int main()
//{
//	int a = - 7;
//	int b = a >> 1;  //-4
//
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//
//	return 0;
//}

//位操作符

//int main()
//{
//	int a = 3;
//	int b = -5;
//
//	int c = a & b; //按位与
//	int d = a | b; //按位或
//	int e = a ^ b; //按位异或
//
//	//00000000000000000000000000000011 -  3的补码（正数原返补相同）
//	//10000000000000000000000000000101 - -5的原码
//	//11111111111111111111111111111010 - -5的反码
//	 
//	//11111111111111111111111111111011 - -5的补码
//	//00000000000000000000000000000011 -  3的补码
//	//00000000000000000000000000000011 -  3和-5按位与的结果，即3
//
//	//11111111111111111111111111111011 - -5的补码
//	//00000000000000000000000000000011 -  3的补码
//	//11111111111111111111111111111011 -  3和-5按位或的结果，即-5
//
//	//11111111111111111111111111111011 - -5的补码
//	//00000000000000000000000000000011 -  3的补码
//	//11111111111111111111111111111000 -  3和-5按位异或的补码结果（真值不相同时为真）
//	//11111111111111111111111111110111 -  反码结果
//	//10000000000000000000000000001000 -  原码结果，即-8
//
//	printf("c=%d\n", c);  // 3
//	printf("d=%d\n", d);  //-5
//	printf("e=%d\n", e);  //-8
//
//	return 0;
//}

//不能创建临时变量（第三个变量），实现两个数的交换

//int main()
//{
//	int a = 3;
//	int b = 5;
//	
//	a = a ^ b;  //a = 3 ^ 5
//	b = a ^ b;  //b = 3 ^ 5 ^ 5 = 3
//	a = a ^ b;  //a = 3 ^ 5 ^ 3 = 5
//
//	return 0;
//}

//编写代码实现：求一个整数存储在内存中二进制中1的个数(汉明权重)
//求补码的二进制中1的个数
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	int m = 0;
//	int count = 0;
//
//	while(num != 0)
//	{
//		m = num & 1;  //按位与，若最后一位为1，则结果为1；反之为0
//		num=num >> 1;  //num右移一位，丢弃原来已经统计过的最右边的数  num >>= 1
//
//		if (m == 1)
//		{
//			count++;
//		}
//	}
//	printf("count=%d\n", count);
//
//	return 0;
//}

//赋值操作符
//int main()
//{
//	int a = 3;
//	a = a + 5;
//	a += 5;
//
//	a = a >> 1;
//	a >>= 1;
//	return 0;
//}

//单目操作符
//int main()
//{
//	int a = 0;
//
//	//~ 按二进制位取反
//	//00000000000000000000000000000000 - a的补码序列（0算正数）
//	//11111111111111111111111111111111 - a按位取反之后的补码结果,~a
//	//11111111111111111111111111111110 - 反码
//	//10000000000000000000000000000001 - 原码 -1
//
//	printf("%d\n", ~a);
//
//	return 0;
//}

//int main()
//{
//	int a = 13;
//	//00000000000000000000000000001101 - a的补码
//	//让第二位的0变成1
//	//00000000000000000000000000001101 - a的补码
//	//00000000000000000000000000000010 - 1<<1
//	//进行按位或操作
//
//	//让第n位的0变成1，就让这个数按位或上1左移（n-1）位后的结果
//	//即a |= (1 << (n-1))
//
//	//让第n位的1变成0，就让这个数按位与上【1左移（n-1）位按位取反后】的结果
//	//00000000000000000000000000001101 - a的补码
//	//00000000000000000000000000001000 - 1 << 3
//	//11111111111111111111111111110111 - ~ ( 1 << 3 )
//	//00000000000000000000000000000101 - a &= ~ (1 << 3)
//
//
//	a = a | (1 << 1);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	printf("%d\n", a--); //10，先把a的值传给printf函数，再自减1
//	printf("%d\n", a);  //9
//
//	test(a--); //先把a的值传给函数test，再自减1
//
//	return 0;
//
//}

//逻辑操作符
//面试题
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//因为a++的结果为0，所以后面的++b和d++都不会执行
//	//短路运算（左边的结果为0，右边不再计算；左边的结果不为0，则右边继续计算）
//
//	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);  //1,2,3,4
//	return 0;
//}

//变式
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ || ++b || d++;
//	//a=1为真，对于逻辑或而言，表达式已经为真了，所以++b和d++都不继续运算了
//
//	printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);  //2,2,3,4
//	return 0;
//}

//下标引用操作符
//int main()
//{
//	int arr[10] = { 0 };
//	//arr[7] --> *(arr+7) --> *(7+arr) --> 7[arr]
//	// C 语言数组下标的本质是“指针 + 偏移”，加法可以交换
//	//*(arr+7)就是指跳过7个元素，指向第8个元素
//
//	arr[7] = 8;
//	7[arr] = 9; //合法，但谁这么写谁就是纯傻逼
//
//	return 0;
//}

//结构体成员访问操作符

//struct Stu
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//void set_Stu(struct Stu* ps)
//{
//	//结构体对象.成员
//	strcpy((*ps).name, "zhangsan");
//	(*ps).age = 20;
//	(*ps).score = 100.0;
//
//	//结构体指针->成员
//	strcpy(ps->name, "zhangsan");
//	ps -> age = 20;
//	ps -> score = 100.0;
//	
//}
//
//void print_Stu(struct Stu s)
//{
//	printf("%s %d %.2lf\n", s.name, s.age, s.score);
//}
//
//int main()
//{
//	struct Stu s = { 0 };
//	set_Stu(&s);
//	print_Stu(s);
//
//	return 0;
//}

//表达式求值
//int main()
//{
//	//char类型的数据有符号之分，根据二进制序列中的最高位来决定
//	char a = 5;
//	char b = 126;
//	char c = a + b;
//
//	//00000000000000000000000000000101 -   5的补码
//	//00000000000000000000000001111110 - 126的补码
//	//00000000000000000000000010000011 - a+b
//	// 
//	//char a = 00000101
//	//char b = 01111110
//	//char c = a + b = 00000000000000000000000000000101 + 00000000000000000000000001111110 = 10000011
//	//                 运算时高位补齐（符号位为0）          运算时高位补齐（符号位为0）         实际存储的比特数
//	
//	//打印，高位补充，根据c的符号位来补位，即1
//	//11111111111111111111111110000011 - 补码c
//	//11111111111111111111111110000010 - 反码c
//	//10000000000000000000000001111101 - 原码c，结果为-125
//
//	printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//
//	if (a == 0xb6)
//		printf("a"); //发生整型提升，值改变
//
//	if (b == 0xb600)
//		printf("b");  //发生整型提升，值改变
//
//	if (c == 0xb6000000)
//		printf("c");  //未发生整型提升，值不改变
//
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c)); //1
//	printf("%u\n", sizeof(+c));//4  发生了运算，产生了整型提升，c变成了32个字节
//	printf("%u\n", sizeof(-c));//4  发生了运算，产生了整型提升，c变成了32个字节
//	return 0;
//}


//作业
int i;
int main()
{
    i--;
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}


//求两个数二进制中不同位的个数
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);

	int compare = 0;
	compare = m ^ n;  
	//通过按位异或来确定有多少位不相同，不相同位的个数等于compare中二进制补码中1的个数

	int cal = 0;
	int count = 0;

	while (compare != 0)
	{
		cal = compare & 1;  //按位与1，确认最后一位是否为1
		compare = compare >> 1;  //compare向右移1位，从而逐一比较

		if (cal == 1)  //若为1，统计数+1
		{
			count++;
		}
	}

	printf("有%d位不同\n", count);

	return 0;
}

//打印一个整数的二进制序列
int main()
{
	int num = 0;
	scanf("%d", &num);
	int arr[32] = { 0 };  //装32个数字
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;

	while (num != 0)
	{
		int cpr = num & 1;
		num = num >> 1;
		
		if (right >= 0)
		{
			if (cpr == 1)
			{
				arr[right] = 1;
				right--;
			}
			else
			{
				arr[right] = 0;
				right--;
			}
		}
		else
		{
			break;
		}
	}
	int i = 0;

	printf("该整数的二进制补码序列为:\n");
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}

	return 0;
}

//计算求和Sn=a+aa+aaa+aaaa+aaaaa
int Sum(int a,int b)
{
	int i = 0;
	int tmp = 0;
	int sum = 0;
	for (i = 0; i < b; i++)
	{
		tmp = a + tmp*10;
		sum = sum + tmp;

	}
	return sum;
	
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);

	int sum = Sum(a,b);
	printf("%d\n", sum);

	return 0;

}

//打印水仙花数

//计算多少位
int Digitnum(int n)
{
	int count = 0;
	do
	{
		count++;
		n = n / 10;
	} 
	while (n >= 1);

	return count;

}
//
//次方函数
int multi(int r,int n)
{
	int i = 0;
	int tmp = 1;

	for (i = 1; i <= n; i++)
	{
		tmp = tmp * r;
	}

	return tmp;
}

int main()
{
	int i = 0;
	int num = 0;
	//设计一个计算多少位的函数
	for (num = 0; num <= 100000; num++)
	{
		int n = Digitnum(num); //num有多少位

		//拆分数字
		int r = 0;//num依次模10之后的余数就是在不同位上的数字
		int sum = 0;
		int y = num;

		for (i = 1; i <= n; i++)
		{
			r = y % 10;
			y = y / 10;

			sum = sum + multi(r, n);

		}
		if (sum == num)
		{
			printf("%d ", num);
		}
	}
	return 0;
}

//青蛙跳台阶
//青蛙可以一次跳一个台阶，也可以跳两个台阶
int fib(int n)
{
	if (n <= 2)
	{
		return n;
	}
	else if (n > 2)
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int m = fib(n);

	printf("%d\n", m);
	return 0;
}

//练习6（序列中删除指定数字）
int main()
{
	int n = 10;
	int arr[10] = { 0 };

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d ", &arr[i]);
	}

	int del = 0;
	scanf("%d", &del);

	int j = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] != del)
		{
			arr[j++] = arr[i];
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
	
}

//最高分与最低分之差
int main()
{
	int n = 10;
	int arr[10] = {0};
	int max = 0;
	int min = 100;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int cs = max - min;
	printf("%d\n", cs);
	return 0;

}

//字母大小写转换

int main()
{
	char ch = 0;

	//根据scanf函数的返回值进行判断，如果成功读取到一个字符，则返回1；若读取失败，则会返回EOF
	while (scanf("%c",&ch)==1)  
	{
		if (ch >= 'a' && ch <= 'z')
		{
			printf("%c\n", ch - 32);
			getchar();

		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			printf("%c\n", ch + 32);
			getchar();

		}
		else
		{
			printf("输入有误，请重试！\n");
			getchar();
		}
	}

	return 0;
}

int main()
{
	char ch = 0;

	//根据scanf函数的返回值进行判断，如果成功读取到一个字符，则返回1；若读取失败，则会返回EOF
	while (scanf("%c",&ch)==1)  
	{
		if (islower(ch))
		{
			printf("%c\n", toupper(ch));
			getchar();

		}
		else if (isupper(ch))
		{
			printf("%c\n", tolower(ch));
			getchar();

		}
		else
		{
			printf("输入有误，请重试！\n");
			getchar();
		}
	}

	return 0;
}



//判断是不是字母
int main()
{
	char ch = 0;
	while (scanf("%c", &ch) == 1)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			printf("%c是一个字母\n", ch);
		}
		else
		{
			printf("%c不是一个字母\n", ch);

		}
		getchar();
	}

	return 0;

}

int main()
{
	char ch = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (isalpha(ch))
		{
			printf("%c是一个字母\n", ch);
		}
		else
		{
			printf("%c不是一个字母\n", ch);

		}
		getchar();
	}

	return 0;

}

//变种水仙花数
int main()
{
	int i = 0;
	for (i = 10000; i <= 99999; i++)  //生成所有五位数
	{
		int sum = 0;
		int r = 0;
		//sum和r必须要放在循环体里面，以确保每一次循环结束之后，这两个数字都能够初始化，以准备继续进行新的循环
		for (r = 1; r <= 4; r++)
		{
			int k = (int)pow(10, r);  //pow函数返回的是浮点类型的数字,要强制类型转换成int
			sum += (i / k) * (i % k);
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}

	return 0;
}