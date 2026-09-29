#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <random>


namespace Helper
{
	static void PrintBlankLines(int numLines)
	{
		for (int i = 0; i < numLines; i++)
		{
			std::cout << std::endl;
		}
	}

	template <typename T>
	static void Print(const T& message, int numLines)
	{
		std::cout << message;
		PrintBlankLines(numLines);
	}

	static int RandomNumberGenerator(int min, int max)
	{
		static std::mt19937 gen(std::random_device{}());
		std::uniform_int_distribution<int> distrib(min, max);
		return distrib(gen);
	}

	static void Continue()
	{
		Helper::Print("Press 'ENTER' to continue...", 1);
		std::cin.ignore();
		std::cin.clear();
	}

	static void MemoryLeakDector()
	{
		// Turn on automatic leak - checking at program exit, using the debug allocator
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetBreakAlloc(-1); // set block of memory to find memory block
		_CrtDumpMemoryLeaks(); // Report any currently-tracked leaks
	}

	static void ClearConsole()
	{
#ifdef _WIN32
		std::system("cls");
#else
		std::system("clear");
#endif
	}

}