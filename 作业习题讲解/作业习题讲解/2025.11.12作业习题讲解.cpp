#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//小乐乐改数字

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	
//	int tmp = n;
//	int count = 0;
//	int sum = 0;
//	
//	while (tmp != 0)
//	{
//		//if ((tmp % 10) % 2 == 1)
//		//{
//		//	sum += 1 * pow(10, count);
//		//	count++;
//		//	
//		//}
//		//else if ((tmp % 10) % 2 == 0)
//		//{
//		//	sum += 0 * pow(10, count);
//		//	count++;
//		//}
//
//		sum += ((tmp % 10) % 2) * pow(10, count);
//		count++;
//		tmp /= 10;
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}

//打印直角三角形

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 0;
//	//先打印空格
//	for (i = 1; i <= n; i++)
//	{
//		int j = n * 2 - i * 2;
//		for (j = n * 2 - i * 2; j > 0; j--)
//		{
//			printf(" ");
//		}
//
//		//在打印"* "
//		int k = i;
//		for (k = i; k > 0; k--)
//		{
//			printf("* ");
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

//课堂版本
//int main()
//{
//	int n = 0;
//
//	//多组输入
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0; 
//		int j = 0;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i + j < n - 1)
//				{
//					printf("  ");  //每2个空格一打
//				}
//				else
//				{
//					printf("* ");
//				}
//			}
//			printf("\n");
//		} 
//	}
//	return 0;
//}

//网购问题
//int main()
//{
//	float price = 0.0f;
//	int month = 0;
//	int date = 0;
//	int coupon = 0;
//
//	scanf("%f %d %d %d", &price, &month, &date, &coupon);
//
//	if ((month == 11) && (date == 11))
//	{
//		price = price * 0.7;
//		if (coupon == 1)
//		{
//			price -= 50;
//		}
//	}
//	else if ((month == 12) && (date == 12))
//	{
//		price = price * 0.8;
//		if (coupon == 1)
//		{
//			price -= 50;
//		}
//	}
//
//	//花的钱不能是负数（商家不会倒找钱）
//	if (price < 0.0)
//	{
//		printf("%.2f\n", 0);
//	}
//	else
//	{
//		printf("%.2f\n", price);
//	}
//	
//	return 0;
//}

//猜名次
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	//穷举每一位选手的排名情况
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						//将穷举出来的结果根据选手猜的结果一一比对
//						//因为所有选手都只猜对了一半
//						//所以每个选手的说的两个表达式的真值之和恒为1
//						//如果都为真，那么和为2；如果都为假，那么和为0
//						if (   (b == 2) + (a == 3) == 1
//							&& (b == 2) + (e == 4) == 1
//							&& (c == 1) + (d == 2) == 1
//							&& (c == 5) + (d == 3) == 1
//							&& (e == 4) + (a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);
//							}
//						}
//						
//					}
//
//				}
//			}
//		}
//	}
//	return 0;
//}

//猜凶手
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//
//	int i = 0;
//
//	for (a = 0; a <= 1; a++)
//	{
//		for (b = 0; b <= 1; b++)
//		{
//			for (c = 0; c <= 1; c++)
//			{
//				for (d = 0; d <= 1; d++)
//				{
//					if ((a == 0) + (c == 1) + (d == 1) + (d == 0) == 3)
//					{
//						if (a + b + c + d == 1)
//						{
//							int arr1[] = { a,b,c,d };
//							char arr2[] = { 'A','B','C','D','\0' };
//							for (i = 0; i < 4; i++)
//							{
//								if (arr1[i] % 2 == 1)
//								{
//									printf("%c是凶手！\n", arr2[i]);
//								}
//							}
//							//printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	return 0;
//}

//杨辉三角

//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//
//	//初始化元素
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//字符串左旋

//我的版本

//void left_rotate(char* arr, int k)
//{
//	
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//每次旋转1个字符，循环k次
//
//		//1.把要移动的字符先存起来
//		char tmp = arr[0];
//
//		//2.把后面的元素移到前面去
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//
//		//3.
//		arr[len - 1] = tmp;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcd";
//	int k = 1;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	left_rotate(arr, k);
//
//	printf("%s\n", arr);
//
//	return 0;
//}

//逆序左旋算法

//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		//交换完下标变化
//		left++;
//		right--;
//	}
//}
//
//void left_rotate(char* arr,int k,int len)
//{
//	k = k % len;
//	//任何一个数模上大于它的数，其结果一定是它本身
//
//	reverse(arr,arr+k-1);  //左边逆序
//	reverse(arr+k,arr+len-1);  //右边逆序
//	reverse(arr,arr+len-1);  //整个逆序
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 4;
//	int len = strlen(arr);
//
//	left_rotate(arr,k,len);
//	printf("%s\n", arr);
//
//	return 0;
//}

//杨氏矩阵
//struct Point  //声明一个结构体类型
//{
//	int a = 0;
//	int b = 0;
//};
//
//struct Point find_num(int arr[3][3], int row, int col, int k)
//{
//	int x = 0;
//	int y = col-1;
//	//先从右上角的元素开始比较
//
//	struct Point axis { -1,-1 };
//	struct Point* px = &axis;
//
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] < k)  //右上角元素小于被查找元素
//		{
//			x++;  //排除这一行
//		}
//		else if (arr[x][y] > k)  //右上角元素大于被查找元素
//		{
//			y--;  //排除这一列
//		}
//		else  //找到了
//		{
//			px->a = x;
//			px->b = y;
//			return axis;
//		}
//	}
//	return axis; //没找到
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//
//	struct Point ret = find_num(arr, 3, 3, k);
//	//定义了结构体变量，接受一个返回值为结构体类型的数据
//	
//	printf("%d在第%d行第%d列\n",k,ret.a,ret.b);
//
//	return 0;
//}


