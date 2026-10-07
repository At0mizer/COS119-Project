#include "GameEngine.h"
#include "GameManager.h"
#include "AActor.h"
#include "Helper.h"

GameEngine* GEngine = nullptr; // Sets the Global GameEngine pointer to nullptr

// Destructor
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

void GameEngine::PrintBlankLines(int numOfBlankLines)
{
	for (int i = 0; i < numOfBlankLines; i++)
	{ 
		std::cout << std::endl;
	}

}

void GameEngine::ErrorMessage(std::string message)
{
	TypeOut(message, 1ms, 1s, Color::Red, 1);
}

void GameEngine::ClearLastLine()
{
	Print("\x1b[1A\x1b[2K\r", Color::White, 0);
}

void GameEngine::ClearConsole()
{
#ifdef _WIN32
	system("cls"); // If the system is a windowOS then it calls this function
#else
	system("clear"); // If the system is not a windowOS (i.e. MacOS) then it calls this function
#endif
}

void GameEngine::Continue()
{
	system("pause");
}


