#pragma once
#include <iostream>
#include "User_Auth.cpp"
#include "FileUtility.cpp"
using namespace std;


class Menu_Backend_User:public User_auth
{
private : 
	//User user;
	FileUtility FileIO;
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
		FileIO.OpenDatatoFile("Login\\temp.dat");
		FileIO.WriteDataToFile_User(user1);
		FileIO.CloseDatatoFile();

		return user_auth1.getPrivilege();
		
	}



	void addUser() //needed refactoring with addition of parameters instead
	{
		system("cls");
		cout << "\t\t==================================Account Creation============================================" << endl;
	
		User user;
		
		user.getUser();

		FileIO.OpenDatatoFile(USER);
		FileIO.WriteDataToFile_User(user);
		FileIO.CloseDatatoFile();

		FileIO.OpenDatatoFile("Accounts\\" + user.getUsername() + "_Acc.dat");
		FileIO.WriteDataToFile_User(user);
		FileIO.CloseDatatoFile();

		cout << "\t\t=============================================================================================" << endl;
	

	}

	void viewUser()
	{
		system("cls");
		cout << "\t\t==================================Display User=============================================" << endl;
		User user;
		

		FileIO.OpenDatafromFile(USER);
		//FileIO.ReadDataFromFile_User(user);
		FileIO.ReadDataFromFile_User_Basic(user);
		FileIO.CloseDataFromFile();

		cout << "\t\t===========================================================================================" << endl;
	
	}

	void viewUser_basic()
	{
		system("cls");
		cout << "\t\t==================================Display User=============================================" << endl;
		User user;


		FileIO.OpenDatafromFile(USER);
		FileIO.ReadDataFromFile_User_Basic(user);
		FileIO.CloseDataFromFile();

		cout << "\t\t===========================================================================================" << endl;
	}

	void updateUser(string name)
	{
		system("cls");
		cout << "\t\t==================================Update User=============================================" << endl;
		User user;
		

		FileIO.OpenDatatoFile("Accounts_All\\temp.dat");
		FileIO.OpenDatafromFile(USER);
		FileIO.UpdateUser(user, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		FileIO.RenameRemoveUser();

		cout << "\t\t===========================================================================================" << endl;
		

	}


	void searchUser(string name)
	{
		system("cls");
		cout << "\t\t==================================Search User=============================================" << endl;
		User user;
		


		FileIO.OpenDatafromFile(USER);
		FileIO.SearchUser(user, name);
		FileIO.CloseDataFromFile();

		cout << "\t\t==========================================================================================" << endl;
	
	}

	void deleteUser(string name)
	{
		system("cls");
		cout << "\t\t==================================Delete User=============================================" << endl;
		User user;
		

		FileIO.OpenDatatoFile("Accounts_All\\temp.dat");
		FileIO.OpenDatafromFile(USER);
		FileIO.DeleteUser(user, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		FileIO.RenameRemoveUser();

		cout << "\t\t==========================================================================================" << endl;
		
	}

	void ModifyProfile(string name)
	{
		User user;

		FileIO.OpenDatatoFile("Login\\temp.dat");
		FileIO.OpenDatafromFile(USER);
		FileIO.UpdateUser(user, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		
	}

	//void RenameUser()
	//{
	//	int removeStatus = 0;
	//	if (remove(USER) != 0)
	//	{
	//		//cerr << "Failed to remove the file! " << endl;

	//	}
	//	removeStatus = rename("temp.dat", USER);
	//	if (removeStatus == 0)
	//	{
	//		cout << "Deletion Succeeded" << endl;
	//	}
	//	else
	//	{
	//		cout << "Deletion Failed " << endl;
	//	}

	//}

	

	//int getPrivilege()
	//{
	//	return Privilege;
	//}
	//void setPrivilege(int privilege)
	//{
	//	this->Privilege = privilege;
	//}
};