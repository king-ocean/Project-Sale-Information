#include"function.h"
#include"Page.h"
#include<iostream>
#include<string>


//接口的外部实现
void ChildFunc::InputMan(FILE* fp, Salesman* head)

{

	Salesman* pnew, * ptail;
	ptail = head;
	pnew = (Salesman*)malloc(sizeof(Salesman));
	printf("代号	姓名	性别	联系电话	联系地址	出生年月日	入职时间");
	printf("日期输入格式xxxx-xx-xx\n");
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
		printf("是否继续添加（是1，否0）？\n");
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
		printf("是否继续查询（是1，否0）？\n");
		scanf("%d", &n);

	} while (n == 1);
	fclose(fp);

}

void ChildFunc::SearchMan(Salesman* head)

{

	char number[10];
	Salesman* p;

	printf("请输入需要查询的销售员代号\n");
	scanf("%s", number);
	p = FindMan(head, number);

	if (p == NULL)
	{
		printf("没有该销售员\n");
		return;
	}
	else
	{

		printf("代号\t姓名\t性别\t联系电话\t联系地址\t出生年月日\t入职时间\n");
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
		printf("是否继续修改（是1，否0）？\n");
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

	printf("请输入需要修改的人员的代号\n");
	scanf("%s", number);
	p = FindMan(head, number);

	if (p == NULL)
	{
		printf("没有该销售员\n");
		return;
	}

	printf("请选择需要修改信息的类别:\n");
	printf("(1.代号\t2.姓名\t3.性别\t4.联系电话\t5.联系地址\t6.出生年月日\t7.入职时间)\n");
	scanf("%d", &type);

	printf("请输入新的内容:\n");
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
		printf("是否继续删除（是1，否0）？\n");
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

	printf("请输入需要删除的销售员代号\n");
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