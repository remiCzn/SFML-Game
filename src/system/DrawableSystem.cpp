#include "DrawableSystem.hpp"

void DrawableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto &o: objects) {
        this->add(o);
    }
    this->sort();
}

void DrawableSystem::processRemovals() {
    auto objIterator = drawables.begin();
    while (objIterator != drawables.end()) {
        auto obj = *objIterator;
        if (obj->isQueuedForRemoval()) {
            objIterator = drawables.erase(objIterator);
        } else {
            ++objIterator;
        }
    }
}

void DrawableSystem::draw(Window &window) {
    for (auto &d: drawables) {
        d->draw(window);
    }
}

void DrawableSystem::add(std::shared_ptr<Object> object) {
    std::shared_ptr<DrawableComponent> draw = object->getDrawable();

    if (draw) {
        drawables.emplace_back(object);
    }
}

void DrawableSystem::sort() {
    std::sort(drawables.begin(), drawables.end(),
              [](const std::shared_ptr<Object> &a, const std::shared_ptr<Object> &b) -> bool {
                  return a->getDrawable()->getSortOrder() < b->getDrawable()->getSortOrder();
              });
}
