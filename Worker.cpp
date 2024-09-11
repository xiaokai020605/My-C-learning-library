#include"Worker.h"

//普通职工
void Employee::showInfo() 
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理派发的任务" << endl;
}
string Employee::getDeptName()
{
	return string("员工");
 }
Employee::Employee(int id, string name, int deid)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DepId;
}
//经理
Manager::Manager(int id, string name, int deid)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DepId;
}
//重写父类当中的纯虚函数
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id<<"\t"
		<< "职工姓名：" << this->m_name<<"\t"
		<< "岗位：" << this->getDeptName()<<"\t"
		<< "岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
 }
string Manager::getDeptName()
{
	return string("经理");
 }

//老板
//构造函数，初始化变量
Boos::Boos(int id, string name, int deid)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DepId;
}
//重写父类当中的纯虚函数
void Boos::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：派发任务，摸鱼" << endl;
 }
string Boos::getDeptName()
{
	return string("老板");
 }

