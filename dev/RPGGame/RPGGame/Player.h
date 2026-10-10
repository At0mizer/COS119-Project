#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player() = default;
	Player(std::string _name, std::string _classname, int _health, int _armorClass, int _stamina, int _expPoints) : Character(_name, _classname, _armorClass, _health, _stamina, _expPoints){};

	void BeginPlay() override;

};

