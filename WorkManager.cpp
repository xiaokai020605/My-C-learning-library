#include"WorkManager.h"


WorkManager::WorkManager()
{
	//�ļ������ڵ�ʱ���ʼ��

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout<<"�ļ�������"<<endl;
		//��ʼ������
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArrary = NULL;//��ʼ��ָ��
		this->m_Fileempty = true;
		ifs.close();
		return;
	}

	//�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArrary = NULL;//��ʼ��ָ��
		this->m_Fileempty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArrary = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArrary[i]->m_Id<<"\t"
	//		<< "������" << this->m_EmpArrary[i]->m_name<<"\t"
	//		<< "ְλ��" << this->m_EmpArrary[i]->getDeptName()<<endl;
	//}

}

//ͳ���ļ��е�����
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��

	int id;
	string name;
	string did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//ͳ����������
		num++;
	}
	return num;
}


void WorkManager:: Show_Menu()
{
	cout << "********************************" << endl;
	cout << "***** ��ӭʹ��ְ������ϵͳ *****" << endl;
	cout << "******* 0.�˳��������  ********" << endl;
	cout << "******* 1.����ְ����Ϣ  ********" << endl;
	cout << "******* 2.��ʾְ����Ϣ  ********" << endl;
	cout << "******* 3.ɾ����ְְ��  ********" << endl;
	cout << "******* 4.�޸�ְ����Ϣ  ********" << endl;
	cout << "******* 5.����ְ����Ϣ  ********" << endl;
	cout << "******* 6.���ձ������  ********" << endl;
	cout << "******* 7.��������ĵ�  ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//�ļ�����
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�--д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArrary[i]->m_Id << " "
			<< this->m_EmpArrary[i]->m_name << " "
			<< this->m_EmpArrary[i]->getDeptName() << endl;

	}

	//�ر��ļ�
	ofs.close();
}

void  WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkManager::Add_Emp()
{
	while (true)
	{
		cout << "������Ҫ��ӵ�������" << endl;
		int addNum = 0;//��¼����
		cin >> addNum;

		if (addNum > 0)
		{
			//���
			//��������¿ռ��С
			int newSize = this->m_EmpNum+addNum ;//�¿ռ��С=ԭ��������

			//�����¿ռ�
			Worker** newSpace = new Worker * [newSize];

			//�ж�ԭ�������Ƿ�Ϊ��
			if (this->m_EmpArrary != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArrary[i];//����ԭ�ȵ����ݵ��µ�����
				}
			}

			//����µ���Ա,�������
			for (int i = 0; i < addNum; i++)
			{
				int id;//ְ�����
				string name;//ְ������
				int dSelect;//����ѡ��

				bool temp = true;//ѭ����־���жϱ���Ƿ��ظ��������ٴ�����

				while (temp == true)
				{
					cout << "�������" << i + 1 << "����ְ�����:" << endl;
					cin >> id;
					
					if (this->IsExist(id)!=-1)
					{
						cout << "ְ������ظ������������룡" << endl;
					}
					else {
						temp = false;
					}
					
				}
				cout << "�������" << i + 1 << "����ְ������:" << endl;
				cin >> name;

				cout << "��ѡ���ְ���ĸ�λ: " << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
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
					cout << "��������" << endl;
					break;
				}
				//��������ְ��ָ�뱣�浽����
				newSpace[this->m_EmpNum + i] = worker;
			}
			//�ͷ�ԭ�пռ�
			delete[] this->m_EmpArrary;
			//�����¿ռ��ָ��
			this->m_EmpArrary = newSpace;
			//�����µ�ְ������
			this->m_EmpNum = newSize;

			//����ְ����Ϊ�յı�־
			this->m_Fileempty = false;

			//��ʾ��ӳɹ�
			cout << "�ɹ����" << addNum << "����ְ����" << endl;

			//�������ݵ��ļ�
			this->save();
			break;
		}
		else {
			cout << "�����������������" << endl;
		}
		//�������������������
	}
	system("pause");
	system("cls");
}

//��ʼ��Ա��
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
		if (did == "��ְͨ��")
		{
			worker = new Employee(id, name, 1);

		}
		else if (did == "����")
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
	ifs.close();//�ر��ļ�
}

//��ʾְ��
void WorkManager::show_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬����
			this->m_EmpArrary[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
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


//ɾ��ְ������
void  WorkManager::Del_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫɾ��ְ����ţ�" << endl;
		int id = 0;//��¼���������
		cin >> id;

		//�ж�ְ���Ƿ����
		int ret = this->IsExist(id);//����λ�ã���-1������

		if (ret != -1)
		{
			//ְ�����ڣ�����ɾ��retλ�õ�ְ��
			for (int i = ret; i < this->m_EmpNum-1; i++)//�ӵ�ǰ�ҵ���λ�ÿ�ʼ�ƶ�
			{
				//����ǰ��
				this->m_EmpArrary[i] = this->m_EmpArrary[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա����
			//����ͬ���ļ���
			this->save();

			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�ְ�������ڣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::Mod_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ұ�ŵ�ְ��
			delete this->m_EmpArrary[ret];//�ͷ��Ǹ�λ�õ��ڴ�

			int newId = 0;
			string newName = " ";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ����" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "��ѡ���ְ���ĸ�λ: " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
				cout << "��������" << endl;
				break;
			}

			this->m_EmpArrary[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ�
			this->save();
		}
		else {

			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkManager::Find_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;//��¼ѡ��
		cin >> select;

		if (select == 1)//ְ����Ų���
		{
			int id = 0;
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�,���Ϊ" << id << "����Ϣ���£�" << endl;
				this->m_EmpArrary[ret]->showInfo();
			}
			else {
				cout << "ְ�������ڣ�" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ����ְ����������" << endl;
			cin >> name;

			bool flag = false;//����ȷ�Ϸ�ʽ
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArrary[i]->m_name)
				{
					cout << "���ҳɹ�!\t" << name << "����Ϣ���£�" << endl;
					flag = true;//�޸ı�־
					this->m_EmpArrary[i]->showInfo();//չʾ��Ϣ
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;//���ò���ȷ�����ж��Ƿ���ڣ������㣬��ʹ��i��������޸�
			}
		}
		else {
			cout << "��������" << endl;
		}
		
	}
	system("pause");
	system("cls");
}

//����--ѡ������
void WorkManager::Sort_Emp()
{
	if (this->m_Fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���Ž�������" << endl;
		cout << "2.��ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum-1; i++)
		{
			int minOrMax = i;//������Сֵ�����ֵ�±�
			if (select == 1)//����
			{
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArrary[minOrMax]->m_Id > this->m_EmpArrary[j]->m_Id)
					{
						minOrMax = j;//�����±�
					}
				}
			}
			else//����
			{
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArrary[minOrMax]->m_Id <this->m_EmpArrary[j]->m_Id)
					{
						minOrMax = j;//�����±�
					}
				}
			}
			//���ҵ�����Сֵ�����ֵ�͵�ǰ�����ֵ����Сֵ���н���
			if (i != minOrMax)
			{
				swap(this->m_EmpArrary[i], this->m_EmpArrary[minOrMax]);
			}
		}
		cout << "����ɹ��������Ľ��Ϊ:" << endl;
		this->save();
		this->show_Emp();
	}
}
//����ļ�
void  WorkManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//���
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArrary != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
					delete this->m_EmpArrary[i];
					this->m_EmpArrary[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArrary;
			this->m_EmpArrary = NULL;
			this->m_EmpNum = 0;
			this->m_Fileempty = true;
			
		}
		cout << "��ճɹ���" << endl;

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