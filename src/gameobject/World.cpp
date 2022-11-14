#include "World.hpp"

template<>
void World::push(const std::shared_ptr<Player> &gameobject) {
    this->_player = gameobject;
}

template<>
const std::shared_ptr<Player> &World::get<Player>() {
    return this->_player;
}

template<>
void World::push(const std::shared_ptr<Tilemap> &gameobject) {
    this->_tilemap = gameobject;
}

template<>
const std::shared_ptr<Tilemap> &World::get<Tilemap>() {
    return this->_tilemap;
}