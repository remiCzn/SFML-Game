#include <string>
#include <iostream>
#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent(const std::string &asset_path, sf::IntRect intrect,
                                     std::shared_ptr<PhysicsComponent> physics) {
    if (!this->texture.loadFromFile(asset_path)) {
        std::cout << "Can't load asset from " + asset_path << std::endl;
    }
    this->texture_rect = intrect;
    this->_physics = physics;
    this->sprite = sf::Sprite(texture, this->texture_rect);
    this->sprite.setScale(5.0, 5.0);
}


void GraphicsComponent::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->draw(this->sprite);
}

void GraphicsComponent::update() {
    this->sprite.setPosition(this->_physics->getPosition());
    std::cout << this->sprite.getPosition().x << std::endl;
}

