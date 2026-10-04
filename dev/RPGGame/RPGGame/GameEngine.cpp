#include "GameEngine.h"
#include "GameManager.h"
#include "AActor.h"
#include "Helper.h"
#include <utility>

GameEngine::~GameEngine()
{
	bIsRunning = false;
	for (AActor* actor : ActorRegistry)
	{
		delete actor;
	}
	ActorRegistry.clear();


}

void GameEngine::Run()
{
	GameManager manager(*this);

	manager.MainMenu();
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
			Helper::Print("Actor was destroyed", Helper::Color::Red, 1);
		}
		else {
			++it;
		}		
	}
}





