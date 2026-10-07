#include "AActor.h"

void AActor::BeginPlay()
{}

void AActor::EndPlay()
{}

void AActor::Destroy()
{
	bPendingDestruction = true; // deferred destrutction flag
}
