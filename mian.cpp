#include"student.h"

//主函数
int main() 
{
	while (1)
	{
		//打印菜单
		menu();
		//读取一个字符 整数.
		char ch = _getch();
		switch (ch)
		{
		case'1'://1.录入学生信息
			input();
			break;
		case'2'://2.显示学生成绩
			show();
			break;
		case'3'://3.保存学生成绩
			save();
			break;
		case'4'://4.读取学生成绩
			read();
			break;
		case'5'://5.总计学生人数
			total();
			break;
		case'6'://6.查找学生成绩
			find();
			break;
		case'7'://7.修改学生成绩
			change();
			break;
		case'8'://8.删除学生成绩
			deletes();
			break;
		case'9'://9.插入学生成绩
			insert();
			break;
		case's'://10.排序学生成绩
			sort();
			break;
		case '0'://0.退出系统
			return 0;
			break;
		default://其他输入有错误时
			printf("输入有误，没有该功能\n\n");
			system("pause");  //暂停
			system("cls");    //清屏
			break;
		}
	}
	return 0;
}

//菜单
void menu()
{
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t*\t\t学生成绩管理系统\t\t*\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t*\t\t请选择功能(0-8):\t\t*\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t*\t\t1.录入学生成绩\t\t\t*\n");
	printf("\t\t*\t\t2.显示学生成绩\t\t\t*\n");
	printf("\t\t*\t\t3.保存学生成绩\t\t\t*\n");
	printf("\t\t*\t\t4.读取学生成绩\t\t\t*\n");
	printf("\t\t*\t\t5.合计学生人数\t\t\t*\n");
	printf("\t\t*\t\t6.查找学生成绩\t\t\t*\n");
	printf("\t\t*\t\t7.修改学生成绩\t\t\t*\n");
	printf("\t\t*\t\t8.删除学生成绩\t\t\t*\n");
	printf("\t\t*\t\t9.插入学生成绩\t\t\t*\n");
	printf("\t\t*\t\ts.排序学生成绩\t\t\t*\n");
	printf("\t\t*\t\t0.退出系统\t\t\t*\n");
	printf("\t\t-------------------------------------------------\n");
}

//打印成绩表格
void printfList()
{
	printf("*************************************************\n");
	printf("*\t\t    学生成绩表    \t\t*\n");
	printf("*************************************************\n");
	printf("|\t学号\t|\t姓名\t|\t成绩\t|\n");
	printf("*************************************************\n");
}

//录入学生成绩
void input()
{
	//创建一个学生，在堆中分配内存
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	//指针指向下一个空指针
	pNewNode->Next = NULL;

	//查找链表的尾结点
	Node* p = Head;
	while (Head != NULL && p->Next != NULL)
	{
		p = p->Next;
	}

	//把节点插到链表的尾节点
	if (Head == NULL)
	{
		Head = pNewNode;
	}
	else 
	{
		p->Next = pNewNode;
	}

	//录入学生信息
	printf("请输入学生姓名：\n");
	scanf_s("%s", pNewNode->stu.name, sizeof(pNewNode->stu.name));
	printf("请输入学生学号：\n");
	scanf_s("%d", &pNewNode->stu.num);//sizeof(pNewNode->stu.name)
	printf("请输入学生成绩：\n");
	scanf_s("%d", &pNewNode->stu.grade);//sizeof(pNewNode->stu.grade)

	printf("学生信息录入成功。\n\n");
	system("pause");
	system("cls");
}

//显示学生成绩
void show() 
{
	system("cls");

	//遍历链表
	Node* p = Head;
	if (p == NULL) 
	{
		printf("系统中暂无学生信息，请录入后查看!\n\n");
	}
	else
	{
		printfList();

		while (p != NULL)
		{
			printf("|\t%d\t|\t%s\t|\t%d\t|\n",p->stu.num, p->stu.name, p->stu.grade);

			//下一个节点
			p = p->Next;
			printf("*************************************************\n");
		}
	}
	system("pause");
	system("cls");
}

