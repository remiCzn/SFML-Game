#ifndef GAME_COLLIDABLESYSTEM_HPP
#define GAME_COLLIDABLESYSTEM_HPP

#include "defines.hpp"
#include "../objects/Object.hpp"
#include "../component/collider/BoxColliderComponent.hpp"

using Colliders = std::vector<std::shared_ptr<BoxColliderComponent>>;

class CollidableSystem {
public:
    CollidableSystem();

    void add(std::vector<std::shared_ptr<Object>> &objects);

    void processRemovals();

    void update();

private:
    std::vector<std::shared_ptr<BoxColliderComponent>> collidables;
};


#endif //GAME_COLLIDABLESYSTEM_HPP
