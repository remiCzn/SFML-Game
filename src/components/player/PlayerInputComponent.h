#ifndef GAME_PLAYERINPUTCOMPONENT_H
#define GAME_PLAYERINPUTCOMPONENT_H

#include "../InputComponent.h"
#include "../GraphicsComponent.h"

class PlayerInputComponent : public InputComponent {
public:
    explicit PlayerInputComponent(std::shared_ptr<PhysicsComponent> physics);

    void handleInput(const sf::Keyboard::Key &keycode) override;

    void update() override;

private:
    std::shared_ptr<PhysicsComponent> _physics;
    float speed_force;
};


#endif //GAME_PLAYERINPUTCOMPONENT_H
