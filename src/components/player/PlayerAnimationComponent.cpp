#include "PlayerAnimationComponent.h"

PlayerAnimationComponent::PlayerAnimationComponent(std::shared_ptr<PhysicsComponent> physics) : GraphicsComponent(
        "assets/character/chara1.png", sf::IntRect(0, 0, PLAYER_DIM.x, PLAYER_DIM.y), std::move(physics)) {
    this->direction = Down;
    this->animations.insert(std::make_pair(Down, sf::Vector2u(1, 0)));
    this->animations.insert(std::make_pair(Left, sf::Vector2u(1, 1)));
    this->animations.insert(std::make_pair(Right, sf::Vector2u(1, 2)));
    this->animations.insert(std::make_pair(Up, sf::Vector2u(1, 3)));
}

void PlayerAnimationComponent::update(const float &dt) {
    GraphicsComponent::update(dt);
    this->updateDirection();
}

void PlayerAnimationComponent::setTexture(int x, int y) {
    this->sprite.setTextureRect(sf::IntRect(x * PLAYER_DIM.x, y * PLAYER_DIM.y, PLAYER_DIM.x, PLAYER_DIM.y));
}

void PlayerAnimationComponent::updateDirection() {
    sf::Vector2f v = this->_physics->getVelocity();
    if (v.x > 0) {
        this->setDirection(Right);
    } else if (v.x < 0) {
        this->setDirection(Left);
    } else {
        if (v.y > 0) {
            this->setDirection(Down);
        } else if (v.y < 0) {
            this->setDirection(Up);
        }
    }
}

void PlayerAnimationComponent::setDirection(const Direction &new_dir) {
    if (this->direction != new_dir) {
        this->direction = new_dir;
        sf::Vector2i idx = this->animations.at(new_dir);
        this->setTexture(idx.x, idx.y);
    }
}

void PlayerAnimationComponent::render(const std::shared_ptr<sf::RenderTarget> &target) {
    GraphicsComponent::render(target);
}


