#include"Worker.h"

//��ְͨ��
void Employee::showInfo() 
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ����ɷ�������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
 }
Employee::Employee(int id, string name, int deid)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DepId;
}
//����
Manager::Manager(int id, string name, int deid)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DepId;
}
//��д���൱�еĴ��麯��
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id<<"\t"
		<< "ְ��������" << this->m_name<<"\t"
		<< "��λ��" << this->getDeptName()<<"\t"
		<< "��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
 }
string Manager::getDeptName()
{
	return string("����");
 }

//�ϰ�
//���캯������ʼ������
Boos::Boos(int id, string name, int deid)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DepId;
}
//��д���൱�еĴ��麯��
void Boos::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ���ɷ���������" << endl;
 }
string Boos::getDeptName()
{
	return string("�ϰ�");
 }

