#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include "GameObject.hpp"
#include "../components/player/PlayerInputComponent.hpp"
#include "../components/player/PlayerAnimationComponent.hpp"

class Player : public GameObject {
public:
    Player();

    sf::Vector2i getPlayerCenterPosition();
};


#endif //GAME_PLAYER_HPP
