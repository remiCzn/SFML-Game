#include "PlayerAnimationComponent.h"

PlayerAnimationComponent::PlayerAnimationComponent(std::shared_ptr<PhysicsComponent> physics) : GraphicsComponent(
        "assets/character/chara1.png", sf::IntRect(0, 0, PLAYER_DIM.x, PLAYER_DIM.y), std::move(physics)) {
    this->direction = Down;
    this->state = Idle;
    this->changingTexture = false;

    this->initAnimation(Down, Idle, {sf::Vector2i(1, 0)}, INFINITY);
    this->initAnimation(Left, Idle, {sf::Vector2i(1, 1)}, INFINITY);
    this->initAnimation(Right, Idle, {sf::Vector2i(1, 2)}, INFINITY);
    this->initAnimation(Up, Idle, {sf::Vector2i(1, 3)}, INFINITY);

    this->initAnimation(Down, Walk, {
            sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(1, 0)}, (float) 0.15);
    this->initAnimation(Left, Walk, {
            sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(1, 1)}, (float) 0.15);
    this->initAnimation(Right, Walk, {
            sf::Vector2i(0, 2), sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(1, 2)}, (float) 0.15);
    this->initAnimation(Up, Walk, {
            sf::Vector2i(0, 3), sf::Vector2i(1, 3), sf::Vector2i(2, 3), sf::Vector2i(1, 3)}, (float) 0.15);
}

void PlayerAnimationComponent::initAnimation(
        Direction _direction,
        State _state,
        const std::vector<sf::Vector2i> &_frames,
        float _delay
) {
    this->animations[_direction][_state] = std::make_unique<Animation<sf::Vector2i>>(_frames, _delay);
}

void PlayerAnimationComponent::update(const float &dt) {
    GraphicsComponent::update(dt);
    this->updateDirectionAndState();
    bool hasChanged = this->animations.at(this->direction).at(this->state)->tick(dt);
    if (hasChanged || this->changingTexture) {
        sf::Vector2i idx = this->animations.at(this->direction).at(this->state)->getFrame();
        this->setTexture(idx.x, idx.y);
    }
}

void PlayerAnimationComponent::setTexture(const int &x, const int &y) {
    this->sprite.setTextureRect(sf::IntRect(x * PLAYER_DIM.x, y * PLAYER_DIM.y, PLAYER_DIM.x, PLAYER_DIM.y));
    this->changingTexture = false;
}

void PlayerAnimationComponent::updateDirectionAndState() {
    sf::Vector2f v = this->_physics->getVelocity();
    if (v.x > 0) {
        this->setState(Walk);
        this->setDirection(Right);
    } else if (v.x < 0) {
        this->setState(Walk);
        this->setDirection(Left);
    } else {
        if (v.y > 0) {
            this->setState(Walk);
            this->setDirection(Down);
        } else if (v.y < 0) {
            this->setState(Walk);
            this->setDirection(Up);
        } else {
            this->setState(Idle);
        }
    }
}

void PlayerAnimationComponent::setDirection(const Direction &new_dir) {
    if (this->direction != new_dir) {
        this->direction = new_dir;
        this->changingTexture = true;
    }
}

void PlayerAnimationComponent::setState(const State &new_state) {
    if (this->state != new_state) {
        this->state = new_state;
        this->changingTexture = true;
    }
}

void PlayerAnimationComponent::render(const std::shared_ptr<sf::RenderTarget> &target) {
    GraphicsComponent::render(target);
}


