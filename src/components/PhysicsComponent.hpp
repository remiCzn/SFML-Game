#ifndef GAME_PHYSICSCOMPONENT_HPP
#define GAME_PHYSICSCOMPONENT_HPP

#include "defines.h"
#include "constants.h"

class PhysicsComponent {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::FloatRect box;

    sf::RectangleShape boxshape;

public:
    PhysicsComponent();

    void update(float dt);

    void render(const std::shared_ptr<sf::RenderTarget> &target);

    void setVelocityX(float x);

    void setVelocityY(float y);

    const sf::Vector2f &getPosition();

    const sf::Vector2f &getVelocity();

    const sf::FloatRect &getNextPosition(const float &dt);

};

#endif //GAME_PHYSICSCOMPONENT_HPP
