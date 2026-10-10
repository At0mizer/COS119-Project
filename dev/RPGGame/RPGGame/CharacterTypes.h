#pragma once

struct CharacterTypes
{
	std::string Name;
	std::string Desc;
	int Health = 0;
	int ArmorClass = 0;
	int Stamina = 0;
};

inline const CharacterTypes Warlock{ "Warlock", "\033[3mBound by a pact with an unknown patron, the Warlock trades safety for devastating dark magic.\033[0m", 10, 13, 15};
inline const CharacterTypes Soldier{ "Soldier", "\033[3mA battle-hardened fighter who trusts in steel, discipline, and the grit to outlast any foe.\033[0m", 12, 16, 20};