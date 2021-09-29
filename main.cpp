#include<iostream>
#include<string>
#include"Page.h"
#include"function.h"
#include"Cus.h"
#include"Producer.h"
#include "ProAndMark.h"


using namespace std;



int GetPage(Page& m_page)

{

	int n;
	n = m_page.MainSelect();
	return n;

}

int ManManage(Page& m_man)

{

	int n;
	n = m_man.ManManage();
	return n;

}

int ProductManage(ChildPage& p_pro)

{

	int n;
	n = p_pro.ProductManage();
	return n;

}

int SellerManage(ChildPage& seller)

{

	int n;
	n = seller.SellerManage();
	return n;

}

int CustomerManage(ChildPage& cust)

{

	int n;
	n = cust.CustomerManage();
	return n;

}


int main()

{

	ChildPage page;
	ChildPage man;
	ChildFunc Man;
	ChildProAndMark Pro;
	ChildProd prod;
	MemberCus customer;

	for (;;)

	{
		switch (GetPage(page))

		{
		case 1:
			switch (ManManage(man))

			{
			case 1:
				Man.AddSalesman();
				continue;

			case 2:
				Man.CheckMan();
				continue;

			case 3:
				Man.AlterMan();
				continue;

			case 4:
				Man.DeleteMan();
				continue;

			case 0:
				break;

			}
			break;

		case 2:
			switch (ProductManage(man))

			{
			case 1:
				Pro.AddProduct();
				continue;

			case 2:
				Pro.CheckProduct();
				continue;

			case 3:
				Pro.AlterProduct();
				continue;

			case 4:
				Pro.DeleteProduct();
				continue;

			case 0:
				break;

			}
			break;

		case 3:
			switch (SellerManage(man))

			{
			case 1:
				prod.AddProducer();
				continue;

			case 2:
				prod.CheckProducer();
				continue;

			case 3:
				prod.AlterProducer();
				continue;

			case 4:
				prod.DeleteProducer();
				continue;

			case 0:
				break;

			}
			break;

		case 4:
			switch (CustomerManage(man))

			{
			case 1:
				customer.AddCustomer();
				continue;

			case 2:
				customer.CheckCustomer();
				continue;

			case 3:
				customer.AlterCustomer();
				continue;
				
			case 4:
				customer.DeleteCustomer();
				continue;

			case 0:
				break;

			}

		default:
			break;

		}

	}

}

