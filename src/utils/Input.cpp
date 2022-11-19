//
// Created by cazin on 19/11/2022.
//

#include "Input.hpp"

void Input::update() {
    this->lastFrameKeys = this->thisFrameKeys;
    this->thisFrameKeys[(int) Key::Left] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    this->thisFrameKeys[(int) Key::Up] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    this->thisFrameKeys[(int) Key::Down] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    this->thisFrameKeys[(int) Key::Right] =
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    this->thisFrameKeys[(int) Key::Esc] = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
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
