#pragma once

#include<iostream>
#include<string>
#include<string.h>
#include"Producer.h"

//接口定义
class ProAndMark
{
public:
	ProAndMark() {};
	virtual ~ProAndMark() {};
	virtual void AddProduct() = 0;
	virtual void AddProductInformation() = 0;
	virtual void AddMarketingInformation() = 0;
	virtual void InputProductInformation(FILE* fp, ProductInformation* head) = 0;
	virtual void InputMarketingInformation(FILE* fp, MarketingInformation* primal) = 0;
	virtual void ReadProductInformation(FILE* fp, ProductInformation* head) = 0;
	virtual void ReadMarketingInformation(FILE* fp, MarketingInformation* primal) = 0;
	virtual void CheckProduct() = 0;
	virtual ProductInformation* FindProductInformation(ProductInformation* head, char* name) = 0;
	virtual MarketingInformation* FindMarketingInformation(MarketingInformation* primal, char* name) = 0;
	virtual void SearchProduct(ProductInformation* head, MarketingInformation* primal) = 0;
	virtual void AlterProduct() = 0;
	virtual void ChangeProductInformation(FILE* fp, ProductInformation* head) = 0;
	virtual void ChangeMarketingInformation(FILE* fp, MarketingInformation* primal) = 0;
	virtual void DeleteProduct() = 0;
	virtual ProductInformation* CancelProductInformation(ProductInformation* head, char* code) = 0;
	virtual MarketingInformation* CancelMarketingInformation(MarketingInformation* primal, char* code) = 0;
	virtual void InputAgain(FILE* fp, ProductInformation* head) = 0;
	virtual void InputAgain(FILE* fp, MarketingInformation* primal) = 0;
};

//接口实现
class ChildProAndMark :public ProAndMark
{
public:
	ChildProAndMark() {};
	virtual ~ChildProAndMark() {};
	void AddProduct();
	void AddProductInformation();
	void AddMarketingInformation();
	void InputProductInformation(FILE* fp, ProductInformation* head);
	void InputMarketingInformation(FILE* fp, MarketingInformation* primal);
	void ReadProductInformation(FILE* fp, ProductInformation* head);
	void ReadMarketingInformation(FILE* fp, MarketingInformation* primal);
	void CheckProduct();
	ProductInformation* FindProductInformation(ProductInformation* head, char* name);
	MarketingInformation* FindMarketingInformation(MarketingInformation* primal, char* name);
	void SearchProduct(ProductInformation* head, MarketingInformation* primal);
	void AlterProduct();
	void ChangeProductInformation(FILE* fp, ProductInformation* head);
	void ChangeMarketingInformation(FILE* fp, MarketingInformation* primal);
	void DeleteProduct();
	ProductInformation* CancelProductInformation(ProductInformation* head, char* code);
	MarketingInformation* CancelMarketingInformation(MarketingInformation* primal, char* code);
	void InputAgain(FILE* fp, ProductInformation* head);
	void InputAgain(FILE* fp, MarketingInformation* primal);

};


