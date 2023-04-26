#pragma once
#include <raylib.h>

class SoundManager {

    private:
        //Background Music 8 - Musics
    
    Music MusicaNivel1;
    Music MusicaNivel2;
    Music MusicaNivel3;
    Music MusicaBoss;
    Music Prologo;
    Music Menu;
    Music Epilogo;
    Music Dialog;

    //Sound Effects - 9 Effects
    Sound enemyShoot;
    Sound normalShoot;
    Sound superShoot;
    Sound powerUP;
    Sound explosion;
    Sound FinalExplosion;
    Sound damage;
    Sound kamikaze;
    Sound superCanonShoot;
    

        //Title and Victory 3 - Title and Victory
    Sound startGame;
    Sound select;
    Sound victory;
    
    public:
        SoundManager();
        ~SoundManager();
        //Music
        void playLvl1Music();
        void playLvl2Music();
        void playLvl3Music();
        void playPrologueMusic();
        void playBossMusic();
        void playMenuMusic();
        void playDialogMusic();
        void playEpilogueMusic();

        //Sounds
        void playSoundStart();
        void playSoundSelect();
        void playSoundVictory();
        void playSoundShoot();
        void playSoundMegaShoot();
        void playSoundPowerUP();
        void playSoundEnemyShoot();
        void playSoundExplosion();
        void playSoundFinalExplosion();
        void playSoundKamikaze();
        void playSoundSuperCannonShoot();
        void playSoundDamage();
};