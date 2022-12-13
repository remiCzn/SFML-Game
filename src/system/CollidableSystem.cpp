#include "CollidableSystem.hpp"
#include "../utils/Debug.hpp"

CollidableSystem::CollidableSystem() = default;

void CollidableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto &o: objects) {
        auto collider = o->getComponent<ColliderComponent>();
        if (collider) {
            this->collidables.push_back(collider);
        }
    }
}

void CollidableSystem::processRemovals() {
    auto itr = collidables.begin();
    while (itr != collidables.end()) {
        auto obj = *itr;
        if (obj->owner->isQueuedForRemoval()) {
            itr = collidables.erase(itr);
        } else {
            ++itr;
        }
    }
}

void CollidableSystem::update() {
    for (auto &collidable: collidables) {
        Debug::drawRect(collidable->getCollidable(), sf::Color::Red);
        if (collidable->owner->getComponent<TransformComponent>()->isStatic()) {
            continue;
        }

        Colliders collisions = Colliders();

        for (auto &collision: collidables) {
            if (collidable->owner->getComponent<InstanceIdComponent>()->get() ==
                collision->owner->getComponent<InstanceIdComponent>()->get()) {
                continue;
            }

            bool m = collidable->intersects(collision);

            if (m) {
                //TODO: Check if the collision block in both axis or not
                collidable->owner->getComponent<TransformComponent>()->stopX();
                collidable->owner->getComponent<TransformComponent>()->stopY();
            }
        }
    }
}
