#ifndef GAME_PLAYERINPUTCOMPONENT_H
#define GAME_PLAYERINPUTCOMPONENT_H

#include "../InputComponent.h"
#include "../GraphicsComponent.h"

class PlayerInputComponent : public InputComponent {
public:
    explicit PlayerInputComponent(std::shared_ptr<PhysicsComponent> physics);

    void handleInput(sf::Keyboard::Key &keycode) override;

private:
    std::shared_ptr<PhysicsComponent> _physics;
};


#endif //GAME_PLAYERINPUTCOMPONENT_H
