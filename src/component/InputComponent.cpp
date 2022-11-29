#include "InputComponent.hpp"

InputComponent::InputComponent(Object *owner) : Component(owner), moveSpeed(100) {

}

void InputComponent::setInput(Input *_input) {
    this->input = _input;
}

void InputComponent::setMovementSpeed(int _moveSpeed) {
    this->moveSpeed = _moveSpeed;
}

void InputComponent::update(const float &dt) {
    if (input == nullptr) {
        return;
    }

    sf::Vector2f move = sf::Vector2f(0, 0);
    if (input->isKeyPressed(Input::Key::Left)) {
        move.x = -static_cast<float>(this->moveSpeed);
    } else if (input->isKeyPressed(Input::Key::Right)) {
        move.x = static_cast<float>(this->moveSpeed);
    }

    if (input->isKeyPressed(Input::Key::Up)) {
        move.y = -static_cast<float>(this->moveSpeed);
    } else if (input->isKeyPressed(Input::Key::Down)) {
        move.y = static_cast<float>(this->moveSpeed);
    }

    if (move == sf::Vector2f(0, 0)) {
        this->animation->setAnimation(AnimationState::Idle);
    } else {
        this->animation->setAnimation(AnimationState::Walk);
        if (move.x > 0) {
            this->animation->setDirection(FacingDirection::Right);
        } else if (move.x < 0) {
            this->animation->setDirection(FacingDirection::Left);
        } else {
            if (move.y > 0) {
                this->animation->setDirection(FacingDirection::Down);
            } else if (move.y < 0) {
                this->animation->setDirection(FacingDirection::Up);
            }
        }
    }
    this->owner->transform->translate(move * dt);
}

void InputComponent::awake() {
    this->animation = this->owner->getComponent<AnimationComponent>();
}
