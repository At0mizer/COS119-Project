#pragma once
#include "Player.h"
#include "Dialogue.h"
#include "Input.h"
#include "CharacterTypes.h"

using namespace std::chrono_literals;

namespace CharacterCreator
{
	//Foward Declared
	void IsNameValid(std::string inputName, Player& player);

	void ApplyClass(Player& player, const CharacterTypes& charClass)
	{
		player.charStats.ClassName = charClass.Name;
		player.charStats.Health = charClass.Health;
		player.charStats.Stamina = charClass.Stamina;

	}

	void PrintStats(const CharacterTypes& charClass)
	{
		const std::string border = "  ##" + std::string(charClass.Desc.size() + 4, '=') + "##";
		const std::string titlePad((charClass.Desc.size() + 8 - charClass.Name.size()) / 2, ' ');

		GEngine->Print(border, Color::BMagenta, 1);
		GEngine->Print(titlePad + charClass.Name, Color::BMagenta, 1);
		GEngine->Print(border, Color::BMagenta, 2);

		GEngine->Print("    \033[1mHP      : \033[22m" + std::to_string(charClass.Health), Color::Green, 1);
		GEngine->Print("    \033[1mAC      : \033[22m" + std::to_string(charClass.ArmorClass), Color::Green, 1);
		GEngine->Print("    \033[1mStamina : \033[22m" + std::to_string(charClass.Stamina), Color::Green, 2);

		GEngine->Print("    \033[1mDesc: \033[0m" + charClass.Desc, Color::White, 2);

		GEngine->Print(border, Color::BMagenta, 2);
	}

	void CreateName(Player& player)
	{
		GEngine->ClearConsole();

		GEngine->Print("  ##================================##", Color::BMagenta, 1);
		GEngine->Print("             CREATE YOUR HERO", Color::BMagenta, 1);
		GEngine->Print("  ##================================##", Color::BMagenta, 2);

		GEngine->TypeOut("[BAP] Every legend needs a name. What's yours?", 30ms, 1s, Color::Cyan, 2);
		GEngine->Print(">> ", Color::White, 0);

		std::string inputName;
		getline(std::cin, inputName);
		GEngine->PrintBlankLines(1);

		IsNameValid(inputName, player);

	}

