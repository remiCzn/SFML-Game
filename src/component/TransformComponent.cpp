//
// Created by cazin on 20/11/2022.
//

#include "TransformComponent.hpp"

TransformComponent::TransformComponent(Object *owner) : Component(owner), position(0, 0) {

}

void TransformComponent::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void TransformComponent::setPosition(const sf::Vector2f &pos) {
    position = pos;
}

void TransformComponent::translate(float x, float y) {
    position.x += x;
    position.y += y;
}

void TransformComponent::translate(sf::Vector2f pos) {
    position += pos;
}

void TransformComponent::setX(float x) {
    position.x = x;
}

void TransformComponent::setY(float y) {
    position.y = y;
}

void TransformComponent::translateX(float x) {
    position.x += x;
}

void TransformComponent::translateY(float y) {
    position.y += y;
}

const sf::Vector2f &TransformComponent::getPosition() const {
    return this->position;
}
