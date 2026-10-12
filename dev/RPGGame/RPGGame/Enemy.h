#pragma once
#include "Character.h"
#include <vector>

class Enemy : public Character
{
public:
    Enemy() = default;

    void PushToVector(Enemy& enemy);

private:
    std::vector<Enemy> enemies;
};

