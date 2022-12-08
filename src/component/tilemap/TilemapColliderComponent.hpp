#ifndef GAME_TILEMAPCOLLIDERCOMPONENT_HPP
#define GAME_TILEMAPCOLLIDERCOMPONENT_HPP


#include "../collider/ColliderComponent.hpp"

class TilemapColliderComponent : public ColliderComponent {
public:
    explicit TilemapColliderComponent(Object *owner);

    ~TilemapColliderComponent();

    bool intersects(std::shared_ptr<ColliderComponent> other) override;
};


#endif //GAME_TILEMAPCOLLIDERCOMPONENT_HPP
