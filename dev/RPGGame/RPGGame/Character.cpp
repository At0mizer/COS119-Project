#include "Character.h"
#include "GameEngine.h"
#include "Screens.h"
#include "Abilties.h"

void Character::TakeDamage(int _dmgAmt)
{}



int Character::RollInitiative()
{
	initiative = UMath::RandRange(1, 20);
	return initiative;
}

void Character::Attack(Character& character)
{
	// takes the ability and the damage 
}

void Character::PrintStats() const
{}

