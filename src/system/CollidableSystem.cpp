#include "CollidableSystem.hpp"
#include "../utils/Debug.hpp"

CollidableSystem::CollidableSystem() = default;

void CollidableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto &o: objects) {
        auto collider = o->getComponent<BoxColliderComponent>();
        if (collider) {
            this->collidables.push_back(collider);
        }
    }
}

void CollidableSystem::processRemovals() {
    auto itr = collidables.begin();
    while (itr != collidables.end()) {
        if ((*itr)->owner->isQueuedForRemoval()) {
            itr = collidables.erase(itr);
        } else {
            ++itr;
        }
    }
}

void CollidableSystem::update() {
    for (auto &collidable: collidables) {
        if (collidable->owner->transform->isStatic()) {
            continue;
        }

        Colliders collisions = Colliders();

        for (auto &collision: collidables) {
            if (collidable->owner->instanceID->get() == collision->owner->instanceID->get()) {
                continue;
            }

            bool m = collidable->intersects(collision);

            if (m) {
                //TODO: Check if the collision block in both axis or not
                collidable->owner->transform->stopX();
                collidable->owner->transform->stopY();
            }
        }
    }
}
