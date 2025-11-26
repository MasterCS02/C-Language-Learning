#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



//int main()
//{
//	int n = 0;
//	int m = 0;
//	while ((scanf("%d %d",&n,&m)) == 2)
//	{
//		//求最小公倍数
//
//		int i = 0;
//		for (i = 1; ((n * i) % m) != 0; i++)
//		{
//			;
//		}
//		int lcm = n * i;
//
//		//求最大公约数
//
//		int k = min(n, m);
//
//		while (k)
//		{
//			if ((n % k == 0) && (m % k == 0))
//			{
//				break;
//			}
//			k--;
//		}
//
//		int gcd = k;
//
//		int sum = gcd + lcm;
//
//		printf("%d\n", sum);
//	}
//
//	return 0;
//}

//效率低的版本
//int main()
//{
//	int n = 0;
//	int m = 0;
//	while ((scanf("%d %d", &n, &m)) == 2)
//	{
//		//求最小公倍数
//
//		int i = max(n,m);
//
//		while (i)
//		{
//			if ((i % n == 0) && (i % m == 0))
//			{
//				break;
//			}
//			i++;
//		}
//		int lcm = i;
//
//		//求最大公约数
//
//		int k = min(n, m);
//
//		while (k)
//		{
//			if ((n % k == 0) && (m % k == 0))
//			{
//				break;
//			}
//			k--;
//		}
//
//		int gcd = k;
//
//		int sum = gcd + lcm;
//
//		printf("%d\n", sum);
//	}
//
//	return 0;
//}

//辗转相除法
//int main()
//{
//	int n = 0;
//	int m = 0;
//	while ((scanf("%d %d", &n, &m)) == 2)
//	{
//		//求最大公约数
//
//		int i = max(n,m);
//		int j = min(n,m);
//		int r = 0;
//
//		while (r = i % j)
//		{
//			i = j;
//			j = r;
//		}
//
//		//当r != 0的时候，说明还没有找到最大公约数
//		//等于0了，就说明j就是最大公约数
//
//		int gcd = j;
//		int lcm = (n * m) / gcd;
//
//		int sum = lcm + gcd;
//		printf("%d\n", sum);
//	}
//
//	return 0;
//}


//空心正方形图案

//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if ((i == 0) || (i == n - 1))  
//				{
//					printf("* ");  //第一行和最后一行全都打印*
//					Sleep(100);
//				}
//				else if (((i != 0) && (i != n - 1)) && ((j == 0) || (j == n - 1)))
//				{
//					printf("* ");  //第一列和最后一列全都打印*
//					Sleep(100);
//
//				}
//				else
//				{
//					printf("  ");  //其他地方空格填补
//					Sleep(100);
//
//				}
//
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)  //多组输入
//	{
//		int i = 0;
//
//		//打印上半部分
//		for (i = 0; i < n + 1; i++)
//		{
//			int j = 0;
//			//打印空格
//			for (j = 0; j < 2 * n - i * 2; j++)    //每行的空格数
//			{
//				printf(" ");
//			}
//
//			//打印*
//			for (j = 0; j < i + 1; j++)   //每行的*数
//			{
//				printf("*");
//
//			}
//			printf("\n");
//		}
//
//		//打印下半部分
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			//打印空格
//			for (j = 0; j < 2*(i + 1); j++)  //每行的空格数
//			{
//				printf(" ");
//			}
//
//			//打印*
//			for (j = 0; j < n - i; j++)   //每行的*数
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}


//int cmp_int(const void* e1, const void* e2)
//{
//	return(*(int*)e1 - *(int*)e2);  //升序排序
//}


//int main()
//{
//	int arr[7] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int tmp = 0;
//
//	do 
//	{
//		for (i = 0; i < 7; i++)
//		{
//			tmp = scanf("%d", &arr[i]);
//		}
//
//		//使用qsort函数对数组元素进行排序（升序）
//		qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//		//这样一来，第一个就是最小值
//		//最后一个就是最大值
//
//		//计算除最值之外的分数的平均值
//		float sum = 0;
//		for (i = 1; i <= 5; i++)
//		{
//			sum += arr[i];
//		}
//		printf("%.2f\n", sum / 5);
//
//	} while (tmp == 1);
//
//
//	return 0;
//}

//int main()
//{
//	int score = 0;
//	int n = 0;
//	int max = 0;
//	int min = 100;
//	int sum = 0;
//	while (scanf("%d", &score) == 1)
//	{
//		n++;
//		sum += score;
//
//		if (score > max)
//		{
//			max = score;
//		}
//		if (score < min)
//		{
//			min = score;
//		}
//
//		if (n == 7)
//		{
//			printf("%.2lf\n", (sum - max - min) / 5.0);
//			n = 0;
//			max = 0;
//			min = 100;
//			sum = 0;
//		}
//	}
//	return 0;
//}

//int main()
//{
//    unsigned char puc[4];  //创建puc的一个字符数组
//    struct tagPIM
//    {
//        //先开辟一个字节
//        unsigned char ucPim1;
//        //再开辟一个字节
//        unsigned char ucData0 : 1;  //给ucData0 1个比特位
//        unsigned char ucData1 : 2;  //给ucData1 2个比特位
//        unsigned char ucData2 : 3;  //给ucData2 3个比特位
//
//        //总共2个字节
//    }*pstPimData;
//
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//
//    pstPimData->ucPim1 = 2;
//
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}

//找单身狗


