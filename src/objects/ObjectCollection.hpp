#ifndef GAME_OBJECTCOLLECTION_HPP
#define GAME_OBJECTCOLLECTION_HPP

#include "Object.hpp"

class ObjectCollection {
public:
    void add(const std::shared_ptr<Object> &object);

    void update(const float &dt);

    void lateUpdate(const float &dt);

    void draw(Window &window);

    void processNewObjects();

    void processRemovals();

private:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> newObjects;
};


#endif //GAME_OBJECTCOLLECTION_HPP
