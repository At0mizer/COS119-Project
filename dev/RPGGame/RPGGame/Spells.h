#pragma once
#include <string>
#include <vector>

struct Ability
{
	std::string Name;
	std::string Desc;
	int Damage = 0; // Damage dealth to the target
	int Health = 0; // Health resortation to the user
	int cost = 0; // Mana for spell casters, stamina for martial classes
};

inline const std::vector<Ability> AllAbilities =
{
	{"Eldritch Blast", " A Crackling beam of dark energy", 20, 0, 5}

};