#include <iostream>
#include <cctype>
//#include ""
using namespace std;

#include <string>

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};

#define  MAX 1000

struct Addressbooks
{
	struct Person personArrar[MAX];
	int m_size;
};




void showMenu()
{
	cout << "******************************"<<endl ;
	cout << "*******  1�������ϵ��  *******"<<endl ;
	cout << "*******  2����ʾ��ϵ��  *******"<<endl ;
	cout << "*******  3��ɾ����ϵ��  *******"<<endl ;
	cout << "*******  4��������ϵ��  *******"<<endl ;
	cout << "*******  5���޸���ϵ��  *******"<<endl ;
	cout << "*******  6�������ϵ��  *******"<<endl ;
	cout << "*******  0���˳�ͨѶ¼  *******"<<endl ;
	cout << "******************************"<<endl ;

}

void addPerson(Addressbooks *abs)
{
	if (abs->m_size ==MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArrar[abs->m_size].m_Name = name;
		
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArrar[abs->m_size].m_Sex = sex;
				break;
			}
			 
			cout << "������������������" << endl;
				  
		}
		
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArrar[abs->m_size].m_Age = age;
				 
		cout << "������绰" << endl;
		string phone = " ";
		cin >> phone;
		abs->personArrar[abs->m_size].m_Phone = phone;

		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArrar[abs->m_size].m_Addr = address;
		
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");

	}
		
	 
}

int isExist(Addressbooks *abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArrar[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void ShowPerson(Addressbooks *abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
		 
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArrar[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArrar[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArrar[i].m_Age << "\t";
			cout << "�绰��" << abs->personArrar[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArrar[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void  deletePerson(Addressbooks *abs)
{
	cout << "������Ҫɾ����������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret)
	{
		for (int i = ret; i < abs->m_size;i++)
		{
			abs->personArrar[i] = abs->personArrar[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
		
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");


}

void findPerson(Addressbooks *abs)
{
	cout << "������Ҫ���ҵ�������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret)
	{
		cout << "������" << abs->personArrar[ret].m_Name << "\t";
		cout << "�Ա�" <<(abs->personArrar[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArrar[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArrar[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArrar[ret].m_Addr << endl;

		


	}										 
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs)
{
	cout << "������Ҫ�޸ĵ�������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret)
	{
		cout << "������Ҫ�޸ĵ�������" << endl;
		string name;
		cin >> name;
		abs->personArrar[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArrar[ret].m_Sex = sex;
				break;
			}

			cout << "������������������" << endl;

		}

		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArrar[ret].m_Age = age;

		cout << "������绰" << endl;
		string phone = " ";
		cin >> phone;
		abs->personArrar[ret].m_Phone = phone;

		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArrar[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
    else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(Addressbooks *abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


int main()
{
	Addressbooks abs;
	abs.m_size = 0;

	int select = 0; 
	
	while (true)
	{
		showMenu();
		 
		cin >> select;
// 		if (NULL ==isdigit(select))
// 		{
// 			cin.clear();
// 			cin.ignore();
// 			cin.sync();
// 			system("cls");
// 			continue;
// 		}
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			ShowPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
		  break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;

		default:
			system("cls");
			break;
		}
	}
	
	
	 
	system("pause");
	return 0;
}