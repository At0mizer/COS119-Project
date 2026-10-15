#include "Town.h"
#include "GameEngine.h"
#include "GameSession.h"
#include "Input.h"
#include "UMath.h"

void Town::TownArea()
{
	GameSession Session;

	GEngine->ClearConsole();

	int RandNum = UMath::RandRange(0, townNames.size() - 1);

	GEngine->Print("<=><=><=><=><=>" + townNames[RandNum] + "<=><=><=><=><=>", Color::Blue, 2);
	GEngine->TypeOut("Please select an option", 30ms, 1000ms, Color::Blue, 1);
	GEngine->TypeOut("1. Shop", 1ms, 250ms, Color::White, 1);
	GEngine->TypeOut("2. Long Rest", 1ms, 250ms, Color::White, 1);
	GEngine->TypeOut("3. Exit Safe Zone", 1ms, 250ms, Color::White, 1);
	GEngine->TypeOut("4. Main Menu", 1ms, 700ms, Color::White, 1);

	while (bSafeZone)
	{

		int userInput = Input::GetInput(">> ", 1, 4);

		switch (userInput)
		{
		case 1:
			GEngine->TypeOut("Shop is currently closed! Sorry for the inconvenience ", 15ms, 1000ms, Color::Cyan, 1);
			GEngine->ClearLastLine(1);
			break;
		case 2:
			GEngine->TypeOut("Long Rest: You have fully healed and recovered spell points", 15ms, 1000ms, Color::Cyan, 1);
			GEngine->ClearLastLine(1);
			break;
		case 3:
			Input::FlushInput();
			bSafeZone = false;
			break;
		case 4:
			Input::FlushInput();
			Session.RequestSessionEnd();
			bSafeZone = false;
			break;
		default:
			break;
		}
	}
}
