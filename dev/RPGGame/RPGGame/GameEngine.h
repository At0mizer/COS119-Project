#pragma once

#include <iostream>
#include <vector>
#include "Helper.h"
#include "Menus.h"

// Forward declaration so the GameEngine knows that AActor exists
class AActor;

class GameEngine
{
public:
	GameEngine() = default;
	// Destructor to ensure no memory leaks if the engine closes
	~GameEngine();

	void Run();

/*
* The Manager vs. The Managed conundrum
*
* Question: Who should manage who?
* Instead of having each class worry about deleting itself after being used
*		- Enemy should worry about enemy things
*		- Player should worry about player things
*		- NPC should worry about NPC things
*		- None of these should have to worry about deleting themselves
*
* The class notifies the engine that it has completed its tasks and
* is ready for deletion by using Destroy().
*
* Destroy() flags the object instance with the destruction flag
*
* The engine then removes the object from the heap and frees up that memory address
* Then it purges the pointer from the engine's pointer registry to eliminate any dangling pointers
* (Dangling pointers are pointers that refer to a memory location that has been freed up)
*
* This is a simple deferred-destruction object management system or a simple garbage collection system
* Deferred meaning it will delete this object when it is safe, instead of immediately
*
*/

	void ProcessDeferredDestruction();

	// Registers a new actor into the engine
	void RegisterActor(AActor* Actor);

private:
	// The master list of every actor that is currently alive
	std::vector<AActor*> ActorRegistry;

	void MainMenu();

	bool bIsRunning = true;

protected:
	


};