#ifndef GAME_PHYSICSCOMPONENT_H
#define GAME_PHYSICSCOMPONENT_H

#include "defines.h"

class PhysicsComponent {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    PhysicsComponent();

    void update(float dt);

    void setVelocityX(float x);

    void setVelocityY(float y);

    const sf::Vector2f &getPosition();

};

#endif //GAME_PHYSICSCOMPONENT_H
