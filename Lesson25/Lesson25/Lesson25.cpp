#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	if (3 == 5)
		printf("hehe\n");

	int age = 20;
	if (age > 18)
		printf("成年\n");

	int age = 10;
	if (age < 18)//默认if语句后面跟1条语句，如果要跟多条语句，则需要加上大括号
	{
		printf("未成年\n");
		printf("不能饮酒\n");
	}
	else
		printf("成年\n");


	多分支
	int age = 56;
	if (age < 18)
		printf("青少年\n");
	else if (age >= 18 && age < 28)
		printf("青年\n");
	else if (age >= 28 && age < 40)
		printf("中年\n");
	else if (age >= 40 && age < 60)
		printf("壮年\n");
	else if (age >= 60 && age <= 100)
		printf("老年\n");
	else
		printf("老寿星\n");

	return 0;
}

int main()
{
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("呵呵\n");
		else
			printf("哈哈\n");
			
	return 0;
}

更好的编写方式
int main()
{
	int a = 0;
	int b = 2;
	if (a == 1)
	{
		if (b == 2)
			printf("呵呵\n");
		else
			printf("哈哈\n");
	}
	return 0;
}

1.变量的命名（有意义，规范）
2.空格，空行，换行
int main()
{
	char first_name[20] = { 0 };//定义一个长度为20的字符数组，这个数组里可以存放20个字符
	char FirstName[20] = { 0 };

	return 0;

}


不好的代码编写方式
int test()
{
	int a = 4;
	if (a == 3)
		return 1;
	return 0;
}

int main()
{
	int r = test();
	printf("%d\n", r);
	return 0;
}

良好的代码编写方式
int test()
{
	int a = 4;
	if (a == 3)
		return 1;
	else
		return 0;
}

int main()
{
	int num = 3;
	if (num == 5)
		printf("hehe\n");
	
	return 0;
}

//或者
int main()
{
	int num = 3;
	if (5 == num)//更好地防止将等于和赋值搞混出现的错误
		printf("hehe\n");

	return 0;
}


判断奇偶数
int main()
{
	int a = 0;
	scanf("%d", &a);
	if (a % 2 == 0)
		printf("偶数\n");
	else
		printf("奇数\n");

	return 0;
}



输出1-100之间的奇数
方法一
void test()
{
	static int num = 1;
	if (num % 2 == 1)
		printf("%d\n", num);
	num++;

}

int main()
{
	int i = 0;
	while (i < 100)
	{
		test();
		i++;
	}

	return 0;
}

方法二
int main()
{
	int i = 1;
	while (i < 100)
	{
		if (i % 2 == 1)
			printf("%d\n", i);
		i++;
	}

	return 0;
}

switch语句
输入1-7,分别打印对应的星期
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("Monday\n");
		break;

	case 2:
		printf("Tuseday\n");
		break;

	case 3:
		printf("Wendesday\n");
		break;

	case 4:
		printf("Thursday\n");
		break;

	case 5:
		printf("Friday\n");
		break;

	case 6:
		printf("Saturday\n");
		break;

	case 7:
		printf("Sunday\n");
		break;

	}

	return 0;

}

输入1-5，输出weekday;输入6-7，输出weekend
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;

	case 6:
	case 7:
		printf("weekend\n");
		break;
	}

	return 0;
}


default语句
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;

	case 6:
	case 7:
		printf("weekend\n");
		break;

	default:
		printf("选择错误\n");
		break;
	}

	return 0;
}

switch语句练习
int main()
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:m++;//m=3
	case 2:n++;//n=2
	case 3:
		switch (n)//n=2
		{
		case 1:n++;
		case 2:m++;n++;//m=4;n=3
			break;
		}//继续向下运行
	case 4:m++;//m=5;n=3
		break;
	default:
		break;
	}
	printf("m=%d, n=%d\n", m, n);
}

循环语句
int main()
{
	while(1)
	{
		printf("hehe\n");
	}

	return 0;

}

int main()
{
	int i = 1;
	while (i <= 10)
	{
		printf("%d\n", i);
		i++;
	}
	return 0;
}


break语句
int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (5 == i)
			break;

		printf("%d\n", i);
		i++;
	}
	return 0;
}


continue语句
int main()
{
	int i = 0;
	while (i <= 10)
	{
		i++;
		if (5 == i)
			continue;
		//continue一旦被执行，将会跳出本次循环中continue后面的语句，直接去判断下一次要不要进行循环
		printf("%d\n", i);

	}
	return 0;
}

getchar and putchar
int main()
{
	//int ch = 0;
	//while(getchar())//getchar()从输入缓冲区中获取字符
	int ch = getchar();//把获取到的字符的ASCII码值赋值到ch中
	//getchar()如果遇到end of file或者读取错误时，会返回EOF，而EOF定义值是-1，即为一个整型，所以返回值类型为int


	//根据ch中的ASCII码值，将对应的字符打印出来
	printf("%c\n", ch);//方法1
	putchar(ch);//方法2


	printf("%d\n", ch);//仅将ch中的ASCII码值打印出来


	return 0;
}


int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)//!=EOF即表明的是返回值不是EOF时
	{
		putchar(ch);
	}

	return 0;
}


清空缓存区
int main()
{
	char password[20] = {0};
	//假设密码是一个字符串
	printf("请输入密码：");
	scanf("%s", password);//数组名本身就是一个地址，所以没有必要再加上&取地址符

	//%s会从输入缓冲区中读取字符，直到遇到"空格"、"Tab"、"换行符"才会停止

	//假设输入123456，实则在输入缓冲区中存入了123456\n共7个字符。scanf拿走123456之后，在输入缓冲区中还留下了一个\n

	//getchar();//读取输入缓冲区中剩余的\n
	int ch = 0;
	while ((ch = getchar()) != '\n')
	{
		;
	}

	printf("请确认密码（Y/N）:");
	int ret = getchar(); 
	if ('Y' == ret)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}

int main()
{
	char ch = '\0';//把字符型变量初始化为空字符，如同int a = 0
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch>'9')
			continue;
		//判断ch字符的ASCII码值是否在这个区间范围内，即小于字符0的ASCII码的值，或大于字符9的ASCII码的值时，直接跳过下列语句，重新进入循环
		putchar(ch);
	}
	//只打印数字字符，跳过其他字符
	return 0;
}

int Max(int x, int y)
{
	int x = 0;
	int y = 0;
	if (x > y)
		return x;
	else
		return y;
}

int Min(int n, int m)
{
	int n = 0;
	int m = 0;
	if (n < m)
		return n;
	else
		return m;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int num1 = Max(a, b);
	int num2 = Min(a, b);
	int mod = num1 / num2;
	while (mod != 0)
	{

	}


}

