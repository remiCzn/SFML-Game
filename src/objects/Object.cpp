#include "Object.hpp"

Object::Object() : queuedForRemoval(false) {
    transform = this->addComponent<TransformComponent>();
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
    drawable->draw(window);
}

bool Object::isQueuedForRemoval() const {
    return queuedForRemoval;
}

void Object::queueForRemoval() {
    queuedForRemoval = true;
}

std::shared_ptr<DrawableComponent> Object::getDrawable() {
    return drawable;
}
