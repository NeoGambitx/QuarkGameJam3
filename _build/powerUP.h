#pragma once

#include <raylib.h>
#include <stdlib.h>

class PowerUP {

private:
	Texture2D sprite;
	Vector2 pos;
	int velocidad;
	int tipo; //1 = HEALTH - 2 = POWER - 3 = SPEED
	int yLimit; //Si pasa este numero la posicion Y - Esta fuera de pantalla
	Rectangle collisionBox;

public:
	PowerUP(int screenWidth, int screenHeight); // Random entre 3 tipos
	void printPowerUP();
	bool isOffScreen();
	~PowerUP();
	Rectangle getCollisionBox();
	int getTipo();
};