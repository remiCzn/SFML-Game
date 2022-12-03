#include "CollidableSystem.hpp"

CollidableSystem::CollidableSystem() {
//TODO
}

void CollidableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto &o: objects) {
        auto collider = o->getComponent<BoxColliderComponent>();
        if (collider) {
            //TODO
            collisionTree.insert(collider);
        }
    }
}

void CollidableSystem::processRemovals() {

}

void CollidableSystem::update() {

}

void CollidableSystem::resolve() {

}

void CollidableSystem::processCollisions(std::vector<std::shared_ptr<Object>> &first,
                                         std::vector<std::shared_ptr<Object>> &second) {

}
