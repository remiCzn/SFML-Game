#ifndef GAME_INPUT_HPP
#define GAME_INPUT_HPP

#include "defines.hpp"
#include "Window.hpp"

enum class Key {
    None = 0,
    Left = 1,
    Right = 2,
    Up = 3,
    Down = 4,
    Esc = 5,
    Debug = 6
};

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

class Window;

class Input {
public:

    static void update(const Window &window);

    static bool isKeyPressed(Key key);

    static bool isKeyDown(Key key);

    static bool isKeyUp(Key key);

private:
    static std::unordered_set<Key> thisFrameKeys;
    static std::unordered_set<Key> lastFrameKeys;
};


#endif //GAME_INPUT_HPP
