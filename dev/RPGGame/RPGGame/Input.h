#pragma once
#include <string>
#include "Helper.h"

namespace Input
{
	static int GetInput(std::string message, int min, int max)
	{

		std::string ErrorMessage = "Invalid Option... Please select one of the options from the options menu.";

		while (true)
		{
			Helper::Print(message, Helper::Color::White, 0);
			std::string userChoice;
			getline(std::cin, userChoice);

			try // tries to see if stoi can convert the userChoice
			{
				int convInput = std::stoi(userChoice);
				if (convInput >= min and convInput <= max)
				{
					return convInput;
				}
				else
				{
					Helper::TypeOut(ErrorMessage, 1, 3, Helper::Color::Red, 1);

					Helper::ClearLastLine();
					Helper::ClearLastLine();
				}
			}
			catch (const std::exception&) // if stoi cannot convert the userChoice, and tells the user to input a valid choice
			{
				Helper::TypeOut(ErrorMessage, 1, 3, Helper::Color::Red, 1);

				Helper::ClearLastLine();
				Helper::ClearLastLine();
			}
		}
	}
}