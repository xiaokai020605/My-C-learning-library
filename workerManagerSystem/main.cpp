#include<iostream>
#include<string>
#include"WorkManager.h"
#include"Worker.h"
using namespace std;

int main()
{
	//测试代码
	/*Worker* worker = NULL;
	worker = new Employee(1, "张三", 2);
	worker->showInfo();*/

	//实例化管理者对象
	WorkManager wm;

	int choice = 0;//声明一个选择变量
	
	//菜单界面循环
	while (true)
	{
		//调用成员函数
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;

		
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除离职
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
