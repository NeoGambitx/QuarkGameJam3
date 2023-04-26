#pragma once
#include <raylib.h>
#include <vector>

class GameBG {

	private:
	//Texture2D bgNivel1;
	//Vector2 bgPos;
	Texture2D bgNivel1;
	Texture2D bgNivel2;
	Texture2D bgNivel3;
	Texture2D bgFinal;
	Vector2 bg2Pos; //Repite para efecto infinito
	std::vector <Texture2D> bgNivel;
	float bgY;

	public:
		~GameBG();
		GameBG();
		Vector2 bgPos;
		Texture2D introBg;
		void pintarBg(int index, float dt);
		void switchBG(int queBg);
};


