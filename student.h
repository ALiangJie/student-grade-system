#pragma once//Ԥ����ָ���֤ͷ�ļ�ֻ����һ��

#include<stdio.h>		//��׼I/O����
#include<conio.h>		//_getch()����
#include<stdlib.h>		//system()����
#include<string.h>		//strlen()����

//����ѧ���ṹ�塢����ڵ�ṹ��
//����һ��ѧ���ṹ��
typedef struct tagStudent
{
	int num;//ѧ��
	char name[20];//����
	int grade;//�ɼ�
}Student;

//���� �ڵ�
typedef struct tagNode 
{
	Student stu;//ѧ������Ϣ   �ڵ��������
	struct tagNode* Next;//ָ����һ���ڵ�  �ڵ��ָ����
}Node;

//����ͷ�ڵ�
Node* Head = NULL;//ָ��ͷ�ڵ� �ÿ�


//��������
void menu();//�˵�
void printfList();//��ӡ�ɼ����
void input();//¼��
void show();//��ʾ
void save();//�洢
void read();//��ȡ
void total();//�ܼ�
void find();//����
void change();//�޸�
void deletes();//ɾ��
void insert();//����
void sort();//����
void link_order(Node* p_head);//������