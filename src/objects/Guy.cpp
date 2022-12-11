#include "Guy.hpp"

Guy::Guy(ResourceManager<sf::Texture> &textureAllocator) {
    auto sprite = this->addComponent<SpriteComponent>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load("assets/character/chara1_2.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));

    auto animation = this->addComponent<AnimationComponent>();
    animation->load("assets/character/animations.json");

    auto collider = this->addComponent<BoxColliderComponent>();

    collider->setOffset(3, 8);
    collider->setSize(GraphcisConsts::PLAYER_DIM.x - 6, GraphcisConsts::PLAYER_DIM.y - 9);

    this->transform->setPosition(-8 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);
}

void Guy::update(const float &dt) {
    Object::update(dt);
}
