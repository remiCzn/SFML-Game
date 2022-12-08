#ifndef GAME_COLLIDERCOMPONENT_HPP
#define GAME_COLLIDERCOMPONENT_HPP

#include "defines.hpp"
#include "../Component.hpp"
#include "../../objects/Object.hpp"

class ColliderComponent : public Component {
public:
    explicit ColliderComponent(Object *owner);

    ~ColliderComponent();

    virtual bool intersects(std::shared_ptr<ColliderComponent> other) = 0;
};


#endif //GAME_COLLIDERCOMPONENT_HPP
