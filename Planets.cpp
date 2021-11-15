#include <iostream>
#include "Galaxies.cpp"

using namespace std;

class Planets: public Galaxies
{
private : 
	char name_Planets[20];
	double age_Planets;
	double radius_Planets;
	double size_Planets;

public : 
	//Default Constructor
	Planets() : name_Planets("Unknown"), age_Planets(0.00), radius_Planets(0.00) {}

	//Overloaded Constructor
	Planets(char name[],double age,double radius)
	{
		memcpy(name_Planets, name, 20); 
		this->age_Planets = age;
		this->radius_Planets = radius;
		this->size_Planets = (4 / 3) * 3.14 * radius * radius;
	}

	double getSize() const
	{
		return size_Planets;
	}

	void setRadius(double radius)
	{
		this->radius_Planets = radius;
		this->size_Planets = (4 / 3) * 3.14 * radius * radius;
	}

};