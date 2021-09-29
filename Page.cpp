#include"Page.h"
#include<iostream>
#include<string>



//接口的外部实现
void ChildPage::Form()

{

	printf("\t\t   ┌────────────────────────────┐\n");
	printf("\t\t   │ 1. 添加信息    2. 信息查询 │\n");
	printf("\t\t   │                            │\n");
	printf("\t\t   │ 3. 修改信息    4. 删除信息 │\n");
	printf("\t\t   │                            │\n");
	printf("\t\t   │ 0. 返回上级                │\n");
	printf("\t\t   └────────────────────────────┘\n");
	printf("\t\t请您选择(0-4):");

}

int ChildPage::MainSelect()

{

	int n;
	system("cls"); /*清屏*/
	printf("\t\t ====================================\n");
	printf("\t\t│         销售信息管理系统          │\n");
	printf("\t\t ====================================\n");
	printf("\t\t  ┌──────────────────────────────┐\n");
	printf("\t\t  │ 1. 人员管理     2. 产品管理  │\n");
	printf("\t\t  │                              │\n");
	printf("\t\t  │ 3. 进货商管理   4. 顾客管理  │\n");
	printf("\t\t  └──────────────────────────────┘\n");
	printf("\t\t请您选择(1-4):");
	scanf("%d", &n);
	return n;

}

int ChildPage::ManManage()

{

	int n;
	system("cls"); /*清屏*/
	printf("\t\t ====================================\n");
	printf("\t\t│             人员管理              │\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

int ChildPage::ProductManage()

{

	int n;
	system("cls"); /*清屏*/
	printf("\t\t ====================================\n");
	printf("\t\t│             产品管理              │\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

int ChildPage::SellerManage()

{

	int n;
	system("cls"); /*清屏*/
	printf("\t\t ====================================\n");
	printf("\t\t│             进货商管理            │\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

int ChildPage::CustomerManage()

{

	int n;
	system("cls"); /*清屏*/
	printf("\t\t ====================================\n");
	printf("\t\t│             顾客管理              │\n");
	printf("\t\t ====================================\n");
	Form();
	scanf("%d", &n);
	return n;

}

