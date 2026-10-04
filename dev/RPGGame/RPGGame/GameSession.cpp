#include <thread>
#include "GameSession.h"
#include "GameEngine.h"



void GameSession::StartSession()
{


	if (bIsNewGame)
	{
		Helper::Print("New Game Selected!", Helper::Color::Red, 1);
	}
	else
	{
		Helper::Print("Player Data Loaded!", Helper::Color::Red, 1);
	}



	//while (bIsLooping)
	//{
	//	SafeZone();
	//	BattleSequence();
	//	Engine.ProcessDeferredDestruction();
	//}


}

void GameSession::SafeZone()
{

}

void GameSession::BattleSequence()
{

}

// Will become its own Namespace
void GameSession::CreateCharacter()
{
	//CharacterCreation::CreateNewCharacter();
}

// Will become its own Namepsace
void GameSession::SaveGame()
{}
