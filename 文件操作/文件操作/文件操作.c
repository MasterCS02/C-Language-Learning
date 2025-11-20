#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


#include <errno.h>

//int main()
//{
//	//相对路径打开（以只读的形式）
//	FILE* pf1 = fopen("test.txt", "r");
//
//	//绝对路径打开（以只读的形式）
//	FILE* pf2 = fopen("C:\\Users\\pc\\Desktop\\test.txt", "r");
//
//
//	if (pf1 == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//读文件
//
//	//关闭文件
//
//	fclose(pf1);
//	fclose(pf2);
//
//	pf1 = NULL;
//	pf2 = NULL;
//
//
//	return 0;
//}

//文件的顺序读写

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");  //只写模式打开
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//写文件
//	fputc('a', pf);  //把a这个字符写入文件中
//
//	char i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	//把26个小写字母写入
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");  //以只读模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int ch = 0;  //存放fgetc函数读到的字符
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	//把文件里面存的所有字符全部读出来
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//写一行数据

//int main()
//{
//	FILE* pf = fopen("test.txt", "a");  //以追加模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//写一行数据
//	fputs(" hello world", pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//读一行数据

//现在文件里放的字符串是
//hello world
//hello world
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");  //以只读模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//读一行数据
//	char arr[20];
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	//读出来的是hell，还会在最后的空间放一个\0
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//格式化输出
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",25,50.5f };
//	FILE* pf = fopen("test.txt", "w");  //以只写模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//格式化输出（写入）
//	fprintf(pf, "%s %d %f", s.arr, s.age, s.score);
//	//写入了zhangsan 25 50.500000
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//格式化输入
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { 0 };
//
//	FILE* pf = fopen("test.txt", "r");  //以只写模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fscanf(pf, "%s %d %f", s.arr, &(s.age), &(s.score));
//	//fscanf按照格式化字符串的规则
//	//从文件中读取相应的数据，中间有空格
//	//然后再相应地存放到s这个结构体变量中的每一个成员中
//
//	printf("%s %d %f", s.arr, s.age, s.score);
//	//把现在这个结构体变量中的每一个成员的数据输出到屏幕上
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//二进制输出
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",25,50.5f };
//
//	FILE* pf = fopen("test.txt", "wb");  //以二进制写入的模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//二进制写入
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//二进制输入
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};

//int main()
//{
//	struct S s = { 0 };
//
//	FILE* pf = fopen("test.txt", "rb");  //以二进制只读的模式打开
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//二进制读取
//	fread(&s, sizeof(struct S), 1, pf);  //读取二进制文件
//	printf("%s %d %f", s.arr, s.age, s.score);
//	//zhangsan 25 50.500000
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",20,55.5f };
//	struct S tmp = { 0 };
//
//	char buf[100] = { 0 };
//
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.score);
//	//把结构体的数据转换为字符串
//
//	printf("%s\n", buf);
//	//按照字符串形式打印
//
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
//	//把字符串buf中的数据按照规则格式化
//	//再把格式化后的数据存放到tmp中
//
//	printf("%s %d %f\n", tmp.arr, tmp.age, tmp.score);
//	//按照格式化形式打印
//
//	return 0;
//}


//文件的随机读写

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");  
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//读文件abcdef
//	fseek(pf, 2, SEEK_SET);
//
//	int ch = fgetc(pf); 
//	printf("%c\n", ch);
//
//	printf("%d\n", ftell(pf)); //3
//
//	fseek(pf, 2, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fseek(pf, -1, SEEK_END);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	printf("%d\n", ftell(pf));//6
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

