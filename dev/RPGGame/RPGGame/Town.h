#pragma once
#include <string>
#include <vector>

class Town
{
public:


	void TownArea();

private:

	bool bSafeZone = true;

	std::vector<std::string> townNames =
	{
		"GoAway Township",
		"Fairview Village",
		"Jocobsville"
	};
};

