#include "powerUP.h"

PowerUP::PowerUP(int screenWidth, int screenHeight) {

	int i = rand() % 3 + 1; // Tipo de Power UP RANDOM . 1 a 3
	int x = 20+rand() % screenWidth+1 -40; 
	int vel = rand() % 7 + 1;

	if (i == 1) {
		this->sprite = LoadTexture("resources/sprites/ui/player/powerUps/health.png");
		this->tipo = 1;
	}
	else if (i == 2) {
		this->sprite = LoadTexture("resources/sprites/ui/player/powerUps/damage.png");
		this->tipo = 2;
	}
	else {
		this->sprite = LoadTexture("resources/sprites/ui/player/powerUps/speed.png");
		this->tipo = 3;
	}
	
	this->pos.x = x;
	this->pos.y = -30;
	this->velocidad = vel;
	this->yLimit = screenHeight + 30;
	this->collisionBox.height = this->sprite.height;
	this->collisionBox.width = this->sprite.width;
	this->collisionBox.x = this->pos.x;
};

void PowerUP::printPowerUP(){
	this->pos.y += this->velocidad; //Hacemos que caiga
	DrawTextureV(this->sprite, this->pos, WHITE); //Mostramos
}

bool PowerUP::isOffScreen() {
	if (this->pos.y >= this->yLimit) return true;
	else return false;
}

PowerUP::~PowerUP() {
	UnloadTexture(this->sprite);
}

Rectangle PowerUP::getCollisionBox() {
	this->collisionBox.y = this->pos.y; //Actualiza valor Y - X es fijo
	return this->collisionBox;
}

int PowerUP::getTipo() {
	return this->tipo;
}