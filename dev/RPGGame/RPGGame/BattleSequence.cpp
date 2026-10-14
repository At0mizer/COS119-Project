#include "BattleSequence.h"
#include "Player.h"
#include "Enemy.h"
#include "Skeleton.h"
#include "Goblin.h"

BattleSequence::BattleSequence()
{
	CreateEnemies();

}

BattleSequence::~BattleSequence()
{
	
}

void BattleSequence::Battle(Player& player)
{
	GEngine->ClearConsole();
	GEngine->TypeOut("Oh no!! You have been ambushed!!", 30ms, 1s, Color::BMagenta, 1);

	GEngine->Print(player.charStats.Name + " Initiative: " + std::to_string(player.RollIntiative()), Color::Blue, 1);

	for (auto enemy : EnemyList)
	{
		GEngine->Print("Name: " + enemy->charStats.Name + "| Initiative" + std::to_string(enemy->RollIntiative()), Color::Blue, 1);
	}

	system("pause");

}

void BattleSequence::CreateEnemies()
{
	EnemyList.push_back(new Skeleton());
	EnemyList.push_back(new Skeleton());
	EnemyList.push_back(new Goblin());
	EnemyList.push_back(new Goblin());
}


void BattleSequence::RemoveDeadEnemies()
{
	GEngine->ProcessDeferredDestruction();
}
