#pragma once
#include "AActor.h"


struct CharacterStats
{
	std::string Name;
	int health;
};

class Character : public AActor
{
public:

	CharacterStats charStats;

	Character(std::string _name, int _charHealth)
	{
		charStats.Name = _name;
		charStats.health = _charHealth;
	}

	void PrintStats()
	{
		Helper::Print(charStats.Name + std::to_string(charStats.health), 1);
	}

protected:



};

