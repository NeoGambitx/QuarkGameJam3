#pragma once
#include "Enemy.h"
#include "ProjectileFactory.h"

class EnemyShip : public Enemy
{
public:
	EnemyShip();
	~EnemyShip();
	int getPositionX() override;
	void setPositionX(int posX) override;
	int getPositionY() override;
	void setPositionY(int posy) override;
	void shoot();
	void movementMechanics() override;
};