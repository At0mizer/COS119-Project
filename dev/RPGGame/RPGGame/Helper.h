#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <string_view>
#include <random>
#include <thread>
#include <chrono>

namespace Helper
{

	enum class Color
	{
		Red,
		Blue,
		Green,
		White,
		Cyan,
		Purple
	};


	// ======================================
	//									PRINTING										   
	//										LOGIC											  
	// ======================================
	static void PrintBlankLines(int numLines)
	{
		for (int i = 0; i < numLines; i++)
		{
			std::cout << std::endl;
		}
	}

	template <typename T>
	static void Print(const T& message, Color color, int numLines)
	{
		switch (color)
		{
		case Color::Red:
			std::cout << "\033[31m";
			break;

		case Color::Blue:
			std::cout << "\033[34m";
			break;

		case Color::Green:
			std::cout << "\033[32m";
			break;

		case Color::White:
			std::cout << "\033[37m";
			break;

		case Color::Cyan:
			std::cout << "\033[36m";
			break;

		case Color::Purple:
			std::cout << "\033[35m";
			break;
		}

		std::cout << message;

		// Reset console color
		std::cout << "\033[0m";
		PrintBlankLines(numLines);
	}

	template <typename T>
	static void TypeOut(const T& message, int delayMs, int delayLine, Helper::Color color, int BlankLines)
	{
		for (char c : message)
		{
			Helper::Print(c, color, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
		}

		std::this_thread::sleep_for(std::chrono::seconds(delayLine));
		Helper::PrintBlankLines(BlankLines);
	}

	static void ShowError(std::string message)
	{
		TypeOut(message, 1, 1, Helper::Color::Red, 1);
	}

	static void ClearLastLine()
	{
		Print("\x1b[1A\x1b[2K\r", Helper::Color::White, 0);
	}

// ======================================
//								END OF PRINTING										   
//										LOGIC											  
// ======================================


	static int RandomNumberGenerator(int min, int max)
	{
		static std::mt19937 gen(std::random_device{}());
		std::uniform_int_distribution<int> distrib(min, max);
		return distrib(gen);
	}

	static void Continue()
	{
		Helper::Print("Press 'ENTER' to continue...", Color::White, 1);
		std::cin.ignore();
		std::cin.clear();
	}

	static void MemoryLeakDector()
	{
		// Turn on automatic leak - checking at program exit, using the debug allocator
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetBreakAlloc(-1);
	}

	static void ClearConsole()
	{
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
	}
}
