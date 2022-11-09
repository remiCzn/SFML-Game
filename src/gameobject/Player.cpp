#include "Player.h"

sf::Vector2f Player::getPlayerCenterPosition() {
    return this->_physics->getPosition() + sf::Vector2f(38, 54);
}

Player::Player() : GameObject() {
    this->add_physics_component(new PhysicsComponent());
    this->add_graphics_component(new PlayerAnimationComponent(this->_physics));
    this->add_input_component(new PlayerInputComponent(this->_physics));
}
