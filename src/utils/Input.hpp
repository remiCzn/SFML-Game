#ifndef GAME_INPUT_HPP
#define GAME_INPUT_HPP

#include "defines.hpp"

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
    std::unordered_set<Key> thisFrameKeys;
    std::unordered_set<Key> lastFrameKeys;
};


#endif //GAME_INPUT_HPP
