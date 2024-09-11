#pragma once
#include<iostream>
#include"Worker.h"
#include<fstream>
using namespace std;

#define FILENAME "empFile.txt"

class WorkManager
{
public:
	WorkManager();

	//�˵�չʾ
	void Show_Menu();
	//ʵ���˳�����
	void exitSystem();

	~WorkManager();

	void Add_Emp();//���ְ��

	void save();//�����ļ�

	int m_EmpNum;//��¼�ļ��е���������
	Worker** m_EmpArrary;//Ա������ָ��

	//�ж��ļ��Ƿ�Ϊ��
	bool m_Fileempty;

	//ͳ���ļ����е�����
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ������
	void show_Emp();

	//ɾ��ְ������
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

};
