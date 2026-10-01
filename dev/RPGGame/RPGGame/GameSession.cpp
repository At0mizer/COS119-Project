#include "GameSession.h"
#include "Player.h"

void GameSession::SessionRun()
{
	bool bIsRunning = true;
	while (bIsRunning)
	{
		Player* player = new Player("Chuck Noris", 1000000, 0);

		for (int i = 0; i < 2; i++)
		{
			Helper::Print("Game Session Started...", Helper::Color::Red, 2);
		}

		Helper::Print("======== Character Stats ========", Helper::Color::Cyan, 1);
		player->PrintStats(Helper::Color::Cyan);

		Helper::Print("Chuck Norris was destroyed... Or did he destroy the destroy....", Helper::Color::Cyan, 1);

		Engine.RegisterActor(player);
		player->Destroy();

		Engine.ProcessDeferredDestruction();

		std::cin.ignore();
		std::cin.get();

		bIsRunning = false;
	}

}
