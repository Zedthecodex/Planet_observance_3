#pragma once

#include <iostream>
#include "../Planet_observance_3/Menu/Menu_Backend_User.cpp"
using namespace std;


class Menu_User :public Menu_Backend_User
{
private:
	char username[20];

public:

	void Display_Classifier()
	{
		system("cls");
		

		viewUser();

		system("pause");;
	}

	void Add_Classifier()
	{
		

		addUser();

		system("pause");
	}

	void Update_Classifier()
	{
		system("cls");
		
		viewUser();

		cout << "Enter username to update : " << endl;
		cin >> username;

		updateUser(username);

		system("pause");
	}

	void Search_Classifier()
	{
		system("cls");

		cout << "Please enter a username to search : " << endl;
		cin >> username;

		searchUser(username);

		system("pause");
	}

	void Modify_Profile()
	{
		system("cls");

		cout << "Please enter your username : " << endl;
		cin >> username;

		ModifyProfile(username);

		system("pause");
	}

	void Delete_Clasifier()
	{
		system("cls");
		

		viewUser();

		cout << "Enter username to delete : " << endl;
		cin >> username;

		deleteUser(username);

		system("pause");
	}

	void Display_Navigator()
	{
		system("cls");

		viewUser_basic();

		system("pause");
	}

	

	
};