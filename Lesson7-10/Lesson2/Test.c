#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//例子1：用const修饰的常变量
// 
//int main()
//{
	//30;
	//3.14;
	//'w';//单引号内是字符常量
	//"abc";//双引号内是字符串常量

	//const int a = 10;//这就是const修饰的常变量
	//a = 20;
	//printf("%d\n", a);

	//const int n = 10;
	//int arr[n] = { 0 };
	
	//return 0;
//}

//例子2：用define定义的标识符常量

//#define max 100
//#define str "abcd"
//
//int main()
//{
//	printf("%d\n", max);
//	int a = max;
//	printf("%d\n", a);
//	printf("%s\n", str);//%s打印字符串
//
//	return 0;
//}

//例子3：枚举常量


//三原色
//enum Color
//{
//	//枚举常量
//	RED,//默认值是0
//	GREEN,//默认值是1
//	BLUE,//默认值是2
//};
//
////性别
//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//
//int main()
//{
//	int num = 10;
//	enum Color c = RED;
//	printf("%d\n", num);
//
//	return 0;
//
//}

//例子4：字符串

//int main()
//{
	//#qwer$
	//char 字符类型
	//'a'

	//char ch = 'w';
	//char arr1[] = "abcdef";//如果不确定字符串中的字符有多少个，则arr[]中的数字也可省略
	//char arr2[] = { 'a', 'b', 'c', 'd', 'e', 'f','\0' };

	//int len1=strlen("abc");//求字符串长度的一个函数
	//printf("%d\n", strlen(arr1));
	//printf("%d\n", strlen(arr2));

	//printf("%s\n", arr1);
	//printf("%s\n", arr2);//如果直接打印，因为没有\0结束标志，会导致指令一直在内存中寻找\0结束标识符，会一直打印，直到找到标识符为止

	//return 0;
//}

//例子5：转义字符
// 
//int main()
//{
//	printf("abc\n");//    \n为换行，即是一个转义字符
//	printf("abcn");//      n就是一个普通字符
//
//	return 0;
//}

//int main()
//{
//	printf("abc0ef");//0就是一个普通字符
//	printf("\n");
//	printf("abc\0ef");//   \0是一个结束标志，也代表转义字符,字符串遇到结束标志则自动停止
//	return 0;
//}

//%d - 打印整型
//%c - 打印字符
//%s - 打印字符串
//%f - 打印单精度浮点型（float）的数据
//%lf - 打印双精度浮点型（double float）的数据
//%zu - 打印sizeof的返回值


//例子6：\'的用法：

//int main()
//{
//	//printf("%c\n", ''');(这行代码是没有办法把中间那单个单引号打出来的，因为编译器会默认前两个单引号为一对，而最后一个单引号就落单了)
//	printf("%c\n", '\'');//所以，如果需要打印单引号，则需要对其进行转义，即\'
//
//	return 0;
//}

//例子7：打印字符串的注意事项：

//int main()
//{
	//printf("abcdef\n");//打印字符串时，可以直接双引号输入内容；但是打印整型不可以
	//printf("%s\n", "abcdef");//与上述代码打印结果相同
	//printf("\"");//打印单个双引号，就是用\"进行转义
	//printf("\n"); 
	//printf("abcd\\0ef");//如果想要打印字符串abcd\0ef，则需要在\0前再加一个\,防止\0被转义
	//printf("\a");//警报音
	//printf("abc\tdef");//水平制表符\t，和tab键的效果相同
	//printf("%c\n", '\130');//打印结果为X，其中，130为八进制数，\130代表把八进制的130转换为10进制之后，得出来的10进制数字在ASCII码表中，所对应的字母，即X。此类转义字符为\ddd类型
	//printf("%c\n", '\x63');//打印结果为c，其中，x63为16进制数，\x63代表把十六进制的63转换为10进制之后，得出来的10进制数字在ASCII码表中，所对应的字母，即c。此类转义字符为\xdd类型
	//printf("%d\n", strlen("qwer t"));//空格也是字符
	//printf("%d\n", strlen("c:\test\628\test.c"));//考题，制表符的字符长度为一个单位，8不属于八进制的数字
//	return 0;
//}

//例子8：注释
/*
int main()
{
	
	int a = 10;
	int b = 20;
	
	return 0;
}
*/

//例子9：
//函数

//int Add(int x, int y);//想要使用Add函数，则需要先对Add函数进行定义，Add为函数名，x与y是函数参数，int是返回类型。
//{
//	int z = 0;
//	z = x + y;
//	return z;//大括号里的内容是函数体
//	//return (x + y);
//}
//
//int main()
//{
//	int n1 = 0;
//	int n2 = 0;
//	//输入
//	scanf("%d %d", &n1, &n2);
//	//int sum = n1 + n2;
//	int sum = Add(n1, n2);
//	printf("%d\n", sum);
//	return 0;//因为返回的是0，0是一个整数，所以要在最前面加上int
//}

//例子10 数组：
//int main()
//{
//	//int a = 10;
//	//int b = 11;
//	//int c = 12;
//	//int d = 0;
//	//int e = 1;
//	//...0-9(都是整数)
//
//	int arr[10] = { 10,11,12,13,14,15,16,17,18,19 };
//	//printf("%d\n", arr[8]);
//
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d ", arr[i]);
//		i = i + 1;
//	}
//
//	return 0;
//}


int get_max(x, y)//构建比较最大值的函数
{
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	int n1 = 0;
	int n2 = 0;//定义两个变量
	scanf("%d %d", &n1, &n2);//输入两个变量的值
	int max = get_max(n1, n2);
	printf("%d\n", max);
	return 0;
}