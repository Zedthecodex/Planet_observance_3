#include <iostream>
#include "User_Auth.cpp"
using namespace std;


class Menu_Backend:public User_auth
{
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

	//int getPrivilege()
	//{
	//	return Privilege;
	//}
	//void setPrivilege(int privilege)
	//{
	//	this->Privilege = privilege;
	//}
};