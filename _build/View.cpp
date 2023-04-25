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

void View::printProjectiles(std::vector<Projectile*> p){
	for (int i = 0; i < p.size(); i++) {
		DrawTexturePro(p[i]->getTexture(), p[i]->getRec(), p[i]->getPositionAndScale(), p[i]->getCenter(),
			p[i]->getRot(), WHITE);
	}
}

void View::animarProjectiles(std::vector<Projectile*> p) {
	for (int i = 0; i < p.size(); i++) {		
		p[i]->animacion();
	}
}

void View::moverProjectiles(std::vector<Projectile*> p) {
	for (int i = 0; i < p.size(); i++) {
		p[i]->mover();
	}
}

void View::printEnemigos(std::vector<Enemy*> listaEnemigos) {
	for (int i = 0; i < listaEnemigos.size(); i++) {
		DrawTextureRec(listaEnemigos[i]->getTexture(), listaEnemigos[i]->getRec(), listaEnemigos[i]->getPos(), WHITE);
	}
}

void View::animarEnemies(std::vector<Enemy*> listaEnemigos) {
	for (int i = 0; i < listaEnemigos.size(); i++) {
		listaEnemigos[i]->animacion();
	}
}

void View::printSprite(Texture2D sprite, Vector2 pos, Color tint) {
	DrawTextureV(sprite, pos, tint);
}

void View::transition(Color c) {
	DrawRectangle(0, 0, this->screenWidth, this->screenHeight, c);
}
/*void View::moverEnemies(std::vector<Enemy*> listaEnemigos) {
	for (int i = 0; i < listaEnemigos.size(); i++) {
		listaEnemigos[i]->mover();
	}
}*/