#pragma once
#include <raylib.h>
#include <vector>

class GameBG {

	private:
	//Texture2D bgNivel1;
	Vector2 bgPos;
	Vector2 bg2Pos; //Repite para efecto infinito
	std::vector <Texture2D> bgNivel;
	float bgY;

	public:
		~GameBG();
		GameBG();
		void pintarBg(int index, float dt);
};


