#pragma once
//Producer.h

#include<iostream>
#include<string>


using namespace std;

typedef  struct Producer              //进货商信息
{
	char code[10];
	char name[10];
	char phone[15];
	char address[50];
	struct Producer* next;
}Producer;

typedef struct ProductInformation                     //产品信息
{
	char code[10];
	char name[10];
	int totalNumber;
	float unitPrice;
	char producer[10];
	char stockDate[12];
	struct ProductInformation* next;
}ProductInformation;

typedef struct MarketingInformation                  //销售信息
{
	char salesman[10];
	char customer[10];
	char customerPhone[15];
	char productName[20];
	char productCode[20];
	int amount;
	float unitPrice;
	char notes[30];
	char salesDate[12];
	struct MarketingInformation* next;
}MarketingInformation;

class Prod
{
public:
	Prod() {};
	virtual ~Prod() {};
	virtual void AddProducer() = 0;
	virtual void InputProducer(FILE* fp, Producer* head) = 0;
	virtual void ReadProducer(FILE* fp, Producer* head) = 0;
	virtual Producer* FindProducer(Producer* head, char* name) = 0;
	virtual void CheckProducer() = 0;
	virtual void SearchProducer(Producer* head) = 0;
	virtual void InputAgain(FILE* fp, Producer* head) = 0;
	virtual void AlterProducer() = 0;
	virtual void ChangeProducer(Producer* head) = 0;
	virtual void DeleteProducer() = 0;
	virtual Producer* CancelProducer(Producer* head) = 0;
	//virtual ProductInformation* CancelProductInformation(ProductInformation* head, char* name) = 0;
	//virtual MarketingInformation* CancelMarketingInformation(MarketingInformation* primal, char* name) = 0;

};

class ChildProd :public Prod
{
public:
	ChildProd() {};
	~ChildProd() {};
	virtual void AddProducer();
	virtual void InputProducer(FILE* fp, Producer* head);
	virtual void ReadProducer(FILE* fp, Producer* head);
	virtual Producer* FindProducer(Producer* head, char* name);
	virtual void CheckProducer();
	virtual void SearchProducer(Producer* head);
	virtual void InputAgain(FILE* fp, Producer* head);
	virtual void AlterProducer();
	virtual void ChangeProducer(Producer* head);
	virtual void DeleteProducer();
	virtual Producer* CancelProducer(Producer* head);
	//virtual ProductInformation* CancelProductInformation(ProductInformation* head, char* name);
	//virtual MarketingInformation* CancelMarketingInformation(MarketingInformation* primal, char* name);


};