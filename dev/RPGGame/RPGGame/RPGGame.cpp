#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "GameEngine.h"
#include "Helper.h"


int main()
{
	Helper::MemoryLeakDector();

	GameEngine engine;

	// Calls the Run() method in the GameEngine.h
	engine.Run();

	return 0;
}
