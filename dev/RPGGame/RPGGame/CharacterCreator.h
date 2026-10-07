#pragma once
#include "Player.h"
#include "Dialogue.h"
#include "Helper.h"

using namespace std::chrono_literals;

namespace CharacterCreator
{
	void CreateName(Player& player)
	{
		GEngine->TypeOut("[BAP] Let's begin with your name.", 30ms, 1s, Color::Cyan, 2);
		GEngine->Print("Input Name Here: ", Color::White,  1);
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
				GEngine->ClearConsole();
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
	}

};

