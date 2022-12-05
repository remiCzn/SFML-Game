#include "CollidableSystem.hpp"
#include "../utils/Debug.hpp"

CollidableSystem::CollidableSystem() = default;

void CollidableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto &o: objects) {
        auto collider = o->getComponent<BoxColliderComponent>();
        if (collider) {
            this->collidables.push_back(collider);
            this->collisionTree.insert(collider);
        }
    }
}

void CollidableSystem::processRemovals() {
    auto itr = collidables.begin();
    while (itr != collidables.end()) {
        if ((*itr)->owner->isQueuedForRemoval()) {
            collisionTree.remove(*itr);
            itr = collidables.erase(itr);
        } else {
            ++itr;
        }
    }
}

void CollidableSystem::update() {
    collisionTree.drawDebug();
    collisionTree.clear();
    for (const auto &collidable: collidables) {
        collisionTree.insert(collidable);
    }
}

void CollidableSystem::resolve() {
    for (auto &collidable: collidables) {
        if (collidable->owner->transform->isStatic()) {
            continue;
        }

        Colliders collisions = collisionTree.search(collidable->getCollidable());

        for (auto &collision: collisions) {
            if (collidable->owner->instanceID->get() == collision->owner->instanceID->get()) {
                continue;
            }

            Manifold m = collidable->intersects(collision);

            if (m.colliding) {
                Debug::drawRect(collidable->getCollidable(), sf::Color::Red);
                Debug::drawRect(collision->getCollidable(), sf::Color::Red);

                if (collision->owner->transform->isStatic()) {
                    collidable->resolveOverlap(m);
                } else {
                    //TODO handle where both objects are not static // implements rigidbody & mass
                    collidable->resolveOverlap(m);
                }
            }
        }
    }
}

void CollidableSystem::updatePosition(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto o: objects) {
        if (!o->transform->isStatic()) {
            auto collider = o->getComponent<BoxColliderComponent>();

            if (collider) {
                collisionTree.updatePosition(collider);
            }
        }
    }
}
