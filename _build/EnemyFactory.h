#pragma once
#include "Enemy.h"
#include "View.h"

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	Enemy* createEnemy(int enemyType, int width, int height);
};
