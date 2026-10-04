#pragma once

class GameEngine;

class GameManager
{
public:
	GameManager(GameEngine& _engine)
		: Engine(_engine)
	{}
	
	void MainMenu();

	void LoadGame();
	

private:
	GameEngine& Engine;


};

 