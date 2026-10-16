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
#include "Input.h"

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
		int index = UMath::RandRange(1, static_cast<int>(enemyList.size()) - 1);
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

	SelectEnemies();             // 1. decide who's in the fight
	RollForInitiative(player);   // 2. roll turn order for those fighters
	RunCombat(player);           // 3. take turns until one side wins

	enemyBattleList.clear();     // 4. clean up for the next battle
	turnOrder.clear();
}

// Runs the fight using the initiative order from RollForInitiative
void BattleSequence::RunCombat(Player& player)
{
	// Build the list of who is actually fighting, keeping the initiative order.
// turnOrder has every enemy in enemyList, so only keep the player and
// the enemies that were picked for this battle.
	std::vector<Character*> fighters;
	std::vector<Character*> enemies;

	for (Character* c : turnOrder)
	{
		bool isPlayer = (c == &player);
		bool inBattle = std::find(enemyBattleList.begin(), enemyBattleList.end(), c) != enemyBattleList.end();

		if (isPlayer || inBattle)
		{
			fighters.push_back(c);

			if (inBattle)
			{
				enemies.push_back(c);
			}
		}
	}

	GEngine->ClearConsole();
	GEngine->Print("<=><=><=><=><=> BATTLE START <=><=><=><=><=>", Color::BMagenta, 1);

	int round = 1;

	while (IsAlive(&player) && AnyAlive(enemies))
	{
		GEngine->Print("--- Round " + std::to_string(round) + " ---", Color::Blue, 1);

		for (Character* c : fighters)
		{
			if (!IsAlive(c))
			{
				continue; // dead characters skip their turn
			}

			if (c == &player)
			{
				PlayerTurn(player, enemies);
			}
			else
			{
				EnemyTurn(c, player);
			}

			// Stop as soon as one side is wiped out
			if (!IsAlive(&player) || !AnyAlive(enemies))
			{
				break;
			}
		}

		round++;
	}

	if (IsAlive(&player))
	{
		GEngine->TypeOut("Victory! All enemies have been defeated!", 30ms, 1000ms, Color::Cyan, 1);
	}
	else
	{
		GEngine->TypeOut("You have fallen...", 30ms, 1000ms, Color::Red, 1);
	}

	system("pause");
}

// Player picks an enemy to attack
void BattleSequence::PlayerTurn(Player& player, const std::vector<Character*>& enemies)
{
	// 1. Pick a spell
	GEngine->Print("Your turn! Choose a spell:", Color::White, 1);

	int abilityCount = static_cast<int>(player.charAbilities.abilities.size());

	for (int i = 0; i < abilityCount; i++)
	{
		GEngine->Print(std::to_string(i + 1) + ". " + player.charAbilities.abilities[i].Name     //CharacterAbilities[i].Name
			+ " | Damage: " + std::to_string(player.charAbilities.abilities[i].Damage), Color::White, 1);
	}

	int spellChoice = Input::GetInput(">> ", 1, abilityCount);
	int damage = player.charAbilities.abilities[spellChoice - 1].Damage;

	// 2. Pick a target (only living enemies)
	std::vector<Character*> targets;

	for (Character* e : enemies)
	{
		if (IsAlive(e))
		{
			targets.push_back(e);
		}
	}

	GEngine->Print("Choose a target:", Color::White, 1);

	for (int i = 0; i < static_cast<int>(targets.size()); i++)
	{
		GEngine->Print(std::to_string(i + 1) + ". " + targets[i]->charStats.Name
			+ " | Health: " + std::to_string(targets[i]->charStats.Health), Color::White, 1);
	}

	int targetChoice = Input::GetInput(">> ", 1, static_cast<int>(targets.size()));

	Attack(&player, targets[targetChoice - 1], damage);
}

void BattleSequence::EnemyTurn(Character* enemy, Player& player)
{
	Attack(enemy, &player, enemy->charStats.Attack);
}

void BattleSequence::Attack(Character* attacker, Character* target, int damage)
{
	target->charStats.Health -= damage;

	if (target->charStats.Health < 0)
	{
		target->charStats.Health = 0;
	}

	GEngine->TypeOut(attacker->charStats.Name + " attacks " + target->charStats.Name
		+ " for " + std::to_string(damage) + " damage!", 15ms, 500ms, Color::Gray, 1);

	if (!IsAlive(target))
	{
		GEngine->TypeOut(target->charStats.Name + " has been defeated!", 15ms, 500ms, Color::Red, 1);
	}
}

bool BattleSequence::IsAlive(const Character* character) const
{
	return character->charStats.Health > 0;
}

bool BattleSequence::AnyAlive(const std::vector<Character*>& characters) const
{
	for (const Character* c : characters)
	{
		if (IsAlive(c))
		{
			return true;
		}
	}

	return false;
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

