
#ifndef CREATESHIP_H
#define CREATESHIP_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include "BattleField.h"
#include "CreateShip.h"
#include "Count.h"
#include <vector>

using namespace std;
using namespace sf;


vehicle* CreateShip(vector<Vector2f> coords);
BigShip* CreateShip2(vector<Vector2f> coords);
Small* CreateShip3(vector<Vector2f> coords);
vehicle* PCreateShip(vector<Vector2f> coords);
BigShip* PCreateShip2(vector<Vector2f> coords);
Small* PCreateShip3(vector<Vector2f> coords);

#endif // !CREATESHIP_H
