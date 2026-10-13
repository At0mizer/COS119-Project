#pragma once
#include <vector>
#include "Enemy.h"

class BattleSequence
{
public:
	BattleSequence() = default;
	~BattleSequence();

	void CreateEnemies();
	void RemoveDeadEnemies();


private:
	std::vector<Enemy*> EnemyList;
	Enemy enemy;
};

