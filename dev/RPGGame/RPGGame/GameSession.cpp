#include <thread>
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
		GEngine->Print("New Game Selected!", Color::Red, 1);

		std::this_thread::sleep_for(std::chrono::seconds(2));
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

void GameSession::SafeZone(Player& player)
{

}

void GameSession::BattleMode(Player& player)
{
	BattleSequence battle;
	battle.Battle(player);
}


void GameSession::GameLoop(Player& player)
{
	SafeZone(player);
	BattleMode(player);
	GEngine->ProcessDeferredDestruction();
}

// Will become its own Namepsace
void GameSession::SaveGame()
{}
