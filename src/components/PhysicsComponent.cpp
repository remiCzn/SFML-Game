#include "PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent() {
    this->position = sf::Vector2f(-16 * TilemapConsts::TILE_SIZE,
                                  -16 * TilemapConsts::TILE_SIZE);
    this->velocity = sf::Vector2f(0, 0);
    this->box = sf::FloatRect(this->position.x, this->position.x, 19, 27);
}

void PhysicsComponent::update(float dt) {
    this->position += this->velocity * dt;
    this->velocity = sf::Vector2f(0, 0);
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
