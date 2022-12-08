#ifndef GAME_TILEMAPCOLLIDERCOMPONENT_HPP
#define GAME_TILEMAPCOLLIDERCOMPONENT_HPP


#include "../collider/ColliderComponent.hpp"
#include "./TilemapComponent.hpp"

class TilemapColliderComponent : public ColliderComponent {
public:
    explicit TilemapColliderComponent(Object *owner);

    void load();

    ~TilemapColliderComponent();

    bool intersects(std::shared_ptr<ColliderComponent> other) override;

    bool intersects(const sf::FloatRect &other);

    const sf::FloatRect &getCollidable() override;

    void drawDebug();

private:
    std::vector<sf::FloatRect> collidingTiles;
    sf::FloatRect AABB;
    Map<bool> collision_map;
};


#endif //GAME_TILEMAPCOLLIDERCOMPONENT_HPP
