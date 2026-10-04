#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <array>
#include <string_view>
#include "helper.h"
#include "Player.h"

namespace IntroLines
{
	inline constexpr std::array<std::string_view, 5> Lines =
	{
		"[Narrator] You wake up in a patch of grass on the side of the road.",
		"[Narrator] You have no memory of how you got here or even where here is.",
		"[Narrator] The first thing you do is look around to take in your surroundings.",
		"[Narrator] You don't see much of worth while, until you see smoke rising in the distance.",
		"[You] Huh? Wait... I see smoke! It could be a sign of civilization!"
	};
}

namespace CharacterCreator
{
	inline constexpr  std::array<std::string_view, 2> Lines1 =
	{
		"[BAP] Hello! Welcome to the Build-A-Player!",
		"[BAP] I'm gonna be walking through the process of creating a new character today!",
	};

}

namespace Dialogue
{
	void CharacterCreateDialogue()
	{
		for (const auto& line : CharacterCreator::Lines1)
		{
			Helper::TypeOut(line, 30, 100, Helper::Color::Cyan);
		}
	}

	void Intro()
	{

		for (const auto& line : IntroLines::Lines)
		{
			Helper::TypeOut(line, 30, 100, Helper::Color::White);
		}

	}


	void StartDialogue()
	{
		Intro();
	}

};

