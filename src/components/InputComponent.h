#ifndef GAME_INPUTCOMPONENT_H
#define GAME_INPUTCOMPONENT_H

#include "defines.h"

class InputComponent {
public:
    virtual ~InputComponent() = default;

    virtual void handleInput(sf::Keyboard::Key &keycode) = 0;
};


#endif //GAME_INPUTCOMPONENT_H
