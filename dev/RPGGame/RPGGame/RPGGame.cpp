#include "GameEngine.h"
#include "Helper.h"


int main()
{

	Helper::MemoryLeakDector();

	GameEngine engine;

	// Calls the Run() method in the GameEngine.h
	engine.Run();

}
