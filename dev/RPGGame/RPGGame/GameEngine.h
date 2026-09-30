#pragma once

#include <iostream>
#include <vector>
#include "Menus.h"

// Forward declaration so the GameEngine knows that AActor exists
class AActor;

class GameEngine
{
public:
	// Destructor to ensure no memory leaks if the engine closes
	~GameEngine();

	void Run();

	// Spawns/Registers a new actor into the engine
	void RegisterActor(AActor* NewActor);

	void ProcessDeferredDestruction();

private:
	// The master list of every actor that is currently alive
	std::vector<AActor*> ActorRegistry;

};