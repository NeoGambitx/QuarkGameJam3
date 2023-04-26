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
		return new EnemyShip(width, height, 1);
	case 2:
		return new EnemyObstacle(width, height);
	case 3:
		return new EnemyShip(width, height, 2);
	case 4:
		return new EnemyShip(width, height, 3);
	default:
		return nullptr;
	}
}