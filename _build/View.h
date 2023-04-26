#pragma once
#include <raylib.h>
#include "Enemy.h"
#include <vector>
#include "Ship.h"

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
	NIVEL2,
	NIVEL3,
	NIVEL_FINAL,
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
		void setCurrentScreen(GameScreen gs);
		GameScreen getCurrentScreen();
};




