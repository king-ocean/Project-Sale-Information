#include"function.h"
#include"Page.h"
#include<iostream>
#include<string>


//�ӿڵ��ⲿʵ��
void ChildFunc::InputMan(FILE* fp, Salesman* head)

{

	Salesman* pnew, * ptail;
	ptail = head;
	pnew = (Salesman*)malloc(sizeof(Salesman));
	printf("����	����	�Ա�	��ϵ�绰	��ϵ��ַ	����������	��ְʱ��");
	printf("���������ʽxxxx-xx-xx\n");
	scanf("%s%s%s%s%s%s%s", pnew->number, pnew->name,
		pnew->gender, pnew->phone, pnew->address,
		pnew->birthDate, pnew->employedDate);
	fprintf(fp, "%-8s %-8s%-8s%-15s\t%-16s%-16s%s\n", pnew->number, pnew->name,
		pnew->gender, pnew->phone, pnew->address,
		pnew->birthDate, pnew->employedDate);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;

}

void ChildFunc::AddSalesman()

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Salesman.txt", "a+");
	int n;
	Salesman* head = NULL;
	do {
		InputMan(fp, head);
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);

}



void ChildFunc::ReadMan(FILE* fp, Salesman* head)

{

	Salesman* p, * q;

	q = head;

	while (!feof(fp))
	{

		p = (Salesman*)malloc(sizeof(Salesman));
		fscanf(fp, "%10s%10s%4s%15s%80s%14s%10s", p->number, p->name, p->gender,
			p->phone, p->address, p->birthDate, p->employedDate);
		q->next = p;
		q = p;

	}
	q->next = NULL;

}

Salesman* ChildFunc::FindMan(Salesman* head, char* number)

{

	while (head != NULL)
	{

		if (strcmp(number, head->number) == 0)
		{
			return head;
		}
		head = head->next;

	}
	return NULL;

}

void ChildFunc::CheckMan()

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Salesman.txt", "r");
	Salesman* head;
	head = (Salesman*)malloc(sizeof(Salesman));
	ReadMan(fp, head);
	int n;
	do {

		SearchMan(head);
		printf("�Ƿ������ѯ����1����0����\n");
		scanf("%d", &n);

	} while (n == 1);
	fclose(fp);

}

void ChildFunc::SearchMan(Salesman* head)

{

	char number[10];
	Salesman* p;

	printf("��������Ҫ��ѯ������Ա����\n");
	scanf("%s", number);
	p = FindMan(head, number);

	if (p == NULL)
	{
		printf("û�и�����Ա\n");
		return;
	}
	else
	{

		printf("����\t����\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t����������\t��ְʱ��\n");
		printf("%-8s%-8s%-8s%-15s\t%-16s%-16s%s\n", p->number, p->name, p->gender, p->phone, p->address,
			p->birthDate, p->employedDate);

	}

}

void ChildFunc::InputAgain(FILE* fp, Salesman* head)

{

	head = head->next;
	while (head->next != NULL)
	{

		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", head->number, head->name,
			head->gender, head->phone, head->address,
			head->birthDate, head->employedDate);
		head = head->next;

	}

}

void ChildFunc::AlterMan()

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Salesman.txt", "r");
	Salesman* head;
	head = (Salesman*)malloc(sizeof(Salesman));
	int n;
	ReadMan(fp, head);
	fclose(fp);
	do {

		fp = fopen("d:\\Salesman.txt", "w+");
		ChangeMan(head);
		printf("�Ƿ�����޸ģ���1����0����\n");
		scanf("%d", &n);
		fclose(fp);

	} while (n == 1);

	fp = fopen("d:\\Salesman.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);

}

void ChildFunc::ChangeMan(Salesman* head)

{

	char content[10], number[10];
	int type;
	Salesman* p;

	printf("��������Ҫ�޸ĵ���Ա�Ĵ���\n");
	scanf("%s", number);
	p = FindMan(head, number);

	if (p == NULL)
	{
		printf("û�и�����Ա\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1.����\t2.����\t3.�Ա�\t4.��ϵ�绰\t5.��ϵ��ַ\t6.����������\t7.��ְʱ��)\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
	scanf("%s", content);

	switch (type)
	{

	case 1:
		strcpy(p->number, content);
		break;

	case 2:
		strcpy(p->name, content);
		break;

	case 3:
		strcpy(p->gender, content);
		break;

	case 4:
		strcpy(p->phone, content);
		break;

	case 5:
		strcpy(p->address, content);
		break;

	case 6:
		strcpy(p->birthDate, content);
		break;

	case 7:
		strcpy(p->employedDate, content);
		break;

	}

}

void ChildFunc::DeleteMan()

{

	system("cls");
	FILE* fp;
	system("cls");
	fp = fopen("d:\\Salesman.txt", "r");
	Salesman* head;
	head = (Salesman*)malloc(sizeof(Salesman));
	int n;
	ReadMan(fp, head);
	fclose(fp);
	do {

		CancelMan(head);
		printf("�Ƿ����ɾ������1����0����\n");
		scanf("%d", &n);

	} while (n == 1);
	fp = fopen("d:\\Salesman.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);

}

Salesman* ChildFunc::CancelMan(Salesman* head)

{

	char number[10];
	Salesman* p, * pold;

	printf("��������Ҫɾ��������Ա����\n");
	scanf("%s", number);

	p = head;
	while (head != NULL && strcmp(number, p->number) == 0)
	{

		head = head->next;
		free(p);
		p = head;

	}
	if (head == NULL)
	{

		return head;

	}
	p = head->next;
	pold = head;
	while (p != NULL)
	{

		if (strcmp(number, p->number) == 0)
		{
			pold->next = p->next;
			free(p);
			p = pold->next;
		}
		else
		{
			pold = p;
			p = p->next;
		}

	}
	return head;

}