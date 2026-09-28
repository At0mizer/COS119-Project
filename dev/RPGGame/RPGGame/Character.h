#pragma once
#include <iostream>
#include <string>

class Character
{
public:

	Character(std::string _name, int charHealth)
		: name(_name), charHealth(charHealth)
	{}

	int Health() const { return charHealth; }
	void Health(int _charHealth ) { charHealth = _charHealth; }

	void SetName(const std::string& _name) { name = _name;  }

protected:
	std::string name;
	int charHealth;

private:
public:


};

