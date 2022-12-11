#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP


#include "Object.hpp"
#include "../utils/ResourceManager.hpp"
#include "../utils/Input.hpp"
#include "constants.hpp"
#include "../component/InputComponent.hpp"
#include "../utils/SocketClient.hpp"
#include "Guy.hpp"

class Player : public Guy {
public:
    explicit Player(ResourceManager<sf::Texture> &textureAllocator);
};


#endif //GAME_PLAYER_HPP
