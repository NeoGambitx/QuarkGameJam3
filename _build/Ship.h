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
	Vector2 mainShipPos;
	Rectangle mainShipRec;
	int playerSpeed;
	int mainShipframe;
	//Fin agregadas

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
	void animacion();
	void tookDamage(int damage);
};
