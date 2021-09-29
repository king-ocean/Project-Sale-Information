#include"ProAndMark.h"
#include"Page.h"
#include<iostream>
#include<string>

//接口的外部实现
void ChildProAndMark::AddProduct()

{

	system("cls");
	int type;
	printf("请选择需要添加的类型——1.产品自身信息，2.产品销售信息\n");
	scanf("%d", &type);

	if (type == 1)
	{
		AddProductInformation();
	}

	else if (type == 2)
	{
		AddMarketingInformation();
	}

}

void ChildProAndMark::AddProductInformation()

{

	FILE* fp;
	fp = fopen("d:\\ProductInformation.txt", "a+");
	ProductInformation* head = NULL;
	int n;

	do {
		InputProductInformation(fp, head);
		printf("是否继续添加（是1，否0）？\n");
		scanf("%d", &n);
	} 
	while (n == 1);

	fclose(fp);

}

void ChildProAndMark::AddMarketingInformation()

{

	FILE* fp;
	fp = fopen("d:\\MarketingInformation.txt", "a+");
	MarketingInformation* primal = NULL;
	//int n = 1;
	int n;

	do {
		InputMarketingInformation(fp, primal);
		printf("是否继续添加（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fclose(fp);

}

void ChildProAndMark::InputProductInformation(FILE* fp, ProductInformation* head)

{

	ProductInformation* pnew, * ptail;
	ptail = head;
	pnew = (ProductInformation*)malloc(sizeof(ProductInformation));
	printf("编码\t名称\t总数\t进价\t产商\t入库时间(如：xxxx-xx-xx)\n");
	scanf("%s\t%s\t%d\t%f\t%s\t%s", pnew->code, pnew->name, &pnew->totalNumber,
		&pnew->unitPrice, pnew->producer, pnew->stockDate);
	fprintf(fp, "%-8s %-8s %-8d %-8.2f %-8s %s\n", pnew->code, pnew->name,
		pnew->totalNumber, pnew->unitPrice, pnew->producer, pnew->stockDate);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;

}

void ChildProAndMark::InputMarketingInformation(FILE* fp, MarketingInformation* primal)

{

	MarketingInformation* pnew, * ptail;
	ptail = primal;
	pnew = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	printf("销售员\t顾客\t顾客联系方式\t产品名称\t产品编码\t销售数量\t售价\t说明\t销售时间(如：xxxx-xx-xx)\n");
	scanf("%s%s%s%s%s%d%f%s%s", pnew->salesman, pnew->customer, pnew->customerPhone, pnew->productName,
		pnew->productCode, &pnew->amount, &pnew->unitPrice, pnew->notes, pnew->salesDate);
	fprintf(fp, "%-8s%-8s%-16s%-16s%-16s%-8d\t%-8.2f%-8s%s\n", pnew->salesman, pnew->customer,
		pnew->customerPhone, pnew->productName, pnew->productCode, pnew->amount,
		pnew->unitPrice, pnew->notes, pnew->salesDate);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;

}

void ChildProAndMark::ReadProductInformation(FILE* fp, ProductInformation* head)

{

	ProductInformation* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (ProductInformation*)malloc(sizeof(ProductInformation));
		fscanf(fp, "%10s%10s%d%f%10s%12s", p->code, p->name, &p->totalNumber, &p->unitPrice,
			p->producer, p->stockDate);
		if (!feof(fp))
		{
			q->next = p;
			q = p;
		}
	}

	q->next = NULL;

}

void ChildProAndMark::ReadMarketingInformation(FILE* fp, MarketingInformation* primal)

{

	MarketingInformation* p, * q;

	q = primal;

	while (!feof(fp))
	{
		p = (MarketingInformation*)malloc(sizeof(MarketingInformation));
		/*fscanf(fp, "%10s%10s%15s%20s%20s%d%f%30s%12%", p->salesman, p->customer,
			p->customerPhone, p->productName, p->productCode, &p->amount,
			&p->unitPrice, p->notes, p->salesDate);*/
		fscanf(fp, "%10s%10s%15s%20s%20s%d%f%30s%12s", p->salesman, p->customer,
			p->customerPhone, p->productName, p->productCode, &p->amount,
			&p->unitPrice, p->notes, p->salesDate);
		if (!feof(fp))
		{
			q->next = p;
			q = p;
		}
	}

	q->next = NULL;

}

void ChildProAndMark::CheckProduct()

{

	system("cls");
	FILE* fp, * fp2;
	fp = fopen("d:\\ProductInformation.txt", "r");
	fp2 = fopen("d:\\MarketingInformation.txt", "r");
	ProductInformation* head;
	MarketingInformation* primal;
	head = (ProductInformation*)malloc(sizeof(ProductInformation));
	primal = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	ReadProductInformation(fp, head);
	ReadMarketingInformation(fp2, primal);
	int n;

	do {
		SearchProduct(head, primal);
		printf("是否继续查询（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fclose(fp);
	fclose(fp2);

}

ProductInformation* ChildProAndMark::FindProductInformation(ProductInformation* head, char* name)

{

	while (head != NULL)
	{
		if (strcmp(name, head->code) == 0)
		{
			return head;
		}
		head = head->next;
	}

	return NULL;

}

MarketingInformation* ChildProAndMark::FindMarketingInformation(MarketingInformation* primal, char* name)

{

	while (primal != NULL)
	{
		if (strcmp(name, primal->productCode) == 0)
		{
			return primal;
		}
		primal = primal->next;
	}

	return NULL;

}

void ChildProAndMark::SearchProduct(ProductInformation* head, MarketingInformation* primal)

{

	char productCode[20];
	ProductInformation* p;
	MarketingInformation* q;

	printf("请输入需要查询的产品编码\n");
	scanf("%s", productCode);
	p = FindProductInformation(head, productCode);

	if (p == NULL)
	{
		printf("没有该产品\n");
	}
	else
	{
		printf("编码\t名称\t总数\t进价\t产商\t入库时间\n");
		printf("%-8s%-8s%-8d%-8.2f%-8s%s\n", p->code, p->name, p->totalNumber,
			p->unitPrice, p->producer, p->stockDate);
	}
	q = FindMarketingInformation(primal, productCode);
	/*printf("销售时间\t销售数量\t售价\t销售员\t顾客\t顾客联系方式\t说明\n");
	printf("%s\t%s\t%s\t%s\t%s\t%d\t%f\t%s\t%s\n", q->salesDate, q->amount, q->unitPrice,
		q->salesman, q->customer, q->customerPhone, q->notes);*/

	if (q != NULL)
	{
		printf("销售员\t顾客\t顾客电话\t产品名称\t产品编号\t销售数量\t售价\t说明\t销售时间\n");
		printf("%-8s%-8s%-16s%-16s%-16s%-8d\t%-8.2f%-8s%s\n", q->salesman, q->customer, q->customerPhone,
			q->productName, q->productCode, q->amount, q->unitPrice, q->notes, q->salesDate);
	}

	else
	{
		printf("没有此产品的销售信息\n");
	}
	//primal = primal->next;

}

void ChildProAndMark::InputAgain(FILE* fp, ProductInformation* head)

{

	head = head->next;

	while (head != NULL)
	{
		fprintf(fp, "%s\t%s\t%d\t%f\t%s\t%s\n", head->code, head->name,
			head->totalNumber, head->unitPrice, head->producer, head->stockDate);
		head = head->next;
	}

}

void ChildProAndMark::InputAgain(FILE* fp, MarketingInformation* primal)

{

	primal = primal->next;
	while (primal != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%f\t%s\t%s\n", primal->salesman, primal->customer,
			primal->customerPhone, primal->productName, primal->productCode, primal->amount,
			primal->unitPrice, primal->notes, primal->salesDate);
		primal = primal->next;
	}

}

void ChildProAndMark::AlterProduct()

{

	system("cls");
	FILE* fp;
	FILE* fp2;
	fp = fopen("d:\\ProductInformation.txt", "r");
	fp2 = fopen("d:\\MarketingInformation.txt", "r");
	ProductInformation* head;
	MarketingInformation* primal;
	head = (ProductInformation*)malloc(sizeof(ProductInformation));
	primal = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	ReadProductInformation(fp, head);
	ReadMarketingInformation(fp2, primal);
	//fclose(fp);
	//int n = 1;
	int n;

	do {
		printf("1、修改产品自身信息；2、修改产品销售信息\n");
		scanf("%d", &n);

		if (n == 1)
		{
			ChangeProductInformation(fp, head);
		}
		else if (n == 2)
		{
			ChangeMarketingInformation(fp2, primal);
		}
		else
		{
			printf("输入错误！");
		}

		printf("是否继续修改（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\ProductInformation.txt", "w+");
	fp2 = fopen("d:\\MarketingInformation.txt", "w+");
	InputAgain(fp, head);
	InputAgain(fp2, primal);
	fclose(fp);
	fclose(fp2);

}



void ChildProAndMark::ChangeProductInformation(FILE* fp, ProductInformation* head)

{

	char content[10], code[10];
	int type;
	ProductInformation* p;

	printf("请输入需要修改的产品编码\n");
	scanf("%s", code);

	p = FindProductInformation(head, code);
	if (p == NULL)
	{
		printf("没有该产品\n");
		return;
	}

	printf("请选择需要修改信息的类别:\n");
	printf("(1.编码\t2.名称\t3.总数\t4.单价\t5.产商\t6.入库时间(如：xxxx-xx-xx))\n");
	scanf("%d", &type);

	printf("请输入新的内容:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->code, content);
		break;
	case 2:
		strcpy(p->name, content);
		break;
	case 3:
		p->totalNumber = atoi(content);
		break;
	case 4:
		p->unitPrice = atof(content);
		break;
	case 5:
		strcpy(p->producer, content);
		break;
	case 6:
		strcpy(p->stockDate, content);
		break;
	}

}


void ChildProAndMark::ChangeMarketingInformation(FILE* fp, MarketingInformation* primal)

{
	char content[30], productCode[20];
	int type;
	MarketingInformation* p;

	printf("请输入需要修改的产品名称\n");
	scanf("%s", &productCode);

	p = FindMarketingInformation(primal, productCode);
	if (p == NULL)
	{
		printf("没有该产品\n");
		return;
	}

	printf("请选择需要修改信息的类别:\n");
	printf("(1、销售员；2、顾客；3、顾客电话；4、产品名称；5、产品编号；6、销售数量；7、售价；8、说明；9、销售时间）\n");
	scanf("%d", &type);

	printf("请输入新的内容:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->salesman, content);
		break;
	case 2:
		strcpy(p->customer, content);
		break;
	case 3:
		strcpy(p->customerPhone, content);
		break;
	case 4:
		strcpy(p->productName, content);
		break;
	case 5:
		strcpy(p->productCode, content);
		break;
	case 6:
		p->amount = atoi(content);
		break;
	case 7:
		p->unitPrice = atof(content);
		break;
	case 8:
		strcpy(p->notes, content);
		break;
	case 9:
		strcpy(p->salesDate, content);
		break;
	}

}

void ChildProAndMark::DeleteProduct()

{

	system("cls");
	FILE* fp;
	FILE* fp2;
	fp = fopen("d:\\ProductInformation.txt", "r");
	fp2 = fopen("d:\\MarketingInformation.txt", "r");
	ProductInformation* head;
	MarketingInformation* primal;
	head = (ProductInformation*)malloc(sizeof(ProductInformation));
	primal = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	int n;
	char productCode[20];
	ReadProductInformation(fp, head);
	ReadMarketingInformation(fp2, primal);
	fclose(fp);
	fclose(fp2);
	do {
		printf("请输入需要删除的产品编码\n");
		scanf("%s", productCode);
		CancelProductInformation(head, productCode);
		CancelMarketingInformation(primal, productCode);
		printf("是否继续删除（是1，否0）？\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\ProductInformation.txt", "w+");
	fp2 = fopen("d:\\MarketingInformation.txt", "w+");
	InputAgain(fp, head);
	InputAgain(fp2, primal);
	fclose(fp);
	fclose(fp2);

}

ProductInformation* ChildProAndMark::CancelProductInformation(ProductInformation* head, char* code)

{

	//char name[10];
	ProductInformation* p, * pold;

	//printf("请输入需要删除的产品名称\n");
	//scanf("%s", name);

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

MarketingInformation* ChildProAndMark::CancelMarketingInformation(MarketingInformation* primal, char* code)

{

	MarketingInformation* p, * pold;
	p = primal;
	while (primal != NULL && strcmp(code, p->productCode) == 0)
	{
		primal = primal->next;
		free(p);
		p = primal;
	}
	if (primal == NULL)
	{
		return primal;
	}
	p = primal->next;
	pold = primal;
	while (p != NULL)
	{
		if (strcmp(code, p->productCode) == 0)
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
	return primal;

}