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
        auto comp = getComponent<T>();
        if (comp != nullptr) {
            return comp;
        }

        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);
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

    bool isQueuedForRemoval() const;

    void queueForRemoval();

private:
    Container<Component> components;
    bool queuedForRemoval;
};


#endif //GAME_OBJECT_HPP
