#include"Cus.h"
#include"Page.h"
#include<iostream>
#include<string>

using namespace std;

void MemberCus::AddCustomer()          //顾客添加函数

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Customer.txt", "a+");
	int n;
	Customer* head = NULL;
	do {
		InputCustomer(fp, head);
		printf("是否继续添加（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);

}

void MemberCus::InputCustomer(FILE* fp, Customer* head)

{

	Customer* pnew, * ptail;
	ptail = head;
	pnew = (Customer*)malloc(sizeof(Customer));
	printf("编号\t姓名\t联系电话\t联系地址\n");
	scanf("%s%s%s%s", pnew->code, pnew->name, pnew->phone, pnew->address);
	fprintf(fp, "%-8s %-8s %-16s %s\n", pnew->code, pnew->name, pnew->phone, pnew->address);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;

}


void MemberCus::ReadCustomer(FILE* fp, Customer* head)

{

	Customer* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (Customer*)malloc(sizeof(Customer));
		fscanf(fp, "%10s%10s%15s%50s", p->code, p->name, p->phone, p->address);
		q->next = p;
		q = p;
	}
	q->next = NULL;

}


Customer* MemberCus::FindCustomer(Customer* head, char* code)

{

	while (head != NULL)
	{
		if (strcmp(code, head->code) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;

}


void MemberCus::CheckCustomer()      //顾客查询函数

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Customer.txt", "r");
	Customer* head;
	head = (Customer*)malloc(sizeof(Customer));
	ReadCustomer(fp, head);
	int n;
	do {
		SearchCustomer(head);
		printf("是否继续查询（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);

}


void MemberCus::SearchCustomer(Customer* head)

{

	char code[10];
	Customer* p;

	printf("请输入需要查询的顾客编号\n");
	scanf("%s", code);
	p = FindCustomer(head, code);

	if (p == NULL)
	{
		printf("没有该顾客\n");
		return;
	}
	else
	{
		printf("编号\t姓名\t联系电话\t联系地址\n");
		printf("%-8s%-8s%-16s%s\n", p->code, p->name, p->phone, p->address);
	}

}


void MemberCus::InputAgain(FILE* fp, Customer* head)

{

	head = head->next;

	while (head->next != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", head->code, head->name, head->phone, head->address);
		head = head->next;
	}

}


void MemberCus::AlterCustomer()        //顾客修改函数

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Customer.txt", "r");
	Customer* head;
	head = (Customer*)malloc(sizeof(Customer));
	int n;
	ReadCustomer(fp, head);
	fclose(fp);
	do {
		fp = fopen("d:\\Customer.txt", "w+");
		ChangeCustomer(head);
		printf("是否继续修改（是1，否0）？\n");
		scanf("%d", &n);
		fclose(fp);
	} while (n == 1);

	fp = fopen("d:\\Customer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);

}


void MemberCus::ChangeCustomer(Customer* head)

{

	char content[10], code[10];
	int type;
	Customer* p;

	printf("请输入需要修改的顾客的编号\n");
	scanf("%s", code);
	p = FindCustomer(head, code);

	if (p == NULL)
	{
		printf("没有该顾客\n");
		return;
	}

	printf("请选择需要修改信息的类别:\n");
	printf("(1.姓名\t2.联系电话\t3.联系地址)\n");
	scanf("%d", &type);

	printf("请输入新的内容:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->name, content);
		break;

	case 2:
		strcpy(p->phone, content);
		break;

	case 3:
		strcpy(p->address, content);
		break;
	}

}


void MemberCus::DeleteCustomer()       //顾客删除函数

{

	system("cls");
	FILE* fp;
	system("cls");
	fp = fopen("d:\\Customer.txt", "r");
	Customer* head;
	head = (Customer*)malloc(sizeof(Customer));
	int n;
	ReadCustomer(fp, head);
	fclose(fp);
	do {
		CancelCustomer(head);
		printf("是否继续删除（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\Customer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);

}



Customer* MemberCus::CancelCustomer(Customer* head)

{

	char code[10];
	Customer* p, * pold;

	printf("请输入需要删除的顾客编号\n");
	scanf("%s", code);

	p = head;

	while (head != NULL && strcmp(code, p->code) == 0)
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
		if (strcmp(code, p->code) == 0)
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

