#pragma once

class GameEngine;
class Player;

class GameSession
{
public:
	GameSession(GameEngine& _engine)
		: Engine(_engine)
	{}

	void StartSession();
	void SafeZone(Player& player);
	void BattleMode(Player& player);

	void CreateCharacter(Player& player);

	void GameLoop(Player& player);

	bool GetIsNewGame() const { return bIsNewGame; }
	void SetIsNewGame() { bIsNewGame = true; }

	void SaveGame();

private:
	GameEngine& Engine;

	bool bIsNewGame = false;
	bool bIsLooping = true;
};

