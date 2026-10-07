#pragma once
#include "GObject.h"

class AActor : public GObject
{
public:
	AActor() 
	{
		BeginPlay();
	};



	virtual ~AActor() 
	{}

	virtual void BeginPlay();
	virtual void EndPlay();

	virtual void Destroy(); // Deletes the object pointer then assigns it to nullptr

	std::string Name;
	bool PendingDestruction() const { return bPendingDestruction; }

private:
	bool bPendingDestruction = false;
};

