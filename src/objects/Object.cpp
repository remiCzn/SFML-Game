#include "Object.hpp"

Object::Object() : queuedForRemoval(false) {
    this->addComponent<TransformComponent>();
    this->addComponent<InstanceIdComponent>();
}

void Object::awake() {
    for (auto &c: components) {
        c->awake();
    }
}

void Object::start() {
    for (auto &c: components) {
        c->start();
    }
}

void Object::update(const float &dt) {
    for (auto &c: components) {
        c->update(dt);
    }
}

void Object::lateUpdate(const float &dt) {
    for (auto &c: components) {
        c->lateUpdate(dt);
    }
}

void Object::draw(Window &window) {
    this->getComponent<DrawableComponent>()->draw(window);
}

bool Object::isQueuedForRemoval() const {
    return queuedForRemoval;
}

void Object::queueForRemoval() {
    queuedForRemoval = true;
}