//int find_num(int arr[3][3], int* px, int* py, int k)
//{
//	int x = 0;
//	int y = *py - 1;
//	//先从右上角的元素开始比较
//
//
//	while (x <= *px - 1 && y >= 0)
//	{
//		if (arr[x][y] < k)  //右上角元素小于被查找元素
//		{
//			x++;  //排除这一行
//		}
//		else if (arr[x][y] > k)  //右上角元素大于被查找元素
//		{
//			y--;  //排除这一列
//		}
//		else  //找到了
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	*px = -1;
//	*py = -1;
//
//	return 0; //没找到
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//
//	int x = 3;
//	int y = 3;
//
//	int ret = find_num(arr, &x, &y, k);
//	//定义了结构体变量，接受一个返回值为结构体类型的数据
//
//	if (ret == 1)
//	{
//		printf("%d在第%d行第%d列\n", k, x, y);
//	}
//	if (ret == 0)
//	{
//		printf("坐标不存在");
//	}
//
//	return 0;
//}

//旋转字符串判断
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		left++;
//		right--;
//	}
//}

//穷举法
//int is_left_rotate(char arr1[], char arr2[])
//{
//	//将arr1每一个旋转的结果与arr2比较
//	int len = strlen(arr1);
//	int i = 0;
//
//	//旋转
//	for (i = 0; i < len; i++)
//	{
//		char tmp = arr1[0];
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			arr1[j] = arr1[j + 1];
//		}
//		arr1[len - 1] = tmp;
//
//		if (strcmp(arr1, arr2) == 0)
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//
//	//判断arr2中的字符串是否可以通过arr1中的字符串旋转的到
//	int ret = is_left_rotate(arr1, arr2);
//
//	if (ret == 1)
//	{
//		printf("ok\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//
//	return 0;
//}

//库函数法

//int is_left_rotate(char arr1[], char arr2[])
//{
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//
//	if (len1 != len2)
//		return 0;
//
//	strncat(arr1, arr1, len1);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//
//	//判断arr2中的字符串是否可以通过arr1中的字符串旋转的到
//	int ret = is_left_rotate(arr1, arr2);
//
//	if (ret == 1)
//		printf("ok\n");
//	else
//		printf("no\n");
//
//	return 0;
//}

//int main()
//{
//	int n = 2;
//	int m = 3;
//	//scanf("%d %d", &n, &m);
//
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	
//	//输入矩阵中的元素
//	for (i = 0; i < n; i++)  //行
//	{
//		for (j = 0; j < m; j++)  //列
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//输出
//	//把原来的行改成列，原来的列改成行
//	//再直接打印出来就可以了
//	for (i = 0; i < m; i++)  //列
//	{
//		for (j = 0; j < n; j++)  //行
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//判断上三角矩阵
// 我的版本
//int main()
//{
//	int n = 3;
//	//scanf("%d", &n);
//	int arr[3][3] = { 0 };
//	int i = 0;
//	int j = 0;
//	int count = 0;
//
//	//输入
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//判断
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if ((i > j) && arr[i][j] == 0)
//			{
//				count++;
//			}
//		}
//	}
//
//	if (count == ((n-1) * n) / 2)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//
//	return 0;
//}

//课堂版本
//int main()
//{
//	int n = 3;
//	//scanf("%d", &n);
//	int arr[3][3] = { 0 };
//	int i = 0;
//	int j = 0;
//	int flag = 1;  //是上三角矩阵
//
//	//输入
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//判断
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < i; j++)  //直接在j<i的范围去找
//		{
//			if (arr[i][j] != 0)
//			{
//				flag = 0;  //不是上三角矩阵
//				goto end;
//			}
//		}
//	}
//	end:
//	if (flag == 0)
//		printf("NO\n");
//	else
//		printf("YES\n");
//
//
//	return 0;
//}

//判断有序序列
//我的版本
//int main()
//{
//
//	int flag = 1;  //假设是有序序列
//	int i = 0;
//
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		if (i + 2 < sz)
//		{
//			if (((arr[i] - arr[i + 1] > 0) && (arr[i + 1] - arr[i + 2] < 0))
//			 || ((arr[i] - arr[i + 1] < 0) && (arr[i + 1] - arr[i + 2] > 0)))
//			{
//				flag = 0;
//				break;
//			}
//		}
//	}
//
//	if (flag == 1)
//		printf("sorted\n");
//	else
//		printf("unsorted\n");
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int arr[50] = { 0 };
//	scanf("%d", &n);
//	int i = 0;
//	int flag1 = 0;  //判断升序
//	int flag2 = 0;  //判断降序
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (i > 0)
//		{
//			if (arr[i] > arr[i - 1])
//			{
//				flag1 = 1;
//			}
//			else if(arr[i] < arr[i - 1])
//			{
//				flag2 = 1;
//			}
//			else
//			{
//				;
//			}
//		}
//	}
//	if (flag1 + flag2 <= 1)
//		printf("sorted\n");
//	else
//		printf("unsorted\n");
//
//	return 0;
//}

