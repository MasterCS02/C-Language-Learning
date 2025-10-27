#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//分支与循环作业讲解

//int main()
//{
//	printf("%c\n", 'a');
//	printf("%c\n", 97);//以ASCII码来打印对应的字符
//
//	return 0;
//}


//打印若干ASCII码值对应的字符
//int main()
//{
//	int arr[] = { 73,32,99,97,110,32,100,111,32,105,106,33 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	while (i < sz)
//	{
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}

//打印生日年月日
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int date = 0;
//
//	scanf("%4d%2d%2d", &year, &month, &date);
//	//%md,d前面的数字就代表了这是输入了多少位的整型
//  //即%m格式控制可以指定输入域宽
//
//	printf("year=%d\n", year);
//
//	printf("month=%02d\n", month);
//	//%0md为格式控制符，会在输出数值时，指定左面不适用的空位置自动填0,必须在已经明确域宽的前提下使用
//
//	printf("date=%02d\n", date);
//
//	return 0;
//
//}

//学生基本信息的输入输出
//int main()
//{
//	int id = 0;
//	float c = 0.0f;
//	float math = 0.0f;
//	float english = 0.0f;
//	//在赋值浮点型数据时，如果直接赋值0.0的话，会被编译器默认为是double类型的浮点型数据，所以要在后面加上f，确保数据类型是float
//
//	scanf("%09d;%f,%f,%f", &id, &c, &math, &english);
//
//	printf("The each subject score of No. %09d is %.2f, %.2f, %.2f.\n", id, c, math, english);
//	//.2f代表精确到小数点后两位数字
//
//	return 0;
//}

//输出Hello World的返回值
//int main()
//{
//	int n= printf("Hello World!");
//	//printf的返回值就是字符的个数
//	//若要换行，不能把换行符直接加在字符串后面，否则会导致返回值多出来一个1，因为换行符的个数也被算进去了
//
//	printf("\n%d\n", n);//换行符要加在%d前面
//	return 0;
//}

//输出printf
//int main()
//{
//	printf("printf(\"Hello World!\\n\");\n");
//	//想要打印双引号，就要在前面加上反斜杠，如\"，同样，若想打印\n，则需要在前面再加上一个反斜杠，防止其被解释为换行符
//
//	printf("cout<<\"Hello World!\"<<endl;\n");
//
//	return 0;
//}

//寻找最大数

//方法一：
//int main()//输入数字
//{
//	int arr[4] = { 0 };  //先定义一个拥有四个整型元素的数组
//	int i = 0;
//	while (i < 4)  //创建循环，定义循环次数
//	{
//		scanf("%d", &arr[i]);  //在每一次的循环中，依次输入数字，将数字存在对应的数组空间中
//			i++;
//	}
//
//	//找最大值
//	int max = arr[0];	//假设数组中第一个元素就是最大值
//
//	i = 1;
//	while (i < 4)  //创建循环
//	{
//		if (arr[i] > max)  //如果后续数组内的数字大于原先假定的max数字
//		{
//			max = arr[i];  //则令这个更大的数字赋值于max变量当中
//		}
//		i++;
//	}
//
//	printf("The max number is: %d\n", max);  //打印出这个最大值
//
//	return 0;
//
//}

//方法二：

//int main()
//{
//	int i = 1;
//
//	int n = 0;
//	int max = 0;
//	
//	scanf("%d", &max);
//	while (i < 4)
//	{
//		scanf("%d", &n);
//		
//		if (n > max)
//			max = n;
//		i++;
//	}
//
//	printf("The max number is: %d\n", max);
//
//	return 0;
//}

//计算球体的体积，精确到小数点后3位数

//int main()
//{
//	double r = 0.0f;
//	double v = 0.0f;
//	scanf("%lf", &r);
//	v = 4 / 3.0 * 3.1415926 * r *r *r;
//	printf("%.3lf\n", v);
//
//	return 0;
//}

//计算BMI指数

//int main()
//{
//	int w = 0;
//	int h = 0;
//	float bmi = 0.0f;
//	scanf("%d %d", &w, &h);
//	float hm = h / 100.0;//100后面的.0千万不能忘
//	bmi =w/(hm*hm);
//	printf("%.2f\n", bmi);
//
//	return 0;
//}





