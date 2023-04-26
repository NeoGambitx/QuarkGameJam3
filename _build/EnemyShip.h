#pragma once
#include "Enemy.h"
#include "ProjectileFactory.h"

class EnemyShip : public Enemy
{
private:
	int WhereInYcross;
	bool derecha;
	int reloadTime;
public:
	EnemyShip(int screenWidth, int screenHeight);
	~EnemyShip();
	void shoot();
	void movementMechanics() override;
	virtual Texture2D getTexture() override;
	virtual Vector2 getPos() override;
	virtual Rectangle getRec() override;
	virtual void animacion() override;
	virtual Rectangle getCollisionBox() override;
	virtual bool doesItKillme(int damage) override;
	virtual void tookDamage(int damage) override;
	bool canShoot();
	bool isOffScreen();
	int getDamage();
};