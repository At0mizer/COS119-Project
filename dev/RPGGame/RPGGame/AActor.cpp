#include "AActor.h"

void AActor::BeginPlay()
{}

void AActor::Destroy()
{
	bPendingDestruction = true; // deferred destrutction flag
}
