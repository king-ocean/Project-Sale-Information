#pragma once

#include<iostream>
#include<string>

//define interface
class Page
{
public:
	Page() {};
	virtual ~Page() {};
	virtual void Form() = 0;//һ������������Ĺ���
	virtual int MainSelect() = 0;//ϵͳ��ҳ��
	virtual int ManManage() = 0;//��Ա����ͷҳ��

};

//ʵ�ֽӿ�
//ʵ�ֽӿ���ͨ��������ʵ�ֵģ�ÿ�����������������ص㣬���Ի�ȡͬһ�ӿڵĲ�ͬʵ��
//Ҳ������ν�Ķ�̬
class ChildPage :public Page
{
public:
	ChildPage() {};
	~ChildPage() {};
	void Form();
	int MainSelect();
	int ManManage();
	int ProductManage();
	int SellerManage();
	int CustomerManage();


};
