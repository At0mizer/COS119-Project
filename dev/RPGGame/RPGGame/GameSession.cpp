#include <thread>
#include "Input.h"
#include "GameSession.h"
#include "GameEngine.h"
#include "CharacterCreator.h"
#include "BattleSequence.h"
#include "Player.h"
#include "Goblin.h"
#include "Skeleton.h"
#include "Dialogue.h"


void GameSession::StartSession()
{
	Player* player = new Player();

	if (bIsNewGame)
	{
		bIsNewGame = false;
		GEngine->ClearConsole();

		CreateCharacter(*player);
	}
	else
	{
		GEngine->Print("Player Data Loaded!", Color::Red, 1);
	}

	Dialogue::StartDialogue();
	GameLoop(*player);
}

void GameSession::CreateCharacter(Player& player)
{

	Engine.RegisterActor(&player); // Registers the actor to the vector so it will be added to the destruction list

	// Calls the CreateCharacter method from the CharacterCreator namespace
	CharacterCreator::CreateCharacter(player);
}

void GameSession::SafeZone(Player& player) // This will go in its own class eventually
{
	GEngine->TypeOut("Welcome to the safe zone!", 30ms, 1s, Color::Blue, 1);
	GEngine->TypeOut("Please select an option", 30ms, 1s, Color::Blue, 1);

	int userInput = Input::GetInput("Select a thing", 1, 2);
	
	bool bSafeZone = true;

	while (bSafeZone)
	{
		switch (userInput)
		{
		case 1:
			bSafeZone = false;
			break;
		case 2:
			bIsLooping = false;
			bSafeZone = false;
			break;
		default:
			break;
		}
	}
}

void GameSession::BattleMode(Player& player)
{
	BattleSequence battle;
	battle.Battle(player);

}


void GameSession::GameLoop(Player& player)
{
	while (bIsLooping)
	{
		SafeZone(player);

		if (bIsLooping)
		{
			BattleMode(player);
			GEngine->ProcessDeferredDestruction();
		}

		GEngine->ProcessDeferredDestruction();
	}
}

// Will become its own Namepsace
void GameSession::SaveGame()
{}
