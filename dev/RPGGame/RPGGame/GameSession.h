#pragma once
#include "Helper.h"

class GameEngine;

class GameSession
{
public:
	GameSession(GameEngine& _engine)
		: Engine(_engine)
	{}

	void StartSession();
	void SafeZone();
	void BattleSequence();

	void CreateCharacter();

	bool GetIsNewGame() const { return bIsNewGame; }
	void SetIsNewGame() { bIsNewGame = true; }

	void SaveGame();

private:
	GameEngine& Engine;

	bool bIsNewGame = false;
	bool bIsLooping = true;
};

