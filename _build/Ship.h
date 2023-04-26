#pragma once
#include "View.h"
#include <raylib.h>


class Ship
{
private:
	int health; // = 100 - Modifico, valor iniciado en constructor
	int lives; //= 3 igual a health
	// int position; comento var -> la posicion es en Vector2 (coordenadas)
	//Fede > Variables - Agregadas ▼ ▼ ▼
	Texture2D mainShipSprite;
	Texture2D mainShipFullHealth;
	Texture2D mainShipDamaged;
	Texture2D mainShipVeryDamaged;
	//LEVEL 3 SHIP
	Texture2D superShipFullHealth;
	Texture2D superShipDamaged;
	Texture2D superShipVeryDamaged;
	Vector2 mainShipPos;
	Rectangle mainShipRec;
	Rectangle collisionBox;
	int playerSpeed;
	int mainShipframe;
	Vector2 originalPos;
	//Fin agregadas
	float shootDelay;
	int limitX;
	int limitY;

public:
	Ship(int windowsWidth, int windowsHeight);
	~Ship();
	int getHealth();
	void setHealth(int newHealth);
	int getLives();
	void setLives(int newNumberOfLives);
	void shoot();
	//Agregados - Modificados
	Vector2 getPosition(); //Modificados 2 getter y setter
	void setPosition(Vector2 newPosition);
	Texture2D getTexture();
	Rectangle getRec();
	int getSpeed(); //Declarado para hacer pruebas de colisiones
	void setSpeed(int speed);
	void animacion();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void tookDamage(int damage);
	float getShootDelay();
	void setShootDelay(float delay);
	Rectangle getCollisionBox();
	bool doesItKillme(int damage);
};
