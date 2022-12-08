#include "BoxColliderComponent.hpp"

BoxColliderComponent::BoxColliderComponent(Object *owner) : ColliderComponent(owner),
                                                            offset(sf::Vector2f(0.f, 0.f)) {}

BoxColliderComponent::~BoxColliderComponent() = default;

bool BoxColliderComponent::intersects(std::shared_ptr<ColliderComponent> other) {
    std::shared_ptr<BoxColliderComponent> boxCollider = std::dynamic_pointer_cast<BoxColliderComponent>(other);
    if (boxCollider) {
        const sf::FloatRect &rect1 = getCollidable();
        const sf::FloatRect &rect2 = boxCollider->getCollidable();

        if (rect1.intersects(rect2)) {
            return true;
        }
    }

    return false;
}

void BoxColliderComponent::setCollidable(const sf::FloatRect &rect) {
    AABB = rect;
    setPosition();
}

const sf::FloatRect &BoxColliderComponent::getCollidable() {
    setPosition();
    return AABB;
}

void BoxColliderComponent::setPosition() {
    const sf::Vector2f &pos = owner->transform->getNextFramePosition();

    AABB.left = pos.x + offset.x;
    AABB.top = pos.y + offset.y;
}

void BoxColliderComponent::setOffset(const sf::Vector2f &_offset) {
    this->offset = _offset;
}

void BoxColliderComponent::setOffset(float x, float y) {
    offset.x = x;
    offset.y = y;
}

void BoxColliderComponent::setSize(const sf::Vector2f &size) {
    AABB.width = size.x;
    AABB.height = size.y;
}

void BoxColliderComponent::setSize(float width, float height) {
    AABB.width = width;
    AABB.height = height;
}
