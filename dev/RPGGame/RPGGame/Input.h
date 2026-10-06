#pragma once
#include <string>
#include "Helper.h"

namespace Input
{
	int GetInput(std::string message, int min, int max)
	{

		while (true)
		{
			Helper::Print(message, Helper::Color::White, 1);
			std::string userChoice;
			getline(std::cin, userChoice);

			try
			{
				int convInput = std::stoi(userChoice);
				if (convInput >= min and convInput <= max)
				{
					return convInput;
				}
				else
				{
					Helper::Print("Invalid Option... Please select one of the options from the options menu.", Helper::Color::Red, 1);
				}
			}
			catch (...)
			{
				Helper::Print("Invalid Option... Please select one of the options from the options menu.", Helper::Color::Red, 1);
			}
		}
	}
}