int cmp_int(const void* e1, const void* e2)
{
	return(*(int*)e1 - *(int*)e2);  //升序排序
}

//int main()
//{
//	int arr[] = { 90,87,87,12,192,192,380,380,101,101 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//思路：
//	//先把数组中的元素按从小到大进行排序
//	//相邻的数字相减，看结果
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (i == 0)
//		{
//			if ((arr[i] - arr[i + 1]) != 0)
//			{
//				printf("%d ", arr[i]);
//			}
//		}
//		if (i == sz - 1)
//		{
//			if ((arr[i] - arr[i - 1]) != 0)
//			{
//				printf("%d ", arr[i]);
//			}
//
//		}
//		if ((i >= 1) && (i <= sz - 1))
//		{
//			if (((arr[i] - arr[i - 1]) != 0) && ((arr[i] - arr[i + 1]) != 0))
//			{
//				printf("%d ", arr[i]);
//			}
//		}
//	}
//
//	return 0;
//}
//

//课堂版本

//void find_single_num(int* arr, int sz, int* pd1, int* pd2)
//{
//	int i = 0;
//	int ret = 0;
//
//	//异或
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//
//	//计算ret的二进制中左右边第几位是1
//	int pos = 0;
//	for (pos = 0; pos < 32; pos++)
//	{
//		if ((ret >> pos) & 1 == 1)
//		{
//			break;
//		}
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		//分组
//		if ((arr[i] >> pos) & 1 == 1)
//		{
//			*pd1 ^= arr[i];
//		}
//		else
//		{
//			*pd2 ^= arr[i];
//		}
//	}
//
//}
//
//int main()
//{
//	//分组
//	//1.所有数字异或
//	//2.找出异或的结果数字中哪一位为1，这一位被称为第n位
//	//3.以第n位为1，分一组；第n位为0，分一组
//
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int dog1 = 0;
//	int dog2 = 0;
//
//	find_single_num(arr, sz, &dog1, &dog2);
//	printf("%d %d", dog1, dog2);
//
//	return 0;
//}

//atoi函数实现
//enum Status
//{
//	VALID,
//	INVALID
//}status = INVALID;//默认非法
//
//
//#include <assert.h>
//int my_atoi(const char* str)
//{
//	//1.防止传进空指针
//	assert(str);
//	int flag = 1;  //默认为正数
//
//	long long ret = 0;
//
//	//2.确保传进来的不是空字符串
//	// 判断字符串第一个字符是不是\0
//	if (*str == '\0')
//	{
//		return 0;  //非法0
//	}
//
//	//3.空格（跳过空格）
//	while (isspace(*str))
//	{
//		str++;
//	}
//
//	//4.+-正负问题
//	//正负号一定出现在字符串首部
//	if (*str == '-')  //注1
//	{
//		flag = -1;
//		str++;
//	}
//	else if (*str == '+')
//	{
//		str++;
//	}
//
//	//计算
//	while (*str)
//	{
//		//确保计算的是数字字符，排除字母
//		if (isdigit(*str))
//		{
//			ret = ret * 10 + flag * (*str - '0');
//
//			//每次计算之后判断是否越界
//			if (ret > INT_MAX || ret < INT_MIN)
//			{
//				return 0;  //越界直接返回0
//			}
//		}
//		else  //有字母直接返回（非法）
//		{
//			return (int)ret;  
//		}
//		str++;
//
//	}
//
//	//如果转换过程正常，没有出现任何中断
//	//那么此时str应指向\0
//	if (*str == '\0')
//	{
//		status = VALID;
//	}
//
//	return (int)ret;
//}
//
//int main()
//{
//	char arr[] = "+125";
//
//	int ret = my_atoi(arr);
//
//	if (status == VALID)
//	{
//		printf("合法返回：%d\n",ret);
//	}
//	else if(status == INVALID)
//	{
//		printf("非法返回：%d\n", ret);
//	}
//	return 0;
//}

//#define INT_PTR int*
//typedef int* int_ptr;
//
//INT_PTR a, b; 
////这里宏替换之后会变成
////int* a,b;
////其中，a的类型是int*，b的类型是int
//
//int_ptr c, d;  //c和d都是指针类型

#define SWAP_BIT(n) (((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))

int main()
{
	//1010 1010 1010 1010 1010 1010 1010 1010 - 原序列
	//0101 0101 0101 0101 0101 0101 0101 0101 - 移位后的结果
	//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  - 偶数位所有数字
	// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 - 奇数位所有数字

	//提取偶数位数字
	//将原序列 按位与 下列二进制序列
	//BIN - 0101 0101 0101 0101 0101 0101 0101 0101
	//HEX - 5    5    5    5    5    5    5    5
	//奇数位 & 0 --> 奇数位清空（全为0）
	//偶数位 & 1 --> 偶数位保留（结果不变）
	//按位与出来的结果就是偶数位序列
	//将其左移一位

	//提取奇数位数字
	//将原序列按位与下列二进制序列
	//BIN - 1010 1010 1010 1010 1010 1010 1010 1010
	//HEX - a    a    a    a    a    a    a    a
	//按位与出来的结果就是奇数位序列
	//将其右移一位

	//将分离出来的偶数位序列和奇数位序列相加起来
	//就是原序列奇数位和偶数位互换之后的结果

	int n = 0;
	scanf("%d", &n);
	int ret = SWAP_BIT(n);
	printf("%d\n", ret);

	return 0;
}

