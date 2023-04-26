#pragma once
#include <raylib.h>
#include "Enemy.h"
#include <vector>
#include "Ship.h"
#include "Projectile.h"

// Para mostrar las diferentes escenas

typedef enum GameScreen
{
	LOGO = 0,
	TITLE,
	PROLOGUE,
	QUESTIONS,
	PREG1,
	PREG2,
	PREG3,
	NIVEL1,
	PRELVL1,
	POSTLVL1,
	PRELVL2,
	POSTLVL2,
	PRELVL3,
	POSTLVL3,
	PRELVLF,
	PRELVLF2,
	POSTLVLF,
	POSTLVLF2,
	POSTLVLF3,
	ENDING
} GameScreen;


class View
{	
	private:
		int screenWidth; //Se estaba usando 640
		int screenHeight; // x 576 
		int fps; //60
		char tituloJuego[50]; //
		GameScreen currentScreen;
	public: 
		//GameBG gameBG; da error de memoria - algo que ver con la carga de texturas
		//UI ui;
		View(int screenW, int screenH, int _fps, char titulo[]);
		void inicializarScreen();
		int getScreenWidth();
		int getScreenHeight();
		void printSpriteSheet(Texture2D texture, Rectangle rec, Vector2 v2);
		void printSprite(Texture2D texture, Vector2 pos, Color tint);
		void printProjectiles(std::vector<Projectile*> proyectiles);
		void printEnemigos(std::vector<Enemy*> listaEnemigos);
		void animarEnemies(std::vector<Enemy*> listaEnemigis);
		void animarProjectiles(std::vector<Projectile*> proyectiles);
		void moverProjectiles(std::vector<Projectile*> proyectiles);
		void setCurrentScreen(GameScreen gs);
		void transition(Color c);
		GameScreen getCurrentScreen();
};




