#pragma once
#include <assert.h>

#define MAX 100  //通讯录最大信息数
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDRESS 30
#define DEFAULT_SIZE 1  //通讯录的默认容量
#define INC_SIZE 2  //每次增长的大小

//人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];

}PeoInfo;  
//重新命名这个结构体类型为PeoInfo


//动态版本
typedef struct Contact
{
	PeoInfo* data;  //存放人的信息
	int count;      //记录当前通讯录中实际人的个数
	int capacity;   //当前通讯录的容量
}Contact;


//初始化通讯录
void InitContact(Contact* pc);

//销毁通讯录（释放空间）
void DestroyContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//打印通讯录中的信息
void ShowContact(const Contact* pc); //这里只显示，不修改，所以用const保护

//删除指定联系人
void DelContact(Contact* pc);

//查找
int FindByName(Contact* pc, char name[]);

//查找指定联系人
void SearchContact(Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//排序通讯录中的内容
//按照名字排序
void SortContact(Contact* pc);

//保存通讯录的信息到文件
int SaveContact(const Contact* pc);

//加载文件的信息到通讯录中
void LoadContact(Contact* pc);