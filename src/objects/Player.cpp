#include "Player.hpp"

Player::Player(ResourceManager<sf::Texture> &textureAllocator) : Guy(textureAllocator) {
    auto movement = this->addComponent<InputComponent>();
}
