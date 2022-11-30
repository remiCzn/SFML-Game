#include "BoxColliderComponent.hpp"

BoxColliderComponent::BoxColliderComponent(Object *owner) : ColliderComponent(owner), origin(Origin::AbsCentre),
                                                            offset(sf::Vector2f(0.f, 0.f)) {}

BoxColliderComponent::~BoxColliderComponent() = default;

Manifold BoxColliderComponent::intersects(std::shared_ptr<ColliderComponent> other) {
    Manifold m;
    m.colliding = false;

    std::shared_ptr<BoxColliderComponent> boxCollider = std::dynamic_pointer_cast<BoxColliderComponent>(other);
    if (boxCollider) {
        const sf::FloatRect &rect1 = getCollidable();
        const sf::FloatRect &rect2 = boxCollider->getCollidable();

        if (rect1.intersects(rect2)) {
            m.colliding = true;
            m.other = rect2;
        }
    }

    return m;
}

void BoxColliderComponent::resolveOverlap(const Manifold &m) {
    auto transform = this->owner->transform;

    if (transform->isStatic()) { return; }

    const sf::FloatRect &rect1 = getCollidable();
    const sf::FloatRect &rect2 = m.other;

    if (!rect1.intersects(rect2)) { return; }

    float resolve = 0;
    float xDiff = (rect1.left + (rect1.width * 0.5f) - (rect2.left + (rect2.width * 0.5f)));
    float yDiff = (rect1.top + (rect1.height * 0.5f) - (rect2.top + (rect2.height * 0.5f)));

    if (fabs(xDiff) > fabs(yDiff)) {
        if (xDiff > 0) {
            resolve = (rect2.left + rect2.width) - rect1.left;
        } else {
            resolve = -((rect1.left + rect1.width) - rect2.left);
        }

        transform->translate(resolve, 0);
    } else {
        if (xDiff > 0) {
            resolve = (rect2.top + rect2.height) - rect1.top;
        } else {
            resolve = -((rect1.top + rect1.height) - rect2.top);
        }

        transform->translate(0, resolve);
    }

}

void BoxColliderComponent::setCollidable(const sf::FloatRect &rect) {
    AABB = rect;
    setPosition();
}

const sf::FloatRect &BoxColliderComponent::getCollidable() {
    setPosition();
    return AABB;
}

void BoxColliderComponent::setOrigin(const Origin &origin) {
    this->origin = origin;
}

void BoxColliderComponent::setPosition() {
    const sf::Vector2f &pos = owner->transform->getPosition();

    switch (origin) {
        case (Origin::TopLeft): {
            AABB.left = pos.x + offset.x;
            AABB.top = pos.y + offset.y;
            break;
        }
        case (Origin::AbsCentre): {
            AABB.left = pos.x - (AABB.width / 2) + offset.x;
            AABB.top = pos.y - (AABB.height / 2) + offset.y;
            break;
        }
        case (Origin::MidBottom): {
            AABB.left = pos.x - (AABB.width / 2) + offset.x;
            AABB.top = pos.y - AABB.height + offset.y;
        }
    }
}
