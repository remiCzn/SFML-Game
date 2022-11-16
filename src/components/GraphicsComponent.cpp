#include <string>
#include <iostream>
#include <utility>
#include "GraphicsComponent.hpp"

GraphicsComponent::GraphicsComponent(const std::string &asset_path, sf::IntRect intrect,
                                     std::shared_ptr<PhysicsComponent> physics) {
    if (!this->texture.loadFromFile(asset_path)) {
        std::cout << "Can't load asset from " + asset_path << std::endl;
    }
    this->texture_rect = intrect;
    this->_physics = std::move(physics);
    this->sprite = sf::Sprite(texture, this->texture_rect);
}


void GraphicsComponent::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->draw(this->sprite);
}

void GraphicsComponent::update(const float &dt) {
    this->sprite.setPosition((sf::Vector2f) (sf::Vector2i) this->_physics->getPosition());
}

