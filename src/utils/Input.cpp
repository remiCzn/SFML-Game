#include "Input.hpp"

std::unordered_set<Key> Input::thisFrameKeys = {};
std::unordered_set<Key> Input::lastFrameKeys = {};

void Input::update() {
    lastFrameKeys = thisFrameKeys;
    thisFrameKeys = std::unordered_set<Key>();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        thisFrameKeys.insert(Key::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        thisFrameKeys.insert(Key::Up);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        thisFrameKeys.insert(Key::Down);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        thisFrameKeys.insert(Key::Right);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        thisFrameKeys.insert(Key::Esc);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
        thisFrameKeys.insert(Key::Debug);
    }
}

bool Input::isKeyUp(Key key) {
    return lastFrameKeys.contains(key) && !thisFrameKeys.contains(key);
}

bool Input::isKeyPressed(Key key) {
    return thisFrameKeys.contains(key);
}

bool Input::isKeyDown(Key key) {
    return !lastFrameKeys.contains(key) && thisFrameKeys.contains(key);
}
