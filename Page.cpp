#include"Page.h"
#include<iostream>
#include<string>



//�ӿڵ��ⲿʵ��
void ChildPage::Form()

{

	printf("\t\t   ������������������������������������������������������������\n");
	printf("\t\t   �� 1. �����Ϣ    2. ��Ϣ��ѯ ��\n");
	printf("\t\t   ��                            ��\n");
	printf("\t\t   �� 3. �޸���Ϣ    4. ɾ����Ϣ ��\n");
	printf("\t\t   ��                            ��\n");
	printf("\t\t   �� 0. �����ϼ�                ��\n");
	printf("\t\t   ������������������������������������������������������������\n");
	printf("\t\t����ѡ��(0-4):");

}

int ChildPage::MainSelect()

{

	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��         ������Ϣ����ϵͳ          ��\n");
	printf("\t\t ====================================\n");
	printf("\t\t  ����������������������������������������������������������������\n");
	printf("\t\t  �� 1. ��Ա����     2. ��Ʒ����  ��\n");
	printf("\t\t  ��                              ��\n");
	printf("\t\t  �� 3. �����̹���   4. �˿͹���  ��\n");
	printf("\t\t  ����������������������������������������������������������������\n");
	printf("\t\t����ѡ��(1-4):");
	scanf("%d", &n);
	return n;

}

int ChildPage::ManManage()

{

	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             ��Ա����              ��\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

int ChildPage::ProductManage()

{

	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             ��Ʒ����              ��\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

int ChildPage::SellerManage()

{

	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             �����̹���            ��\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

int ChildPage::CustomerManage()

{

	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             �˿͹���              ��\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

