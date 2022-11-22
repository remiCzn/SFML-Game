#ifndef GAME_SPRITECOMPONENT_HPP
#define GAME_SPRITECOMPONENT_HPP

#include "../objects/Object.hpp"
#include "Component.hpp"
#include "../utils/ResourceManager.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent(Object *owner);

    void setTextureAllocator(ResourceManager<sf::Texture> *textureAllocator);

    void load(const std::string &filePath);

    void load(int id);

    void setTextureRect(sf::IntRect textureRect);

    void lateUpdate(const float &dt) override;

    void draw(Window &window) override;

private:
    sf::Sprite sprite;
    ResourceManager<sf::Texture> *allocator;
};


#endif //GAME_SPRITECOMPONENT_HPP
