#ifndef GAME_TILEMAPCOMPONENT_HPP
#define GAME_TILEMAPCOMPONENT_HPP

#include "defines.hpp"
#include "constants.hpp"
#include "../Component.hpp"

template<typename T>
using Map = std::unordered_map<int, std::unordered_map<int, T>>;

struct TileInfo {
    std::vector<int> textureLayers;
    bool collision;
};

using Chunk = Map<TileInfo>;

class TilemapComponent : public Component {
public:
    TilemapComponent(Object *owner);

    void load(const std::string &mapString);

    const Chunk &getChunk(int x, int y);

    const Map<Chunk> &getChunks();

private:
    Map<Chunk> chunks;

    void addGraphicChunk(Json::Value chunk);

    void addCollisionChunk(Json::Value chunk);
};


#endif //GAME_TILEMAPCOMPONENT_HPP
