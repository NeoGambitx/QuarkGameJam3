#include "EnemyObstacle.h"
// Problemas con libreria raylib -> #include <Windows.h>
#include <cstdlib>
#include <iostream>

// Viewport macros
#define VIEWPORT_HEIGHT 100
#define VIEWPORT_WIDTH 100

// Derived Enemy class
EnemyObstacle::EnemyObstacle()
{
	this->damage = 30;
	this->health = 10;
}

// Derived class destructor
EnemyObstacle::~EnemyObstacle() {}

// Get enemy position
Vector2 EnemyObstacle::getPos()
{
	return this->position;
}

Texture2D EnemyObstacle::getTexture() {
	return this->sprite;
}

Rectangle EnemyObstacle::getRec() {
	return this->rec;
}

void EnemyObstacle::animacion() {
	this->rec.x = this->frame * this->rec.width;
	this->frame++;
	//Volvemos al 1er Frame de animación
	if (this->frame > 4) {
		this->frame = 0;
	}
}


void EnemyObstacle::movementMechanics()
{
	srand((unsigned)time(NULL));

	// Necessary values
	int displacement = 0;
	const int randomXPosition = rand() % VIEWPORT_WIDTH;

	//Set position on X axis
	//this->setPositionX(randomXPosition);

	// Movement
	while (displacement <= VIEWPORT_HEIGHT)
	{
		//this->setPositionY(VIEWPORT_HEIGHT - displacement);
		//Sleep(1);
	}
}

Rectangle EnemyObstacle::getCollisionBox() {
	this->collisionBox.x = this->position.x;
	this->collisionBox.y = this->position.y;
	this->collisionBox.width = this->rec.width;
	this->collisionBox.height = this->rec.height;
	return this->collisionBox;
}

bool EnemyObstacle::doesItKillme(int damage) {
	if (damage >= this->health) {
		return true;
	}
	else {
		return false;
	}
}

void EnemyObstacle::tookDamage(int damage) {
	this->health -= damage;
}

bool EnemyObstacle::canShoot() {
	return false;
}