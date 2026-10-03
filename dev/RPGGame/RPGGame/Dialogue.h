#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "helper.h"

namespace IntroLines
{
	inline const std::vector<std::string> Lines =
	{
		"[Narrator] You wake up in a patch of grass on the side of the road.",
		"[Narrator] You have no memory of how you got here or even where here is.",
		"[Narrator] The first thing you do is look around to take in your surroundings.",
		"[Narrator] You don't see much of worth while, until you see smoke rising in the distanc",
		"[You] Huh? Wait... I see smoke! It could be a sign of civilization!",
	};
}

namespace Dialogue
{
	template <typename T>
	void TypeOut(const T& message, int delayMs)
	{

		auto time = std::chrono::milliseconds(10);

		for (char c : message)
		{
			Helper::Print(c, Helper::Color::White, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
		}

		std::cin.ignore();
	}

	void Intro()
	{

		for (const std::string& line : IntroLines::Lines)
		{
			Dialogue::TypeOut(line, 30);
		}


	}


	void StartDialogue()
	{
		Intro();
	}

};

