#include "Ship.h"

// Class constructor -  FEDE: Modifico -- Depende de la vista para ubicar inicialmente (diferente resolucion diferente POS)
Ship::Ship(int windowsWidth, int windowsHeight) {
	this->health = 100;
	this->lives = 3;
	this->mainShipSprite = LoadTexture("resources/sprites/player/mainShipFH.png");
	this->mainShipPos.x = windowsWidth / 2 - 32;
	this->mainShipPos.y = windowsHeight - 100;
	this->mainShipRec.width = mainShipSprite.width / 4;
	this->mainShipRec.height = mainShipSprite.height;
	this->mainShipRec.x = 0;
	this->mainShipRec.y = 0;
	this->playerSpeed = 2;
	this->mainShipframe = 0; // 4 Frames
}

// Class destructor
Ship::~Ship() {
	UnloadTexture(this->mainShipSprite);
}

// Get ship health
int Ship::getHealth()
{
	return this->health;
}

// Set ship health
void Ship::setHealth(int newHealth)
{
	this->health = newHealth;
}

// Get ship lives
int Ship::getLives()
{
	return this->lives;
}

// Set ship lives
void Ship::setLives(int newLives)
{
	this->lives = newLives;
}

// Get the position of the ship -- MODIFICADO devuelve VECTOR
Vector2 Ship::getPosition()
{
	return this->mainShipPos;
}

// Set the position of the ship
void Ship::setPosition(Vector2 newPosition)
{
	this->mainShipPos = newPosition;
}

// Shoot weapon
void Ship::shoot()
{
	// Llamar al ProjectileFactory
}

// Agregados ▼ ▼
Texture2D Ship::getTexture() {
	return this->mainShipSprite;
}

Rectangle Ship::getRec() {
	return this->mainShipRec;
}

void Ship::animacion() {
	this->mainShipRec.x = this->mainShipframe * this->mainShipRec.width;
	this->mainShipframe++;
	//Volvemos al 1er Frame de animación
	if (this->mainShipframe > 4) {
		this->mainShipframe = 0;
	}
}

int Ship::getSpeed() { //Probablemente innecesaria, solo para probar movimiento y colisiones
	return this->playerSpeed;
}

void Ship::tookDamage(int damage) {
	if (damage > this->health) {
		this->health = 0;
	}
	else {
		this->health = this->health - damage;
	}
	
	
	//Si health = 0 deberia restar 1 vida;
}