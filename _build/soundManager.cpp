#include "soundManager.h"

SoundManager::SoundManager() {
	InitAudioDevice();

	//Cargar Pistas de audio
	this->startGame = LoadSound("resources/sound/inicio.wav");
	this->MusicaNivel1 = LoadMusicStream("resources/sound/bgMusic/nivel1.wav");
}

void SoundManager::playSoundStart() {
	PlaySound(this->startGame);
}

void SoundManager::playLvl1Music() {
	PlayMusicStream(this->MusicaNivel1);
	UpdateMusicStream(this->MusicaNivel1);
}

SoundManager::~SoundManager() {
	CloseAudioDevice();
}