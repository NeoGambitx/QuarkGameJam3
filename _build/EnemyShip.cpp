#include "EnemyShip.h"
// Problemas con libreria raylib ->#include <Windows.h>
#include <cstdlib>
#include <iostream>

// Viewport macros
#define VIEWPORT_HEIGHT 100
#define VIEWPORT_WIDTH 100

// Derived class constructor
EnemyShip::EnemyShip(int screenWidth, int screenHeight)
{
	int x = 20 + rand() % screenWidth + 1 - 40;
	int vel = rand() % 5 + 1;
	this->WhereInYcross = rand() % screenHeight - 100;

	this->damage = 10;
	this->health = 10;
	this->sprite = LoadTexture("resources/sprites/enemies/explorador.png");
	this->position.x = x;
	this->position.y = -50;
	this->rec.width = this->sprite.width / 4;
	this->rec.height = this->sprite.height;
	this->rec.x = 0;
	this->rec.y = 0;
	this->speed = 2;
	this->frame = 0; // 4 Frames
	this->shootDelay = 1;
	this->reloadTime = 0;

	if (this->position.x <= screenWidth / 2) this->derecha = true; //Si esta del lado izq de la pantalla se cruza hacia la derecha
	else this->derecha = false; //Sino se cruza a la izquierda
}

// Derived class destructor
EnemyShip::~EnemyShip() {
	UnloadTexture(this->sprite);
}



Vector2 EnemyShip::getPos()
{
	return this->position;
}

Rectangle EnemyShip::getRec() {
	return this->rec;
}

Texture2D EnemyShip::getTexture() {
	return this->sprite;
}

void EnemyShip::animacion() {
	this->rec.x = this->frame * this->rec.width;
	this->frame++;
	//Volvemos al 1er Frame de animación
	if (this->frame > 4) {
		this->frame = 0;
	}
}



// Shoot
void EnemyShip::shoot()
{
	// Call ProjectileFactory
}


// Movement mechanics
void EnemyShip::movementMechanics()
{
	if (this->WhereInYcross >= this->position.y) {
		this->position.y += this->speed;
		if (derecha) this->position.x += this->speed;
		else this->position.x -= this->speed;
	}
	else this->position.y += this->speed;
}



Rectangle EnemyShip::getCollisionBox() {
	this->collisionBox.x = this->position.x;
	this->collisionBox.y = this->position.y;
	this->collisionBox.width = this->rec.width;
	this->collisionBox.height = this->rec.height;
	return this->collisionBox;
}

bool EnemyShip::doesItKillme(int damage) {
	if (damage >= this->health) {
		return true;
	}
	else {
		return false;
	}
}

void EnemyShip::tookDamage(int damage) {
	this->health -= damage;
}

bool EnemyShip::canShoot() {
	if (this->reloadTime/60 >= this->shootDelay) {
		this->reloadTime = 0;
		return true;
	}
	else { 
		this->reloadTime++;
		return false;
	}
}