#include "Sprite.hpp"

Sprite::Sprite(Object *owner) : Component(owner) {

}

void Sprite::load(const std::string &filePath) {
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void Sprite::draw(Window &window) {
    window.draw(sprite);
}

void Sprite::setTextureRect(sf::IntRect textureRect) {
    this->sprite.setTextureRect(textureRect);
}

void Sprite::lateUpdate(const float &dt) {
    this->sprite.setPosition(owner->transform->getPosition());
}
