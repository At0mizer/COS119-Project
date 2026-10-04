#include "GameManager.h"
#include "GameEngine.h"
#include "GameSession.h"
#include "Menus.h"

void GameManager::MainMenu()
{
	GameSession Session(Engine);

	while (Engine.IsRunning())
	{
		int MenuChoice = Menus::MainMenu();

		if (MenuChoice == 4)
		{
			Engine.RequesetQuit();

		}

		if (MenuChoice == 1)
		{
			Session.SetIsNewGame();
			Session.StartSession();
		}

		if (MenuChoice == 2)
		{
			LoadGame();
			Session.StartSession();
		}
	}
	
}

void GameManager::LoadGame()
{
	// This will eventually load player save data
}


