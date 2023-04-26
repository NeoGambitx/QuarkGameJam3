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

// Set enemy ship position
void EnemyObstacle::setPositionX(int posx)
{
	this->positionX = posx;
}

void EnemyObstacle::setPositionY(int posy)
{
	this->positionY = posy;
}

// Get enemy position
int EnemyObstacle::getPositionX()
{
	return this->positionX;
}

int EnemyObstacle::getPositionY()
{
	return this->positionY;
}

void EnemyObstacle::movementMechanics()
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