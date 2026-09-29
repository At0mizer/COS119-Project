#pragma once
#include <iostream>
#include <string>

struct CharacterStats
{
	std::string Name;
	int health;
};

class Character
{
public:

	CharacterStats* charStats;

	Character(std::string _name, int _charHealth)
	{
		charStats->Name = _name;
		charStats->health = _charHealth;
	}



protected:



};

