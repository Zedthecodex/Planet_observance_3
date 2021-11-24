#include <iostream>
#include <vector>
#include "Menu_Backend_User.cpp"
#include "Menu_Backend_Planets.cpp"
using namespace std;

class Menu:public Menu_Backend_User, Menu_Backend_Planets
{
private:
	int Choice = 0;
	int Privilege = 0;
	char username[20];
public : 
	

	void login_Menu()
	{
		system("cls");
		cout << "\t\t\t==========Login==========" << endl;
		cout << "\n\n" << "\t\t\t1).Login " << endl;
		cout << "\t\t\t2).Exit " << endl;
		cout << "\n\n\t\t\t=========================" << endl;
		cin >> Choice;
		switch(Choice)
		{
		case 1: 
			
			Privilege = login_Menu_Back();  // This is used to check for admin or user privileges
			//cout << "You are in!" << endl;
			main_Menu(Privilege);

			break;

		case 2:
			cout << "Exiting....." << endl;
			exit(0);
			break;

		default : 
			system("cls");
			cout << "Please choose between the choices give" << endl;
			login_Menu();
			break;
		}

	}

	void main_Menu(int &Privilege)
	{
		cout << "You are now in the menu" << endl;
		if (Privilege == 2)
		{
			cout << "This is a classifier privileged account " << endl;
			main_Menu_Admin();
		}
		else if (Privilege == 1)
		{
			cout << "This is a basic User account" << endl;
		}
	}

	void main_Menu_Admin()
	{
		system("cls");
		cout << "\t\t\t==========Classifier Account==========" << endl;
		cout << "\n\n\t\t\t 1).Manage Users" << endl;
		cout << "\t\t\t 2).Manage Planets" << endl;
		cout << "\t\t\t 3).Modify Profile" << endl;
		cout << "\t\t\t 4).Sign Out and Exit" << endl;
		cout << "\n\n\t\t\t======================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			menu_User_Manager();
			break;

		case 2: 
			menu_Planets_Manager();
			break;

		case 3: 

			break;

		case 4 : 
			
			break;
		}

	}

	void menu_User_Manager()
	{
		system("cls");
		cout << "\t\t\t==========User Management==========" << endl;
		cout << "\n\n\t\t\t 1).View Users" << endl;
		cout << "\t\t\t 2).Add Users" << endl;
		cout << "\t\t\t 3).Update Users" << endl;
		cout << "\t\t\t 4).Search User" << endl;
		cout << "\t\t\t 5).Delete User" << endl;
		cout << "\t\t\t 6).Go back " << endl;
		cout << "\n\n\t\t\t===================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			
			viewVector();
			system("pause");
			menu_User_Manager();
			break;

		case 2: 
			addVector();
			system("pause");
			menu_User_Manager();
			break;

		case 3:
			viewVector();
			cout << "Enter username to update : " << endl;
			cin >> username;
			updateUser(username);
			system("pause");
			menu_User_Manager();
			break;

		case 4: 
			system("cls");
			cout << "Please enter a username to search : " << endl;
			cin >> username;
			searchUser(username);
			system("pause");
			menu_User_Manager();
			break;
			
		case 5:
			viewVector();
			cout << "Enter username to delete : " << endl;
			cin >> username;
			deleteUser(username);
			system("pause");
			menu_User_Manager();
			break;

		case 6 :

			main_Menu_Admin();
			break;

		}

		
	}

	void menu_Planets_Manager()
	{
		system("cls");
		cout << "\t\t\t==========Planets Management==========" << endl;
		cout << "\n\n\t\t\t 1).View Planets" << endl;
		cout << "\t\t\t 2).Add Planets" << endl;
		cout << "\t\t\t 3).Update Planet" << endl;
		cout << "\t\t\t 4).Search Planet" << endl;
		cout << "\t\t\t 5).Delete Planet" << endl;
		cout << "\t\t\t 6).Go back " << endl;
		cout << "\n\n\t\t\t===================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			viewPlanets();
			system("pause");
			menu_Planets_Manager();
			break;
		case 2:
			AddPlanet();
			system("pause");
			menu_Planets_Manager();
			break;
		case 3:
			viewPlanets();
			cout << "Please Enter a Planet's Name to update: " << endl;
			cin >> name;
			updatePlanet(name);
			system("pause");
			menu_Planets_Manager();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			main_Menu_Admin();
			break;
		}
	}





};