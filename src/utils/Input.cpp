#include "Input.hpp"

std::unordered_set<Key> Input::thisFrameKeys = {};
std::unordered_set<Key> Input::lastFrameKeys = {};

void Input::update() {
    lastFrameKeys = thisFrameKeys;
    thisFrameKeys.clear();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
        || sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -50
        || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -50) {
        thisFrameKeys.insert(Key::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
        || sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 50
        || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -50) {
        thisFrameKeys.insert(Key::Up);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::S)
        || sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -50
        || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 50) {
        thisFrameKeys.insert(Key::Down);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        || sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 50
        || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 50) {
        thisFrameKeys.insert(Key::Right);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Joystick::isButtonPressed(0, 6)) {
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
