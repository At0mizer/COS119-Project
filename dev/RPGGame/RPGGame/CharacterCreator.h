#pragma once
#include "Player.h"
#include "Dialogue.h"
#include "Input.h"
#include "CharacterTypes.h"

using namespace std::chrono_literals;

namespace CharacterCreator
{

	void ApplyClass(Player& player, const CharacterTypes& charClass)
	{
		player.charStats.ClassName = charClass.name;
		player.charStats.Health = charClass.health;
		player.charStats.Stamina = charClass.stamina;

	}

	void PrintStats(const CharacterTypes& charClass)
	{
		const std::string border = "  ##" + std::string(charClass.desc.size() + 4, '=') + "##";
		const std::string titlePad((charClass.desc.size() + 8 - charClass.name.size()) / 2, ' ');

		GEngine->Print(border, Color::Magenta, 1);
		GEngine->Print(titlePad + charClass.name, Color::Magenta, 1);
		GEngine->Print(border, Color::Magenta, 2);

		GEngine->Print("    \033[1mHP      : \033[0m" + std::to_string(charClass.health), Color::Green, 1);
		GEngine->Print("    \033[1mStamina : \033[0m" + std::to_string(charClass.stamina), Color::Green, 2);

		GEngine->Print("    \033[1mDesc: \033[0m" + charClass.desc, Color::White, 2);

		GEngine->Print(border, Color::Magenta, 2);
	}

	void CreateName(Player& player)
	{
		GEngine->PrintBlankLines(1);
		GEngine->Print("======== Character Creator ========", Color::White, 1);
		GEngine->TypeOut("[BAP] Let's begin with your name.", 30ms, 1s, Color::Cyan, 2);
		GEngine->Print("Input Name Here: ", Color::White, 1);
		GEngine->Print(">> ", Color::White, 0);

		std::string inputName;
		getline(std::cin, inputName);
		GEngine->PrintBlankLines(1);

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

			GEngine->TypeOut("[BAP] So your name is " + inputName + "? (Y/N) ", 30ms, 1s, Color::Cyan, 1);
			GEngine->Print(" >> ", Color::White, 0);

			char userChoice;
			std::cin >> userChoice;

			if (userChoice == 'Y' or userChoice == 'y')
			{
				std::cin.ignore();
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

	void SelectClass(Player& player)
	{
		GEngine->ClearConsole();
		GEngine->Print("======== Select a Class ========", Color::White, 1);
		GEngine->TypeOut("[BAP] Now, let's select your class.", 30ms, 1s, Color::Cyan, 1);

		GEngine->TypeOut("1." + Warlock.name + 
			"\tHealth: " + std::to_string(Warlock.health) + 
			"\tMana: " + std::to_string(Warlock.stamina), 
			10ms, 0s, Color::Cyan, 1);

		GEngine->TypeOut("2." + Soldier.name + 
			"\tHealth: " + std::to_string(Soldier.health) + 
			"\tStamina: " + std::to_string(Soldier.stamina), 
			10ms, 0s, Color::Cyan, 1);

		int ClassSelection = Input::GetInput(">> ", 1, 2);


		if (ClassSelection == 1)
		{
			GEngine->PrintBlankLines(1);
			GEngine->TypeOut("[BAP] A Warlock, huh? Making deals with mysterious patrons already?", 30ms, 1s, Color::Cyan, 1);
			GEngine->TypeOut("[BAP] Bold. I like it!", 30ms, 1s, Color::Cyan, 2);

			const std::string border = "  ##" + std::string(Soldier.desc.size() + 4, '=') + "##";
			const std::string titlePad((Warlock.desc.size() + 8 - Warlock.name.size()) / 2, ' ');

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
			GEngine->TypeOut("[BAP] A Soldier! Nothing beats a good sword and a steady arm.", 30ms, 1s, Color::Cyan, 1);
			GEngine->TypeOut("[BAP] Solid choice!", 30ms, 1s, Color::Cyan, 2);

			PrintStats(Soldier);

			GEngine->TypeOut("[BAP] Are you ready to enlist? (Y/N)", 30ms, 0s, Color::Cyan, 1);
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

	void CreateCharacter(Player& player)
	{
		Dialogue::CharacterCreateDialogue();
		CreateName(player);
		SelectClass(player);
	}



};

