#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//8
int f(int x)
{
	return ((x > 2) ? x * f(x - 1) : 3);
 }

int i;
i = f(f(2));
//
//
////10
int fun(int a)
{
	a ^= (1 << 5) - 1;
	return a;
}

//21^=(1<<5)-1

//1
//00000000000000000000000000000001
//1<<5
//00000000000000000000000000100000
//(1<<5)-1
//00000000000000000000000000100000
//11111111111111111111111111111111
//00000000000000000000000000011111 - 补码结果

//21
//00000000000000000000000000010101
//00000000000000000000000000011111
//00000000000000000000000000001010

//void swap_space(char* str, int len1)
//{
//	char* ret = str;  //记录字符串起始位置
//	int count = 0;
//	//统计空格数
//	while (*str)
//	{
//		if (isspace(*str))
//		{
//			count++;
//		}
//		str++;
//	}
//
//	int num_space = count * 2;
//	int i = 0;
//
//	//追加字符串(相当于延长字符串长度)
//	char space[100] = { 0 };
//	for (i = 0; i < num_space; i++)
//	{
//		space[i] = ' ';
//	}
//
//	space[i] = '\0';
//	
//	strncat(ret, space, num_space);
//
//	int len2 = strlen(ret);
//
//	int end1 = len1 - 1;
//	int end2 = len2 - 1;
//	
//	//移动
//	while (end1 >= 0)
//	{
//
//		if (isspace(ret[end1]))
//		{
//			ret[end2--] = '0';
//
//			ret[end2--] = '2';
//
//			ret[end2--] = '%';
//
//			end1--;
//		}
//		ret[end2--] = ret[end1--];
//	}
//
//}
//
//int main()
//{
//
//	char arr[100] = "we are happy and we are fine.";
//
//	int len = strlen(arr);
//
//	swap_space(arr,len);
//
//	printf("%s\n", arr);
//	//printf("%d\n", len);
//
//	return 0;
//
//}

class Solution {
public:

	void replaceSpace(char* str, int length)
	{
		char* cur = str;
		int space_count = 0;
		while (*cur)
		{
			if (isspace(*cur))
			{
				space_count++;
			}
			cur++;
		}

		int end1 = length - 1;
		int end2 = length - 1 + space_count * 2;

		while (end1 != end2)
		{
			if (!isspace(str[end1]))
			{
				str[end2--] = str[end1--];
			}
			else
			{
				str[end2--] = '0';
				str[end2--] = '2';
				str[end2--] = '%';

				end1--;
			}
		}
	}
};

