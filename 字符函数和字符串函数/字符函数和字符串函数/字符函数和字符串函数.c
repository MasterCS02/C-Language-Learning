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
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;  //被查找的主字符串起点
	const char* s2 = str2;  //目标子串的起点
	const char* p = str1;   //p用来记录每次比较的起点，位于主字符串

	while (*p)  //确认p指针不是指向空位置
	{
		s1 = p;  //p指针是主字符串被查找的起始位置
		s2 = str2;  //s2回到子串的起始位置

		//比较
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)  //如果相等，各自++
		{
			s1++;
			s2++;
		}

		//比较结束后，确认s2是否指向\0
		//若指向\0，则说明查找成功
		if (*s2 == '\0')
		{
			return p;
		}
		p++;
	}

	//当p指针都指向了主字符串的末尾处但还是没有查找成功的话
	//就说明子串不存在于主串
	//返回空指针
	return NULL;
	
}

int main()
{
	char email[] = "nicereyes@163.com";
	char substr[] = "163";
	char* ret = my_strstr(email, substr);

	if (ret == NULL)
	{
		printf("子串不存在！\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}

