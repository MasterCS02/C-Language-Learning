#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//模拟实现strlen

////计数器方法
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	assert(str != NULL);  
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t n = my_strlen(arr);
//	printf("%u\n", n);
//		
//	return 0;
//}

////strcpy的一个错误用法
//int main()
//{
//	char* p = "abcdef";
//	char arr[] = "bit";
//	strcpy(p, arr);
//
//	return 0;
//}

////strcpy模拟实现
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;  //先把目标字符串的起始地址给存好
//	while (*dest++ = *src++)  
//	{
//		;
//	}
//	//先赋值，再各自++，最后根据表达式返回值进行判断。
//	//若赋值了\0，则这个表达式的返回值为0，条件为假，自动退出循环
//	//省去了最后再增添一条赋值\0的语句
//	
//	return ret;  //返回目标字符串的起始地址
//
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	char* a = my_strcpy(arr2, arr1);
//	
//	printf("%s\n", a);
//
//	return 0;
//}

//strcat字符串追加
//模拟实现
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	//找到目标字符串的'\0'
//	while (*dest)
//	{
//		dest++;
//	}
//
//	//拷贝字符串
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	my_strcat(arr1, "world");
//
//	printf("%s\n", arr1);
//	//hello world
//
//	return 0;
//}

//模拟实现
//版本1
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}

//版本2（改进版）
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//
//int main()
//{
//	char arr1[20] = "zhangsan";
//	char arr2[] = "zhangsanfeng";
//
//	int ret = my_strcmp(arr1, arr2);
//	if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else if (ret == 0)
//	{
//		printf("==\n");
//	}
//	else
//	{
//		printf(">\n");
//	}
//
//	return 0;
//}

//strncpy
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "hello world";
//	strncpy(arr1, arr2, 5);  //只拷贝5个字符
//
//	printf("%s\n", arr1);
//	return 0;
//}

//strncat
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3);  //只追加3个字符，并会在末尾追加\0
//
//	printf("%s\n", arr1);  //hello wor
//	return 0;
//}

//strncmp
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//	int ret = strncmp(arr1, arr2, 4);  //比较4对字符
//
//	if (ret == 0)
//	{
//		printf("==\n");
//	}
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf(">\n");
//	}
//	
//	return 0;
//}

//strstr
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;  //被查找的主字符串起点
//	const char* s2 = str2;  //目标子串的起点
//	const char* p = str1;   //p用来记录每次比较的起点，位于主字符串
//
//	while (*p)  //确认p指针不是指向空位置
//	{
//		s1 = p;  //p指针是主字符串被查找的起始位置
//		s2 = str2;  //s2回到子串的起始位置
//
//		//比较
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)  //如果相等，各自++
//		{
//			s1++;
//			s2++;
//		}
//
//		//比较结束后，确认s2是否指向\0
//		//若指向\0，则说明查找成功
//		if (*s2 == '\0')
//		{
//			return p;
//		}
//		p++;
//	}
//
//	//当p指针都指向了主字符串的末尾处但还是没有查找成功的话
//	//就说明子串不存在于主串
//	//返回空指针
//	return NULL;
//	
//}
//
//int main()
//{
//	char email[] = "nicereyes@163.com";
//	char substr[] = "163";
//	char* ret = my_strstr(email, substr);
//
//	if (ret == NULL)
//	{
//		printf("子串不存在！\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strtok
//切割字符串

//int main()
//{
//	const char* sep = "@.";  //定义分隔符集合
//	char email[] = "nickreyes@163.com";
//	char cp[30] = { 0 };
//	strcpy(cp, email);
//
//	char* ret = strtok(cp, sep);  //第一次分割
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, sep);  //第二次分割
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, sep);  //第三次分割
//	printf("%s\n", ret);
//
//	return 0;
//}

//int main()
//{
//	const char* sep = "@.";  //定义分隔符集合
//	char email[] = "nickreyes@163.com";
//	char cp[30] = { 0 };
//	strcpy(cp, email);
//
//	char* ret = NULL;  //指针初始化为空指针
//	for (ret = strtok(cp, sep); ret != NULL; ret = strtok(NULL, sep))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}

//strerror
//int main()
//{
//	printf("%s\n", strerror(0));
//	//No error
//
//	printf("%s\n", strerror(1));
//	//Operation not permitted
//
//	printf("%s\n", strerror(2));
//	//No such file or directory
//
//	printf("%s\n", strerror(3));
//	//No such process
//
//	printf("%s\n", strerror(4));
//	//Interrupted function call
//
//	printf("%s\n", strerror(5));
//	//Input / output error
//
//	return 0;
//}

//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//		//
//	}
//	return 0;
//}


//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		(char*)dest = (char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//
//	return ret;
//}
//
//
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	//分两种情况
//	//1. dest<src
//	if (dest < src)
//	{
//		//前->后
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	//2. dest>src
//	else
//	{
//		//后->前
//		while(num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//
//void test()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	// 1 2 1 2 3 4 5 8 9 10
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//memcpy负责拷贝两块独立空间中的数据
//重叠内存的拷贝是无法完成的，得通过memmove函数才能实现\


//memcmp
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//
//	int arr2[] = { 1,3,2 };
//	//01 00 00 00 03 00 00 00 02 00 00 00
//
//	int ret = memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);  //-1
//
//	return 0;
//}

//memset
int main()
{
	//char arr[] = "hello bit";
	//memset(arr, 'x', 5);
	//printf("%s\n", arr);
	////xxxxx bit

	int arr[10] = { 0 };
	//把arr 初始化为全1

	return 0;
}