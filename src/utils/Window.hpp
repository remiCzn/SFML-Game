#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include "defines.hpp"

class Window {
public:
    Window(const std::string &windowname);

    void update();

    void beginDraw();

    void draw(const sf::Drawable &drawable);

    void endDraw();

    sf::Vector2u getCenter() const;

    sf::Vector2u getSize() const;

    void setScale(float scale);

    bool isOpen() const;

private:
    sf::RenderWindow window;
    std::shared_ptr<sf::View> view;
};


#endif //GAME_WINDOW_HPP
