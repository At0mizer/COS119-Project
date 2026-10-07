#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player() = default;
	Player(std::string _name, int _health, int _expPoints) : Character(_name, _health, _expPoints){};

	void BeginPlay() override;

};

