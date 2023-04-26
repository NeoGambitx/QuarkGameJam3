#pragma once
#include <raylib.h>
class Enemy
{
protected:
	int health; // = 100 - Modifico, valor iniciado en constructor
	int damage;
	Texture2D sprite;
	Vector2 position;
	Rectangle rec;
	Rectangle collisionBox;
	int speed;
	int frame;
	float shootDelay;
	int screenLimit;

public:
	Enemy() {}
	//virtual ~Enemy() = 0;
	virtual void movementMechanics() = 0;
	virtual Texture2D getTexture() = 0;
	virtual Vector2 getPos() = 0;
	virtual Rectangle getRec() = 0;
	virtual void animacion() = 0;
	virtual Rectangle getCollisionBox() = 0;
	virtual bool doesItKillme(int damage) = 0;
	virtual void tookDamage(int damage) = 0;
	virtual bool canShoot() = 0;
	virtual bool isOffScreen() = 0;
	virtual int getDamage() = 0;
	virtual bool isTheSuperBoss() = 0;
};