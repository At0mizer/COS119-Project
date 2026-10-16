#include "Town.h"
#include "GameEngine.h"
#include "GameSession.h"
#include "Player.h"
#include "Input.h"
#include "UMath.h"

Town::Town(GameSession& _session, Player& player)
	: session(_session)
{}

void Town::TownArea()
{
	bSafeZone = true; // reset every time we enter town

	// Pick a name once and keep it for later visits
	if (currentTownName.empty())
	{
		if (townNames.empty())
		{
			currentTownName = "Unnamed Town";
		}
		else
		{
			int lastIndex = static_cast<int>(townNames.size()) - 1;
			currentTownName = townNames[UMath::RandRange(0, lastIndex)];
		}
	}

	PrintMenu();

	while (bSafeZone)
	{
		int userInput = Input::GetInput(">> ", 1, 4);

		switch (userInput)
		{
		case 1: // Shop - needs the inventory system first
			GEngine->TypeOut("The shop is closed for now. Come back later!", 15ms, 1000ms, Color::Cyan, 1);
			GEngine->ClearLastLine(1);
			break;

		case 2: // Long Rest - not implemented yet
			GEngine->TypeOut("The inn isn't open yet.", 15ms, 1000ms, Color::Cyan, 1);
			GEngine->ClearLastLine(1);
			break;

		case 3:
			bSafeZone = false;
			break;

		case 4:
			session.RequestSessionEnd();
			bSafeZone = false;
			break;
		}
	}

	Input::FlushInput();
}

void Town::LongRest(Player& player)
{
	//player.charStats.Health = 
}

void Town::PrintMenu() const
{
	GEngine->ClearConsole();
	GEngine->Print("<=><=><=><=><=>" + currentTownName + "<=><=><=><=><=>", Color::Blue, 2);
	GEngine->TypeOut("Please select an option", 30ms, 1000ms, Color::Blue, 1);
	GEngine->TypeOut("1. Shop", 1ms, 250ms, Color::White, 1);
	GEngine->TypeOut("2. Long Rest", 1ms, 250ms, Color::White, 1);
	GEngine->TypeOut("3. Exit Safe Zone", 1ms, 250ms, Color::White, 1);
	GEngine->TypeOut("4. Main Menu", 1ms, 700ms, Color::White, 1);
}