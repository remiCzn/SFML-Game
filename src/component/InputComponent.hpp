#ifndef GAME_INPUTCOMPONENT_HPP
#define GAME_INPUTCOMPONENT_HPP


#include "Component.hpp"
#include "../objects/Object.hpp"
#include "../utils/Input.hpp"
#include "AnimationComponent.hpp"

class InputComponent : public Component {
public:
    InputComponent(Object *owner);

    void awake() override;

    void setInput(std::shared_ptr<Input> input);

    void setMovementSpeed(int moveSpeed);

    void update(const float &dt) override;

private:
    int moveSpeed;
    std::shared_ptr<AnimationComponent> animation;
    std::shared_ptr<Input> input;
};


#endif //GAME_INPUTCOMPONENT_HPP
