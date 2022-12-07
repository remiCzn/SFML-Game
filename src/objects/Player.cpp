#include "Player.hpp"

#include <utility>
#include "../component/SpriteComponent.hpp"
#include "constants.hpp"
#include "../component/InputComponent.hpp"

Player::Player(ResourceManager<sf::Texture> &textureAllocator, std::shared_ptr<Input> input) : Object() {
    auto sprite = this->addComponent<SpriteComponent>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load("assets/character/chara1.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));

    auto movement = this->addComponent<InputComponent>();
    movement->setInput(std::move(input));

    auto animation = this->addComponent<AnimationComponent>();
    animation->load("assets/character/animations.json");

    this->transform->setPosition(-8 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);
}

void Player::update(const float &dt) {
    Object::update(dt);
    this->socket.updatePosition(this->transform->getPosition());
}
