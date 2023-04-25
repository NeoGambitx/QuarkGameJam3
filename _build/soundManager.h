#pragma once
#include <raylib.h>

class SoundManager {

    private:
    Sound startGame;
    Music MusicaNivel1;
    
    public:
        SoundManager();
        ~SoundManager();
        void playLvl1Music();
        void playSoundStart();
};