	void SelectClass(Player& player)
	{
		GEngine->ClearConsole();
		GEngine->Print("##================================##", Color::BMagenta, 1);
		GEngine->Print("	   Select a Class", Color::BMagenta, 1);
		GEngine->Print("##================================##", Color::BMagenta, 1);
		GEngine->TypeOut("[BAP] Now, " + player.charStats.Name + ", let's select your class.", 30ms, 1s, Color::Cyan, 2);

		GEngine->TypeOut("1. " + Warlock.Name +
			"\tHealth: " + std::to_string(Warlock.Health) +
			"\tAC: " + std::to_string(Warlock.ArmorClass) +
			"      Mana: " + std::to_string(Warlock.Stamina),
			10ms, 0s, Color::Green, 1);

		GEngine->TypeOut("2. " + Soldier.Name +
			"\tHealth: " + std::to_string(Soldier.Health) +
			"\tAC: " + std::to_string(Soldier.ArmorClass) +
			"      Stamina: " + std::to_string(Soldier.Stamina),
			10ms, 0s, Color::Green, 2);

		int ClassSelection = Input::GetInput(">> ", 1, 2);


		if (ClassSelection == 1)
		{
			GEngine->PrintBlankLines(1);
			GEngine->TypeOut("[BAP] A Warlock, huh? Making deals with mysterious patrons already?", 30ms, 1s, Color::Cyan, 1);
			GEngine->TypeOut("[BAP] Bold. I like it!", 30ms, 1s, Color::Cyan, 2);

			const std::string border = "  ##" + std::string(Soldier.Desc.size() + 4, '=') + "##";
			const std::string titlePad((Warlock.Desc.size() + 8 - Warlock.Name.size()) / 2, ' ');

			PrintStats(Warlock);

			GEngine->TypeOut("[BAP] Ready to sign on the dotted line? (Y/N)", 30ms, 0s, Color::Cyan, 1);
			GEngine->Print(">> ", Color::White, 0);

			char userChoice;
			std::cin >> userChoice;

			if (userChoice == 'Y' or userChoice == 'y')
			{
				std::cin.ignore();
				GEngine->ClearConsole();
				ApplyClass(player, Warlock);
			}
			else if (userChoice == 'N' or userChoice == 'n')
			{
				std::cin.ignore();
				GEngine->ClearConsole();
				SelectClass(player);// Recursively restarts name creation if the input is 'N'

			}
			else
			{
				std::cin.ignore();
				GEngine->ErrorMessage("ERROR: Invalid Input! Must be 'Y' or 'N'! ");

				GEngine->ClearConsole();

				SelectClass(player); // Recursively restarts name creation if the input is not 'Y' or 'N'
			}
		}

		else
		{
			GEngine->PrintBlankLines(1);
			GEngine->TypeOut("[BAP] A Soldier! Nothing beats a good sword and a steady arm.", 30ms, 1s, Color::Green, 1);
			GEngine->TypeOut("[BAP] Solid choice!", 30ms, 1s, Color::Green, 2);

			PrintStats(Soldier);

			GEngine->TypeOut("[BAP] Are you ready to enlist? (Y/N)", 30ms, 0s, Color::Green, 1);
			GEngine->Print(">> ", Color::White, 0);

			char userChoice;
			std::cin >> userChoice;

			if (userChoice == 'Y' or userChoice == 'y')
			{
				std::cin.ignore();
				ApplyClass(player, Soldier);
			}
			else if (userChoice == 'N' or userChoice == 'n')
			{
				std::cin.ignore();
				GEngine->ClearConsole();
				SelectClass(player);// Recursively restarts name creation if the input is 'N'

			}
			else
			{
				std::cin.ignore();
				GEngine->ErrorMessage("ERROR: Invalid Input! Must be 'Y' or 'N'! ");

				GEngine->ClearConsole();

				SelectClass(player); // Recursively restarts name creation if the input is not 'Y' or 'N'
			}
		}
	}

	void IsNameValid(std::string inputName, Player& player)
	{
		if (!inputName.empty())
		{
			for (int i = 0; i < inputName.size(); i++)
			{
				if (isdigit(inputName[i]))
				{
					GEngine->ErrorMessage("ERROR: Your name should not contain any numbers!");

					std::this_thread::sleep_for(2s);
					GEngine->ClearConsole();

					CreateName(player);
					return;
				}
			}

			GEngine->TypeOut("Are you sure this is correct (Y/N): " + inputName, 30ms, 1s, Color::White, 1);
			GEngine->Print(" >> ", Color::White, 0);

			char userChoice;
			std::cin >> userChoice;

			if (userChoice == 'Y' or userChoice == 'y')
			{
				std::cin.ignore();
				GEngine->TypeOut("[BAP] So your name is " + inputName + "?", 30ms, 1s, Color::Cyan, 1);
				GEngine->TypeOut("[BAP] What a fitting name for a legend!", 30ms, 1s, Color::Cyan, 1);
				player.Name(inputName); // Sets the inputted name to the character's name located in the struct CharacterStats
			}
			else if (userChoice == 'N' or userChoice == 'n')
			{
				std::cin.ignore();
				GEngine->ClearConsole();
				CreateName(player);// Recursively restarts name creation if the input is 'N'

			}
			else
			{
				std::cin.ignore();
				GEngine->ErrorMessage("ERROR: Invalid Input! Must be 'Y' or 'N'! ");

				GEngine->ClearConsole();

				CreateName(player); // Recursively restarts name creation if the input is not 'Y' or 'N'
			}
		}
		else
		{
			GEngine->ErrorMessage("ERROR: Player name is empty!");
			GEngine->ClearConsole();

			CreateName(player);
		}
	}

	void CreateCharacter(Player& player)
	{
		Dialogue::CharacterCreateDialogue();
		CreateName(player);
		SelectClass(player);
	}



};

