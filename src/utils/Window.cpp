#include "Window.hpp"

Window::Window(const std::string &windowname)
        : window(sf::VideoMode(800, 600), windowname) {
    this->view = std::make_shared<sf::View>(this->window.getDefaultView());
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void Window::update() {
    sf::Event event;
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Window::beginDraw() {
    window.clear(sf::Color::Black);
    window.setView(*this->view);
}

void Window::draw(const sf::Drawable &drawable) {
    window.draw(drawable);
}

void Window::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    window.draw(drawable, states);
}

void Window::endDraw() {
    window.display();
}

bool Window::isOpen() const {
    return window.isOpen();
}

sf::Vector2u Window::getCenter() const {
    return {window.getSize().x / 2, window.getSize().y / 2};
}

sf::Vector2u Window::getSize() const {
    return window.getSize();
}

void Window::setScale(float scale) {
    sf::Vector2u size = this->window.getSize();
    this->view->setSize(sf::Vector2f(size.x / scale, size.y / scale));
    this->view->setCenter(0, 0);
}

void Window::setCenter(sf::Vector2f position) {
    this->view->setCenter(position);
}
