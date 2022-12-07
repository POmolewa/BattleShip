#include <iostream>
#include <SFML/Graphics.hpp>
#include "Battleship.h"
#include "Count.h"



using namespace std;
using namespace sf;

vehicle::vehicle()
{
	Small1.loadFromFile("Textures/small.png");
}

void vehicle::score1(Count x)
{
	x.add();
}

void vehicle::SetVehicle(Vector2f pos)
{
	Veh.setTexture(Small1);
	Veh.setPosition(pos);
}

Sprite vehicle::GetVehicle()
{
	return Veh;
}

bool vehicle::GetStatus()
{
	return Is_hit;
}

BigShip::BigShip()
{
	Small2.loadFromFile("Textures/med.png");
}
void BigShip::SetVehicle(Vector2f pos)
{
	BigBoat.setTexture(Small2);
	BigBoat.setPosition(pos);
}
void BigShip::score2(Count x)
{
	x.add2();
}
Sprite BigShip::GetVehicle1()
{
	return BigBoat;
}

Small::Small()
{
	Small3.loadFromFile("Textures/Bigg.png");
}
void Small::SetVehicle(Vector2f pos)
{
	Smalls.setTexture(Small3);
	Smalls.setPosition(pos);
}
void Small::score3(Count x)
{
	x.add3();
}
Sprite Small::GetVehicle2()
{
	return Smalls;
}