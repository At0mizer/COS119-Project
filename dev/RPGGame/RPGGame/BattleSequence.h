#pragma once

class Character;
class Player;
class Enemy;

class BattleSequence
{
public:
	BattleSequence();
	~BattleSequence();

	void CreateEnemies();

	void RollForInitiative(Player& player);
	void Battle(Player& player);

	const std::vector<Enemy*>& EnemyList() const { return enemyList;  }
	const std::vector<Character*>& TurnOrder() const { return turnOrder; }

private:
	std::vector<Enemy*> enemyList;
	std::vector<Character*> turnOrder;

	bool bIsLooping = true;
};

