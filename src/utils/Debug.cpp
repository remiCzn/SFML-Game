#include "Debug.hpp"

std::vector<sf::RectangleShape> Debug::rects = {};
std::vector<std::array<sf::Vertex, 2>> Debug::lines = {};
bool Debug::debugMode = false;

void Debug::draw(Window &window) {
    if (debugMode) {
        for (auto &r: rects) {
            window.draw(r);
        }
        rects.clear();

        for (auto &l: lines) {
            sf::Vertex line[2] = {l.at(0), l.at(1)};
            window.draw(line, 1, sf::Lines);
        }
        lines.clear();
    }
}

void Debug::drawRect(const sf::FloatRect &rect, sf::Color color) {
    if (debugMode) {
        sf::Vector2f size(rect.width, rect.height);
        sf::Vector2f pos(rect.left, rect.top);
        sf::RectangleShape shape(size);
        shape.setPosition(pos);
        shape.setOutlineColor(color);
        shape.setOutlineThickness(0.3f);
        shape.setFillColor(sf::Color::Transparent);
        rects.push_back(shape);
    }
}

void Debug::drawLine(const sf::Vector2f &from, const sf::Vector2f &to, sf::Color color) {
    if (debugMode) {
        lines.push_back({
                                sf::Vertex(from, color),
                                sf::Vertex(to, color)
                        });
    }
}

void Debug::log(const std::string &msg) {
    if (debugMode) {
        std::cout << msg << std::endl;
    }
}

void Debug::logWarning(const std::string &msg) {
    if (debugMode) {
        std::cout << "WARNING: " << msg << std::endl;
    }
}

void Debug::logError(const std::string &msg) {
    if (debugMode) {
        std::cout << "ERROR: " << msg << std::endl;
    }
}

void Debug::switchDebugMode() {
    debugMode = !debugMode;
}
