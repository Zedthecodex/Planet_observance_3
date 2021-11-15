#pragma once

#include <iostream>
#include "User.cpp"
#include <fstream>



#ifndef USER_AUTH_CPP
#define USER_AUTH_CPP



using namespace std;

class User_auth {
private :
	User user;
	int Privilege = 0;


public : 
	void checkVector(User& user_login)
	{
		User user;
		ofstream fout;

		ifstream fin;

	/*	fout.open(("Accounts\\" + user_login.getUsername() + "_Acc.dat"), ios::out | ios::app | ios::binary);
		fout.write("");
		fout.close();*/

		fin.open(("Accounts\\" + user_login.getUsername() + "_Acc.dat"), ios::in | ios::binary);
		if (!fin)
		{
			cerr << "That Username does not exist" << endl;
			exit(1);
		}
		
		while (fin.read((char*)&user, sizeof(user)))
		{
			//cout << user.getUsername() << endl;
			
			if (user_login.getPassword() == user.getPassword())
			{
				if (user.getRole() == "Classifier")
				{
					setPrivilege(2);
						//cout << "You are in!" << endl;
					cout << "You are in as a classifier " << endl;
				
				}
				else
				{
					setPrivilege(1);
					cout << "You are in as a basic User" << endl;
				}
			}
			else
			{
					cout << "Password doesn't match the preset. Please try again" << endl;
			}
			}
		
	}
	int getPrivilege()
	{
		return Privilege;
	}

	void setPrivilege(int privilege)
	{
		this->Privilege = privilege;
	}
	
};






#endif // !USER_AUTH_CPP