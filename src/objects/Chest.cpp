#include "Chest.hpp"
#include "../component/SpriteComponent.hpp"
#include "constants.hpp"
#include "../component/collider/BoxColliderComponent.hpp"

Chest::Chest(ResourceManager<sf::Texture> &textureAllocator) : Object() {
    auto sprite = this->addComponent<SpriteComponent>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load("assets/tilesheet/inside.png");
    sprite->setTextureRect(sf::IntRect(512, 336, 16, 32));

    auto collider = this->addComponent<BoxColliderComponent>();
    collider->setSize(16, 20);
    collider->setOffset(0, 5);

    this->transform->setStatic(true);
}


