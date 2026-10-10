#pragma once

struct CharacterTypes
{
	std::string name;
	std::string desc;
	int health = 0;
	int stamina = 0;
};

inline const CharacterTypes Warlock{ "Warlock", "\033[3mBound by a pact with an unknown patron, the Warlock trades safety for devastating dark magic.\033[0m", 10, 15};
inline const CharacterTypes Soldier{ "Soldier", "\033[3mA battle-hardened fighter who trusts in steel, discipline, and the grit to outlast any foe.\033[0m", 12, 20};