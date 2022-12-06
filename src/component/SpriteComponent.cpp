#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(Object *owner) : Component(owner), allocator(nullptr) {

}

void SpriteComponent::load(const std::string &filePath) {
    if (allocator) {
        int textureId = allocator->add(filePath);

        this->load(textureId);
    }
}

void SpriteComponent::draw(Window &window) {
    window.draw(sprite);
}

void SpriteComponent::setTextureRect(sf::IntRect textureRect) {
    this->sprite.setTextureRect(textureRect);
}

void SpriteComponent::lateUpdate(const float &dt) {
    sf::Vector2f pos = owner->transform->getPosition();
    const sf::IntRect &spriteBounds = sprite.getTextureRect();
    sprite.setPosition(
            pos.x,
            pos.y
    );
}

void SpriteComponent::setTextureAllocator(ResourceManager<sf::Texture> *textureAllocator) {
    this->allocator = textureAllocator;
}

void SpriteComponent::load(int id) {
    if (id >= 0) {
        std::shared_ptr<sf::Texture> texture = allocator->get(id);
        sprite.setTexture(*texture);
    }
}
