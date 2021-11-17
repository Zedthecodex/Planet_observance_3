#include <iostream>
#include <vector>
#include "Planets.cpp"
#include "Stations.cpp"
#include <fstream>

const char Planets_All[] = "Planets_All\\Planets.dat";

class Menu_Backend_Planets : public Planets, Stations
{
private:



public: 
	char name[20];
	double age;
	double radius;
	double size;

	void viewPlanets()
	{
		system("cls");
		cout << "\t\t\t=========Displaying Planets==========" << endl;

		Planets planet;

		ifstream fin;
		fin.open((Planets_All), ios::in | ios::binary);

		while (fin.read((char*)&planet, sizeof(Planets))) {

			if (fin.eof())
			{
				break;
			}
			planet.displayPlanets();
		}

	}


	void AddPlanet()
	{
		system("cls");
		cout << "\t\t\t=========Planets Creation==========" << endl;
		cout << "Name of Planet :" << endl;
		cin >> name;
		cout << "age of Planet : " << endl;
		cin >> age;
		cout << "radius of Planet :" << endl;
		cin >> radius;

		//size = (4 / 3) * 3.14 * radius * radius;

		Planets planet(name, age, radius);
		fstream fout;

		fout.open(Planets_All, ios::out | ios::app | ios::binary);
		fout.write((char*)&planet, sizeof(Planets));
		fout.close();

		fout.open(("Planets_All\\Planets\\" + planet.getName() + "_planet.dat"), ios::out | ios::app | ios::binary);
		fout.write((char*)&planet, sizeof(Planets));
		fout.close();

	}

	void updatePlanet(string name)
	{

		system("cls");
		fstream fio;
		Planets planet;

		fio.open(Planets_All, ios::in | ios::out | ios::binary);
		if (!fio)
		{
			cerr << "File failed to open";
			exit(1);
		}
		while (fio.read((char*)&planet, sizeof(Planets)))
		{
			if (planet.getName() == name)
			{
				planet.getPlanet();
				int position = (-1) * static_cast<int>(sizeof(Planets));
				fio.seekp(position, ios::cur);
				fio.write((char*)&planet, sizeof(Planets));
				cout << "Planet updated" << endl;
				break;
			}
		}
		fio.close();

		fio.open(("Planets_All\\Planets\\" + planet.getName() + "_planet.dat"), ios::out | ios::app | ios::binary);
		if (!fio)
		{
			cerr << "File failed to open";
			exit(1);
		}
		while (fio.read((char*)&planet, sizeof(Planets)))
		{
			if (planet.getName() == name)
			{
				planet.getPlanet();
				int position = (-1) * static_cast<int>(sizeof(Planets));
				fio.seekp(position, ios::cur);
				fio.write((char*)&planet, sizeof(Planets));
				cout << "Planet updated" << endl;
				break;
			}
		}

	}

	void searchPlanet()
	{

	}
};