#include "InstanceIdComponent.hpp"

int InstanceIdComponent::count = 0;

InstanceIdComponent::InstanceIdComponent(Object *owner) : Component(owner), id(count++) {

}

InstanceIdComponent::~InstanceIdComponent() = default;

int InstanceIdComponent::get() const {
    return id;
}
