#ifndef GAME_SPRITE_HPP
#define GAME_SPRITE_HPP


#include "Component.hpp"

class Sprite : public Component {
public:
    Sprite(Object *owner);

    void load(const std::string &filePath);

    void setTextureRect(sf::IntRect textureRect);

    void draw(Window &window) override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_SPRITE_HPP
