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
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);

	fclose(fp);

}
void ChildProd::InputProducer(FILE* fp, Producer* head)

{

	Producer* pnew, * ptail;
	ptail = head;
	pnew = (Producer*)malloc(sizeof(Producer));
	printf("���\t����\t��ϵ�绰\t��ϵ��ַ\n");
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
		printf("�Ƿ������ѯ����1����0����\n");
		scanf("%d", &n);
	} while (n == 1);

	fclose(fp);

}

void ChildProd::SearchProducer(Producer* head)

{

	char code[10];
	Producer* p;

	printf("��������Ҫ��ѯ�Ľ����̱��\n");
	scanf("%s", code);
	p = FindProducer(head, code);

	if (p == NULL)
	{
		printf("û�иý�����\n");
		return;
	}
	else
	{
		printf("���\t����\t��ϵ�绰\t��ϵ��ַ\n");
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
		printf("�Ƿ�����޸ģ���1����0����\n");
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

	printf("��������Ҫ�޸ĵĽ����̵ı��\n");
	scanf("%s", code);
	p = FindProducer(head, code);

	if (p == NULL)
	{
		printf("û�иý�����\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1.����\t2.��ϵ�绰\t3.��ϵ��ַ)\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
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
		printf("�Ƿ����ɾ������1����0����\n");
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

	printf("��������Ҫɾ���Ľ����̱��\n");
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
