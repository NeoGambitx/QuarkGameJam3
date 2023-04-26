#include "View.h"
#include <string.h>

void View::inicializarScreen(){
	InitWindow(this->screenWidth, this->screenHeight, this->tituloJuego); //inicia la ventana de raylib 
	SetTargetFPS(this->fps);
}

View::View(int screenW, int screenH, int _fps, char titulo[]){//ui(screenW, screenH),gameBG() 
	this->screenWidth = screenW;
	this->screenHeight = screenH;
	this->fps = _fps;
	strcpy(this->tituloJuego, titulo);
	this->currentScreen = LOGO;
}

int View::getScreenWidth() {
	return this->screenWidth;
}

int View::getScreenHeight() {
	return this->screenHeight;
}


void View::printSpriteSheet(Texture2D texture, Rectangle rec, Vector2 v2 ) {
	DrawTextureRec(texture, rec, v2, WHITE);
}

GameScreen View::getCurrentScreen() {
	return this->currentScreen;
}

void View::setCurrentScreen(GameScreen gs) {
	this->currentScreen = gs;
}
