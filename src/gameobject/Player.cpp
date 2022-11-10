#include "Player.h"

sf::Vector2i Player::getPlayerCenterPosition() {
    return static_cast<sf::Vector2i>(this->_physics->getPosition()) +
           sf::Vector2i(PLAYER_DIM.x * SCALE / 2, PLAYER_DIM.y * SCALE / 2);
}

Player::Player() : GameObject() {
    this->add_physics_component(new PhysicsComponent());
    this->add_graphics_component(new PlayerAnimationComponent(this->_physics));
    this->add_input_component(new PlayerInputComponent(this->_physics));
}
