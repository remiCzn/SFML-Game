#include "PlayerInputComponent.h"

#include <utility>

PlayerInputComponent::PlayerInputComponent(std::shared_ptr<PhysicsComponent> physics) {
    this->_physics = physics;
}

void PlayerInputComponent::handleInput(sf::Keyboard::Key &keycode) {
    switch (keycode) {
        case sf::Keyboard::Q:
            std::cout << "Left" << std::endl;
            this->_physics->setVelocityX(-400);
            break;
        case sf::Keyboard::D:
            std::cout << "Right" << std::endl;
            this->_physics->setVelocityX(400);
            break;
        case sf::Keyboard::Z:
            std::cout << "Up" << std::endl;
            this->_physics->setVelocityY(-400);
            break;
        case sf::Keyboard::S:
            std::cout << "Down" << std::endl;
            this->_physics->setVelocityY(400);
            break;
        default:
            break;
    }
}
