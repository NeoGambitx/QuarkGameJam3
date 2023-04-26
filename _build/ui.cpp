#include "UI.h"

UI::UI(int screenW, int screenH) {

    // > Menu Principal Botones
    this->playBtnPos.x = screenW / 2 - 100;
    this->playBtnPos.y = screenH / 2;
    this->salirBtnPos.x = screenW / 2 - 100;
    this->salirBtnPos.y = screenH / 2 + 100;
    this->playButton = LoadTexture("resources/sprites/ui/menuP/playbutton.png");
    this->playButtonPress = LoadTexture("resources/sprites/ui/menuP/playbuttonPressed.png");
    this->salirBtn = LoadTexture("resources/sprites/ui/menuP/salirBtn.png");
    this->salirBtnPress = LoadTexture("resources/sprites/ui/menuP/salirBtnPress.png");

    // > UI Player
    this->marcoVida = LoadTexture("resources/sprites/ui/player/vida/marcoVida.png");
    this->barraVida = LoadTexture("resources/sprites/ui/player/vida/barrasVida.png");

    // > UI Marco - BarraVida / 2 Frames - Normal y titilando para mostrar daño
    this->marcoVidaPos.x = screenW / 15;
    this->marcoVidaPos.y = screenH - 80;
    this->marcoVidaRec.width = this->marcoVida.width / 2; //2 Frames
    this->marcoVidaRec.height = this->marcoVida.height;
    this->marcoVidaRec.x = 0;
    this->marcoVidaRec.y = 0;
    this->marcoVidaFrame = 0;

    // > UI - Barras de VIDA variables // 11 frames - Vacio (muerte) 10 barras %
    this->barraVidaPos.x = screenW / 15 - 1;
    this->barraVidaPos.y = screenH - 80;
    this->barraVidaRec.width = barraVida.width / 11; //11 Frames
    this->barraVidaRec.height = barraVida.height;
    this->barraVidaRec.x = 0;
    this->barraVidaRec.y = 0;
    this->barraVidaFrame = 0;
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