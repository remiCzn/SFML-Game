#include "ColliderComponent.hpp"

ColliderComponent::ColliderComponent(Object *owner) : Component(owner), _isTrigger(false) {}

ColliderComponent::~ColliderComponent() = default;

bool ColliderComponent::isTrigger() const {
    return _isTrigger;
}

void ColliderComponent::setTrigger(bool isTrigger) {
    this->_isTrigger = isTrigger;
}
