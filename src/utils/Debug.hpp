#ifndef GAME_DEBUG_HPP
#define GAME_DEBUG_HPP

#include "defines.hpp"
#include "Window.hpp"

class Debug {
public:
    static void draw(Window &window);

    static void drawRect(const sf::FloatRect &rect, sf::Color color = sf::Color::White);

    static void drawLine(const sf::Vector2f &from, const sf::Vector2f &to, sf::Color color = sf::Color::White);

    static void log(const std::string &msg);

    static void logWarning(const std::string &msg);

    static void logError(const std::string &msg);

private:
    static std::vector<std::array<sf::Vertex, 2>> lines;
    static std::vector<sf::RectangleShape> rects;
};


#endif //GAME_DEBUG_HPP
