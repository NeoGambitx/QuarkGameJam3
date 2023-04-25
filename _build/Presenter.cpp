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
    View* vista = new View(640, 576, 60, "Proyecto HyperNova"); //Iniciamos VISTA
    vista->inicializarScreen();
    UI* ui = new UI(vista->getScreenWidth(), vista->getScreenHeight()); //Iniciamos UI
    vista->setCurrentScreen(LOGO); //Iniciamos el GameScreen en LOGO
    SoundManager* soundManager = new SoundManager(); //Sonido
    GameBG* gameBg = new GameBG(); //Iniciamos GameBG
    Story* story = new Story();
    Color transitionColor = BLACK;
    bool transitionComplete{};
    int opcionTitulo = 1;

    // -> Player - Enemigos - Mecánicas
    Ship* mainShip = new Ship(vista->getScreenWidth(), vista->getScreenHeight());
    bool megaShot{}; // True = con megaShot
    bool superSpeed{}; // True = con superSpeed;
    int megaShotTime{}; // Tiempo para usar megaShot
    int superSpeedTime{}; // TIempo para usar superSpeed
    EnemyFactory* enemyFactory = new EnemyFactory;
    std::vector<Enemy*> enemyList;
    bool PowerUpEnPantalla{};
    int contadorPowerUp{};
    PowerUP* power;

    // -> Variables LOCALES
    int framesCounter = 0; //Para llevar cuenta de FPS -> 60 = 1 segundo
    const float updateTime{ 1.0 / 12.0 }; //Tiempo para realizar la siguiente animacion
    float  runningTime{}; //Tiempo para realizar la siguiente animacion
    int Score{}; //Puntaje (Cada destruccion de naves, debería sumar x Puntos)
    
    //NIVEL1
    bool level1Exit = false;
    unsigned const int level1Ciclos = 60;
    int level1ContadorCiclos{};
    int level1Frames = 0;

    //Colisiones
    std::vector<Explosion*> explosionManager;

    

    //Poyectiles
    ProjectileFactory* PFactory = new ProjectileFactory();
    std::vector<Projectile*> listaProyectiles;
    int indexProj = 0;
    bool shooted = false;
    float shootPassTime = 0;

    //enemyFactory->createEnemy(1, vista->getScreenWidth(), vista->getScreenHeight())
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
            if (!transitionComplete) {
                if (transitionColor.a == 0) {
                    transitionComplete = true;
                    WaitTime(2);
                }
                else {
                    transitionColor.a -= 5;
                }
            }
            else {
                if (transitionColor.a != 255) {
                transitionColor.a += 5;
                }
            }
            
            if (framesCounter > 120)
            {
                vista->setCurrentScreen(TITLE);
            }
        }
        break;
        case TITLE:
        {
            // TODO: Update TITLE screen variables here!

            // Press enter to change to NIVEL1 screen
            if (opcionTitulo == 1) {
                
                if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S)) {
                    opcionTitulo = 2;
                }

                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    soundManager->playSoundStart();
                    mainShip->setLives(3);
                    mainShip->setHealth(100);
                    WaitTime(2);
                    vista->setCurrentScreen(PROLOGUE);
                }
            }
            else {
                if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S)) {
                    opcionTitulo = 1;
                }
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    return;
                }
            }
            
        }
        break;
        case PROLOGUE: {
            
            if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
            else framesCounter++;

            if (IsKeyDown(KEY_ENTER)) vista->setCurrentScreen(NIVEL1);
        } break;
        case NIVEL1:
        {   
            contadorPowerUp++;
            if (!PowerUpEnPantalla && contadorPowerUp >= 300) { //Si pasaron 5 segundos sin aparecer un POWER UP
                power = new PowerUP(vista->getScreenWidth(), vista->getScreenHeight());
                PowerUpEnPantalla = true;
            }
            else if (PowerUpEnPantalla){
                if (power->isOffScreen()) {
                    //delete power;
                    contadorPowerUp = 0;
                    PowerUpEnPantalla = false;
                }
            }          
            //Vamos añadiendo enemigos en el NIVEL 1
            
           
            if (level1ContadorCiclos < level1Ciclos) {
                if (level1Frames >= 120) { //Si pasaron 2 seg generar enemigo
                    enemyList.push_back(enemyFactory->createEnemy(1, vista->getScreenWidth(), vista->getScreenHeight()));
                    level1ContadorCiclos++;
                    level1Frames = 0;
                }
                else {
                    level1Frames++;
                }
            }
            //Si terminamos de generar enemigos, y estan todos muertos pasamos de nivel
            if (level1ContadorCiclos == level1Ciclos && enemyList.size() == 0) vista->setCurrentScreen(ENDING); 
            
            if (mainShip->getLives() == 0) vista->setCurrentScreen(TITLE);
            
            
            
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
            ui->printLogo();
            vista->transition(transitionColor);
        }
        break;
        case TITLE:
        {
            // Pantalla de título
            ui->printMenuPBg();
            ui->printPointer(opcionTitulo);
            ui->menuPbotonPlay();
            ui->menuPbotonSalir();
        }
        break; 
        case PROLOGUE: {
            DrawText(TextSubtext(story->intro, 0, framesCounter / 10), 10, 10, 20, MAROON);
            
        } 
        break;
        case NIVEL1:
        {
            //NIVEL 1 - Iniciamos Musica y Graficos
            //Musica
            soundManager->playLvl1Music();
            //Codigo Fondo - BG
            gameBg->pintarBg(0, dt);

            //Power UPS
            if (PowerUpEnPantalla) {
                power->printPowerUP();
                //Colisiones MAIN SHIP con POWER UPS
                if (CheckCollisionRecs(mainShip->getCollisionBox(), power->getCollisionBox())) {
                    if (power->getTipo() == 1) {
                        mainShip->setHealth(100); //1 = VIDA + 100
                        delete power;
                    }
                    else if (power->getTipo() == 2) {
                        megaShot = true;
                        megaShotTime = 300; // 300 / 60 = 5 Segundos;
                        delete power;
                    }
                    else {
                        superSpeed = true;
                        superSpeedTime = 300;
                        mainShip->setSpeed(5);
                        delete power;
                    }

                    PowerUpEnPantalla = false;
                    contadorPowerUp = 0;
                }
            } //Fin colisiones PowerUPS

            //Verificando PowerUps - Manejando Tiempos
            if (megaShot) {
                if (megaShotTime == 0) {
                    megaShot = false;
                }
                else {
                    megaShotTime--;
                }
            }

            if (superSpeed) {
                if (superSpeedTime == 0) {
                    superSpeed = false;
                    mainShip->setSpeed(3);
                }
                else {
                    superSpeedTime--;
                }
            }// Fin PowerUps
            
       
            //ANIMACIONES - Update Time
            // actualizar RunningTime
            runningTime += dt;
            if (runningTime >= updateTime) {
                /* runningTime = 0; */
                //Animamos proximo frame
                vista->animarProjectiles(listaProyectiles); //Projectiles
                mainShip->animacion(); // Main Ship
                vista->animarEnemies(enemyList); //Enemigos - Asteroides y naves
                
                //Chequeamos si la animacion de la explosión termino y borramos del vector
                for (int z = 0; z < explosionManager.size(); z++) {
                    explosionManager[z]->animar();
                    explosionManager[z]->mostrarExplosion();
                    if (explosionManager[z]->isItDone()) {
                      explosionManager.erase(explosionManager.begin() + z);
                    }
                }

                runningTime = 0; // Reset Running Time (limita la animacion)
            }

           
            //Jugador
            vista->printSpriteSheet(mainShip->getTexture(), mainShip->getRec(), mainShip->getPosition());
            
            //User Interface (UI)
            ui->MarcoVida();
            ui->vidaActual(mainShip->getHealth());
            DrawText(TextFormat("Score: %i", Score), vista->getScreenWidth() - 100, 10, 20, LIGHTGRAY); //Score


            // Movimiento JUGADOR 
            if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT) && mainShip->getPosition().x < vista->getScreenWidth())
            {   
                mainShip->moveRight();
            }
            if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) && mainShip->getPosition().x > 0)
            {   
                mainShip->moveLeft();
            }
            if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN) && mainShip->getPosition().y < vista->getScreenHeight())
            {   
                mainShip->moveDown();
            }
            if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP) && mainShip->getPosition().y > 0)
            {
                mainShip->moveUp();
            }
            if (IsKeyDown(KEY_SPACE)) { 
                if (!shooted) {
                    Projectile* p;
                    if (megaShot)  p = PFactory->createProjectile(3, indexProj, mainShip->getPosition(), 270, false);
                    else p = PFactory->createProjectile(1, indexProj, mainShip->getPosition(), 270, false);
                    listaProyectiles.push_back(p);
                    shootPassTime = 0;
                    shooted = true;
                }
            }
            
            //PROJECTILES
            vista->printProjectiles(listaProyectiles);
            shootPassTime++;
            if (shootPassTime/60 > mainShip->getShootDelay()) {
                shooted = false;
            }
            vista->moverProjectiles(listaProyectiles);



            //ENEMIGOS
            vista->printEnemigos(enemyList);
            


            //Colisiones -> Projectiles con Todo lo demás
            for (int i = 0; i < listaProyectiles.size(); i++) { //Proyectil contra MAIN SHIP
                if (CheckCollisionRecs(listaProyectiles[i]->getPositionAndScale(), mainShip->getCollisionBox()) && listaProyectiles[i]->isEnemyShoot()) {
                    if (mainShip->doesItKillme(listaProyectiles[i]->getDamageDone())) {
                        Explosion* e = new Explosion(mainShip->getPosition(), true);
                        explosionManager.push_back(e); 
                        mainShip->tookDamage(listaProyectiles[i]->getDamageDone());
                        //Si tenemos 0 vidas automaticamente volvemos al menú principal. Pero podemos imprimir algo acá con WaitTime();
                        //If vidas = 0 GAME OVER 
                        // Agregar chek de vidas restantes
                        //Agregar mensaje de Game OVER - Volver a menú inicial.
                    }
                    else {
                        Explosion* e = new Explosion(mainShip->getPosition(), false);
                        explosionManager.push_back(e);
                        mainShip->tookDamage(listaProyectiles[i]->getDamageDone());
                    }
                    listaProyectiles.erase(listaProyectiles.begin() + i);
                    break;
                }

                for (int j=0; j<enemyList.size(); j++) {
                    if (CheckCollisionRecs(listaProyectiles[i]->getPositionAndScale(), enemyList[j]->getCollisionBox()) && !listaProyectiles[i]->isEnemyShoot()) {
                        if (enemyList[j]->doesItKillme(listaProyectiles[i]->getDamageDone())) {//Si el daño lo mata, mostrar explosion y borrar de la lista enemigos.
                            Explosion* exp = new Explosion(enemyList[j]->getPos(), true);
                            explosionManager.push_back(exp);
                            enemyList.erase(enemyList.begin() + j);
                        }
                        else {
                            enemyList[j]->tookDamage(listaProyectiles[i]->getDamageDone());
                            Explosion* miniExp = new Explosion(enemyList[j]->getPos(), false);
                        }
                        listaProyectiles.erase(listaProyectiles.begin() + i);
                        break; // VER - No puede borrarse si sigue en el ciclo, próxima vuelta referencia a un proyectil que no existe.
                    }
                }
            }

            //Borramos Projectiles fuera de pantalla
            for (int out = 0; out < listaProyectiles.size(); out++) {
                if (listaProyectiles[out]->isOutOfBounds(vista->getScreenWidth(), vista->getScreenHeight())) {
                    listaProyectiles.erase(listaProyectiles.begin() + out);
                }
            }

            //Colisiones mainShip con NAVES Y obstaculos
           for (int q = 0; q < enemyList.size(); q++) {
                if (CheckCollisionRecs(enemyList[q]->getCollisionBox(), mainShip->getCollisionBox())) {
                    if (mainShip->doesItKillme(50)){ //50 de daño por colisión directa.
                        Explosion* e = new Explosion(mainShip->getPosition(), true);
                        explosionManager.push_back(e);
                        mainShip->tookDamage(50);
                        //Si tenemos 0 vidas automaticamente volvemos al menú principal. Pero podemos imprimir algo acá con WaitTime();
                        //If vidas = 0 GAME OVER 
                        // Agregar chek de vidas restantes
                        //Agregar mensaje de Game OVER - Volver a menú inicial.
                    }
                    else {
                        Explosion* e = new Explosion(mainShip->getPosition(), false);
                        explosionManager.push_back(e);
                        mainShip->tookDamage(50);
                    }
                    Explosion* destroyedShip = new Explosion(enemyList[q]->getPos(), true);
                    explosionManager.push_back(destroyedShip);
                    enemyList.erase(enemyList.begin() + q);
                    break;
                }
            }

            //Enemigos - Movimiento y ataque
            for (int enemigos = 0; enemigos<enemyList.size(); enemigos++) {
                if (enemyList[enemigos]->canShoot()) {
                listaProyectiles.push_back(PFactory->createProjectile(2, indexProj, enemyList[enemigos]->getPos(), 90, true));
                }
                enemyList[enemigos]->movementMechanics();
            }

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