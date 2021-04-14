#pragma once//预处理指令，保证头文件只编译一次

#include<stdio.h>		//标准I/O函数
#include<conio.h>		//_getch()函数
#include<stdlib.h>		//system()函数
#include<string.h>		//strlen()函数

//定义学生结构体、链表节点结构体
//定义一个学生结构体
typedef struct tagStudent
{
	int num;//学号
	char name[20];//姓名
	int grade;//成绩
}Student;

//链表 节点
typedef struct tagNode 
{
	Student stu;//学生的信息   节点的数据域
	struct tagNode* Next;//指向下一个节点  节点的指针域
}Node;

//创建头节点
Node* Head = NULL;//指向头节点 置空


//函数声明
void menu();//菜单
void printfList();//打印成绩表格
void input();//录入
void show();//显示
void save();//存储
void read();//读取
void total();//总计
void find();//查找
void change();//修改
void deletes();//删除
void insert();//插入
void sort();//排序
void link_order(Node* p_head);//排序函数