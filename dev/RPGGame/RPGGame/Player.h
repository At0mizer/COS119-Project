#pragma once
#include <vector>
#include "Character.h"
#include "Abilties.h"

struct CharacterAbilities
{
	std::vector< CharacterAbility> abilities;
};

class Player : public Character
{
public:
	CharacterAbilities charAbilities;

	Player() {};

};

