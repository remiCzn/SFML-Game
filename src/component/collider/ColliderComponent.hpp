#ifndef GAME_COLLIDERCOMPONENT_HPP
#define GAME_COLLIDERCOMPONENT_HPP

#include "defines.hpp"
#include "../Component.hpp"
#include "../../objects/Object.hpp"

struct Manifold {
    bool colliding = false;
    sf::FloatRect other;
};

class ColliderComponent : public Component {
public:
    explicit ColliderComponent(Object *owner);

    ~ColliderComponent();

    virtual Manifold intersects(std::shared_ptr<ColliderComponent> other) = 0;

    virtual void resolveOverlap(const Manifold &m) = 0;

    bool isTrigger() const;

    void setTrigger(bool isTrigger);

private:
    bool _isTrigger;
};


#endif //GAME_COLLIDERCOMPONENT_HPP
