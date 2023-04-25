#pragma once
#include <raylib.h>

class Projectile
{
private:
	//Texture2D superShootEnemySprite;
	Texture2D projectileSprite; // 1 - Disparo Normal - 2 - Super Disparo, etc.
	Rectangle projectileRec;
	Rectangle PositionAndScale;
	Vector2 center;
	Vector2 projectilePos;
	int projectileSpeed; // Ver distintas velocidades
	int projectileFrame;
	bool isAnEnemyShoot; //True == Enemigo disparando 
	float projectileRotation;
	int index;
	int damage;

public:
	Projectile(int claseDeProjectil, int indice, Vector2 Pos, float rotation, bool isAnEnemyShoot);
	~Projectile();
	void animacion();
	Texture2D getTexture();
	Rectangle getRec();
	Rectangle getPositionAndScale();
	Vector2 getPos();
	Vector2 getCenter();
	float getRot();
	void mover();
	int getDamageDone();
	bool isEnemyShoot();
	bool isOutOfBounds(int screenWidth, int screenHeight);
};