#ifndef GAME_INPUT_HPP
#define GAME_INPUT_HPP

#include "defines.hpp"

enum class Key {
    None = 0,
    Left = 1,
    Right = 2,
    Up = 3,
    Down = 4,
    Esc = 5,
    Debug = 6
};

class Input {
public:

    static void update();

    static bool isKeyPressed(Key key);

    static bool isKeyDown(Key key);

    static bool isKeyUp(Key key);

private:
    static std::unordered_set<Key> thisFrameKeys;
    static std::unordered_set<Key> lastFrameKeys;
};


#endif //GAME_INPUT_HPP
