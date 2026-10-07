#pragma once
#include "AActor.h"


struct CharacterStats
{
	std::string Name = "John Cena";
	int Health = 0;
	int Exp = 0;
};

class Character : public AActor
{
public:

	CharacterStats charStats;

	Character(std::string _name, int _charHealth, int _exp)
	{
		charStats.Name = _name;
		charStats.Health = _charHealth;
		charStats.Exp = _exp;
	}

	void BeginPlay() override;
	void PrintStats(Helper::Color color) const
	{
		Helper::Print("Name: " + charStats.Name + "| Health: " + std::to_string(charStats.Health), color, 1);
	}

	std::string Name() const { return charStats.Name; }
	void Name(std::string _name) { charStats.Name = _name; }

protected:



};