//for循环

//引例
//int main()
//{
//	int i = 1;  //初始化循环变量
//
//	while (i <= 10)  //判断
//	{
//
//		printf("%d", i);
//		i++;  //调整
//	}
//
//	return 0;
//}


//打印1-10
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);
//
//		i = 12;
//		//更改了i的赋值之后，重新进入循环，就变成了13，不满足i小于10的条件，于是直接跳出循环了
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//数组下标为0-9
//
//	int i = 0;
//	for (i = 0; i < 10; i++)//前闭后开
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//for循环的变种
//int main()
//{
//	for (;;)  //for循环的判断部分省略意味着判断的条件会恒成立
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i=0;i<3;i++)  
//	{
//		for(j=0;j<3;j++)
//
//		printf("hehe\n");
//	}
//
//	return 0;
//}
//上面的代码一共会打印9次hehe

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 3; i++)
//	{
//		for (; j < 3; j++)
//
//			printf("hehe\n");
//	}
//
//	return 0;
//}
//但是这串代码只会打印3个hehe，因为j值初始化的表达式被省略，当j循环到3的时候j的值就永远停留在3了


//使用多个变量控制for循环
//int main()
//{
//	int x = 0;
//	int y = 0;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//笔试题
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for(i=0,k=0; k=0 ;i++,k++)//k=0为赋值，0为假，所以不执行循环
//	{
//		k++;
//	}
//	return 0;
//}




///do…while()循环
//break语句
//int main()
//{
//	int i = 1;
//
//	do 
//	{
//		if (i == 5)
//			break;  //当i=5时，直接跳出整个do...while循环体
//
//		printf("%d ", i);
//		i++;
//	}
//	//{}内的是循环体
//
//	while (i <= 10);  //判断表达式
//
//	return 0;
//}


//continue语句
//int main()
//{
//	int i = 1;
//
//	do
//	{
//
//		if (i == 5)
//			continue;  //当i=5时，跳过循环体后面的语句，直接进入判断表达式
//
//		printf("%d ", i);
//
//		i++;
//
//	}
//	//{}内的是循环体
//
//	while (i <= 10);  //判断表达式
//
//	return 0;
//}



//练习1：计算n的阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;  
//	//定义一个变量，负责“记住”前面所有乘积的结果，相当于是一个累乘器，它不能初始化为0
//	int i = 1;  //定义循环变量
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		//随着i不断增加，ret不断进行累乘。ret始终会存储之前一次累乘的结果，即(n-1)!，再乘以自增之后的i，就变成了新的n!，依次循环，直到i=n
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}

//练习2：计算1!+2!+3!+…+10!
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 1;
//
//	int ret = 1;  //累乘器
//	int sum = 0;  //累加器
//
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;  //计算阶乘
//		sum = sum + ret;  //保存累加结果
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//
//}

//练习3（在一个有序数组中查找具体的某个数字n）

//方法一（遍历查找）
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};  //定义数组
//	int k = 7;  //确定要查找的数字
//
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//计算数组元素中的个数（整个数组大小/单个数组元素的大小）
//
//	for (i = 0; i < sz; i++)  //按照下标顺序一个一个找
//	{
//		if (arr[i] == k)
//		{
//			printf("找到了，下标是：%d\n", i);
//			break;
//		}
//	}
//
//	if (i == sz)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}

//方法二（二分查找）
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};  
	int k = 17;  

	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	//定义左下标
	int left = 0;

	//定义右下标
	int right = sz - 1;


	while (left<=right)
	{
		//定义中位数
		int mid = (left + right) / 2;

		if (arr[mid] < k)  //如果数组中间的那个数小于目标数
		{
			left = mid + 1;  //重新定义左下标，使得左下标等于中位数+1
		}
		else if (arr[mid] > k)  //如果数组中间的那个数大于目标数
		{
			right = mid - 1;  //重新定义右下标，使得左下标等于中位数-1
		}
		else
		{
			printf("找到了，下标为：%d\n", mid);
			break;
		}

	}
	if (left > right)
	{
		printf("找不到\n");
	}

	return 0;
}

