#include"student.h"

//������
int main() 
{
	while (1)
	{
		//��ӡ�˵�
		menu();
		//��ȡһ���ַ� ����.
		char ch = _getch();
		switch (ch)
		{
		case'1'://1.¼��ѧ����Ϣ
			input();
			break;
		case'2'://2.��ʾѧ���ɼ�
			show();
			break;
		case'3'://3.����ѧ���ɼ�
			save();
			break;
		case'4'://4.��ȡѧ���ɼ�
			read();
			break;
		case'5'://5.�ܼ�ѧ������
			total();
			break;
		case'6'://6.����ѧ���ɼ�
			find();
			break;
		case'7'://7.�޸�ѧ���ɼ�
			change();
			break;
		case'8'://8.ɾ��ѧ���ɼ�
			deletes();
			break;
		case'9'://9.����ѧ���ɼ�
			insert();
			break;
		case's'://10.����ѧ���ɼ�
			sort();
			break;
		case '0'://0.�˳�ϵͳ
			return 0;
			break;
		default://���������д���ʱ
			printf("��������û�иù���\n\n");
			system("pause");  //��ͣ
			system("cls");    //����
			break;
		}
	}
	return 0;
}

//�˵�
void menu()
{
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t*\t\tѧ���ɼ�����ϵͳ\t\t*\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t*\t\t��ѡ����(0-8):\t\t*\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t*\t\t1.¼��ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t2.��ʾѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t3.����ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t4.��ȡѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t5.�ϼ�ѧ������\t\t\t*\n");
	printf("\t\t*\t\t6.����ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t7.�޸�ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t8.ɾ��ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t9.����ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\ts.����ѧ���ɼ�\t\t\t*\n");
	printf("\t\t*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("\t\t-------------------------------------------------\n");
}

//��ӡ�ɼ����
void printfList()
{
	printf("*************************************************\n");
	printf("*\t\t    ѧ���ɼ���    \t\t*\n");
	printf("*************************************************\n");
	printf("|\tѧ��\t|\t����\t|\t�ɼ�\t|\n");
	printf("*************************************************\n");
}

//¼��ѧ���ɼ�
void input()
{
	//����һ��ѧ�����ڶ��з����ڴ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	//ָ��ָ����һ����ָ��
	pNewNode->Next = NULL;

	//���������β���
	Node* p = Head;
	while (Head != NULL && p->Next != NULL)
	{
		p = p->Next;
	}

	//�ѽڵ�嵽�����β�ڵ�
	if (Head == NULL)
	{
		Head = pNewNode;
	}
	else 
	{
		p->Next = pNewNode;
	}

	//¼��ѧ����Ϣ
	printf("������ѧ��������\n");
	scanf_s("%s", pNewNode->stu.name, sizeof(pNewNode->stu.name));
	printf("������ѧ��ѧ�ţ�\n");
	scanf_s("%d", &pNewNode->stu.num);//sizeof(pNewNode->stu.name)
	printf("������ѧ���ɼ���\n");
	scanf_s("%d", &pNewNode->stu.grade);//sizeof(pNewNode->stu.grade)

	printf("ѧ����Ϣ¼��ɹ���\n\n");
	system("pause");
	system("cls");
}

//��ʾѧ���ɼ�
void show() 
{
	system("cls");

	//��������
	Node* p = Head;
	if (p == NULL) 
	{
		printf("ϵͳ������ѧ����Ϣ����¼���鿴!\n\n");
	}
	else
	{
		printfList();

		while (p != NULL)
		{
			printf("|\t%d\t|\t%s\t|\t%d\t|\n",p->stu.num, p->stu.name, p->stu.grade);

			//��һ���ڵ�
			p = p->Next;
			printf("*************************************************\n");
		}
	}
	system("pause");
	system("cls");
}

//�洢ѧ���ɼ�
void save() 
{
	//���ļ�
	FILE* fp;
	fp = fopen("data.txt", "w");//ѧ���ɼ��������ļ�
	//"r"��ֻ�ܴ��ļ��ж����ݣ����ļ������ȴ��ڣ������ʧ��
	//"w"��ֻ�����ļ�д���ݣ���ָ�����ļ��������򴴽����������������ɾ�������ؽ�һ�����ļ�
	//"a"�����ļ�����������(��ɾ��ԭ������)�����ļ����������ʧ�ܣ���ʱλ��ָ���Ƶ��ļ�ĩβ
	//"r+"���ɶ� / д���ݣ����ļ������ȴ��ڣ������ʧ��
	//"w+"���ɶ� / д���ݣ��ø�ģʽ���½�һ���ļ���������ļ�д���ݣ�Ȼ��ɶ�ȡ���ļ��е�����
	//"a+"���ɶ� / д���ݣ�ԭ�����ļ�����ɾȥ��λ��ָ���Ƶ��ļ�ĩβ

	if (fp == NULL) 
	{
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}

	//д������
	Node* p = Head;
	while (p != NULL)
	{
		//fprintf()��������ָ���ĸ�ʽ(format)���������(stream)д������(argument)��
		fprintf(fp, "|\t%d\t|\t%s\t|\t%d\t|\n", p->stu.num, p->stu.name, p->stu.grade);
		p = p->Next;
	}

	//�ر��ļ�
	fclose(fp);

	printf("���ݱ���ɹ���\n");
	system("pause");
	system("cls");
}

//��ȡѧ���ɼ�
void read()
{
	system("cls");

	//���ļ�
	FILE* fp;
	fp = fopen("data.txt", "r");	//"r"��ֻ�ܴ��ļ��ж����ݣ����ļ������ȴ��ڣ������ʧ��

	if (fp == NULL) 
	{
		printf("���ļ�ʧ��!\n");
		return;
	}

	//����һ��ѧ�����ڶ��з����ڴ�
	Node* p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;

	//���½�������
	Head = p;

	//������ʶ����ı�����
	char str[200];
	int i = 0;//�жϵ�һ����Ϣ�Ƿ�¼��
	while (fscanf(fp, "%s", str) != EOF)  //���ļ�data.txt�и�ʽ����ȡ����
	{   
		//���ļ� 
		//���ʲ���|���߿�ʱ�����и�ֵ
		if (strcmp(str, "|") && str != NULL) 
		{
			switch (i)
			{
			case 0:
				p->stu.num = atoi(str); //atoi()�ǰ��ַ���ת������������һ������
				break;
			case 1:
				strcpy(p->stu.name, str);//strcpy(),�Ѵ�src��ַ��ʼ�Һ���NULL���������ַ������Ƶ���dest��ʼ�ĵ�ַ�ռ�
				break;
			case 2:
				p->stu.grade = atoi(str);
				break;
			default:
				//һ����Ϣ��ȡ���
				//�¶�ȡ��һλѧ����Ϣ
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

	//��ӡ��ȡ���
	show();
}

//�ϼ�ѧ������
void total()
{
	system("cls");
	int count = 0;

	//��������
	Node* p = Head;
	while (p != NULL)
	{
		count++;
		p = p->Next;
	}
	printf("ѧ����������%d\n\n", count);

	system("pause");
	system("cls");
}

//����ѧ���ɼ�
void find()
{
	system("cls");

	//��ѧ��Ϊ����
	int num;
	printf("���������ѧ��ѧ�ţ�");
	scanf("%d", &num);

	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = Head;
	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
	bool isFindStu = false;
	while (p != NULL)
	{
		if (num == p->stu.num)//strcmp�����Ա�����
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
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ!\n\n");
	}

	system("pause");
	system("cls");
}

//�޸�ѧ���ɼ�
void change()
{
	system("cls");
	//��ѧ��Ϊ����
	int num;
	printf("�������޸�ѧ����ѧ�ţ�");
	scanf("%d", &num);

	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = Head;
	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
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

			//�޸�ѧ����Ϣ
			printf("������ѧ��������\n");
			scanf_s("%s", p->stu.name, sizeof(p->stu.name));
			printf("������ѧ�ţ�\n");
			scanf_s("%d", &p->stu.num);
			printf("������ɼ���\n");
			scanf_s("%d", &p->stu.grade);
			isFindStu = true;
			printf("ѧ����Ϣ�޸ĳɹ����뱣�棡\n\n");
		}
		p = p->Next;
	}

	if (!isFindStu) 
	{
		printf("ѧ����������δ�ҵ���ѧ�ţ��޷������޸ģ�\n\n");
	}

	system("pause");
	system("cls");
}

//ɾ��ѧ���ɼ�
void deletes()
{
	system("cls");
	//��ѧ��Ϊɾ��ʾ��
	int num;
	printf("������ɾ��ѧ����ѧ�ţ�");
	scanf("%d", &num);

	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = Head;
	//��¼ǰһ���ڵ㣬ɾ��ʱ�������
	Node* beforeNode = Head;

	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
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

			//ɾ���ڵ�Ϊͷ�ڵ�
			if (p == Head) 
			{
				Head = p->Next;
			}
			//ɾ���ڵ�Ϊβ�ڵ�
			else if (p->Next == NULL) 
			{
				p = beforeNode;
				p->Next = NULL;
			}
			//ɾ���ڵ�Ϊ�м�ڵ�
			else 
			{
				beforeNode->Next = p->Next;
			}
			printf("ɾ���ɹ����뱣�棡\n\n");
		}
		beforeNode = p;
		p = p->Next;
	}

	if (!isFindStu) 
	{
		printf("ѧ����������δ�ҵ���ѧ�����޷�����ɾ��������\n\n");
	}

	system("pause");
	system("cls");
}

