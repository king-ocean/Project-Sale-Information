#pragma once

#include<iostream>
#include<string>
#include<string.h>
using namespace std;


typedef  struct Customer         //顾客信息
{
    char code[10];
    char name[10];
    char phone[15];
    char address[50];
    struct Customer* next;
}Customer;


class Cus
{
public:
    Cus() {};
    virtual ~Cus() {};
    virtual void AddCustomer() = 0;                //顾客管理函数声明
    virtual void InputCustomer(FILE* fp, Customer* head) = 0;
    virtual void ReadCustomer(FILE* fp, Customer* head) = 0;
    virtual Customer* FindCustomer(Customer* head, char* name) = 0;
    virtual void CheckCustomer() = 0;
    virtual void SearchCustomer(Customer* head) = 0;
    virtual void InputAgain(FILE* fp, Customer* head) = 0;
    virtual void AlterCustomer() = 0;
    virtual void ChangeCustomer(Customer* head) = 0;
    virtual void DeleteCustomer() = 0;
    virtual Customer* CancelCustomer(Customer* head) = 0;

};


class MemberCus
{
public:
    MemberCus() {};
    virtual ~MemberCus() {};
    void AddCustomer();                //顾客管理函数声明
    void InputCustomer(FILE* fp, Customer* head);
    void ReadCustomer(FILE* fp, Customer* head);
    Customer* FindCustomer(Customer* head, char* name);
    void CheckCustomer();
    void SearchCustomer(Customer* head);
    void InputAgain(FILE* fp, Customer* head);
    void AlterCustomer();
    void ChangeCustomer(Customer* head);
    void DeleteCustomer();
    Customer* CancelCustomer(Customer* head);

};
