#pragma once
#include "Player.h"
#include "Dialogue.h"
#include "Helper.h"

namespace CharacterCreator
{

	void CreateName(Player& player)
	{
		Helper::TypeOut("[BAP] Let's begin with your name.", 30, 1, Helper::Color::Cyan, 1);
		Helper::Print("Input Name Here: ", Helper::Color::White, 1);
		Helper::Print(">> ", Helper::Color::White, 0);

		std::string inputName;
		getline(std::cin, inputName);

		Helper::TypeOut("[BAP] So your name is " + inputName + "? (Y/N) ", 30, 1, Helper::Color::Cyan, 1);
		Helper::Print(" >> ", Helper::Color::White, 0);

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
			CreateName(player);// Recursively restarts name creation if the input is 'N'
		}
		else
		{
			std::cin.ignore();
			Helper::TypeOut("ERROR: Invalid Input... ", 30, 1, Helper::Color::Cyan, 1);

			std::this_thread::sleep_for(std::chrono::seconds(1)); // Pauses the 
			Helper::ClearConsole();

			CreateName(player); // Recursively restarts name creation if the input is not 'Y' or 'N'
		}

	}

	void CreateCharacter(Player& player)
	{
		Dialogue::CharacterCreateDialogue();
		CreateName(player);
	}
};

