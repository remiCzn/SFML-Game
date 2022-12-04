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
    collider->setCollidable(
            sf::FloatRect(0, 0, (float) GraphcisConsts::PLAYER_DIM.x, (float) GraphcisConsts::PLAYER_DIM.y));

    this->transform->setPosition(-8 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);
}
