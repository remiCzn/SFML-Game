#include "PlayerAnimationComponent.h"

PlayerAnimationComponent::PlayerAnimationComponent(std::shared_ptr<PhysicsComponent> physics) : GraphicsComponent(
        "assets/character/chara1.png", sf::IntRect(0, 0, PLAYER_DIM.x, PLAYER_DIM.y), std::move(physics)) {
    this->direction = Down;
    this->state = Idle;
//    this->idle_animations.insert(std::make_pair(Down, sf::Vector2u(1, 0)));
//    this->idle_animations.insert(std::make_pair(Left, sf::Vector2u(1, 1)));
//    this->idle_animations.insert(std::make_pair(Right, sf::Vector2u(1, 2)));
//    this->idle_animations.insert(std::make_pair(Up, sf::Vector2u(1, 3)));

    this->animations[Down][Idle] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), INFINITY);
    this->animations[Left][Idle] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), INFINITY);
    this->animations[Right][Idle] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), INFINITY);
    this->animations[Up][Idle] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), INFINITY);

    this->animations[Down][Walk] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), 0.5);
    this->animations[Left][Walk] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), 0.5);
    this->animations[Right][Walk] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), 0.5);
    this->animations[Up][Walk] = std::make_unique<Animation<sf::Vector2i>>(std::vector<sf::Vector2i>(), 0.5);
}

void PlayerAnimationComponent::update(const float &dt) {
    GraphicsComponent::update(dt);
    this->updateDirection();
}

void PlayerAnimationComponent::setTexture(const int &x, const int &y) {
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
        sf::Vector2i idx = this->animations.at(new_dir).at(this->state)->getFrame();
        this->setTexture(idx.x, idx.y);
    }
}

void PlayerAnimationComponent::render(const std::shared_ptr<sf::RenderTarget> &target) {
    GraphicsComponent::render(target);
}


