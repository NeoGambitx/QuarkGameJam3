#include "UI.h"

UI::UI(int screenW, int screenH) {

    // > Menu Principal Botones
    this->quarkLogo = LoadTexture("resources/sprites/ui/menuP/gameJam.png");
    this->quarkLogoPos.x = screenW/2 - this->quarkLogo.width/2 -20;
    this->quarkLogoPos.y = screenH/2 - this->quarkLogo.height/2;
    this->menuPbg = LoadTexture("resources/sprites/ui/menuP/background.png");
    this->playButton = LoadTexture("resources/sprites/ui/menuP/playbutton.png");
    this->playButtonPress = LoadTexture("resources/sprites/ui/menuP/playbuttonPressed.png");
    this->salirBtn = LoadTexture("resources/sprites/ui/menuP/salirBtn.png");
    this->salirBtnPress = LoadTexture("resources/sprites/ui/menuP/salirBtnPress.png");
    this->playBtnPos.x = screenW/2 - playButton.width;
    this->playBtnPos.y = screenH/2 - playButton.height/2;
    this->salirBtnPos.x = playBtnPos.x;
    this->salirBtnPos.y = playBtnPos.y + 100;
    this->pointer = LoadTexture("resources/sprites/ui/menuP/pointer.png");

    // > UI Player
    this->marcoVida = LoadTexture("resources/sprites/ui/player/vida/marcoVida.png");
    this->barraVida = LoadTexture("resources/sprites/ui/player/vida/barrasVida.png");

    // > UI Marco - BarraVida / 2 Frames - Normal y titilando para mostrar daño
    this->marcoVidaPos.x = screenW / 15;
    this->marcoVidaPos.y = screenH - 120;
    this->marcoVidaRec.width = this->marcoVida.width / 2; //2 Frames
    this->marcoVidaRec.height = this->marcoVida.height;
    this->marcoVidaRec.x = 0;
    this->marcoVidaRec.y = 0;
    this->marcoVidaFrame = 0;

    // > UI - Barras de VIDA variables // 11 frames - Vacio (muerte) 10 barras %
    this->barraVidaPos.x = screenW / 15 - 1;
    this->barraVidaPos.y = screenH - 120;
    this->barraVidaRec.width = barraVida.width / 11; //11 Frames
    this->barraVidaRec.height = barraVida.height;
    this->barraVidaRec.x = 0;
    this->barraVidaRec.y = 0;
    this->barraVidaFrame = 0;

    // UI - LIVES
    this->lives = LoadTexture("resources/sprites/ui/player/vida/lives.png");
    this->livesPos.x = screenW /15;
    this->livesPos.y = screenH - 60;
    this->livesRec.width = this->lives.width / 3;
    this->livesRec.height = this->lives.height;
    this->livesRec.x = 0;
    this->livesRec.y = 0;
    this->livesFrame = 0;
}

void UI::menuPbotonPlay() {
    DrawTextureEx(this->playButton, this->playBtnPos, 0.0, 2, WHITE);
}

void UI::menuPbotonSalir() {
    DrawTextureEx(this->salirBtn, this->salirBtnPos, 0.0, 2, WHITE);
}

void UI::MarcoVida() {
    DrawTextureRec(this->marcoVida, this->marcoVidaRec, this->marcoVidaPos, WHITE);
}

void UI::vidaActual(int vida) {
    int x = 10;
    if (vida == 100) x = 0;
    else if (vida >= 90 && vida < 100) x = 1;
    else if (vida >= 80) x = 2;
    else if (vida >= 70) x = 3;
    else if (vida >= 60) x = 4;
    else if (vida >= 50) x = 5;
    else if (vida >= 40) x = 6;
    else if (vida >= 30) x = 7;
    else if (vida >= 20) x = 8;
    else if (vida >= 1) x = 9;
    else if (vida == 0) x = 10;
    this->barraVidaRec.x = x * this->barraVidaRec.width;
    DrawTextureRec(this->barraVida, this->barraVidaRec, this->barraVidaPos, WHITE);
}

void UI::printLogo() {
    DrawTextureV(this->quarkLogo, this->quarkLogoPos, WHITE);
}

void UI::printMenuPBg() {
    DrawTexture(this->menuPbg, 0, 0, WHITE);
}

void UI::printPointer(int opcion) {
    if (opcion == 1) {
        DrawTexture(this->pointer, this->playBtnPos.x - 30, this->playBtnPos.y + 30, WHITE);
    }
    else {
        DrawTexture(this->pointer, this->salirBtnPos.x - 30, this->salirBtnPos.y + 30, WHITE);
    }
}

void UI::printLives(int lives) {
    if (lives == 3) this->livesRec.x = 2 * this->livesRec.width;
    else if(lives == 2) this->livesRec.x = 1 * this->livesRec.width;
    else this->livesRec.x = 0 * this->livesRec.width;
    DrawTextureRec(this->lives, this->livesRec, this->livesPos, WHITE);
}