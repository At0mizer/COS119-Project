#pragma once
#include "AActor.h"
#include <iostream>
#include <string>
#include <vector>

struct CharacterStats
{
	std::string Name = "";
	std::string ClassName = "";
	int Health = 0;
	int ArmorClass = 0;
	int Stamina = 0;
	int Exp = 0;
};

class Character : public AActor
{
public:

	CharacterStats charStats;

	Character() = default;

	Character(std::string _name, std::string _classname, int _health, int _armorClass, int _stamina, int _exp)
	{
		charStats.Name = _name;
		charStats.ClassName = _classname;
		charStats.Health = _health;
		charStats.ArmorClass = _armorClass;
		charStats.Stamina = _stamina;
		charStats.Exp = _exp;
	}

	void TakeDamage(int _dmgAmt)
	{
		int reduction = static_cast<int>(charStats.ArmorClass / 0.00125);
		int finalDMG = std::max(0, _dmgAmt - reduction);
		charStats.Health -= finalDMG;
	}

	void PrintStats() const
	{
		GEngine->Print("Name: " + charStats.Name + "| Health: " + std::to_string(charStats.Health), Color::Green, 1);

	}

	std::string Name() const { return charStats.Name; }
	void Name(std::string _name) { charStats.Name = _name; }

};

