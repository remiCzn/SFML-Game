#ifndef GAME_INPUTCOMPONENT_HPP
#define GAME_INPUTCOMPONENT_HPP

#include "defines.h"

class InputComponent {
public:
    virtual ~InputComponent() = default;

    virtual void update() = 0;

    virtual void handleInput(const sf::Keyboard::Key &keycode) = 0;
};


#endif //GAME_INPUTCOMPONENT_HPP
