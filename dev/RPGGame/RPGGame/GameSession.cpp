#include <thread>
#include "GameSession.h"
#include "GameEngine.h"
#include "CharacterCreator.h"
#include "Player.h"
#include "Goblin.h"
#include "Dialogue.h"


void GameSession::StartSession()
{


	if (bIsNewGame)
	{
		bIsNewGame = false;
		GEngine->Print("New Game Selected!", Color::Red, 1);

		std::this_thread::sleep_for(std::chrono::seconds(2));
		GEngine->ClearConsole();

		CreateCharacter();
	}
	else
	{
		GEngine->Print("Player Data Loaded!", Color::Red, 1);
	}

	Dialogue::StartDialogue();
	BattleSequence();
}

void GameSession::SafeZone()
{

}

void GameSession::BattleSequence()
{
	Goblin* goblin = new Goblin();

}


void GameSession::CreateCharacter()
{
	Player* player = new Player();
	Engine.RegisterActor(player); // Registers the actor to the vector so it will be added to the destruction list

	// Calls the CreateCharacter method from the CharacterCreator namespace
	CharacterCreator::CreateCharacter(*player);
 }

// Will become its own Namepsace
void GameSession::SaveGame()
{}
