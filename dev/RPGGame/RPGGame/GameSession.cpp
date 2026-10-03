#include "GameSession.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "GameEngine.h"
#include "GameManager.h"
#include "Player.h"

void GameSession::SessionRun()
{
	GameManager GManager;

	bool bIsRunning = true;
	while (bIsRunning)
	{

		//Player* player = new Player("Chuck Noris", 1000000, 0);

		Helper::Print("Game Session Started...", Helper::Color::Red, 2);

		std::this_thread::sleep_for(std::chrono::seconds(5));

		Helper::ClearConsole();

		GManager.Run();

		Helper::ClearConsole();

		//Helper::Print("======== Character Stats ========", Helper::Color::Cyan, 1);
		//player->PrintStats(Helper::Color::Cyan);

		//Helper::Print("Chuck Norris was destroyed... Or did he destroy the destroy....", Helper::Color::Cyan, 1);

		//Engine.RegisterActor(player);
		//player->Destroy();

		//Engine.ProcessDeferredDestruction();

		//std::cin.ignore();
		//std::cin.get();

		bIsRunning = false;
	}

}
