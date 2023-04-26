#include "soundManager.h"

SoundManager::SoundManager() {
	InitAudioDevice();

	//Cargar Pistas de audio
	//Musica
	this->MusicaNivel1 = LoadMusicStream("resources/sound/bgMusic/nivel1.wav");
	this->MusicaNivel2 = LoadMusicStream("resources/sound/bgMusic/nivel2.mp3");
	this->MusicaNivel3 = LoadMusicStream("resources/sound/bgMusic/nivel3.mp3");
	this->Prologo = LoadMusicStream("resources/sound/bgMusic/Prologo.mp3");
	this->Menu = LoadMusicStream("resources/sound/bgMusic/Menu.mp3");
	this->Epilogo = LoadMusicStream("resources/sound/bgMusic/epilogo.mp3");
	this->Dialog = LoadMusicStream("resources/sound/bgMusic/Dialog.mp3");
	this->MusicaBoss = LoadMusicStream("resources/sound/bgMusic/BossFight.mp3");

	//Effectos de Sonido MP y Victoria
	this->startGame = LoadSound("resources/sound/inicio.wav");
	this->victory = LoadSound("resources/sound/victory.mp3");
	this->select = LoadSound("resources/sound/select.mp3");
	this->gameOver = LoadSound("resources/sound/gameOver.mp3");

	//Effectos Sonidos extra
	this->enemyShoot = LoadSound("resources/sound/effects/enemyShoot.wav");
	this->explosion = LoadSound("resources/sound/effects/explosion.mp3");
	this->FinalExplosion = LoadSound("resources/sound/effects/explosionFinal.mp3");
	this->damage = LoadSound("resources/sound/effects/gotDamage.mp3");
	this->kamikaze = LoadSound("resources/sound/effects/kamikaze.mp3");
	this->normalShoot = LoadSound("resources/sound/effects/normalShoot.mp3");
	this->powerUP = LoadSound("resources/sound/effects/powerUp.wav");
	this->superCanonShoot = LoadSound("resources/sound/effects/SuperCannonShot.mp3");
	this->superShoot = LoadSound("resources/sound/effects/superShoot.mp3");
}


//MUSICA 
void SoundManager::playLvl1Music() {
	PlayMusicStream(this->MusicaNivel1);
	UpdateMusicStream(this->MusicaNivel1);
}

void SoundManager::playLvl2Music() {
	PlayMusicStream(this->MusicaNivel2);
	UpdateMusicStream(this->MusicaNivel2);
}

void SoundManager::playLvl3Music() {
	PlayMusicStream(this->MusicaNivel3);
	UpdateMusicStream(this->MusicaNivel3);
}

void SoundManager::playBossMusic() {
	PlayMusicStream(this->MusicaBoss);
	UpdateMusicStream(this->MusicaBoss);
}

void SoundManager::playDialogMusic() {
	PlayMusicStream(this->Dialog);
	UpdateMusicStream(this->Dialog);
}

void SoundManager::playEpilogueMusic() {
	PlayMusicStream(this->Epilogo);
	UpdateMusicStream(this->Epilogo);
}

void SoundManager::playMenuMusic() {
	PlayMusicStream(this->Menu);
	UpdateMusicStream(this->Menu);
}

void SoundManager::playPrologueMusic() {
	PlayMusicStream(this->Prologo);
	UpdateMusicStream(this->Prologo);
}


//SOUND EFFECTS 
void SoundManager::playSoundStart() {
	PlaySound(this->startGame);
}

void SoundManager::playSoundSelect() {
	PlaySound(this->select);
}

void SoundManager::playSoundVictory() {
	PlaySound(this->victory);
}

void SoundManager::playSoundEnemyShoot() {
	PlaySound(this->enemyShoot);
}

void SoundManager::playSoundExplosion() {
	PlaySound(this->explosion);
}

void SoundManager::playSoundFinalExplosion() {
	PlaySound(this->FinalExplosion);
}

void SoundManager::playSoundDamage() {
	PlaySound(this->damage);
}

void SoundManager::playSoundKamikaze() {
	PlaySound(this->kamikaze);
}

void SoundManager::playSoundShoot() {
	PlaySound(this->normalShoot);
}

void SoundManager::playSoundPowerUP() {
	PlaySound(this->powerUP);
}

void SoundManager::playSoundSuperCannonShoot() {
	PlaySound(this->superCanonShoot);
}

void SoundManager::playSoundMegaShoot() {
	PlaySound(this->superShoot);
}

void SoundManager::playGameOverSound() {
	PlaySound(this->gameOver);
}

SoundManager::~SoundManager() {
	CloseAudioDevice();
	//UnloadMusic
	UnloadMusicStream(MusicaNivel1);
	UnloadMusicStream(MusicaNivel2);
	UnloadMusicStream(MusicaNivel3);
	UnloadMusicStream(Prologo);
	UnloadMusicStream(Menu);
	UnloadMusicStream(Epilogo);
	UnloadMusicStream(Dialog);
	UnloadMusicStream(MusicaBoss);
	//UnloadSounds
	UnloadSound(startGame);
	UnloadSound(victory);
	UnloadSound(select);
	UnloadSound(enemyShoot);
	UnloadSound(explosion);
	UnloadSound(FinalExplosion);
	UnloadSound(damage);
	UnloadSound(kamikaze);
	UnloadSound(normalShoot);
	UnloadSound(powerUP);
	UnloadSound(superCanonShoot);
	UnloadSound(superShoot);
}

