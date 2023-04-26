#include "Projectile.h"

// Class constructor
Projectile::Projectile(int posX, int posY)
{
	this->positionX = posX;
	this->positionY = posY;
}

// Class destructor
Projectile::~Projectile() {}

// Get the position of the projectile on the X axis
int Projectile::getPositionX()
{
	return this->positionX;
}

// Set the position of the projectile on the X axis
void Projectile::setPositionX(int newPosX)
{
	this->positionX = newPosX;
}

// Get the position of the projectile on the Y axis
int Projectile::getPositionY()
{
	return this->positionY;
}

// Set the position of the projectile on the Y axis
void Projectile::setPositionY(int newPosY)
{
	this->positionY = newPosY;
}