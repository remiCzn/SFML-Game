#ifndef GAME_INPUTMOVEMENT_HPP
#define GAME_INPUTMOVEMENT_HPP


#include "Component.hpp"
#include "Object.hpp"
#include "../utils/Input.hpp"

class InputMovement : public Component {
public:
    InputMovement(Object *owner);

    void setInput(Input *input);

    void setMovementSpeed(int moveSpeed);

    void update(const float &dt) override;

private:
    int moveSpeed;
    Input *input;
};


#endif //GAME_INPUTMOVEMENT_HPP
