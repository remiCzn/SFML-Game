#ifndef GAME_COLLIDABLESYSTEM_HPP
#define GAME_COLLIDABLESYSTEM_HPP

#include "defines.hpp"
#include "../objects/Object.hpp"
#include "../component/collider/BoxColliderComponent.hpp"
#include "Quadtree.hpp"

class CollidableSystem {
public:
    CollidableSystem();

    void add(std::vector<std::shared_ptr<Object>> &objects);

    void processRemovals();

    void update();

private:
    void resolve();

    void processCollisions(std::vector<std::shared_ptr<Object>> &first, std::vector<std::shared_ptr<Object>> &second);

    std::map<int, int> collisionLayers;
    std::map<int, std::vector<std::shared_ptr<BoxColliderComponent>>> collidables;

    Quadtree collisionTree;
};


#endif //GAME_COLLIDABLESYSTEM_HPP
