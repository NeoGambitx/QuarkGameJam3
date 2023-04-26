#include "EnemyObstacle.h"
// Problemas con libreria raylib -> #include <Windows.h>
#include <cstdlib>
#include <iostream>

// Viewport macros
#define VIEWPORT_HEIGHT 100
#define VIEWPORT_WIDTH 100

// Derived Enemy class
EnemyObstacle::EnemyObstacle(int screenWidth, int screenHeight){

	int i = rand() % 3 + 1; // Tipo de Power UP RANDOM . 1 a 3
	int x = 20 + rand() % screenWidth + 1 - 40;
	int vel = rand() % 5 + 1;

	if (i == 1) {
		this->sprite = LoadTexture("resources/sprites/enemies/asteroid.png");
		this->damage = 0;
	}
	else if (i == 2) {
		this->sprite = LoadTexture("resources/sprites/enemies/asteroid2.png");
		this->damage = 0;
	}
	else {
		this->sprite = LoadTexture("resources/sprites/enemies/asteroidBig.png");
		this->damage = 30;
	}
	this->health = 10;
	this->position.x = x;
	this->position.y = -30;
	this->speed = vel;
	this->screenLimit = screenHeight + 30;
	this->rec.x = 0;
	this->rec.y = 0;
	this->rec.width = this->sprite.width;
	this->rec.height = this->sprite.height;

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

}


void EnemyObstacle::movementMechanics()
{
	this->position.y += this->speed;
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

bool EnemyObstacle::isOffScreen() {
	if (this->position.y >= this->screenLimit) return true;
	else return false;
}

int EnemyObstacle::getDamage() {
	return this->damage;
}