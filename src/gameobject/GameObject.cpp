#include "GameObject.h"

void GameObject::add_graphics_component(std::string asset_path, sf::IntRect texture_rect) {
    this->_graphics.reset(new GraphicsComponent(asset_path, texture_rect, this->_physics));
}

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
    if (this->_physics) {
        this->_physics->update(dt);
    }
    if (this->_graphics) {
        this->_graphics->update();
    }
}

void GameObject::render(const std::shared_ptr<sf::RenderTarget> &target) {
    if (this->_graphics) {
        this->_graphics->render(target);
    }
}

void GameObject::handleInput(sf::Keyboard::Key &keycode) {
    if (this->_input) {
        this->_input->handleInput(keycode);
    }
}
