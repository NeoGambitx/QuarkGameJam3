#include "explosion.h"

Explosion::Explosion(Vector2 pos, bool tipo) {
	if (tipo) {
		this->sprite = LoadTexture("resources/sprites/fire/explosion1.png");
		this->rec.width = sprite.width / 10; //dividido frames
	}
	else {
		this->sprite = LoadTexture("resources/sprites/fire/explosion2.png");
		this->rec.width = sprite.width / 4; //dividido frames
	}
	this->position = pos;
	this->rec.width = sprite.width / 10; //dividido frames
	this->rec.height = sprite.height;
	this->rec.y = 0;
	this->rec.x = 0;
	this->frame = 0;
	this->done = false;
}

void Explosion::mostrarExplosion() {
	DrawTextureRec(this->sprite, this->rec, this->position, WHITE);
}

void Explosion::animar() {
	this->rec.x = this->frame * this->rec.width;
	this->frame++;
	//Volvemos al 1er Frame de animación
	if (this->frame > 10) {
		this->done = true;
		this->frame = 0;
	}
}

bool Explosion::isItDone(){
	return this->done;
}