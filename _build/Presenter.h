#pragma once
//Librerías
#include <vector>
#include <raylib.h>;
#include <iostream>
#include <math.h>

//Clases propias
#include "EnemyFactory.h"
#include "Ship.h"
#include "Enemy.h"
#include "View.h"
#include "UI.h"
#include "soundManager.h"
#include "Ship.h"
#include "background.h"
#include "Story.h"
#include "Projectile.h"
#include "ProjectileFactory.h"
#include "explosion.h"
#include "powerUP.h"


class Presenter
{
private:
	Ship* ship;
	std::vector<Enemy* > enemyShips;
	std::vector<Enemy* > enemyObstacles;
	//prueba
	std::vector<Ship* > enemies;

public:
	Presenter();
	~Presenter();
	void startGame();
	void enterTransition();
	void shipMoved(int key);
	void shipDamaged();
	void shipDestroyed();
	void gameOver();
};
