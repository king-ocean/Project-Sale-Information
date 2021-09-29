#pragma once

#include<iostream>
#include<string>

//define interface
class Page
{
public:
	Page() {};
	virtual ~Page() {};
	virtual void Form() = 0;//一个功能里包含的功能
	virtual int MainSelect() = 0;//系统主页面
	virtual int ManManage() = 0;//人员管理头页面

};

//实现接口
//实现接口是通过派生类实现的，每个派生类依据自身特点，可以获取同一接口的不同实现
//也就是所谓的多态
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
