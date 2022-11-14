#include "Mainstate.hpp"

Mainstate::Mainstate() : hearthBar(Healthbar(12)) {
    this->view = std::make_shared<sf::View>();
    this->view->setCenter(0, 0);
    this->view->setSize(WindowConsts::WINDOW_SIZE);
}

void Mainstate::update(const float &dt) {
    player.update(dt);
}

void Mainstate::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->setView(*this->view);
    this->view->setCenter(static_cast<sf::Vector2f>(this->player.getPlayerCenterPosition()));
    tilemap.render(target);
    player.render(target);
    target->setView(target->getDefaultView());
    hearthBar.render(target);
}

void Mainstate::handleInput(const sf::Keyboard::Key &key) {
    this->player.handleInput(key);
    switch (key) {
        case sf::Keyboard::O:
            this->hearthBar.addHealth(-1);
            break;
        case sf::Keyboard::P:
            this->hearthBar.addHealth(1);
            break;
        default:
            break;
    }
}
