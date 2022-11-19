#include "Window.hpp"

Window::Window(const std::string &windowname)
        : window(sf::VideoMode(800, 600), windowname) {
    window.setVerticalSyncEnabled(true);
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
}

void Window::draw(const sf::Drawable &drawable) {
    window.draw(drawable);
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
