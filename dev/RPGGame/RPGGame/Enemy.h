#pragma once
#include "Character.h"
#include <vector>

class Enemy : public Character
{
public:
    Enemy() = default;
private:
    std::vector<int> numbers;
};

