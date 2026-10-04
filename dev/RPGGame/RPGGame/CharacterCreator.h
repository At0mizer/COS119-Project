#pragma once
#include "Player.h"
#include "Dialogue.h"
#include "Helper.h"

namespace CharacterCreator
{

	void CreateName(Player& player)
	{
		Helper::TypeOut("[BAP] Let's being! What is your name?", 30, 100, Helper::Color::Cyan);
		Helper::Print(">> ", Helper::Color::White, 0);

		std::string inputName;
		getline(std::cin, inputName);



		Helper::TypeOut("[BAP] So your name is " + inputName + "? (Y/N) ", 30, 100, Helper::Color::Cyan);
		Helper::Print(">> ", Helper::Color::White, 0);

		char userChoice;
		std::cin >> userChoice;

		if (userChoice == 'Y' or userChoice == 'y')
		{
			std::cin.ignore();
			player.Name(inputName);
		}
		else if (userChoice == 'N' or userChoice == 'n')
		{
			std::cin.ignore();
			CreateName(player);
		}

	}

	void CreateCharacter(Player& player)
	{

		Dialogue::CharacterCreateDialogue();
		CreateName(player);

	




	}


};

