#pragma once
#include "Enemy.h"

class EnemyObstacle : public Enemy
{
public:
	EnemyObstacle();
	~EnemyObstacle();
	virtual void movementMechanics() override;
	virtual Texture2D getTexture() override;
	virtual Vector2 getPos() override;
	virtual Rectangle getRec() override;
	virtual void animacion() override;
	virtual Rectangle getCollisionBox() override;
	virtual bool doesItKillme(int damage) override;
	virtual void tookDamage(int damage) override;
	virtual bool canShoot() override;
};