#include "BattleSequence.h"
#include "Skeleton.h"
#include "Goblin.h"


BattleSequence::~BattleSequence()
{
	
}

void BattleSequence::CreateEnemies()
{
	EnemyList.push_back(new Skeleton());
	EnemyList.push_back(new Skeleton());
	EnemyList.push_back(new Goblin());
	EnemyList.push_back(new Goblin());
}


void BattleSequence::RemoveDeadEnemies()
{}
