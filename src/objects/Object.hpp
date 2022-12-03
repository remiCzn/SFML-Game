#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


#include "../utils/Window.hpp"
#include "../component/Component.hpp"
#include "../component/TransformComponent.hpp"
#include "../component/DrawableComponent.hpp"
#include "../component/InstanceIdComponent.hpp"

class Object {
public:
    Object();

    void awake();

    void start();

    void update(const float &dt);

    void lateUpdate(const float &dt);

    virtual void draw(Window &window);

    template<typename T>
    std::shared_ptr<T> addComponent() {

        for (auto &existingComponent: components) {
            if (std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }

        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);
        if (std::dynamic_pointer_cast<DrawableComponent>(newComponent)) {
            drawable = std::dynamic_pointer_cast<DrawableComponent>(newComponent);
        }
        return newComponent;
    }

    template<typename T>
    std::shared_ptr<T> getComponent() {
        for (auto &existingComponent: components) {
            if (std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }

        return nullptr;
    }

    std::shared_ptr<DrawableComponent> getDrawable();

    bool isQueuedForRemoval() const;

    void queueForRemoval();

    std::shared_ptr<TransformComponent> transform;
    std::shared_ptr<InstanceIdComponent> instanceID;

private:
    std::vector<std::shared_ptr<Component>> components;
    std::shared_ptr<DrawableComponent> drawable;
    bool queuedForRemoval;
};


#endif //GAME_OBJECT_HPP
