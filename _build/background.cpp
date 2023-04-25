#include "background.h"

GameBG::GameBG() {
	Texture2D bgNivel1 = LoadTexture("resources/sprites/map/blueNebula.png");
	this->bgNivel.push_back(bgNivel1);
	this->bgY = 0;
	this->bgPos.x = 0.0;
	this->bgPos.y = 0.0;
	this->bg2Pos = this->bgPos;
}

GameBG::~GameBG() {
	for (int i = 0; i < this->bgNivel.size(); i++)
	{
		UnloadTexture(this->bgNivel[i]);
	}
}

void GameBG::pintarBg(int index, float dt) {
	//Codigo Fondo - BG
	this->bgY += 100 * dt;
	if (bgY >= this->bgNivel[index].height)
	{
		bgY = 0.0;
	}
	// Pintamos Fondo
	this->bgPos.x = 0.0;
	this->bgPos.y = this->bgY;

	DrawTextureEx(this->bgNivel[index], this->bgPos, 0, 1, WHITE);
	// Segundo Fondo para repetir en bucle
	this->bg2Pos.x = 0.0;
	this->bg2Pos.y = this->bgY - this->bgNivel[index].height;
	
	DrawTextureEx(this->bgNivel[index], bg2Pos, 0.0, 1, WHITE);
	// ▲ ▲ ▲ Fin fondo
};
