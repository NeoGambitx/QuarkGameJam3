#include "Characters.h"

Characters::Characters()
{
	mainCharacterImg = LoadTexture("resources/characters/mainCharacter.png");
	comandanteImg = LoadTexture("resources/characters/comandante.png");
	trainerImg = LoadTexture("resources/characters/trainer.png");
	comanPosPregResp.x = 500;
	comanPosPregResp.y = 200;
	izqArribaPos.x = 20;
	izqArribaPos.y = 20;

}

Characters::~Characters()
{
	UnloadTexture(mainCharacterImg);
	UnloadTexture(comandanteImg);
	UnloadTexture(trainerImg);
}