#include "Projectile.h"

// Class constructor
Projectile::Projectile(int claseDeProjectil, int indice, Vector2 Pos, float rotation, bool _isAnEnemyShoot)
{
		
	switch (claseDeProjectil)
	{
	case 1: {

		this->projectileSprite = LoadTexture("resources/sprites/fire/normalShoot.png");
		this->projectileSpeed = 5;
		this->damage = 10;
		this->projectileRec.width = projectileSprite.width / 3; //3 Frames normal Shot

	}break;
	case 2: {
		this->projectileSprite = LoadTexture("resources/sprites/fire/enemyShoot.png");
		this->projectileSpeed = 5;
		this->damage = 10;
		this->projectileRec.width = projectileSprite.width / 4;
	}break;
	case 3: {
		this->projectileSprite = LoadTexture("resources/sprites/fire/pulse.png");
		this->projectileSpeed = 7;
		this->damage = 30;
		this->projectileRec.width = projectileSprite.width / 4;
	}break;
	default:
		break;
	}
	this->projectilePos.x = Pos.x;
	this->projectilePos.y = Pos.y;
	this->PositionAndScale.x = Pos.x + 17; //Valor Fijo por las dimensiones de la NAVE
	this->PositionAndScale.y = Pos.y-5; //LO mismo de arriba 
	this->PositionAndScale.height = this->projectileSprite.height;
	this->PositionAndScale.width = this->projectileSprite.width/4;
	this->center.x = this->PositionAndScale.width / 2;
	this->center.y = this->PositionAndScale.height / 2;
	this->isAnEnemyShoot = _isAnEnemyShoot;
	this->projectileFrame = 0;
	this->projectileRec.height = projectileSprite.height;
	this->projectileRec.x = 0;
	this->projectileRec.y = 0;
	this-> projectileRotation = rotation;
	this->index = indice;
}


void Projectile::animacion() {
	this->projectileRec.x = this->projectileFrame * this->projectileRec.width;
	this->projectileFrame++;
	//Volvemos al 1er Frame de animación
	if (this->projectileFrame > 4) {
		this->projectileFrame = 0;
	}
}

Rectangle Projectile::getPositionAndScale() {
	return this->PositionAndScale;
}

Texture2D Projectile::getTexture() {
	return this->projectileSprite;
}

Rectangle Projectile::getRec() {
	return this->projectileRec;
}

Vector2 Projectile::getCenter() {
	return this->center;
}

Vector2 Projectile::getPos() {
	return this->projectilePos;
}

float Projectile::getRot() {
	return this->projectileRotation;
}

void Projectile::mover() {
	if (this->isAnEnemyShoot) {
		//this->projectilePos.y += this->projectileSpeed;
		this->PositionAndScale.y += this->projectileSpeed;
		
	}
	else {
		//this->projectilePos.y -= this->projectileSpeed;
		this->PositionAndScale.y -= this->projectileSpeed;
	}
	
}

int Projectile::getDamageDone() {
	return this->damage;
}

bool Projectile::isEnemyShoot() {
	return this->isAnEnemyShoot;
}

bool Projectile::isOutOfBounds(int screenWidth, int screenHeight) {
	if (this->PositionAndScale.x < -5 || this->PositionAndScale.x > screenWidth + 10) return true;
	else if (this->PositionAndScale.y < -5 || this->PositionAndScale.y > screenHeight + 10) return true;
	else return false;
}

// Class destructor
Projectile::~Projectile() {
	UnloadTexture(this->projectileSprite);
}