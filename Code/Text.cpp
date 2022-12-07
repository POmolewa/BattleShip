#include <iostream>
#include <SFML/Graphics.hpp>
#include "Count.h"
#include <string>

using namespace std;
using namespace sf;


string ChoicesText()
{

	string txt;

	txt =
		"Select a number on your keyboard\n"
		"1: Ground Forces\n"
		"2: Battleship\n"
		"Esc: Quit\n";
	return txt;
}

string Player1Text(Count x)
{

	string txt;

	txt =
		"Player 1's Score: "  + to_string(x.Get());
	return txt;

}

string Player2Text(Count x)
{

	string txt;

	txt = "Player 2's Score: "  + to_string(x.Get());
	return txt;
}

