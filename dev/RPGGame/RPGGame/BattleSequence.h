#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class BattleSequence
{
public:
	BattleSequence();
	~BattleSequence();

	void CreateEnemies();

	void Battle(Player& player);

	void RemoveDeadEnemies();

	const std::vector<Enemy*>& GetEnemyList() const { return EnemyList;  }

private:
	std::vector<Enemy*> EnemyList;
};

