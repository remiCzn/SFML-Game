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
    drawables.draw(window);
}

void ObjectCollection::processNewObjects() {
    if (!newObjects.empty()) {
        for (const auto &o: newObjects) {
            o->awake();
        }

        for (const auto &o: newObjects) {
            o->start();
        }

        objects.insert(objects.end(), newObjects.begin(), newObjects.end());
        drawables.add(newObjects);
        collidables.add(newObjects);
        newObjects.clear();
    }
}

void ObjectCollection::processRemovals() {
    bool removed = false;
    auto objItr = objects.begin();
    while (objItr != objects.end()) {
        auto obj = *objItr;
        if (obj->isQueuedForRemoval()) {
            objItr = objects.erase(objItr);
            removed = true;
        } else {
            ++objItr;
        }
    }
    if (removed) {
        drawables.processRemovals();
        collidables.processRemovals();
    }

}
