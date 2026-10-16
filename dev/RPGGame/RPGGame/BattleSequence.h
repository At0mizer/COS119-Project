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
	void SelectEnemies();
	void Battle(Player& player);

	const std::vector<Enemy*>& EnemyList() const { return enemyList;  }
	const std::vector<Character*>& TurnOrder() const { return turnOrder; }

private:
	void RunCombat(Player& player);
	void PlayerTurn(Player& player, const std::vector<Character*>& enemies);
	void EnemyTurn(Character* enemy, Player& player);
	void Attack(Character* attacker, Character* target, int damage);
	bool IsAlive(const Character* character) const;
	bool AnyAlive(const std::vector<Character*>& characters) const;

	std::vector<Enemy*> enemyList;
	std::vector<Enemy*> enemyBattleList;
	std::vector<Character*> turnOrder;

	bool bIsLooping = true;
};

