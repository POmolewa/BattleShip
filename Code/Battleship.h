#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include<time.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "Count.h"

using namespace std;
using namespace sf;

class vehicle
{
public:
    vehicle();
    virtual void SetVehicle(Vector2f pos);
    virtual Sprite GetVehicle();
    virtual void score1(Count x);
    bool GetStatus();

protected:
    Sprite Veh;
    Texture Small1;
    Texture Small2;
    Texture Small3;
    bool Is_hit = false;
    Vector2f Location;
}; 

class BigShip : public vehicle
{
public:
    BigShip();
    void SetVehicle(Vector2f pos) override;
    Sprite GetVehicle1();
    void score2(Count x);
protected:
    Sprite BigBoat;

};

class Small : public vehicle
{
public:
    Small();
    void SetVehicle(Vector2f pos) override;
    Sprite GetVehicle2();
    void score3(Count x);
protected:
    Sprite Smalls;

};

#endif