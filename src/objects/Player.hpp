#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP


#include "Object.hpp"
#include "../utils/ResourceManager.hpp"
#include "../utils/Input.hpp"
#include "../utils/SocketClient.hpp"

class Player : public Object {
public:
    Player(ResourceManager<sf::Texture> &textureAllocator, std::shared_ptr<Input> input);

    void update(const float &dt) override;

private:
    SocketClient socket;
};


#endif //GAME_PLAYER_HPP
