#pragma once
#include "Helper.h"

class GameEngine;

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

