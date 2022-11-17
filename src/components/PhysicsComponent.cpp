#include "PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent() {
    this->position = sf::Vector2f(-8 * TilemapConsts::TILE_SIZE,
                                  -8 * TilemapConsts::TILE_SIZE);
    this->velocity = sf::Vector2f(0, 0);
    this->box = sf::FloatRect(
            this->position.x,
            this->position.x,
            static_cast<float>(GraphcisConsts::PLAYER_DIM.x),
            static_cast<float>(GraphcisConsts::PLAYER_DIM.y)
    );
    this->boxshape.setOutlineThickness(1.f);
    this->boxshape.setOutlineColor(sf::Color::Green);
    this->boxshape.setFillColor(sf::Color::Transparent);
}

void PhysicsComponent::update(const float &dt, std::shared_ptr<World> world) {
    this->getNextPosition(dt);
    this->position += this->velocity * dt;
    this->velocity = sf::Vector2f(0, 0);
}

void PhysicsComponent::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->draw(this->boxshape);
}

void PhysicsComponent::setVelocityX(float x) {
    this->velocity.x = x;
}

void PhysicsComponent::setVelocityY(float y) {
    this->velocity.y = y;
}

const sf::Vector2f &PhysicsComponent::getPosition() {
    return this->position;
}

const sf::Vector2f &PhysicsComponent::getVelocity() {
    return this->velocity;
}

const sf::FloatRect &PhysicsComponent::getNextPosition(const float &dt) {
    this->box.left = this->position.x + this->velocity.x * dt;
    this->box.top = this->position.y + this->velocity.y * dt;
    this->boxshape.setPosition(this->box.left, this->box.top);
    return this->box;
}
