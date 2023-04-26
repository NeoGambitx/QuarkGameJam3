#pragma once

#include <raylib.h>

class UI
{
	//Texturas y posicion de la interfaz de usuario -
    private:
    // > Menu Principal
    Vector2 playBtnPos;
    Vector2 salirBtnPos;
    Texture2D playButton;
    Texture2D playButtonPress;
    Texture2D salirBtn;
    Texture2D salirBtnPress;

    // > UI Player
    Texture2D marcoVida;
    Texture2D barraVida;

    
    //UI Marco - BarraVida / 2 Frames - Normal y titilando para mostrar daño
    Vector2 marcoVidaPos;
    Rectangle marcoVidaRec;
    int marcoVidaFrame;

    //UI - Barras de VIDA variables
    Vector2 barraVidaPos;
    Rectangle barraVidaRec;
    int barraVidaFrame{};

    public:
        UI(int screenW, int screenH);
        void menuPbotonPlay();
        void menuPbotonSalir();
        void MarcoVida();
        void vidaActual(int vida);

};

