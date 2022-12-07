#include <iostream>
#include <SFML/Graphics.hpp>
#include "BattleField.h"
#include "CreateShip.h"
#include "Tial.h"
#include <vector>

using namespace std;
using namespace sf;

vehicle* CreateShip(vector<Vector2f> coords)
{
	vehicle* veh = new vehicle[3];
	//srand(time(0));

	for (int i = 0; i < 3; i++)
	{
		veh[i].SetVehicle(coords.at(rand() % 60));
	}
	return veh;
}

BigShip* CreateShip2(vector<Vector2f> coords)
{
	BigShip* veh2 = new BigShip[2];
	//srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		veh2[i].SetVehicle(coords.at(rand() % 60));
	}
	return veh2;
}

Small* CreateShip3(vector<Vector2f> coords)
{
	Small* veh3 = new Small[1];
	//srand(time(0));

	for (int i = 0; i < 1; i++)
	{
		veh3[i].SetVehicle(coords.at(rand() % 60));
	}
	return veh3;
}

vehicle* PCreateShip(vector<Vector2f> coords)
{
	vehicle* veh = new vehicle[3];
	//srand(time(0));

	for (int i = 0; i < 3; i++)
	{
		veh[i].SetVehicle(coords.at(rand() % 60));
	}
	return veh;
}

BigShip* PCreateShip2(vector<Vector2f> coords)
{
	BigShip* veh2 = new BigShip[2];
	//srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		veh2[i].SetVehicle(coords.at(rand() % 60));
	}
	return veh2;
}

Small* PCreateShip3(vector<Vector2f> coords)
{
	Small* veh3 = new Small[1];
	//srand(time(0));

	for (int i = 0; i < 1; i++)
	{
		veh3[i].SetVehicle(coords.at(rand() % 60));
	}
	return veh3;
}