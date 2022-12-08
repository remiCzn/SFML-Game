#ifndef GAME_INPUT_HPP
#define GAME_INPUT_HPP

#include "defines.hpp"

enum JoystickButton {
    A = 0,
    B,
    X,
    Y,
    L,
    R,
    start,
    select,
    LAxis,
    RAxis
};

class Input {
public:
    enum class Key {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Esc = 5
    };

    void update();

    bool isKeyPressed(Key key);

    bool isKeyDown(Key key);

    bool isKeyUp(Key key);

private:
    std::unordered_map<int, bool> thisFrameKeys;
    std::unordered_map<int, bool> lastFrameKeys;

};


#endif //GAME_INPUT_HPP
