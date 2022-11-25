#ifndef GAME_BOXCOLLIDERCOMPONENT_HPP
#define GAME_BOXCOLLIDERCOMPONENT_HPP

#include "ColliderComponent.hpp"

enum class Origin {
    TopLeft,
    AbsCentre,
    MidBottom
};

class BoxColliderComponent : public ColliderComponent {
public:
    explicit BoxColliderComponent(Object *owner);

    ~BoxColliderComponent();

    Manifold intersects(std::shared_ptr<ColliderComponent> other) override;

    void resolveOverlap(const Manifold &m) override;

    void setCollidable(const sf::FloatRect &rect);

    const sf::FloatRect &getCollidable();

    void setOrigin(const Origin &origin);

private:
    void setPosition();

    sf::FloatRect AABB;
    Origin origin;
    sf::Vector2f offset;
};


#endif //GAME_BOXCOLLIDERCOMPONENT_HPP
