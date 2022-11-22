#ifndef GAME_SPRITECOMPONENT_HPP
#define GAME_SPRITECOMPONENT_HPP

#include "../objects/Object.hpp"
#include "Component.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent(Object *owner);

    void load(const std::string &filePath);

    void setTextureRect(sf::IntRect textureRect);

    void lateUpdate(const float &dt) override;

    void draw(Window &window) override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //GAME_SPRITECOMPONENT_HPP
