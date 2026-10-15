#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "BattleSequence.h"
#include "Player.h"
#include "Enemy.h"
#include "Skeleton.h"
#include "Goblin.h"
#include "Kobald.h"

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

void BattleSequence::SelectEnemies()
{
	int randNum = UMath::RandRange(1, 3); // Selects a random amount of enemies on the field

	for (int i = 0; i < randNum; i++)
	{
		int index = UMath::RandRange(1, enemyList.size() - 1);
		enemyBattleList.push_back(enemyList[index]);
	}

	for (int i = 0; i < enemyBattleList.size(); i++)
	{
		GEngine->Print(enemyBattleList[i]->charStats.Name + " | Health: " + std::to_string(enemyBattleList[i]->charStats.Health), Color::White, 1);

	}

	system("pause");

}

void BattleSequence::Battle(Player& player)
{
	GEngine->ClearConsole();
	GEngine->Print("<=><=><=><=><=><=><=> FIGHT <=><=><=><=><=><=><=>", Color::BMagenta, 1);
	GEngine->TypeOut("Oh no!! You have been ambushed!!", 30ms, 1000ms, Color::Gray, 1);

	RollForInitiative(player);

	SelectEnemies();

	enemyBattleList.clear();

}

void BattleSequence::CreateEnemies()
{
	int numOfEnemy = UMath::RandRange(5, 11);

	for (int i = 0; i < numOfEnemy; i++)
	{
		int randNum = UMath::RandRange(1, 3);

		if (randNum == 1)
		{
			enemyList.push_back(new Skeleton());
		}
		else if (randNum == 2)
		{
			enemyList.push_back(new Goblin());
		}
		else
		{
			enemyList.push_back(new Kobald());
		}
	}
}
