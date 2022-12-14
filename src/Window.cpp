#include <SFML/Window/Event.hpp>
#include "Window.hpp"

Window::Window() : Window("Window", sf::Vector2u(640, 480)) {

}

Window::Window(const std::string &title, const sf::Vector2u &size) {
    setup(title, size);
}

Window::~Window() {
    window.close();
}

void Window::beginDraw() {
    window.clear(sf::Color::Black);
}

void Window::endDraw() {
    window.display();
}

void Window::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::LostFocus) {
            this->_isFocused = false;
            //TODO update on event manager
        } else if (event.type == sf::Event::GainedFocus) {
            this->_isFocused = true;
            //TODO update on event manager
        }
        //TODO handle event on event manager
    }

    //TODO update event manager

}

bool Window::isDone() const {
    return _isDone;
}

bool Window::isFullscreen() const {
    return _isFullscreen;
}

bool Window::isFocuses() const {
    return _isFocused;
}

void Window::toggleFullscreen(const std::shared_ptr<ECS::EventDetails> &details) {
    _isFullscreen = !_isFullscreen;
    window.close();
    create();
}

void Window::close(const std::shared_ptr<ECS::EventDetails> &event) {
    _isDone = true;
}

sf::RenderWindow *Window::getRenderWindow() {
    return &window;
}

std::shared_ptr<ECS::EventManager> Window::getEventManager() {
    return std::make_shared<ECS::EventManager>(eventManager);
}

sf::Vector2u Window::getWindowSize() {
    return windowSize;
}

void Window::setup(const std::string &title, const sf::Vector2u &size) {
    windowTitle = title;
    windowSize = size;
    _isFullscreen = false;
    _isDone = false;
    _isFocused = true;

    //TODO Add event manager callbacks
    create();
}

void Window::create() {
    sf::Uint32 style = sf::Style::Default;
    if (_isFullscreen) {
        style = sf::Style::Fullscreen;
    }
    window.create(sf::VideoMode(windowSize.x, windowSize.y, 32), windowTitle, style);
}
