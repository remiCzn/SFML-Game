#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include "defines.hpp"
#include "Debug.hpp"
#include "Input.hpp"
#include <cmath>

class Window {
public:
    explicit Window(const std::string &windowname);

    void update();

    void beginDraw();

    void draw(const sf::Drawable &drawable);

    void draw(const sf::Drawable &drawable, const sf::RenderStates &states);

    void draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type);

    void endDraw();

    sf::Vector2u getCenter() const;

    sf::Vector2u getSize() const;

    void setScale(float scale);

    void setCenter(sf::Vector2f position);

    bool isOpen() const;

    tgui::Gui &gui();

    sf::Window &get();

    bool getFocus() const;

private:
    sf::RenderWindow window;
    tgui::Gui tgui;
    std::shared_ptr<sf::View> view;
};


#endif //GAME_WINDOW_HPP
