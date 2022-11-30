#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent() : sortOrder(0) {

}

DrawableComponent::~DrawableComponent() = default;

void DrawableComponent::setOrder(int order) {
    sortOrder = order;
}

int DrawableComponent::getSortOrder() const {
    return sortOrder;
}
