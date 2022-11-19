#include "Object.hpp"

void Object::awake() {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->awake();
    }
}

void Object::start() {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->start();
    }
}

void Object::update(const float &dt) {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->update(dt);
    }
}

void Object::lateUpdate(const float &dt) {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->lateUpdate(dt);
    }
}

void Object::draw(Window &window) {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->draw(window);
    }
}
