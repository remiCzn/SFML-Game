#include "TransformComponent.hpp"

TransformComponent::TransformComponent(Object *owner)
        : Component(owner),
          position(0, 0),
          _isStatic(false),
          nextFramePosition(0, 0) {}

void TransformComponent::setPosition(float x, float y) {
    nextFramePosition.x = round(x);
    nextFramePosition.y = round(y);
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
    nextFramePosition.x = round(x);
}

void TransformComponent::setY(float y) {
    nextFramePosition.y = round(y);
}

void TransformComponent::translateX(float x) {
    nextFramePosition.x += round(x);
}

void TransformComponent::translateY(float y) {
    nextFramePosition.y += round(y);
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
    position = nextFramePosition;
}

const sf::Vector2f &TransformComponent::getNextFramePosition() const {
    return this->nextFramePosition;
}

void TransformComponent::stopX() {
    this->nextFramePosition.x = this->position.x;
}

void TransformComponent::stopY() {
    this->nextFramePosition.y = this->position.y;
}