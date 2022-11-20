#include "InputMovement.hpp"

InputMovement::InputMovement(Object *owner) : Component(owner), moveSpeed(100) {

}

void InputMovement::setInput(Input *input) {
    this->input = input;
}

void InputMovement::setMovementSpeed(int moveSpeed) {
    this->moveSpeed = moveSpeed;
}

void InputMovement::update(const float &dt) {
    if (input == nullptr) {
        return;
    }

    sf::Vector2f move = sf::Vector2f(0, 0);
    if (input->isKeyPressed(Input::Key::Left)) {
        move.x = -this->moveSpeed;
    } else if (input->isKeyPressed(Input::Key::Right)) {
        move.x = this->moveSpeed;
    }

    if (input->isKeyPressed(Input::Key::Up)) {
        move.y = -this->moveSpeed;
    } else if (input->isKeyPressed(Input::Key::Down)) {
        move.y = this->moveSpeed;
    }
    this->owner->transform->translate(move * dt);
}
