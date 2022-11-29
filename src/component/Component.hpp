#ifndef GAME_COMPONENT_HPP
#define GAME_COMPONENT_HPP

#include "../utils/Window.hpp"

class Object;

class Component {
public:
    explicit Component(Object *owner) : owner(owner) {}

    virtual void awake() {};

    virtual void start() {};

    virtual void update(const float &dt) {};

    virtual void lateUpdate(const float &dt) {};
    
    Object *owner;
};

#endif //GAME_COMPONENT_HPP
