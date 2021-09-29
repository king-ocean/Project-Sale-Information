#pragma once

#include<iostream>
#include<string>
#include<string.h>

typedef struct Salesman               //人员信息
{
	char number[10];
	char name[10];
	char gender[4];
	char birthDate[14];
	char phone[15];
	char address[80];
	char employedDate[10];
	struct Salesman* next;
}Salesman;

//定义接口
class Func
{
public:
	Func() {};
	virtual ~Func() {};
	virtual void AddSalesman() = 0;
	virtual void InputMan(FILE* fp, Salesman* head) = 0;
	virtual void ReadMan(FILE* fp, Salesman* head) = 0;
	virtual Salesman* FindMan(Salesman* head, char* name) = 0;
	virtual void CheckMan() = 0;
	virtual void SearchMan(Salesman* head) = 0;
	virtual void InputAgain(FILE* fp, Salesman* head) = 0;
	virtual void AlterMan() = 0;
	virtual void ChangeMan(Salesman* head) = 0;
	virtual void DeleteMan() = 0;
	virtual Salesman* CancelMan(Salesman* head) = 0;

};

//实现接口
class ChildFunc :public Func
{
public:
	ChildFunc() {};
	~ChildFunc() {};
	void AddSalesman();
	void InputMan(FILE* fp, Salesman* head);
	void ReadMan(FILE* fp, Salesman* head);
	Salesman* FindMan(Salesman* head, char* name);
	void CheckMan();
	void SearchMan(Salesman* head);
	void InputAgain(FILE* fp, Salesman* head);
	void AlterMan();
	void ChangeMan(Salesman* head);
	void DeleteMan();
	Salesman* CancelMan(Salesman* head);


};
