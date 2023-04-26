#include "EnemyShip.h"
// Problemas con libreria raylib ->#include <Windows.h>
#include <cstdlib>
#include <iostream>

// Viewport macros
#define VIEWPORT_HEIGHT 100
#define VIEWPORT_WIDTH 100

// Derived class constructor
EnemyShip::EnemyShip()
{
	this->damage = 10;
	this->health = 10;
}

// Derived class destructor
EnemyShip::~EnemyShip() {}

// Set enemy ship position
void EnemyShip::setPositionX(int posx)
{
	this->positionX = posx;
}

void EnemyShip::setPositionY(int posy)
{
	this->positionY = posy;
}

// Get enemy position
int EnemyShip::getPositionX()
{
	return this->positionX;
}

int EnemyShip::getPositionY()
{
	return this->positionY;
}

// Shoot
void EnemyShip::shoot()
{
	// Call ProjectileFactory
}

// Movement mechanics
void EnemyShip::movementMechanics()
{
	srand((unsigned)time(NULL));

	// Necessary values
	int displacement = 0;
	const int randomXPosition = rand() % VIEWPORT_WIDTH;

	// Set position on X axis
	this->setPositionX(randomXPosition);

	// Movement
	while (displacement <= VIEWPORT_HEIGHT)
	{
		this->setPositionY(VIEWPORT_HEIGHT - displacement);
		//Sleep(1);
	}
}