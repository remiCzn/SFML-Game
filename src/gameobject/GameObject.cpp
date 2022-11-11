#include "GameObject.h"

void GameObject::add_graphics_component(GraphicsComponent *graphicsComponent) {
    this->_graphics.reset(graphicsComponent);
}

void GameObject::add_input_component(InputComponent *inputComponent) {
    this->_input.reset(inputComponent);
}

void GameObject::add_physics_component(PhysicsComponent *physicsComponent) {
    this->_physics.reset(physicsComponent);
}

void GameObject::update(const float &dt) {
    if (this->_input) {
        this->_input->update();
    }
    if (this->_graphics) {
        this->_graphics->update(dt);
    }
    if (this->_physics) {
        this->_physics->update(dt);
    }
}

void GameObject::render(const std::shared_ptr<sf::RenderTarget> &target) {
    if (this->_graphics) {
        this->_graphics->render(target);
    }
}

void GameObject::handleInput(const sf::Keyboard::Key &keycode) {
    if (this->_input) {
        this->_input->handleInput(keycode);
    }
}
