#include"WorkManager.h"


WorkManager::WorkManager()
{
	//文件不存在的时候初始化

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout<<"文件不存在"<<endl;
		//初始化属性
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArrary = NULL;//初始化指针
		this->m_Fileempty = true;
		ifs.close();
		return;
	}

	//文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArrary = NULL;//初始化指针
		this->m_Fileempty = true;
		ifs.close();
		return;
	}

	//文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArrary = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();

	////测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArrary[i]->m_Id<<"\t"
	//		<< "姓名：" << this->m_EmpArrary[i]->m_name<<"\t"
	//		<< "职位：" << this->m_EmpArrary[i]->getDeptName()<<endl;
	//}

}

//统计文件中的人数
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读

	int id;
	string name;
	string did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数变量
		num++;
	}
	return num;
}


void WorkManager:: Show_Menu()
{
	cout << "********************************" << endl;
	cout << "***** 欢迎使用职工管理系统 *****" << endl;
	cout << "******* 0.退出管理程序  ********" << endl;
	cout << "******* 1.增加职工信息  ********" << endl;
	cout << "******* 2.显示职工信息  ********" << endl;
	cout << "******* 3.删除离职职工  ********" << endl;
	cout << "******* 4.修改职工信息  ********" << endl;
	cout << "******* 5.查找职工信息  ********" << endl;
	cout << "******* 6.按照编号排序  ********" << endl;
	cout << "******* 7.清空所有文档  ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//文件保存
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件--写文件

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArrary[i]->m_Id << " "
			<< this->m_EmpArrary[i]->m_name << " "
			<< this->m_EmpArrary[i]->getDeptName() << endl;

	}

	//关闭文件
	ofs.close();
}

void  WorkManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkManager::Add_Emp()
{
	while (true)
	{
		cout << "请输入要添加的人数：" << endl;
		int addNum = 0;//记录人数
		cin >> addNum;

		if (addNum > 0)
		{
			//添加
			//计算添加新空间大小
			int newSize = this->m_EmpNum+addNum ;//新空间大小=原来加新增

			//开辟新空间
			Worker** newSpace = new Worker * [newSize];

			//判断原先数据是否为空
			if (this->m_EmpArrary != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArrary[i];//复制原先的数据到新的数组
				}
			}

			//添加新的人员,批量添加
			for (int i = 0; i < addNum; i++)
			{
				int id;//职工编号
				string name;//职工姓名
				int dSelect;//部门选择

				bool temp = true;//循环标志，判断编号是否重复，并且再次输入

				while (temp == true)
				{
					cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
					cin >> id;
					
					if (this->IsExist(id)!=-1)
					{
						cout << "职工编号重复，请重新输入！" << endl;
					}
					else {
						temp = false;
					}
					
				}
				cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
				cin >> name;

				cout << "请选择该职工的岗位: " << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> dSelect;

				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, dSelect);
					break;
				case 2:
					worker = new Manager(id, name, dSelect);
					break;
				case 3:
					worker = new Boos(id, name, dSelect);
					break;
				default:
					cout << "输入有误" << endl;
					break;
				}
				//将创建的职工指针保存到数组
				newSpace[this->m_EmpNum + i] = worker;
			}
			//释放原有空间
			delete[] this->m_EmpArrary;
			//更改新空间的指向
			this->m_EmpArrary = newSpace;
			//更新新的职工人数
			this->m_EmpNum = newSize;

			//更新职工不为空的标志
			this->m_Fileempty = false;

			//提示添加成功
			cout << "成功添加" << addNum << "名新职工！" << endl;

			//保存数据到文件
			this->save();
			break;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}
		//按任意键后清屏，清屏
	}
	system("pause");
	system("cls");
}

//初始化员工
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string did;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == "普通职工")
		{
			worker = new Employee(id, name, 1);

		}
		else if (did == "经理")
		{
			worker = new Manager(id, name, 2);
		}
		else
		{
			worker = new Boos(id, name, 3);
		}
		this->m_EmpArrary[index] = worker;
		index++;
	}
	ifs.close();//关闭文件
}

//显示职工
void WorkManager::show_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用
			this->m_EmpArrary[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int WorkManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArrary[i]->m_Id)
		{
			index = i;

			break;
		}
	}

	return index;
}


//删除职工函数
void  WorkManager::Del_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除职工编号：" << endl;
		int id = 0;//记录输入的数字
		cin >> id;

		//判断职工是否存在
		int ret = this->IsExist(id);//接收位置，或-1不存在

		if (ret != -1)
		{
			//职工存在，并且删除ret位置的职工
			for (int i = ret; i < this->m_EmpNum-1; i++)//从当前找到的位置开始移动
			{
				//数据前移
				this->m_EmpArrary[i] = this->m_EmpArrary[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录人员个数
			//数据同步文件中
			this->save();

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，职工不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::Mod_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找编号的职工
			delete this->m_EmpArrary[ret];//释放那个位置的内存

			int newId = 0;
			string newName = " ";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请选择该职工的岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, newName, dSelect);
				break;
			case 2:
				worker = new Manager(id, newName, dSelect);
				break;
			case 3:
				worker = new Boos(id, newName, dSelect);
				break;
			default:
				cout << "输入有误" << endl;
				break;
			}

			this->m_EmpArrary[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件
			this->save();
		}
		else {

			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkManager::Find_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;//记录选择
		cin >> select;

		if (select == 1)//职工编号查找
		{
			int id = 0;
			cout << "请输入要查找的职工编号：" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功,编号为" << id << "的信息如下：" << endl;
				this->m_EmpArrary[ret]->showInfo();
			}
			else {
				cout << "职工不存在！" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找职工的姓名：" << endl;
			cin >> name;

			bool flag = false;//查找确认方式
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArrary[i]->m_name)
				{
					cout << "查找成功!\t" << name << "的信息如下：" << endl;
					flag = true;//修改标志
					this->m_EmpArrary[i]->showInfo();//展示信息
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;//利用查找确认来判断是否存在，更方便，比使用i方便便于修改
			}
		}
		else {
			cout << "输入有误！" << endl;
		}
		
	}
	system("pause");
	system("cls");
}

//排序--选择排序
void WorkManager::Sort_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum-1; i++)
		{
			int minOrMax = i;//声明最小值或最大值下标
			if (select == 1)//升序
			{
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArrary[minOrMax]->m_Id > this->m_EmpArrary[j]->m_Id)
					{
						minOrMax = j;//更新下标
					}
				}
			}
			else//降序
			{
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArrary[minOrMax]->m_Id <this->m_EmpArrary[j]->m_Id)
					{
						minOrMax = j;//更新下标
					}
				}
			}
			//将找到的最小值或最大值和当前的最大值或最小值进行交换
			if (i != minOrMax)
			{
				swap(this->m_EmpArrary[i], this->m_EmpArrary[minOrMax]);
			}
		}
		cout << "排序成功！排序后的结果为:" << endl;
		this->save();
		this->show_Emp();
	}
}
//清空文件
void  WorkManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArrary != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
					delete this->m_EmpArrary[i];
					this->m_EmpArrary[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArrary;
			this->m_EmpArrary = NULL;
			this->m_EmpNum = 0;
			this->m_Fileempty = true;
			
		}
		cout << "清空成功！" << endl;

	}
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArrary != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArrary[i] != NULL)
			{
				delete this->m_EmpArrary[i];
			}
		}
		delete[] this->m_EmpArrary;
		this->m_EmpArrary = NULL;
	}
	
}