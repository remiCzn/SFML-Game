#include "Game.h"

#include <memory>

Game::Game() {
    this->dt = 0.f;
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Window Example");
    this->view = std::make_shared<sf::View>();
    this->view->setCenter(0, 0);
    this->view->setSize(800, 600);
}

void Game::update() {
    this->dt = this->dtClock.restart().asSeconds();
    player.update(this->dt);
}

void Game::render() {
    this->window->clear(sf::Color::Black);
    this->window->setView(*this->view);
    this->view->setCenter(this->player.getPlayerCenterPosition());
    tilemap.render(this->window);
    player.render(this->window);
    this->window->display();

}

void Game::run() {
    while (this->window && this->window->isOpen()) {
        this->handeEvent();
        this->update();
        this->render();
    }
    this->window->close();
}

void Game::handeEvent() {
    sf::Event e{};
    while (this->window->pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Resized:
                this->window->setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
                continue;
            case sf::Event::Closed:
                this->window->close();
                continue;
            case sf::Event::KeyPressed:
                this->player.handleInput(e.key.code);
            default:
                continue;
        }
    }
}
