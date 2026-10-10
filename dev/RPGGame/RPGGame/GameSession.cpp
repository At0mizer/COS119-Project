#include <thread>
#include "GameSession.h"
#include "GameEngine.h"
#include "CharacterCreator.h"
#include "Player.h"
#include "Dialogue.h"


void GameSession::StartSession()
{


	if (bIsNewGame)
	{
		bIsNewGame = false;
		Helper::Print("New Game Selected!", Helper::Color::Red, 1);

		std::this_thread::sleep_for(std::chrono::seconds(2));
		Helper::ClearConsole();

		CreateCharacter();
	}
	else
	{
		Helper::Print("Player Data Loaded!", Helper::Color::Red, 1);
	}

	Dialogue::StartDialogue();

}

void GameSession::SafeZone()
{

}

void GameSession::BattleSequence()
{

}


void GameSession::CreateCharacter()
{
	Player* player = new Player("", "", 0, 0, 0); // Creates an new empty player
	Engine.RegisterActor(player); // Registers the actor to the vector so it will be added to the destruction list

	// Calls the CreateCharacter method from the CharacterCreator namespace
	CharacterCreator::CreateCharacter(*player);
 }

// Will become its own Namepsace
void GameSession::SaveGame()
{}
