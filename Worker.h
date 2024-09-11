#pragma once
#include<iostream>
using namespace std;

//ְ���������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id=0;//ְ�����
	string m_name;//ְ������
	int m_DepId=0;//���ڸ�λ���
};

//��ְͨ����
class Employee :public Worker
{
public:
	//���캯������ʼ������
	Employee(int id, string name, int deid);


	//��д���൱�еĴ��麯��
	virtual void showInfo();
	virtual string getDeptName() ;
};

//������
class Manager :public Worker
{
public:
	//���캯������ʼ������
	Manager(int id, string name, int deid);


	//��д���൱�еĴ��麯��
	virtual void showInfo();
	virtual string getDeptName();
};

//�ϰ���
class Boos :public Worker
{
public:

	//���캯������ʼ������
	Boos(int id, string name, int deid);

	//��д���൱�еĴ��麯��
	virtual void showInfo();
	virtual string getDeptName();
};