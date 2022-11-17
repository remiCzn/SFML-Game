#include "GameObject.hpp"

void GameObject::add_graphics_component(GraphicsComponent *graphicsComponent) {
    this->_graphics.reset(graphicsComponent);
}

void GameObject::add_input_component(InputComponent *inputComponent) {
    this->_input.reset(inputComponent);
}

void GameObject::add_physics_component(PhysicsComponent *physicsComponent) {
    this->_physics.reset(physicsComponent);
}

void GameObject::update(const float &dt, std::shared_ptr<World> world) {
    if (this->_input) {
        this->_input->update();
    }
    if (this->_graphics) {
        this->_graphics->update(dt);
    }
    if (this->_physics) {
        this->_physics->update(dt, world);
    }
}

void GameObject::render(const std::shared_ptr<sf::RenderTarget> &target) {
    if (this->_graphics) {
        this->_graphics->render(target);
    }

    if (this->_physics) {
        this->_physics->render(target);
    }
}

void GameObject::handleInput(const sf::Keyboard::Key &keycode) {
    if (this->_input) {
        this->_input->handleInput(keycode);
    }
}
