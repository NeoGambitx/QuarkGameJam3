#include "Presenter.h"
#include <ctime>
// Problemas con libreria raylib -> #include <Windows.h>
// #define INITIAL_SHIP_POSITION 50; // manejado en la clase SHIP

// Class constructor
Presenter::Presenter()
{
	//ship = new Ship;
}
// Class destructor
Presenter::~Presenter()
{
	//delete ship;
}

// Player begins new game - FEDE: Modifico para inciar Raylib - y ejecutar el ciclo juego
void Presenter::startGame()
{   
    // -> Vista - Sonido
    View* vista = new View(640, 576, 60, "Nombre del Juego"); //Iniciamos VISTA
    vista->inicializarScreen();
    UI* ui = new UI(vista->getScreenWidth(), vista->getScreenHeight()); //Iniciamos UI
    vista->setCurrentScreen(LOGO); //Iniciamos el GameScreen en LOGO
    SoundManager* soundManager = new SoundManager(); //Sonido
    GameBG* gameBg = new GameBG(); //Iniciamos GameBG
    Story* story = new Story();
    Characters* characters = new Characters(); // inicio personajes

    // -> Player - Enemigos - Mecánicas
    Ship* mainShip = new Ship(vista->getScreenWidth(), vista->getScreenHeight());
    EnemyFactory* enemyFactory = new EnemyFactory;

    // -> Variables LOCALES
    int framesCounter = 0; //Para llevar cuenta de FPS -> 60 = 1 segundo
    const float updateTime{ 1.0 / 12.0 }; //Tiempo para realizar la siguiente animacion
    float  runningTime{}; //Tiempo para realizar la siguiente animacion
    int Score{}; //Puntaje (Cada destruccion de naves, debería sumar x Puntos)
    //TEST - PRUEBA 
    Vector2 newPos; //Variable auxiliar para modificar la posicion de la nave
    Rectangle enemyShipBox;
    Rectangle MainShipBox;

    //Enemigos
    // - Fighter basico - EXTERNALIZAR y borrar
    /**/Texture2D fighter = LoadTexture("resources/sprites/enemies/fighter.png");
    Vector2 fighterPos{ vista->getScreenWidth() / 2, vista->getScreenHeight() / 20 };
    Rectangle figherRec;
    figherRec.width = fighter.width / 4;
    figherRec.height = fighter.height;
    figherRec.x = 0;
    figherRec.y = 0;
    int figherFrame{};
    // SE BORRA ▲ ▲



    // Main LOOP -
    while (WindowShouldClose() == false)
    {
        // Cambiamos GAMESCREEN
        switch (vista->getCurrentScreen())
        {
        case LOGO:
        {
            // TODO: Update LOGO screen variables here!
            framesCounter++; // Count frames
            // Wait for 2 seconds (120 frames) before jumping to TITLE screen
            if (framesCounter > 120)
            {
                vista->setCurrentScreen(TITLE);
            }
        }
        break;
        case TITLE:
        {
            // TODO: Update TITLE screen variables here!

            // Press enter to change to Prologue screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                soundManager->playSoundStart();
                WaitTime(2);
                vista->setCurrentScreen(PROLOGUE);
            }
        }
        break;
        case PROLOGUE: {
            if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
            else framesCounter++;

            if (IsKeyDown(KEY_ENTER)) vista->setCurrentScreen(QUESTIONS);   
        } 
        break;
        case QUESTIONS: {
            if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
            else framesCounter++;

            if (IsKeyDown(KEY_KP_1)) vista->setCurrentScreen(PREG1);
            if (IsKeyDown(KEY_KP_2)) vista->setCurrentScreen(PREG2);
            if (IsKeyDown(KEY_KP_3)) vista->setCurrentScreen(PREG3);
        } 
                             
        break;
        case PREG1:
        {
            if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
            else framesCounter++;

            if (IsKeyDown(KEY_ENTER)) vista->setCurrentScreen(QUESTIONS);
        }
        break;
        case PREG2:
        {
            if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
            else framesCounter++;

            if (IsKeyDown(KEY_ENTER)) vista->setCurrentScreen(QUESTIONS);
        }
        break;
        case PREG3:
        {
            if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
            else framesCounter++;

            if (IsKeyDown(KEY_ENTER)) vista->setCurrentScreen(NIVEL1);
        }
        break;
        case NIVEL1:
        {   
            
            // TODO: Update NIVEL1 screen variables here!
            //int initialPosition = INITIAL_SHIP_POSITION;  //Definido en la clase SHIP
            srand(time(NULL));

            

            //ship->setPosition(initialPosition);

            bool EXIT_LEVEL = false;
            unsigned const int CYCLES_BEFORE_LEVEL_END = 60;
            int count = 0;
            
            /*while (EXIT_LEVEL == false)
            {

                //enemyShips.push_back(enemyFactory->createEnemy(1));
                //Sleep(2000 * (rand() % 3));
                //enemyObstacles.push_back(enemyFactory->createEnemy(2));
                //Sleep(3000 * rand() % 2);
                // Level two

                //Prueba ▼ ▼
                Ship* s = new Ship(rand() % 2, rand() % 5);
                enemies.push_back(s);

                count++;
                if (count == CYCLES_BEFORE_LEVEL_END)
                {
                    EXIT_LEVEL = true;
                }
            }

            //this->enterTransition();

            */
            // OBJETIVOS A CUMPLIR PARA AVANZAR AL NIVEL 2 - 
            /*
            switch (currentLevel)
            {
                // Level one
            case 1:
                enemyShips.push_back(enemyFactory->createEnemy(1));
                //Sleep(2000 * (rand() % 3));
                enemyObstacles.push_back(enemyFactory->createEnemy(2));
                //Sleep(3000 * rand() % 2);
                // Level two
            case 2:
                enemyShips.push_back(enemyFactory->createEnemy(1));
                //Sleep(1500 * (rand() % 3));
                enemyObstacles.push_back(enemyFactory->createEnemy(2));
                //Sleep(2000 * (rand() % 2));

                // Level three
            case 3:
                enemyShips.push_back(enemyFactory->createEnemy(1));
                //Sleep(1000 * (rand() % 3));
                enemyObstacles.push_back(enemyFactory->createEnemy(2));
                //Sleep(1500 * (rand() % 2));
            default:
                continue;
            }*/
        }
        break;
        case NIVEL2:
        {

        }
        break;
        case NIVEL3:
        {

        }
        break;
        case NIVEL_FINAL:
        {

        }
        break;
        case ENDING:
        {
            // PATANALLA FINAL - CREDITOS 
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                vista->setCurrentScreen(TITLE);
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
        switch (vista->getCurrentScreen())
        {
        case LOGO:
        {
            // TODO: Draw LOGO screen here!
            DrawText("PANTALLA DE LOGO ", 20, 20, 40, LIGHTGRAY);
            DrawText("ESPERA 2 SEGUNDOS...", vista->getScreenWidth() / 2 - 100, vista->getScreenHeight() / 2, 20, GRAY);
        }
        break;
        case TITLE:
        {
            // TODO: Draw TITLE screen here!
            DrawRectangle(0, 0, vista->getScreenWidth(), vista->getScreenHeight(), SKYBLUE);
            DrawText("PANTALLA - MENU PRINCIPAL", 20, 20, 20, GRAY);
            //vista->ui.menuPbotonPlay();
            //vista->ui.menuPbotonSalir();
            ui->menuPbotonPlay();
            ui->menuPbotonSalir();

        }
        break; 
        case PROLOGUE: {
            DrawTextureEx(gameBg->introBg, gameBg->bgPos, 0, 2.15, WHITE);
            DrawText(TextSubtext(story->intro, 0, framesCounter / 10), 50, 150, 20, WHITE);
        } 
        break;
        case QUESTIONS: {
            DrawTextureEx(characters->comandanteImg, characters->izqArribaPos, 0.0, 0.25, WHITE);
            DrawText(TextSubtext(story->dialog1, 0, framesCounter / 10), 10, 150, 20, WHITE);
        }
        break;
        case PREG1:
        {
            DrawText(story->preg1, 170, 30, 20, RED);
            DrawTextureEx(characters->mainCharacterImg, characters->izqArribaPos, 0.0, 0.25, WHITE);
            DrawText(TextSubtext(story->resp1, 0, framesCounter / 10), 10, 200, 20, WHITE);
            DrawTextureEx(characters->comandanteImg, characters->comanPosPregResp, 0.0, 0.25, WHITE);
        }
        break;
        case PREG2:
        {
            DrawText(story->preg2, 170, 30, 20, RED);
            DrawTextureEx(characters->mainCharacterImg, characters->izqArribaPos, 0.0, 0.25, WHITE);
            DrawText(TextSubtext(story->resp2, 0, framesCounter / 10), 10, 200, 20, WHITE);
            DrawTextureEx(characters->comandanteImg, characters->comanPosPregResp, 0.0, 0.25, WHITE);
        }
        break;
        case PREG3:
        {
            DrawText(story->preg3, 170, 30, 20, RED);
            DrawTextureEx(characters->mainCharacterImg, characters->izqArribaPos, 0.0, 0.25, WHITE);
            DrawText(TextSubtext(story->resp3, 0, framesCounter / 10), 10, 200, 20, WHITE);
            DrawTextureEx(characters->comandanteImg, characters->comanPosPregResp, 0.0, 0.25, WHITE);
        }
        break;
        case NIVEL1:
        {
            //NIVEL 1 - Iniciamos Musica y Graficos
            //Musica
            soundManager->playLvl1Music();


            //Codigo Fondo - BG
            gameBg->pintarBg(0, dt);


            //  JUGADOR

            // actualizar RunningTime
            runningTime += dt;

            if (runningTime >= updateTime) {
                /* runningTime = 0; */
                //Animamos proximo frame
                mainShip->animacion();
            }
            vista->printSpriteSheet(mainShip->getTexture(), mainShip->getRec(), mainShip->getPosition());
            
            //Test
            //Colisiones funcionando, ver de agregar un RECTAGULO A LA CLASE SHIP y ENEMY
            //Este rectangulo tiene que tener estos datos, la altura y anchura del sprite,
            // y la posicion en tiempo real de las naves. Para poder calcular las colisiones. Debería ser la nave Principal vs VECTOR de ENEMIGOS.
            enemyShipBox.height = fighter.height;
            enemyShipBox.width = fighter.width;
            enemyShipBox.x = fighterPos.x;
            enemyShipBox.y = fighterPos.y;
            MainShipBox.height = mainShip->getTexture().height;
            MainShipBox.width = mainShip->getTexture().width;
            MainShipBox.x = mainShip->getPosition().x;
            MainShipBox.y = mainShip->getPosition().y;

            if (CheckCollisionRecs(MainShipBox, enemyShipBox)) {
                mainShip->tookDamage(10);
            }
            // TEST COLLISIONS
            /*
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
            */
            //vista->ui.MarcoVida();
            //vista->ui.vidaActual();
            ui->MarcoVida();
            ui->vidaActual(mainShip->getHealth());

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
            DrawText(TextFormat("Score: %i", Score), vista->getScreenWidth() - 100, 10, 20, LIGHTGRAY);
            // DAÑADO

            // Movimiento JUGADOR 
            
            if (IsKeyDown(KEY_D) && mainShip->getPosition().x < vista->getScreenWidth())
            {   
                //es mejor con un método propio de SHIP, que tome 1 valor, X o Y, y lo modifique. 
                //Pueden ser 4 funciones 1 para cada direccion o 1 sola con algun filtro de dirección
                newPos = mainShip->getPosition();
                newPos.x += mainShip->getSpeed();
                mainShip->setPosition(newPos);
            }
            if (IsKeyDown(KEY_A) && mainShip->getPosition().x > 0)
            {   
                newPos = mainShip->getPosition();
                newPos.x -= mainShip->getSpeed();
                mainShip->setPosition(newPos);
            }
            if (IsKeyDown(KEY_S) && mainShip->getPosition().y < vista->getScreenHeight())
            {
                newPos = mainShip->getPosition();
                newPos.y += mainShip->getSpeed();
                mainShip->setPosition(newPos);
            }
            if (IsKeyDown(KEY_W) && mainShip->getPosition().y > 0)
            {
                newPos = mainShip->getPosition();
                newPos.y -= mainShip->getSpeed();
                mainShip->setPosition(newPos);
            }
        }
        break;
        case NIVEL2:
        {

        }
        break;
        case NIVEL3:
        {

        }
        break;
        case NIVEL_FINAL:
        {

        }
        break;
        case ENDING:
        {
            // TODO: Draw ENDING screen here!
            DrawRectangle(0, 0, vista->getScreenWidth(), vista->getScreenHeight(), BLUE);
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
    delete soundManager;
}

void Presenter::enterTransition()
{
	// Delete all enemy ships
	for (Enemy* ship : enemyShips)
	{
		delete ship;
	}
	enemyShips.clear();

	// Delete all enemy obstacles
	for (Enemy* obstacle : enemyObstacles)
	{
		delete obstacle;
	}
	enemyObstacles.clear();
}

void Presenter::shipMoved(int key)
{
	// Receive input from the view and process it to interact with the model

}

void Presenter::shipDamaged()
{
	// Fill this
}

// Ship destroyed
void Presenter::shipDestroyed()
{
	int CURRENT_LIVES = ship->getLives();

	if (CURRENT_LIVES >= 1)
	{
		//ship->setLives(CURRENT_LIVES - 1);
	}
	else
	{
		this->enterTransition();
		this->gameOver();
	}
}

// Game over
void Presenter::gameOver()
{
	// Call necessary destructors
	// Send the player back to the home screen
}