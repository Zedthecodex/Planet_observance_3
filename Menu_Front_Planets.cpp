#pragma once
#include <iostream>
#include "../Planet_observance_3/Menu/Menu_Backend_Planets.cpp"
using namespace std;

class Menu_Planets: public Menu_Backend_Planets
{
private:
	char Planet_name[20];

public:

	void Add_Planet()
	{
		system("cls");

		AddPlanet();

		system("pause");
	}

	void Display_planet()
	{
		system("cls");

		viewPlanets();

		system("pause");

	}

	void Update_Planet()
	{
		system("cls");
		
		viewPlanets();

		cout << "Please enter the name of the Planet needed Updating : ";
		cin >> Planet_name;
		updatePlanet(Planet_name);

		system("pause");
	}

	void Search_Planet()
	{
		system("cls");

		cout << "Please enter the name of Planet you are trying to find : ";
		cin >> Planet_name;
		SearchPlanet(Planet_name);

		system("pause");
	}

	void Delete_Planet()
	{
		system("cls");

		viewPlanets();

		cout << "Please enter the name of the Planet you want deleted : ";
		cin >> Planet_name;
		DeletePlanet(Planet_name);

		system("pause");
	}
};