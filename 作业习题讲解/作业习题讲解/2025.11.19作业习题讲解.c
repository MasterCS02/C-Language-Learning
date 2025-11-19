#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>




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

int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < n; j++)
			{
				if ((i == 0) || (i == n - 1))  
				{
					printf("* ");  //第一行和最后一行全都打印*
				}
				else if (((i != 0) && (i != n - 1)) && ((j == 0) || (j == n - 1)))
				{
					printf("* ");  //第一列和最后一列全都打印*
				}
				else
				{
					printf("  ");  //其他地方空格填补
				}

			}
			printf("\n");
		}
	}

	return 0;
}