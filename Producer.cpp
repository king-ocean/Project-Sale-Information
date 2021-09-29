#pragma once
#include<iostream>
#include<string>
#include"Producer.h"
#include"Page.h"
#include<string.h>
void ChildProd::AddProducer()

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Producer.txt", "a+");
	int n;
	Producer* head = NULL;

	do {
		InputProducer(fp, head);
		printf("是否继续添加（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fclose(fp);

}
void ChildProd::InputProducer(FILE* fp, Producer* head)

{

	Producer* pnew, * ptail;
	ptail = head;
	pnew = (Producer*)malloc(sizeof(Producer));
	printf("编号\t姓名\t联系电话\t联系地址\n");
	scanf("%s%s%s%s", pnew->code, pnew->name, pnew->phone, pnew->address);
	fprintf(fp, "%-8s %-8s %-16s %s\n", pnew->code, pnew->name, pnew->phone, pnew->address);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;

}

void ChildProd::ReadProducer(FILE* fp, Producer* head)

{

	Producer* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (Producer*)malloc(sizeof(Producer));
		fscanf(fp, "%10s%10s%15s%50s", p->code, p->name, p->phone, p->address);
		q->next = p;
		q = p;
	}
	q->next = NULL;

}


Producer* ChildProd::FindProducer(Producer* head, char* code)

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

void ChildProd::CheckProducer()

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Producer.txt", "r");
	Producer* head;
	head = (Producer*)malloc(sizeof(Producer));
	ReadProducer(fp, head);
	int n;

	do {
		SearchProducer(head);
		printf("是否继续查询（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fclose(fp);

}

void ChildProd::SearchProducer(Producer* head)

{

	char code[10];
	Producer* p;

	printf("请输入需要查询的进货商编号\n");
	scanf("%s", code);
	p = FindProducer(head, code);

	if (p == NULL)
	{
		printf("没有该进货商\n");
		return;
	}
	else
	{
		printf("编号\t姓名\t联系电话\t联系地址\n");
		printf("%-8s%-8s%-16s%s\n", p->code, p->name, p->phone, p->address);
	}

}



void ChildProd::InputAgain(FILE* fp, Producer* head)

{

	head = head->next;

	while (head->next != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", head->code, head->name, head->phone, head->address);
		head = head->next;
	}

}


void ChildProd::AlterProducer()

{

	system("cls");
	FILE* fp;
	fp = fopen("d:\\Producer.txt", "r");
	Producer* head;
	head = (Producer*)malloc(sizeof(Producer));
	int n;
	ReadProducer(fp, head);
	fclose(fp);

	do {
		fp = fopen("d:\\Producer.txt", "w+");
		ChangeProducer(head);
		printf("是否继续修改（是1，否0）？\n");
		scanf("%d", &n);
		fclose(fp);
	} while (n == 1);

	fp = fopen("d:\\Producer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);

}

void ChildProd::ChangeProducer(Producer* head)

{

	char content[10], code[10];
	int type;
	Producer* p;

	printf("请输入需要修改的进货商的编号\n");
	scanf("%s", code);
	p = FindProducer(head, code);

	if (p == NULL)
	{
		printf("没有该进货商\n");
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


void ChildProd::DeleteProducer()

{

	system("cls");
	FILE* fp;
	system("cls");
	fp = fopen("d:\\Producer.txt", "r");
	Producer* head;
	head = (Producer*)malloc(sizeof(Producer));
	int n;
	ReadProducer(fp, head);
	fclose(fp);

	do {
		CancelProducer(head);
		printf("是否继续删除（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\Producer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);

}

Producer* ChildProd::CancelProducer(Producer* head)

{

	char code[10];
	Producer* p, * pold;

	printf("请输入需要删除的进货商编号\n");
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
