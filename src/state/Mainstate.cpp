//
// Created by cazin on 11/11/2022.
//

#include "Mainstate.h"

void Mainstate::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->setView(*this->view);
    this->view->setCenter(static_cast<sf::Vector2f>(this->player.getPlayerCenterPosition()));
    tilemap.render(target);
    player.render(target);
}

void Mainstate::update(const float &dt) {
    player.update(dt);
}

Mainstate::Mainstate() {
    this->view = std::make_shared<sf::View>();
    this->view->setCenter(0, 0);
    this->view->setSize(WindowConsts::WINDOW_SIZE);
}

void Mainstate::handleInput(const sf::Keyboard::Key &key) {
    this->player.handleInput(key);
}
