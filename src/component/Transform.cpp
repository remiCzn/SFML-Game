//
// Created by cazin on 20/11/2022.
//

#include "Transform.hpp"

Transform::Transform(Object *owner) : Component(owner), position(0, 0) {

}

void Transform::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Transform::setPosition(const sf::Vector2f &pos) {
    position = pos;
}

void Transform::translate(float x, float y) {
    position.x += x;
    position.y += y;
}

void Transform::translate(sf::Vector2f pos) {
    position += pos;
}

void Transform::setX(float x) {
    position.x = x;
}

void Transform::setY(float y) {
    position.y = y;
}

void Transform::translateX(float x) {
    position.x += x;
}

void Transform::translateY(float y) {
    position.y += y;
}

const sf::Vector2f &Transform::getPosition() const {
    return this->position;
}
