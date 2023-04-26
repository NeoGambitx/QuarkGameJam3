#include "Ship.h"

// Class constructor -  FEDE: Modifico -- Depende de la vista para ubicar inicialmente (diferente resolucion diferente POS)
Ship::Ship(int windowsWidth, int windowsHeight) {
	//Cargamos Otros Sprites
	this->standardShipFullHealth = LoadTexture("resources/sprites/player/mainShip100.png");
	this->standardShipDamaged = LoadTexture("resources/sprites/player/mainShip70.png");
	this->standardShipVeryDamaged = LoadTexture("resources/sprites/player/mainShip30.png");
	this->mainShipFullHealth = this->standardShipFullHealth;
	this->mainShipDamaged = this->standardShipDamaged;
	this->mainShipVeryDamaged = this->standardShipVeryDamaged;
	this->superShipFullHealth = LoadTexture("resources/sprites/player/novaShip.png");
	this->superShipDamaged = LoadTexture("resources/sprites/player/novaShip70.png");
	this->superShipVeryDamaged = LoadTexture("resources/sprites/player/novaShip30.png");
	this->health = 100;
	this->lives = 3;
	this->mainShipSprite = mainShipFullHealth;
	this->mainShipPos.x = windowsWidth / 2 - 32;
	this->mainShipPos.y = windowsHeight - 100;
	this->mainShipRec.width = mainShipSprite.width / 4;
	this->mainShipRec.height = mainShipSprite.height;
	this->mainShipRec.x = 0;
	this->mainShipRec.y = 0;
	this->playerSpeed = 3;
	this->mainShipframe = 0; // 4 Frames
	this->shootDelay = 1;

	this->originalPos.x = mainShipPos.x;
	this->originalPos.y = mainShipPos.y;
	this->limitX = windowsWidth;
	this->limitY = windowsHeight;
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
	this->mainShipSprite = mainShipFullHealth;
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

void Ship::setSpeed(int speed) {
	this->playerSpeed = speed;
}

void Ship::tookDamage(int damage) {
	if (damage >= this->health) {
		this->lives--;
		if (this->lives > 0) { 
			this->health = 100;
			this->mainShipSprite = this->mainShipFullHealth;
		}
		this->mainShipPos.x = this->originalPos.x;
		this->mainShipPos.y = this->originalPos.y;
	}
	else {
		this->health = this->health - damage;
		if (this->health > 70) {
			this->mainShipSprite = this->mainShipFullHealth;
		}
		else if (this->health > 40) {
			this->mainShipSprite = this->mainShipDamaged;
		}
		else {
			this->mainShipSprite = this->mainShipVeryDamaged;
		}
	}
	
	
	//Si health = 0 deberia restar 1 vida;
}

void Ship::moveDown() { //S arrow down
	if(this->mainShipPos.y < this->limitY-40) this->mainShipPos.y += this->playerSpeed;
}

void Ship::moveUp() { //W - arrow up
	if(this->mainShipPos.y >10) this->mainShipPos.y -= this->playerSpeed;
}

void Ship::moveRight() {//D - arrow right
	if(this->mainShipPos.x < this->limitX-40)this->mainShipPos.x += this->playerSpeed;
}

void Ship::moveLeft() { //A - arrow left
	if(this->mainShipPos.x > 10)this->mainShipPos.x -= this->playerSpeed;
}

float Ship::getShootDelay() {
	return this->shootDelay;
}

void Ship::setShootDelay(float delay) {
	this->shootDelay = delay;
}

Rectangle Ship::getCollisionBox() { //Toma los datos en tiempo real y devuelve el box de colision.
	this->collisionBox.x = this->mainShipPos.x;
	this->collisionBox.y = this->mainShipPos.y;
	this->collisionBox.width = this->mainShipRec.width;
	this->collisionBox.height = this->mainShipRec.height;
	return this->collisionBox;
}

bool Ship::doesItKillme(int damage) {
	if (damage >= this->health) {
		return true;
	}
	else {
		return false;
	}
}

void Ship::switchMainShip(bool super) {
	if (super) {
		this->mainShipFullHealth = this->superShipFullHealth;
		this->mainShipDamaged = this->superShipDamaged;
		this->mainShipVeryDamaged = this->superShipVeryDamaged;
		this->mainShipRec.height = this->mainShipFullHealth.height;
		this->mainShipRec.width = this->mainShipFullHealth.width / 4;
		this->mainShipSprite = mainShipFullHealth;
	}
	else {
		this->mainShipFullHealth = this->standardShipFullHealth;
		this->mainShipDamaged = this->standardShipDamaged;
		this->mainShipVeryDamaged = this->standardShipVeryDamaged;
		this->mainShipRec.height = this->mainShipFullHealth.height;
		this->mainShipRec.width = this->mainShipFullHealth.width / 4;
		this->mainShipSprite = mainShipFullHealth;
	}
}

// Class destructor
Ship::~Ship() {
	UnloadTexture(this->mainShipSprite);
	UnloadTexture(this->mainShipFullHealth);
	UnloadTexture(this->mainShipDamaged);
	UnloadTexture(this->mainShipVeryDamaged);
	UnloadTexture(this->superShipFullHealth);
	UnloadTexture(this->superShipDamaged);
	UnloadTexture(this->superShipVeryDamaged);
}