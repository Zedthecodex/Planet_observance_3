#include <iostream>
#include "User_Auth.cpp"
using namespace std;

const char USER[] = "Accounts_All\\Accounts.dat";
class Menu_Backend:public User_auth
{
private : 
	//User user;
public : 
	char Username[20];
	char Password[20];
	char role[15];
	char race[15];
	double size;
	int Privilege;

	int login_Menu_Back()
	{
		system("cls");
		cout << "\t\t\t==========Login==========" << endl;
		cout << "Username : " << endl;
		cin >> Username;
		cout << "Password : " << endl;
		cin >> Password;
		cout << "Role : " << endl;
		cin >> role;
		cout << "Race : " << endl;
		cin >> race;

		User user1(Username, Password, role, race);
		User_auth user_auth1;
		user_auth1.checkVector(user1);
		/*cout << user_auth1.getPrivilege() << endl;
		setPrivilege(user_auth1.getPrivilege());*/

		return user_auth1.getPrivilege();
		
	}



	void addVector()
	{
		system("cls");
		cout << "\t\t\t==========Account Creation==========" << endl;
		cout << "Username : " << endl;
		cin >> Username;
		cout << "Password : " << endl;
		cin >> Password;
		cout << "Role : " << endl;
		cin >> role;
		cout << "Race : " << endl;
		cin >> race;

		User user(Username, Password, role, race);
		fstream fout;

		fout.open(("Accounts\\" + user.getUsername() + "_Acc.dat"), ios::out | ios::app | ios::binary);
		
		fout.write((char*)&user, sizeof(user));
		fout.close();

		fout.open(("Accounts_All\\Accounts.dat"), ios::out | ios::app | ios::binary);
		fout.write((char*)&user, sizeof(user));
		fout.close();

	}

	void viewVector()
	{
		system("cls");
		cout << "\t\t\t==========Display User ==========" << endl;
		User user;
		ifstream fin;
		fin.open((USER), ios::in | ios::binary);
		while (fin.read((char*)&user, sizeof(User)))
		{
			if (fin.eof())
			{
				break;
			}
			user.displayUser();
		}
	}

	void updateUser(string name)
	{
		system("cls");
		fstream fio;
		User user;

		fio.open(USER, ios::in | ios::out | ios::binary);
		if (!fio)
		{
			cerr << "File open failed";
			exit(1);
		}

		while (fio.read((char*)&user, sizeof(User)))
		{
			if (user.getUsername() == name)
			{
				user.getUser();
				int position = (-1) * static_cast<int>(sizeof(User));
				fio.seekp(position, ios::cur);
				fio.write((char*)&user, sizeof(User));
				cout << "User updated" << endl;
				break;
			}
		}
		fio.close();

		fio.open(("Accounts\\" + user.getUsername() + "_Acc.dat"), ios::in | ios::out | ios::binary);
		if (!fio)
		{
			cerr << "File open failed";
			exit(1);
		}

		while (fio.read((char*)&user, sizeof(User)))
		{
			if (user.getUsername() == name)
			{
				user.getUser();
				int position = (-1) * static_cast<int>(sizeof(User));
				fio.seekp(position, ios::cur);
				fio.write((char*)&user, sizeof(User));
				cout << "User updated" << endl;
				break;
			}
		}
		fio.close();
	}

	

	//int getPrivilege()
	//{
	//	return Privilege;
	//}
	//void setPrivilege(int privilege)
	//{
	//	this->Privilege = privilege;
	//}
};