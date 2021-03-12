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
	cout << "*******  1、添加联系人  *******"<<endl ;
	cout << "*******  2、显示联系人  *******"<<endl ;
	cout << "*******  3、删除联系人  *******"<<endl ;
	cout << "*******  4、查找联系人  *******"<<endl ;
	cout << "*******  5、修改联系人  *******"<<endl ;
	cout << "*******  6、清口联系人  *******"<<endl ;
	cout << "*******  0、退出通讯录  *******"<<endl ;
	cout << "******************************"<<endl ;

}

void addPerson(Addressbooks *abs)
{
	if (abs->m_size ==MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArrar[abs->m_size].m_Name = name;
		
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArrar[abs->m_size].m_Sex = sex;
				break;
			}
			 
			cout << "输入有误，请重新输入" << endl;
				  
		}
		
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArrar[abs->m_size].m_Age = age;
				 
		cout << "请输入电话" << endl;
		string phone = " ";
		cin >> phone;
		abs->personArrar[abs->m_size].m_Phone = phone;

		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArrar[abs->m_size].m_Addr = address;
		
		abs->m_size++;
		cout << "添加成功" << endl;
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
		cout << "通讯录为空" << endl;
		 
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArrar[i].m_Name << "\t";
			cout << "性别：" << (abs->personArrar[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArrar[i].m_Age << "\t";
			cout << "电话：" << abs->personArrar[i].m_Phone << "\t";
			cout << "住址：" << abs->personArrar[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void  deletePerson(Addressbooks *abs)
{
	cout << "请输入要删除的姓名：" << endl;
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
		cout << "删除成功" << endl;
		
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");


}

void findPerson(Addressbooks *abs)
{
	cout << "请输入要查找的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret)
	{
		cout << "姓名：" << abs->personArrar[ret].m_Name << "\t";
		cout << "性别：" <<(abs->personArrar[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArrar[ret].m_Age << "\t";
		cout << "电话：" << abs->personArrar[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArrar[ret].m_Addr << endl;

		


	}										 
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs)
{
	cout << "请输入要修改的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret)
	{
		cout << "请输入要修改的姓名：" << endl;
		string name;
		cin >> name;
		abs->personArrar[ret].m_Name = name;

		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArrar[ret].m_Sex = sex;
				break;
			}

			cout << "输入有误，请重新输入" << endl;

		}

		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArrar[ret].m_Age = age;

		cout << "请输入电话" << endl;
		string phone = " ";
		cin >> phone;
		abs->personArrar[ret].m_Phone = phone;

		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArrar[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
    else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(Addressbooks *abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
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
			cout << "欢迎下次使用" << endl;
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