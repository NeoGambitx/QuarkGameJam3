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
    Texture2D menuPbg;
    Texture2D quarkLogo;
    Vector2 quarkLogoPos;
    Texture2D pointer;

    // > UI Player
    Texture2D marcoVida;
    Texture2D barraVida;
    Texture2D lives;

    
    //UI Marco - BarraVida / 2 Frames - Normal y titilando para mostrar da�o
    Vector2 marcoVidaPos;
    Rectangle marcoVidaRec;
    int marcoVidaFrame;

    //UI - Barras de VIDA variables
    Vector2 barraVidaPos;
    Rectangle barraVidaRec;
    int barraVidaFrame{};

    //UI Lives
    Vector2 livesPos;
    Rectangle livesRec;
    int livesFrame;

    public:
        UI(int screenW, int screenH);
        void menuPbotonPlay();
        void menuPbotonSalir();
        void MarcoVida();
        void vidaActual(int vida);
        void printLogo();
        void printMenuPBg();
        void printPointer(int opcion);
        void printLives(int lives);

};

