#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"
#include "../components/player/PlayerInputComponent.h"

class Player : public GameObject {
public:
    Player() : GameObject() {
        this->add_physics_component(new PhysicsComponent());
        this->add_graphics_component("assets/character/chara1.png", sf::IntRect(0, 0, 19, 27));
        this->add_input_component(new PlayerInputComponent(this->_physics));
    }
};


#endif //GAME_PLAYER_H
