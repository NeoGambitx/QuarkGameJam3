#pragma once
#include <raylib.h>
#include <vector>

class Characters
{
public:
	Texture2D mainCharacterImg;
	Texture2D comandanteImg;
	Texture2D trainerImg;
	Vector2 izqArribaPos;
	Vector2 comanPosPregResp;
	Characters();
	~Characters();

};

