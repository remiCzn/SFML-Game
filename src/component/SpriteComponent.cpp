#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(Object *owner) : Component(owner) {

}

void SpriteComponent::load(const std::string &filePath) {
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void SpriteComponent::draw(Window &window) {
    window.draw(sprite);
}

void SpriteComponent::setTextureRect(sf::IntRect textureRect) {
    this->sprite.setTextureRect(textureRect);
}

void SpriteComponent::lateUpdate(const float &dt) {
    this->sprite.setPosition(owner->transform->getPosition());
}
