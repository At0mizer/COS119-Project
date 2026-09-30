#include "GameEngine.h"
#include "AActor.h"

GameEngine::~GameEngine()
{
	for (AActor* actor : ActorRegistry)
	{
		delete actor;
	}
	ActorRegistry.clear();
}

void GameEngine::Run()
{
	bool bIsRunning = true;

	while (bIsRunning) {

		int MenuChoice = Menus::MainMenu();

		if (MenuChoice == 4)
		{
			bIsRunning = false; // User chose Quit; breaks of the application
			continue; // Jumps back up to the "while (bIsRunning)
		}

		if (MenuChoice == 1)
		{
		}

	}

}

void GameEngine::RegisterActor(AActor* NewActor)
{
	ActorRegistry.push_back(NewActor);
}

void GameEngine::ProcessDeferredDestruction()
{
	for (auto it = ActorRegistry.begin(); it != ActorRegistry.end(); ) {
		if ((*it)->PendingDestruction()) {

			// This frees up the memory then vaporizes the pointer out of existence
			delete* it;
			it = ActorRegistry.erase(it);
		}
		else {
			++it;
		}
	}
}




