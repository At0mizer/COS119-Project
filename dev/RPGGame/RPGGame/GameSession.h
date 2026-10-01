#pragma once
#include "Helper.h"
#include "GameEngine.h"

class GameSession
{
public:
	GameSession(GameEngine& _engine)
		:  Engine(_engine)
	{}

	void SessionRun();

private:
	GameEngine& Engine;
};

