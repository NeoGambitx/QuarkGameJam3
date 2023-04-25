#include <iostream>
#include <raylib.h>
#include <math.h>

#include "View.h"
/* #include "consoleGame/EnemyShip.h" */

//Importamos clases propias
//#include "Ship.h"

using namespace std;

// Para mostrar las diferentes escenas

typedef enum GameScreen
{
    LOGO = 0,
    TITLE,
    NIVEL1,
    ENDING
} GameScreen;


int main()
{
   
    /* EnemyShip e; */
    // Dimensiones de VENTANA
    const int screenWidth = 640;
    const int screenHeight = 576;
    InitWindow(screenWidth, screenHeight, "Nombre del Juego");
    SetTargetFPS(60);

    // Iniciamos el GameScreen en LOGO
    GameScreen currentScreen = LOGO;
    int framesCounter = 0;

    //Sonido
    InitAudioDevice();
    Sound startGame = LoadSound("resources/sound/inicio.wav");
    Music MusicaNivel1 = LoadMusicStream("resources/sound/bgMusic/nivel1.wav");


    // Vinculamos Texturas
    Texture2D mainShip = LoadTexture("resources/sprites/player/mainShipFH.png");
    Texture2D background = LoadTexture("resources/sprites/map/blueNebula.png");
    Texture2D fighter = LoadTexture("resources/sprites/enemies/fighter.png");

    //UI
    // > Menu Principal
    Vector2 playBtnPos{ screenWidth / 2 - 100, screenHeight / 2 };
    Vector2 salirBtnPos{ screenWidth / 2 - 100, screenHeight / 2 + 100 };
    Texture2D playButton = LoadTexture("resources/sprites/ui/menuP/playbutton.png");
    Texture2D playButtonPress = LoadTexture("resources/sprites/ui/menuP/playbuttonPressed.png");
    Texture2D salirBtn = LoadTexture("resources/sprites/ui/menuP/salirBtn.png");
    Texture2D salirBtnPress = LoadTexture("resources/sprites/ui/menuP/salirBtnPress.png");

    //UI Player
    Texture2D marcoVida = LoadTexture("resources/sprites/ui/player/vida/marcoVida.png");
    Texture2D barraVida = LoadTexture("resources/sprites/ui/player/vida/barrasVida.png");

    // Declaramos Variables de Objetos (Posiciones, rotacion)
    float bgY = 0;

    //UI Player Variables
    Vector2 marcoVidaPos{ screenWidth / 15, screenHeight - 80 };
    Rectangle marcoVidaRec;
    marcoVidaRec.width = marcoVida.width / 2; //2 Frames
    marcoVidaRec.height = marcoVida.height;
    marcoVidaRec.x = 0;
    marcoVidaRec.y = 0;
    int marcoVidaFrame{};

    //UI - Barras de VIDA variables
    Vector2 barraVidaPos{ screenWidth / 15 - 1, screenHeight - 80 };
    Rectangle barraVidaRec;
    barraVidaRec.width = barraVida.width / 11; //11 Frames
    barraVidaRec.height = barraVida.height;
    barraVidaRec.x = 0;
    barraVidaRec.y = 0;
    int barraVidaFrame{};

    //Player Visual
    Vector2 mainShipPos{ screenWidth / 2 - 32, screenHeight - 100 };
    Rectangle mainShipRec;
    mainShipRec.width = mainShip.width / 4;
    mainShipRec.height = mainShip.height;
    mainShipRec.x = 0;
    mainShipRec.y = 0;
    int playerSpeed = 2;
    int mainShipframe{};
    //Tiempo para realizar la siguiente animacion
    const float updateTime{ 1.0 / 12.0 };
    float  runningTime{};
    int Score{};


    //Player Mecanicas
    //Ship player;

    //Enemigos
    // - Fighter basico
    Vector2 fighterPos{ screenWidth / 2, screenHeight / 20 };
    Rectangle figherRec;
    figherRec.width = fighter.width / 4;
    figherRec.height = fighter.height;
    figherRec.x = 0;
    figherRec.y = 0;
    int figherFrame{};

    // Main LOOP -
    while (WindowShouldClose() == false)
    {
        // Cambiamos GAMESCREEN
        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Update LOGO screen variables here!
            framesCounter++; // Count frames
            // Wait for 2 seconds (120 frames) before jumping to TITLE screen
            if (framesCounter > 120)
            {
                currentScreen = TITLE;
            }
        }
        break;
        case TITLE:
        {   
            // TODO: Update TITLE screen variables here!

            // Press enter to change to NIVEL1 screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                PlaySound(startGame);
                WaitTime(2);
                currentScreen = NIVEL1;
            }
        }
        break;
        case NIVEL1:
        {
            // TODO: Update NIVEL1 screen variables here!

            // OBJETIVOS A CUMPLIR PARA AVANZAR AL NIVEL 2 - 
        }
        break;
        case ENDING:
        {
            // PATANALLA FINAL - CREDITOS 
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = TITLE;
            }
        }
        break;
        default:
            break;
        }
        // FIN SWITCH GAMESCREEN








        const float dt{ GetFrameTime() };
        BeginDrawing();
        ClearBackground(BLACK);

        // Comienzo de la logica del Juego
        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Draw LOGO screen here!
            DrawText("PANTALLA DE LOGO ", 20, 20, 40, LIGHTGRAY);
            DrawText("ESPERA 2 SEGUNDOS...", screenWidth / 2 - 100, screenHeight / 2, 20, GRAY);
        }
        break;
        case TITLE:
        {
            // TODO: Draw TITLE screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, SKYBLUE);
            DrawText("PANTALLA - MENU PRINCIPAL", 20, 20, 20, GRAY);
            DrawTextureEx(playButton, playBtnPos, 0.0, 2, WHITE);
            DrawTextureEx(salirBtn, salirBtnPos, 0.0, 2, WHITE);
        }
        break;
        case NIVEL1:
        {
            //NIVEL 1 - Iniciamos Musica y Graficos
            //Musica
            PlayMusicStream(MusicaNivel1);
            UpdateMusicStream(MusicaNivel1);

            //Codigo Fondo - BG
            bgY += 100 * dt;
            if (bgY >= background.height)
            {
                bgY = 0.0;
            }
            // Pintamos Fondo
            Vector2 bgPos{ 0.0, bgY };
            DrawTextureEx(background, bgPos, 0, 1, WHITE);
            // Segundo Fondo para repetir en bucle
            Vector2 bg2Pos{ 0.0, bgY - background.height };
            DrawTextureEx(background, bg2Pos, 0.0, 1, WHITE);
            // ▲ ▲ ▲ Fin fondo


            //  JUGADOR

            // actualizar RunningTime
            runningTime += dt;

            if (runningTime >= updateTime) {
                /* runningTime = 0; */
                mainShipRec.x = mainShipframe * mainShipRec.width;
                mainShipframe++;
                if (mainShipframe > 4) {
                    mainShipframe = 0;
                }
            }
            DrawTextureRec(mainShip, mainShipRec, mainShipPos, WHITE);

            // Marco Vida
            if (runningTime >= updateTime) {
                marcoVidaRec.x = marcoVidaFrame * marcoVidaRec.width;
                marcoVidaFrame++;
                if (marcoVidaFrame > 2) {
                    marcoVidaFrame = 0;
                }
            }
            DrawTextureRec(marcoVida, marcoVidaRec, marcoVidaPos, WHITE);

            // Barra Vida
            if (runningTime >= updateTime) {
                barraVidaRec.x = barraVidaFrame * barraVidaRec.width;
                barraVidaFrame++;
                if (barraVidaFrame > 11) {
                    barraVidaFrame = 0;
                }
            }
            DrawTextureRec(barraVida, barraVidaRec, barraVidaPos, WHITE);


            //Enemigos
            if (runningTime >= updateTime) {
                runningTime = 0;
                figherRec.x = figherFrame * figherRec.width;
                figherFrame++;
                if (figherFrame > 4) {
                    figherFrame = 0;
                }
            }
            DrawTextureRec(fighter, figherRec, fighterPos, WHITE);

            //Score
            DrawText(TextFormat("Score: %i", dt), screenWidth - 100, 10, 20, LIGHTGRAY);
            // DAÑADO

            // Movimiento JUGADOR
            if (IsKeyDown(KEY_D) && mainShipPos.x < screenWidth)
            {
                mainShipPos.x += playerSpeed;
            }
            if (IsKeyDown(KEY_A) && mainShipPos.x > 0)
            {
                mainShipPos.x -= playerSpeed;
            }
            if (IsKeyDown(KEY_S) && mainShipPos.y < screenHeight)
            {
                mainShipPos.y += playerSpeed;
            }
            if (IsKeyDown(KEY_W) && mainShipPos.y > 0)
            {
                mainShipPos.y -= playerSpeed;
            }
        }
        break;
        case ENDING:
        {
            // TODO: Draw ENDING screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        }
        break;
        default:
            break;
        }

        // Final Lógica del juego
        EndDrawing();


    }

    UnloadTexture(mainShip);
    UnloadTexture(background);
    CloseAudioDevice();
}