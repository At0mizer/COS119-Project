#include "AActor.h"

void AActor::Destroy()
{
	bPendingDestruction = true; // deferred destrutction flag
}
