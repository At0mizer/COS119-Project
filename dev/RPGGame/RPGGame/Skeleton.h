#pragma once
#include "Enemy.h"
#include "UMath.h"

class Skeleton : public Enemy
{
public:
	Skeleton()
	{
		charStats.Name = "Skeleton";
		charStats.ClassName = "Enemy_Skeleton";
		charStats.Health = UMath::RandRange(6, 9);
		charStats.ArmorClass = UMath::RandRange(2, 5);
		charStats.Stamina = UMath::RandRange(11, 15);
		charStats.Exp = UMath::RandRange(10, 15);

		RollIntiative();

		GEngine->RegisterActor(this);
	}
};

