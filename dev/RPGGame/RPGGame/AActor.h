#pragma once
#include "GameEngine.h"

class AActor
{
public:
	AActor() 
	{
	};

	virtual ~AActor() 
	{}

	virtual void Destroy(); // Deletes the object pointer then assigns it to nullptr

	std::string Name;
	bool PendingDestruction() const { return bPendingDestruction; }

private:
	bool bPendingDestruction = false;
};

