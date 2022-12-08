#include "TilemapColliderComponent.hpp";

bool TilemapColliderComponent::intersects(std::shared_ptr<ColliderComponent> other) {
    return false;
}

TilemapColliderComponent::TilemapColliderComponent(Object *owner) : ColliderComponent(owner) {}

TilemapColliderComponent::~TilemapColliderComponent() = default;
