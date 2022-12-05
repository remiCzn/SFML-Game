#include "TransformComponent.hpp"

TransformComponent::TransformComponent(Object *owner)
        : Component(owner),
          position(0, 0),
          _isStatic(false),
          previousFramePosition(0, 0) {}

void TransformComponent::setPosition(float x, float y) {
    position.x = round(x);
    position.y = round(y);
}

void TransformComponent::setPosition(const sf::Vector2f &pos) {
    setPosition(pos.x, pos.y);
}

void TransformComponent::translate(float x, float y) {
    translateX(x);
    translateY(y);
}

void TransformComponent::translate(sf::Vector2f pos) {
    translate(pos.x, pos.y);
}

void TransformComponent::setX(float x) {
    position.x = round(x);
}

void TransformComponent::setY(float y) {
    position.y = round(y);
}

void TransformComponent::translateX(float x) {
    position.x += round(x);
}

void TransformComponent::translateY(float y) {
    position.y += round(y);
}

const sf::Vector2f &TransformComponent::getPosition() const {
    return this->position;
}

void TransformComponent::setStatic(bool isStatic) {
    _isStatic = isStatic;
}

bool TransformComponent::isStatic() const {
    return this->_isStatic;
}

void TransformComponent::lateUpdate(const float &dt) {
    previousFramePosition = position;
}

const sf::Vector2f &TransformComponent::getPreviousFramePosition() const {
    return this->previousFramePosition;
}
