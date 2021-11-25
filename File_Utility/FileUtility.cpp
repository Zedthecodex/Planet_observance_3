#pragma once
#include <fstream>
#include <iostream>

#include "../Planet_observance_3/Accounts_All/User.cpp"
#include "../Planet_observance_3/Planets_All/Planets.cpp"
#include "../Planet_observance_3/Stations/Stations.cpp"

using namespace std;
const char USER[] = "Accounts_All\\Accounts.dat";
const char PLANET[] = "Planets_All\\Planets.dat";


class FileUtility {

private:
	ofstream fout;
	ifstream fin;

	int count = 0;

public:

	void OpenDatatoLogin(string filename)
	{
		fout.open(filename, ios::out | ios::app | ios::binary | ios::trunc);
		if (!fout)
		{
			cerr << "File failed to Open!" << endl;
			system("pause");
		}
	}
	void OpenDatatoFile(string filename) //Opens the file for additions or changes
	{
		fout.open(filename, ios::out | ios::app | ios::binary);
		if (!fout)
		{
			cerr << "File Failed to Open!" << endl;
			system("pause");

		}

	}

	void OpenDatafromFile(string filename) // Opening file for either extraction or reading
	{
		fin.open(filename, ios::in | ios::out | ios::binary);
		if (!fout)
		{
			cerr << "File Failed to Open!" << endl;
			system("pause");
		}
		fin.seekg(0, ios::beg);
	}

	void WriteDataToFile_User(User user) //Writing data to a specific file that was given from another method 
	{
		fout.write(reinterpret_cast<char*>(&user), sizeof(User)); // for saving to void WriteDataToFile
	}

	void ReadDataFromFile_User(User user) // This extracts the specific information of each user
	{
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&user), sizeof(User));
			if (fin.eof()) { break; }
			user.displayUser();
			cout << endl;
		}
	

	}
	
	void ReadDataFromFile_User_Basic(User user)
	{
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&user), sizeof(User));
			if (fin.eof()) { break; }
			user.displayUser_Basic();
			cout << endl;
		}
	}


	void UpdateUser(User user, string username)
	{
		count = 0;
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&user), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (user.getUsername() != username)
			{
				WriteDataToFile_User(user);
			}
			else
			{
				user.getUser();
				WriteDataToFile_User(user);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Account not found" << endl;

		}
	}

	void DeleteUser(User user, string username)
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&user), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (user.getUsername() != username)
			{
				WriteDataToFile_User(user);
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}
		else
		{
			cout << "\t\t\t User Deleted " << endl;
		}

	}

	void SearchUser(User user,string username)
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&user), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (user.getUsername() == username)
			{
				user.displayUser();
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}
		
	}

	void WriteDataToFile_Planet(Planets planet)
	{
		fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));

	}

	void UpdatePlanet(Planets planet, string planet_name)
	{
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(Planets)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() != planet_name)
			{
				fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));

			}
			else
			{
				planet.getPlanet();
				fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));
			}
		}
	}

	void ReadDataFromFile_Planet(Planets planet)
	{
		count = 0;
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&planet), sizeof(Planets));
			if (fin.eof()) { break; }
			planet.displayPlanets();
			count++;
		}
		
	}

	void DeletePlanet(Planets planet, string planet_name)
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() != planet_name)
			{
				WriteDataToFile_Planet(planet);
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}
		else
		{
			cout << "\t\t\t User Deleted " << endl;
		}
		/*fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(Planets)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() != planet_name)
			{
				fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));
			}
		}*/
	}

	void SearchPlanet(Planets planet, string planet_name)
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() == planet_name)
			{
				planet.displayPlanets();
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}

	}

	void RenameRemoveUser()
	{
		int res = 0;
		if (remove(USER) != 0)
		{
			cout << "Failed to remove file!" << endl;
		}
		
		res = rename("Accounts_All\\temp.dat", USER);
		if (res == 0)
		{
			cout << "File Updated!" << endl;
		}
		else
		{
			cout << "Failed to rename file" << endl;
		}
	}

	void RenameRemovePlanet()
	{
		int removeStatus = 0;
		if (remove(PLANET) == 0)
		{
			//cout << "Failed to remove!" << endl;
			cout << "Success remove!" << endl;
		}
		else
		{
			cout << "Failed to remove!!!" << endl;
		}
		
		int renameStatus;
		renameStatus = rename("Planets_All\\temp.dat", PLANET);
		if (renameStatus == 0)
		{
			cout << "Success renamed!" << endl;
		}
		else
		{
			cout << "Failed to rename!" << endl;
		}
	}

	void CloseDatatoFile()
	{
		fout.close();
	}

	void CloseDataFromFile()
	{
		fin.close();
	}
};