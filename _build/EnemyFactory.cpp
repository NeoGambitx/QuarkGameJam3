#include "EnemyFactory.h"
#include "EnemyShip.h"
#include "EnemyObstacle.h"

EnemyFactory::EnemyFactory() {}

EnemyFactory::~EnemyFactory() {}

Enemy* EnemyFactory::createEnemy(int enemyType, int width, int height)
{
	int option = enemyType;

	switch (option)
	{
	case 1:
		return new EnemyShip(width, height);
	case 2:
		return new EnemyObstacle;
	default:
		return nullptr;
	}
}