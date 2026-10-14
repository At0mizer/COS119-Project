#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "BattleSequence.h"
#include "Player.h"
#include "Enemy.h"
#include "Skeleton.h"
#include "Goblin.h"

// Constructor
BattleSequence::BattleSequence()
{
	CreateEnemies();
}

// Destructor
BattleSequence::~BattleSequence()
{
	
}



// Each character rolls to decide the turn order (Highest goes first, lowest last)
// then the order is printed for the player
void BattleSequence::RollForInitiative(Player& player)
{

	turnOrder.push_back(&player);

	for (Enemy* enemy : enemyList)
	{
		turnOrder.push_back(enemy);
	}

	for (Character* character : turnOrder)
	{
		character->RollInitiative();
	}

	std::sort(turnOrder.begin(), turnOrder.end(), [](Character* a, Character* b) { return a->Initiative() > b->Initiative(); });

	for (Character* c : turnOrder)
	{
		GEngine->Print("Name: " + c->charStats.Name + "| Initiative: " + std::to_string(c->Initiative()), Color::Blue, 1);
	}

	system("pause");
}

void BattleSequence::Battle(Player& player)
{
	GEngine->ClearConsole();
	GEngine->TypeOut("Oh no!! You have been ambushed!!", 30ms, 1s, Color::BMagenta, 1);

	RollForInitiative(player);
}

void BattleSequence::CreateEnemies()
{
	enemyList.push_back(new Skeleton());
	enemyList.push_back(new Skeleton());
	enemyList.push_back(new Goblin());
	enemyList.push_back(new Goblin());
}
