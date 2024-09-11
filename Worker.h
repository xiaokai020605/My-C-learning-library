#pragma once
#include<iostream>
using namespace std;

//职工抽象基类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id=0;//职工编号
	string m_name;//职工姓名
	int m_DepId=0;//所在岗位编号
};

//普通职工类
class Employee :public Worker
{
public:
	//构造函数，初始化变量
	Employee(int id, string name, int deid);


	//重写父类当中的纯虚函数
	virtual void showInfo();
	virtual string getDeptName() ;
};

//经理类
class Manager :public Worker
{
public:
	//构造函数，初始化变量
	Manager(int id, string name, int deid);


	//重写父类当中的纯虚函数
	virtual void showInfo();
	virtual string getDeptName();
};

//老板类
class Boos :public Worker
{
public:

	//构造函数，初始化变量
	Boos(int id, string name, int deid);

	//重写父类当中的纯虚函数
	virtual void showInfo();
	virtual string getDeptName();
};