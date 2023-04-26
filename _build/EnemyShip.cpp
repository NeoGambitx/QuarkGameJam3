#include "EnemyShip.h"
// Problemas con libreria raylib ->#include <Windows.h>
#include <cstdlib>
#include <iostream>

// Viewport macros
#define VIEWPORT_HEIGHT 100
#define VIEWPORT_WIDTH 100

// Derived class constructor
EnemyShip::EnemyShip(int screenWidth, int screenHeight, int tipo)
{
	int x = 20 + rand() % screenWidth + 1 - 40;
	int vel = rand() % 5 + 1;
	this->WhereInYcross = rand() % screenHeight - 100;

	if (tipo == 1) { //Exploradora 
		this->damage = 20;
		this->health = 10;
		this->sprite = LoadTexture("resources/sprites/enemies/explorador.png");
		this->speed = 3;
		this->shootDelay = 0.9;
		this->isSuperBoss = false;
	}
	else if (tipo == 2) { // DEFENSA
		this->damage = 10;
		this->health = 30;
		this->sprite = LoadTexture("resources/sprites/enemies/CrabShip-sheet.png");
		this->speed = 2;
		this->shootDelay = 1.1;
		this->isSuperBoss = false;
	}
	else {
		this->damage = 50;
		this->health = 500;
		this->sprite = LoadTexture("resources/sprites/enemies/nodriza.png");
		this->speed = 1;
		this->shootDelay = 1.6;
		this->isSuperBoss = true;
	}

	this->position.x = x;
	this->position.y = -50;
	this->rec.width = this->sprite.width / 4;
	this->rec.height = this->sprite.height;
	this->rec.x = 0;
	this->rec.y = 0;
	this->frame = 0; // 4 Frames
	this->reloadTime = 0;
	this->screenLimit = screenHeight + 30;
	if (this->position.x <= screenWidth / 2) this->derecha = true; //Si esta del lado izq de la pantalla se cruza hacia la derecha
	else this->derecha = false; //Sino se cruza a la izquierda
	this->tipo = tipo;
	this->limitXotherShips = screenWidth;
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
	if (this->tipo == 1) {
		if (this->WhereInYcross >= this->position.y) {
			this->position.y += this->speed;
			if (derecha) this->position.x += this->speed;
			else this->position.x -= this->speed;
		}
		else this->position.y += this->speed;
	}
	else { //MOVIMIENTO DE DEFENSA Y NODRIZA
		if (this->position.y <= 80) this->position.y += this->speed; // se mueve hacia abajo hasta cierto punto
		if (derecha) { //Luego pasea de derecha a izquierda
			this->position.x += this->speed;
			if (this->position.x >= this->limitXotherShips) this->derecha = false;
		}
		else {
			this->position.x -= this->speed;
			if (this->position.x <= 30) this->derecha = true;
		}
		
		

	}
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

bool EnemyShip::isOffScreen() {
	if (this->position.y >= this->screenLimit) return true;
	else return false;
}

int EnemyShip::getDamage() {
	return this->damage;
}

bool EnemyShip::isTheSuperBoss() {
	return this->isSuperBoss;
}