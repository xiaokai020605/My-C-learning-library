#include<iostream>
#include<string>
#include"WorkManager.h"
#include"Worker.h"
using namespace std;

int main()
{
	//���Դ���
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 2);
	worker->showInfo();*/

	//ʵ���������߶���
	WorkManager wm;

	int choice = 0;//����һ��ѡ�����
	
	//�˵�����ѭ��
	while (true)
	{
		//���ó�Ա����
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ����ְ
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://���ձ������
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
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