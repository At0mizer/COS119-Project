#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AActor.h"
#include "UMath.h"

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

	int RollIntiative();
	void Attack(Character& character);
	void TakeDamage(int _dmgAmt);

	virtual void PrintStats() const;

	std::string Name() const { return charStats.Name; }
	void Name(std::string _name) { charStats.Name = _name; }

private:
};

