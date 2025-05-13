#pragma once

#include "character.h"
#include <SFML/Audio.hpp>

class CharacterChongyue : public Character {
public:
    using Character::Character;
    void playNaSound(sf::Sound& sound) {
        if (!isPlayingNaSound) {
            sound.stop();
            sound.play();
            isPlayingNaSound = true;
        }
    }

    void stopNaSound() {
        isPlayingNaSound = false;
    }

private:
    bool isPlayingNaSound = false;
};