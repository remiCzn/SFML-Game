#include "Input.hpp"

void Input::update() {
    this->lastFrameKeys = this->thisFrameKeys;
    this->thisFrameKeys[(int) Key::Left] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
            || sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -50
            || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -50;
    this->thisFrameKeys[(int) Key::Up] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
            || sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 50
            || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -50;
    this->thisFrameKeys[(int) Key::Down] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::S)
            || sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -50
            || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 50;
    this->thisFrameKeys[(int) Key::Right] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::D)
            || sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 50
            || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 50;
    this->thisFrameKeys[(int) Key::Esc] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
            || sf::Joystick::isButtonPressed(0, 6);
}

bool Input::isKeyUp(Input::Key key) {
    return lastFrameKeys[(int) key] && !thisFrameKeys[(int) key];
}

bool Input::isKeyPressed(Input::Key key) {
    return thisFrameKeys[(int) key];
}

bool Input::isKeyDown(Input::Key key) {
    return !lastFrameKeys[(int) key] && thisFrameKeys[(int) key];
}
