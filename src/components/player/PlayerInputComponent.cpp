#include "PlayerInputComponent.h"

#include <utility>

PlayerInputComponent::PlayerInputComponent(std::shared_ptr<PhysicsComponent> physics) {
    this->_physics = std::move(physics);
    this->speed_force = PhysicsConsts::PLAYER_SPEED_FLOAT;
}

void PlayerInputComponent::handleInput(sf::Keyboard::Key &keycode) {
//    switch (keycode) {
//        default:
//            break;
//    }
}

void PlayerInputComponent::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        this->_physics->setVelocityX(-this->speed_force);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->_physics->setVelocityX(this->speed_force);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->_physics->setVelocityY(this->speed_force);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        this->_physics->setVelocityY(-this->speed_force);
    }
}
