#include "Input.hpp"

void Input::update() {
    this->lastFrameKeys = this->thisFrameKeys;
    this->thisFrameKeys = std::unordered_set<Key>();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        this->thisFrameKeys.insert(Key::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        this->thisFrameKeys.insert(Key::Up);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->thisFrameKeys.insert(Key::Down);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->thisFrameKeys.insert(Key::Right);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->thisFrameKeys.insert(Key::Esc);
    }
}

bool Input::isKeyUp(Input::Key key) {
    return lastFrameKeys.contains(key) && !thisFrameKeys.contains(key);
}

bool Input::isKeyPressed(Input::Key key) {
    return thisFrameKeys.contains(key);
}

bool Input::isKeyDown(Input::Key key) {
    return !lastFrameKeys.contains(key) && thisFrameKeys.contains(key);
}
