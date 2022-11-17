#ifndef GAME_GAMEOBJECT_HPP
#define GAME_GAMEOBJECT_HPP

#include "../components/GraphicsComponent.hpp"
#include "../components/InputComponent.hpp"
#include "World.hpp"

class GameObject {
public:
    GameObject() = default;

    void add_graphics_component(GraphicsComponent *graphicsComponent);

    void add_input_component(InputComponent *inputComponent);

    void add_physics_component(PhysicsComponent *physicsComponent);

    void update(const float &dt, std::shared_ptr<World> world);

    void render(const std::shared_ptr<sf::RenderTarget> &target);

    void handleInput(const sf::Keyboard::Key &keycode);

protected:
    std::shared_ptr<GraphicsComponent> _graphics;
    std::shared_ptr<InputComponent> _input;
    std::shared_ptr<PhysicsComponent> _physics;
};


#endif //GAME_GAMEOBJECT_HPP
