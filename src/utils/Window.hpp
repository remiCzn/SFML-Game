#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include "defines.hpp"

class Window {
public:
    Window(const std::string &windowname);

    void update();

    void beginDraw();

    void draw(const sf::Drawable &drawable);

    void draw(const sf::Drawable &drawable, const sf::RenderStates &states);

    void endDraw();

    sf::Vector2u getCenter() const;

    sf::Vector2u getSize() const;

    void setScale(float scale);

    void setCenter(sf::Vector2f position);

    bool isOpen() const;

    bool getFocus() const;

private:
    sf::RenderWindow window;
    std::shared_ptr<sf::View> view;
    bool focus;
};


#endif //GAME_WINDOW_HPP
