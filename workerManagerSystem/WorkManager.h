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

	//菜单展示
	void Show_Menu();
	//实现退出功能
	void exitSystem();

	~WorkManager();

	void Add_Emp();//添加职工

	void save();//保存文件

	int m_EmpNum;//记录文件中的人数个数
	Worker** m_EmpArrary;//员工数组指针

	//判断文件是否为空
	bool m_Fileempty;

	//统计文件当中的人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工函数
	void show_Emp();

	//删除职工函数
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//排序函数
	void Sort_Emp();

	//清空文件
	void Clean_File();

};
