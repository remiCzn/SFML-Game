#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"
#include "../components/player/PlayerInputComponent.h"
#include "../components/player/PlayerAnimationComponent.h"

class Player : public GameObject {
public:
    Player();

    sf::Vector2f getPlayerCenterPosition();
};


#endif //GAME_PLAYER_H
