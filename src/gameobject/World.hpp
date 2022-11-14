#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP


#include "../tilemap/Tilemap.hpp"
#include "Player.hpp"

class World {
private:
    std::shared_ptr<Tilemap> _tilemap;
    std::shared_ptr<Player> _player;
public:
    template<typename T>
    void push(const std::shared_ptr<T> &gameobject);

    template<typename T>
    const std::shared_ptr<T> &get();
};


#endif //GAME_WORLD_HPP
