#pragma once
#include "Enemy.h"

class EnemyObstacle : public Enemy
{
public:
	EnemyObstacle();
	~EnemyObstacle();
	int getPositionX() override;
	void setPositionX(int posX) override;
	int getPositionY() override;
	void setPositionY(int posy) override;
	void movementMechanics() override;
};