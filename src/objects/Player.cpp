#include "Player.hpp"
#include "../component/SpriteComponent.hpp"
#include "constants.hpp"
#include "../component/InputComponent.hpp"
#include "../component/collider/BoxColliderComponent.hpp"

Player::Player(ResourceManager<sf::Texture> &textureAllocator, Input &input) : Object() {
    auto sprite = this->addComponent<SpriteComponent>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load("assets/character/chara1.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));

    auto movement = this->addComponent<InputComponent>();
    movement->setInput(&input);

    auto animation = this->addComponent<AnimationComponent>();
    animation->load("assets/character/animations.json");

    auto collider = this->addComponent<BoxColliderComponent>();
    float offset_x = 1.5;
    float offset_y = 3;

    collider->setOffset(offset_x, offset_y);
    collider->setSize(GraphcisConsts::PLAYER_DIM.x - 6, GraphcisConsts::PLAYER_DIM.y - 3);

    this->transform->setPosition(-8 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);
}