//存储学生成绩
void save() 
{
	//打开文件
	FILE* fp;
	fp = fopen("data.txt", "w");//学生成绩表数据文件
	//"r"：只能从文件中读数据，该文件必须先存在，否则打开失败
	//"w"：只能向文件写数据，若指定的文件不存在则创建它，如果存在则先删除它再重建一个新文件
	//"a"：向文件增加新数据(不删除原有数据)，若文件不存在则打开失败，打开时位置指针移到文件末尾
	//"r+"：可读 / 写数据，该文件必须先存在，否则打开失败
	//"w+"：可读 / 写数据，用该模式打开新建一个文件，先向该文件写数据，然后可读取该文件中的数据
	//"a+"：可读 / 写数据，原来的文件不被删去，位置指针移到文件末尾

	if (fp == NULL) 
	{
		printf("打开文件失败。\n");
		return;
	}

	//写入数据
	Node* p = Head;
	while (p != NULL)
	{
		//fprintf()函数根据指定的格式(format)，向输出流(stream)写入数据(argument)。
		fprintf(fp, "|\t%d\t|\t%s\t|\t%d\t|\n", p->stu.num, p->stu.name, p->stu.grade);
		p = p->Next;
	}

	//关闭文件
	fclose(fp);

	printf("数据保存成功！\n");
	system("pause");
	system("cls");
}

//读取学生成绩
void read()
{
	system("cls");

	//打开文件
	FILE* fp;
	fp = fopen("data.txt", "r");	//"r"：只能从文件中读数据，该文件必须先存在，否则打开失败

	if (fp == NULL) 
	{
		printf("打开文件失败!\n");
		return;
	}

	//创建一个学生，在堆中分配内存
	Node* p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;

	//重新建立链表
	Head = p;

	//逐个单词读入文本内容
	char str[200];
	int i = 0;//判断第一个信息是否录入
	while (fscanf(fp, "%s", str) != EOF)  //从文件data.txt中格式化读取数据
	{   
		//读文件 
		//单词不是|或者空时，进行赋值
		if (strcmp(str, "|") && str != NULL) 
		{
			switch (i)
			{
			case 0:
				p->stu.num = atoi(str); //atoi()是把字符串转换成整型数的一个函数
				break;
			case 1:
				strcpy(p->stu.name, str);//strcpy(),把从src地址开始且含有NULL结束符的字符串复制到以dest开始的地址空间
				break;
			case 2:
				p->stu.grade = atoi(str);
				break;
			default:
				//一轮信息读取完成
				//新读取下一位学生信息
				Node* pNewNode = (Node*)malloc(sizeof(Node));
				pNewNode->Next = NULL;
				p->Next = pNewNode;
				p = pNewNode;
				p->stu.num = atoi(str);
				i = 0;
				break;
			}
			i++;
		}
	}

	//打印读取结果
	show();
}

//合计学生人数
void total()
{
	system("cls");
	int count = 0;

	//遍历链表
	Node* p = Head;
	while (p != NULL)
	{
		count++;
		p = p->Next;
	}
	printf("学生总人数：%d\n\n", count);

	system("pause");
	system("cls");
}

//查找学生成绩
void find()
{
	system("cls");

	//以学号为查找
	int num;
	printf("请输入查找学生学号：");
	scanf("%d", &num);

	//遍历链表查找，查找到后进行信息显示
	Node* p = Head;
	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (num == p->stu.num)//strcmp函数对比姓名
		{
			if (!isShowHead) 
			{
				printfList();
				isShowHead = true;
			}
			printf("|\t%d\t|\t%s\t|\t%d\t|\n", p->stu.num, p->stu.name, p->stu.grade);

			isFindStu = true;
			printf("*************************************************\n");
		}
		p = p->Next;
	}

	if (!isFindStu) 
	{
		printf("学号输入有误，系统中暂无该学生信息!\n\n");
	}

	system("pause");
	system("cls");
}

//修改学生成绩
void change()
{
	system("cls");
	//以学号为查找
	int num;
	printf("请输入修改学生的学号：");
	scanf("%d", &num);

	//遍历链表查找，查找到后进行信息显示
	Node* p = Head;
	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (num == p->stu.num) 
		{
			if (!isShowHead) 
			{
				printfList();
				isShowHead = true;
			}
			printf("|\t%d\t|\t%s\t|\t%d\t|\n", p->stu.num, p->stu.name, p->stu.grade);
			printf("*************************************************\n");

			//修改学生信息
			printf("请输入学生姓名：\n");
			scanf_s("%s", p->stu.name, sizeof(p->stu.name));
			printf("请输入学号：\n");
			scanf_s("%d", &p->stu.num);
			printf("请输入成绩：\n");
			scanf_s("%d", &p->stu.grade);
			isFindStu = true;
			printf("学生信息修改成功！请保存！\n\n");
		}
		p = p->Next;
	}

	if (!isFindStu) 
	{
		printf("学号输入有误，未找到该学号！无法进行修改！\n\n");
	}

	system("pause");
	system("cls");
}

