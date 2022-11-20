#ifndef GAME_SPRITE_HPP
#define GAME_SPRITE_HPP

#include "Object.hpp"
#include "Component.hpp"

class Sprite : public Component {
public:
    Sprite(Object *owner);

    void load(const std::string &filePath);

    void setTextureRect(sf::IntRect textureRect);

    void lateUpdate(const float &dt) override;

    void draw(Window &window) override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_SPRITE_HPP
