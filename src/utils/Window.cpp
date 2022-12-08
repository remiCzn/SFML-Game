#include "Window.hpp"

Window::Window(const std::string &windowname)
        : window(sf::VideoMode(800, 600), windowname) {
    this->view = std::make_shared<sf::View>(this->window.getDefaultView());
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    tgui.setTarget(window);
}

void Window::update() {
    sf::Event event;
    if (window.pollEvent(event)) {
        tgui.handleEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    if (Input::isKeyDown(Key::Debug)) {
        Debug::switchDebugMode();
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
    this->view->setCenter(sf::Vector2f(floor(position.x), floor(position.y)));
}

tgui::Gui &Window::gui() {
    return this->tgui;
}

sf::Window &Window::get() {
    return this->window;
}

void Window::draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type) {
    window.draw(vertices, vertexCount, type);
}
