#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP


#include "Object.hpp"
#include "../utils/ResourceManager.hpp"
#include "../utils/Input.hpp"

class Player : public Object {
public:
    Player(ResourceManager<sf::Texture> &textureAllocator, Input &input);

    void draw(Window &window) override;
};


#endif //GAME_PLAYER_HPP
