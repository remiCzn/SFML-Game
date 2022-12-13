#ifndef GAME_OBJECTCOLLECTION_HPP
#define GAME_OBJECTCOLLECTION_HPP

#include "Object.hpp"
#include "../system/DrawableSystem.hpp"
#include "../system/CollidableSystem.hpp"

class ObjectCollection {
public:
    void add(const std::shared_ptr<Object> &object);

    void update(const float &dt);

    void lateUpdate(const float &dt);

    void draw(Window &window);

    void processNewObjects();

    void processRemovals();

private:
    Container<Object> objects;
    Container<Object> newObjects;

    DrawableSystem drawables;
    CollidableSystem collidables;
};


#endif //GAME_OBJECTCOLLECTION_HPP
