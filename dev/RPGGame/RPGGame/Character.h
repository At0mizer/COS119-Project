#pragma once
#include "AActor.h"


struct CharacterStats
{
	std::string Name = "John Cena";
	int health = 0;
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

	void BeginPlay() override;
	void PrintStats(Helper::Color color) const
	{
		Helper::Print("Name: " + charStats.Name + "| Health: " + std::to_string(charStats.health), color, 1);
	}

protected:



};

