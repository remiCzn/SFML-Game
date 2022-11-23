#include "ObjectCollection.hpp"

void ObjectCollection::add(const std::shared_ptr<Object> &object) {
    newObjects.push_back(object);
}

void ObjectCollection::update(const float &dt) {
    for (const auto &o: objects) {
        o->update(dt);
    }
}

void ObjectCollection::lateUpdate(const float &dt) {
    for (const auto &o: objects) {
        o->lateUpdate(dt);
    }
}

void ObjectCollection::draw(Window &window) {
    for (const auto &o: objects) {
        o->draw(window);
    }
}

void ObjectCollection::processNewObjects() {
    if (!newObjects.empty()) {
        for (const auto &o: newObjects) {
            o->awake();
        }

        for (const auto &o: newObjects) {
            o->start();
        }

        objects.assign(newObjects.begin(), newObjects.end());
        newObjects.clear();
    }
}

void ObjectCollection::processRemovals() {
    auto objItr = objects.begin();
    while (objItr != objects.end()) {
        auto obj = **objItr;
        if (obj.isQueuedForRemoval()) {
            objItr = objects.erase(objItr);
        } else {
            ++objItr;
        }
    }
}
