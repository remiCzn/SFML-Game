#ifndef GAME_CHEST_HPP
#define GAME_CHEST_HPP

#include "Object.hpp"
#include "../utils/ResourceManager.hpp"

class Chest : public Object {
public:
    Chest(ResourceManager<sf::Texture> &textureAllocator);
};


#endif //GAME_CHEST_HPP
