#include <iostream>
#include "Galaxies.cpp"
#include "User_Auth.cpp"
#include <vector>
#include "Planets.cpp"
#include "Menu.cpp"
using namespace std;

void saveVector(User& user);


int main()
{
	/*char Username[20];
	char Password[20];
	char role[15];
	char race[15];
	double size;
	cout << " Please Enter the Username : " << endl;
	cin >> Username;
	cout << " Please Enter the Password : " << endl;
	cin >> Password;
	cout << " Please Enter the Role : " << endl;
	cin >> role;
	cout << " Please Enter the race : " << endl;
	cin >> race;*/

	/*User user1(Username, Password, role, race);
	User_auth user_auth;*/
	//saveVector(user1);
	
	/*user_auth.checkVector(user1);

	Galaxies Zeroth(Username, 5.55, 100000);*/
	//cout << Zeroth.getName() << endl;

	//Planets Earth;

	//cout << "Please enter the name of the Planet : " << endl;
	//cin >> Username;
	//cin >> size;
	//Earth.setRadius(size);
	//Earth.setName(Username);

	//cout << Earth.getName() << endl;
	//cout << fixed << Earth.getSize() << endl;
	Menu Menu;
	Menu.login_Menu();

	


}



void saveVector(User& user)
{
	fstream fout;
	
	fout.open(("Accounts\\" + user.getUsername() + "_Acc.dat"), ios::out | ios::app | ios::binary);
	//fout.open(("Accounts.dat"), ios::out | ios::app | ios::binary);
	fout.write((char*)&user, sizeof(user));
	fout.close();

}

