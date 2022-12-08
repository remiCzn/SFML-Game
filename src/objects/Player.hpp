#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP


#include "Object.hpp"
#include "../utils/ResourceManager.hpp"
#include "../utils/Input.hpp"

class Player : public Object {
public:
    Player(ResourceManager<sf::Texture> &textureAllocator);
};


#endif //GAME_PLAYER_HPP
