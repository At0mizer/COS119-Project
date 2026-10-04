#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player(std::string _name, int _health, int _expPoint) : Character(_name, _health), expPoints(_expPoint) {};

	void BeginPlay() override;

private:
	int expPoints;


};

