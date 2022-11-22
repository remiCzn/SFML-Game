#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


#include "../utils/Window.hpp"
#include "../component/Component.hpp"
#include "../component/TransformComponent.hpp"

class Object {
public:
    Object();

    void awake();

    void start();

    void update(const float &dt);

    void lateUpdate(const float &dt);

    void draw(Window &window);

    template<typename T>
    std::shared_ptr<T> addComponent() {
        static_assert(std::is_base_of<Component, T>::value, "must derive from Component");

        for (auto &existingComponent: components) {
            if (std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
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

    std::shared_ptr<TransformComponent> transform;

private:
    std::vector<std::shared_ptr<Component>> components;
};


#endif //GAME_OBJECT_HPP
