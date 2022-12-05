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

    sf::FloatRect getPreviousFrameCollidable() const;

    void setOffset(const sf::Vector2f &_offset);

    void setOffset(float x, float y);

    void setSize(const sf::Vector2f &size);

    void setSize(float width, float height);

private:
    void setPosition();

    sf::FloatRect AABB;
    sf::Vector2f offset;
};


#endif //GAME_BOXCOLLIDERCOMPONENT_HPP
