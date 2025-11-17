#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "dec.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);

	pc->count = 0;
	pc->data = (PeoInfo*)calloc(DEFAULT_SIZE, sizeof(PeoInfo));
	//开辟一个可以存放3个联系人信息的通讯录
	//每个元素大小为PeoInfo类型的结构体

	if (pc->data == NULL)
	{
		printf("InitContact：%s\n", strerror(errno));
		return;
	}
	pc->capacity = DEFAULT_SIZE;
}

//销毁通讯录(释放空间)
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc = NULL;
}

//检查容量
void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SIZE) * sizeof(PeoInfo));
		//如果满了，使用realloc函数进行扩容

		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SIZE;//扩容
			printf("增容成功\n");
		}
		else
		{
			printf("AddContact：%s\n", strerror(errno));
			return;
		}
	}
}

//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);

	CheckCapacity(pc);  //检查容量
	
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->count].name);
	//data是一个类型为结构体变量的数组，[]里面的pc->count代表数组下标
	//data[pc->count]是一个结构体变量，里面还存放着具体的结构体成员信息
	//所以.name就相当于访问data[pc->count]这个结构体变量的name成员的数据
	//name是一个数组，数组名本身就是一个地址，所以在这里不需要取地址

	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	//age是一个整型数据，所以在这里是需要取地址的

	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);

	printf("请输入电话号码:>");
	scanf("%s", pc->data[pc->count].tele);

	printf("请输入地址:>");
	scanf("%s", pc->data[pc->count].address);

	pc->count++;
	printf("成功添加联系人！");

}

//打印
void ShowContact(const Contact* pc)
{
	assert(pc);

	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	//-号表示左对齐

	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name, 
											        pc->data[i].age, 
												    pc->data[i].sex, 
											        pc->data[i].tele, 
											        pc->data[i].address);
	}
}

//查找
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;

	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)  //判断结构体变量中的名字是否与给定的名字相同
		{
			return i;  //返回这个联系人的坐标
		}
	}

	return -1;  //没找到
}

//删除指定联系人
void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };  //填充需要删除的联系人的名字
	int i = 0;

	if (pc->count == 0)
	{
		printf("通讯录为空，没有信息可以删除\n");
		return;
	}

	printf("请输入要删除人的名字:>");
	scanf("%s", name);

	//1.查找
	int pos = FindByName(pc, name);
	
	if (pos == -1)
	{
		printf("要删除的联系人不存在");
		return;
	}

	//2.删除
	//把后面的数据覆盖掉前面的数据
	for (i = pos; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;

	//不需要把最后一个数据给覆盖掉
	//只需要把下标--，那也就访问不到最后一个数据了

	printf("删除成功！\n");

}

//查找联系人
void SearchContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };  //填充需要查找的联系人的名字

	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}

	printf("请输入要查找人的名字:>");

	scanf("%s", name);

	//1.查找
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("要查找的联系人不存在");
		return;
	}

	//2.打印
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
												pc->data[pos].age,
												pc->data[pos].sex,
												pc->data[pos].tele,
												pc->data[pos].address);


}

//修改联系人
void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };  //填充需要修改的联系人的名字

	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}

	printf("请输入要修改的人的名字:>");

	scanf("%s", name);

	//查找要修改的联系人的坐标
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("要查找的联系人不存在");
		return;
	}

	printf("开始修改\n");

	//修改
	//根据给定的坐标，进行相应的修改
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);

	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pos].age));

	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);

	printf("请输入电话号码:>");
	scanf("%s", pc->data[pos].tele);

	printf("请输入地址:>");
	scanf("%s", pc->data[pos].address);

	printf("修改成功！\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//排序
//按照名字来排序
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data,pc->count,sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功\n");
}

