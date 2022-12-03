#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include "defines.hpp"

class Window {
public:
    explicit Window(const std::string &windowname);

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

    tgui::Gui &gui();

    sf::Window & get();

private:
    sf::RenderWindow window;
    tgui::Gui tgui;
    std::shared_ptr<sf::View> view;
};


#endif //GAME_WINDOW_HPP
