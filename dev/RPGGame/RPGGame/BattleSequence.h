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
	void RemoveEnemies();

	void RollForInitiative(Player& player);
	void SelectEnemies();
	void Battle(Player& player);

	const std::vector<Enemy*>& EnemyList() const { return enemyList;  }
	const std::vector<Character*>& TurnOrder() const { return turnOrder; }

private:
	std::vector<Enemy*> enemyList;
	std::vector<Enemy*> enemyBattleList;
	std::vector<Character*> turnOrder;

	bool bIsLooping = true;
};