//删除学生成绩
void deletes()
{
	system("cls");
	//以学号为删除示例
	int num;
	printf("请输入删除学生的学号：");
	scanf("%d", &num);

	//遍历链表查找，查找到后进行信息显示
	Node* p = Head;
	//记录前一个节点，删除时方便操作
	Node* beforeNode = Head;

	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (num == p->stu.num) 
		{
			if (!isShowHead) 
			{
				printfList();
				isShowHead = true;
			}
			printf("|\t%d\t|\t%s\t|\t%d\t|\n", p->stu.num, p->stu.name, p->stu.grade);
			printf("*************************************************\n");
			isFindStu = true;

			//删除节点为头节点
			if (p == Head) 
			{
				Head = p->Next;
			}
			//删除节点为尾节点
			else if (p->Next == NULL) 
			{
				p = beforeNode;
				p->Next = NULL;
			}
			//删除节点为中间节点
			else 
			{
				beforeNode->Next = p->Next;
			}
			printf("删除成功，请保存！\n\n");
		}
		beforeNode = p;
		p = p->Next;
	}

	if (!isFindStu) 
	{
		printf("学号输入有误，未找到该学生，无法进行删除操作！\n\n");
	}

	system("pause");
	system("cls");
}

//插入学生成绩
void insert()
{
	system("cls");
	//以学号为插入示例
	int num;
	printf("请输入插入学生位置学生的学号：");
	scanf("%d", &num);

	//遍历链表查找，查找到后进行信息显示
	Node* p = Head;
	//记录前一个节点，插入时方便操作
	Node* beforeNode = Head;

	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (num == p->stu.num)
		{
			if (!isShowHead)
			{
				printfList();
				isShowHead = true;
			}
			printf("|\t%d\t|\t%s\t|\t%d\t|\n", p->stu.num, p->stu.name, p->stu.grade);
			printf("*************************************************\n");
			isFindStu = true;

			//创建一个新学生，在堆中分配内存
			Node* pNewNode = (Node*)malloc(sizeof(Node));

			//指针指向下一个空指针
			pNewNode->Next = NULL;

			//插入节点为头节点
			if (p == Head)
			{
				pNewNode->Next = p;
				Head = pNewNode;
			}
			//插入节点为尾节点
			else if (p->Next == NULL)
			{
				p->Next = pNewNode;
				pNewNode->Next = NULL;
			}
			//插入节点为中间节点
			else
			{
				beforeNode->Next = pNewNode;
				pNewNode->Next = p;
			}

			//录入学生信息
			printf("请输入学生姓名：\n");
			scanf_s("%s", pNewNode->stu.name, sizeof(pNewNode->stu.name));
			printf("请输入学生学号：\n");
			scanf_s("%d", &pNewNode->stu.num);//sizeof(pNewNode->stu.name)
			printf("请输入学生成绩：\n");
			scanf_s("%d", &pNewNode->stu.grade);//sizeof(pNewNode->stu.grade)
			
			printf("插入成功，请保存！\n\n");
		}
		beforeNode = p;
		p = p->Next;
	}

	if (!isFindStu)
	{
		printf("学号输入有误，未找到该学生，无法进行插入操作！\n\n");
	}

	system("pause");
	system("cls");
}

//排序学生成绩
void sort() 
{
	system("cls");
	//遍历链表
	Node* p = Head;

	link_order(p);
	printf("排序完成！请保存！\n");

	system("pause");
	system("cls");
}

//快排函数
void link_order(Node* p_head)
{
	Node* pb, * pf, temp;
	pf = p_head;
	if (p_head == NULL) //链表为空
	{
		printf("不需要排序\n");
		return;
	}
	if (p_head->Next == NULL) //链表有1个节点
		return;

	while (pf->Next != NULL) //以pf指向的节点为基准节点
	{
		pb = pf->Next;//pb从基准点的下一个节点开始
		while (pb != NULL) 
		{
			if (pf->stu.grade < pb->stu.grade) 
			{
				temp = *pf;
				*pf = *pb;
				*pb = temp;
				temp.Next = pf->Next;
				pf->Next = pb->Next;
				pb->Next = temp.Next;
			}
			pb = pb->Next;
		}
		pf = pf->Next;
	}
	return;
}