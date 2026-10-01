#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <thread>
#include <string>
#include "GameEngine.h"
#include "Helper.h"
#include "Player.h"

int main()
{


	GameEngine engine;

	// Calls the Run() method in the GameEngine.h
	engine.Run();



}
