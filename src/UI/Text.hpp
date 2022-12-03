#ifndef GAME_TEXT_HPP
#define GAME_TEXT_HPP

#include "defines.hpp"

class Text : public sf::Text {
public:
    Text();

protected:
    static std::shared_ptr<sf::Font> font;
};

#endif //GAME_TEXT_HPP
