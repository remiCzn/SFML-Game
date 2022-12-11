#include "Text.hpp"

std::shared_ptr<sf::Font> Text::font = std::make_shared<sf::Font>();

Text::Text() {
    if (Text::font->getInfo().family.empty()) {
        Text::font->loadFromFile("assets/UI/dogicapixel.ttf");
    }
    this->setFont(*Text::font);
}
