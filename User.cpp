#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef USER_CPP
#define USER_CPP



class User {
private : 
	char User_name[20];
	char User_pass[20];
	char User_role[15];
	char User_race[15];

public: 
	//Default Constructor
	User() : User_name("Unknown"), User_pass("Unknown"), User_role("Unknown"), User_race("Unknown") {}

	//Overloaded Constructor

	User(char username[], char password[], char role[], char race[])
	{
		memcpy(this->User_name, username, 20);
		memcpy(this->User_pass, password, 20);
		memcpy(this->User_role, role, 15);
		memcpy(this->User_race, race, 15);

	}
	
	//Accessor Functions
	string getUsername() const
	{
		return User_name;
	}

	string getPassword() const
	{
		return User_pass;
	}

	string getRole() const
	{
		return User_role;
	}

	string getRace() const
	{
		return User_race;
	}

	void setUsername(char username[])
	{
		memcpy(this->User_name, username, 20);
	}

	void setPassword(char password[])
	{
		memcpy(this->User_pass, password, 20);
	}

	void setRole(char role[])
	{
		memcpy(this->User_role, role, 15);
	}

	void setRace(char race[])
	{
		memcpy(this->User_race, race, 15);
	}
};



#endif // !USER_CPP