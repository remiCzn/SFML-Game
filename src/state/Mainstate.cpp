#include "Mainstate.hpp"

Mainstate::Mainstate() : hearthBar(Healthbar(12)) {
    this->view = std::make_shared<sf::View>();
    this->view->setCenter(0, 0);
    this->view->setSize(WindowConsts::WINDOW_SIZE);
    this->world = std::make_shared<World>();
    this->world->push(std::make_shared<Player>());
    this->world->push(std::make_shared<Tilemap>());
}

void Mainstate::update(const float &dt) {
    this->world->get<Player>()->update(dt);
}

void Mainstate::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->setView(*this->view);
    this->view->setCenter(static_cast<sf::Vector2f>(this->world->get<Player>()->getPlayerCenterPosition()));
    this->view->setSize(target->getDefaultView().getSize() / SCALE);
    this->world->get<Tilemap>()->render(target);
    this->world->get<Player>()->render(target);
    target->setView(target->getDefaultView());
    hearthBar.render(target);
}

void Mainstate::handleInput(const sf::Keyboard::Key &key) {
    this->world->get<Player>()->handleInput(key);
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