//����ѧ���ɼ�
void insert()
{
	system("cls");
	//��ѧ��Ϊ����ʾ��
	int num;
	printf("���������ѧ��λ��ѧ����ѧ�ţ�");
	scanf("%d", &num);

	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = Head;
	//��¼ǰһ���ڵ㣬����ʱ�������
	Node* beforeNode = Head;

	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
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

			//����һ����ѧ�����ڶ��з����ڴ�
			Node* pNewNode = (Node*)malloc(sizeof(Node));

			//ָ��ָ����һ����ָ��
			pNewNode->Next = NULL;

			//����ڵ�Ϊͷ�ڵ�
			if (p == Head)
			{
				pNewNode->Next = p;
				Head = pNewNode;
			}
			//����ڵ�Ϊβ�ڵ�
			else if (p->Next == NULL)
			{
				p->Next = pNewNode;
				pNewNode->Next = NULL;
			}
			//����ڵ�Ϊ�м�ڵ�
			else
			{
				beforeNode->Next = pNewNode;
				pNewNode->Next = p;
			}

			//¼��ѧ����Ϣ
			printf("������ѧ��������\n");
			scanf_s("%s", pNewNode->stu.name, sizeof(pNewNode->stu.name));
			printf("������ѧ��ѧ�ţ�\n");
			scanf_s("%d", &pNewNode->stu.num);//sizeof(pNewNode->stu.name)
			printf("������ѧ���ɼ���\n");
			scanf_s("%d", &pNewNode->stu.grade);//sizeof(pNewNode->stu.grade)
			
			printf("����ɹ����뱣�棡\n\n");
		}
		beforeNode = p;
		p = p->Next;
	}

	if (!isFindStu)
	{
		printf("ѧ����������δ�ҵ���ѧ�����޷����в��������\n\n");
	}

	system("pause");
	system("cls");
}

//����ѧ���ɼ�
void sort() 
{
	system("cls");
	//��������
	Node* p = Head;

	link_order(p);
	printf("������ɣ��뱣�棡\n");

	system("pause");
	system("cls");
}

//���ź���
void link_order(Node* p_head)
{
	Node* pb, * pf, temp;
	pf = p_head;
	if (p_head == NULL) //����Ϊ��
	{
		printf("����Ҫ����\n");
		return;
	}
	if (p_head->Next == NULL) //������1���ڵ�
		return;

	while (pf->Next != NULL) //��pfָ��Ľڵ�Ϊ��׼�ڵ�
	{
		pb = pf->Next;//pb�ӻ�׼�����һ���ڵ㿪ʼ
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