#ifndef GAME_TILEMAP_HPP
#define GAME_TILEMAP_HPP

#include "defines.h"
#include "constants.h"
#include "Tilesheet.hpp"

using namespace TilemapConsts;

template<typename T>
using Map = std::unordered_map<int, std::unordered_map<int, T>>;

class Tilemap {
public:
    Tilemap();

    void render(const std::shared_ptr<sf::RenderTarget> &target);

private:

    Map<std::unordered_map<size_t, std::unique_ptr<sf::VertexArray>>> chunks;

    Map<Map<bool>> collisionChunks;

    Tilesheet &tileSheet;

    void addCollisionChunk(Json::Value chunk);

    void addChunk(Json::Value chunk, size_t &layer_idx);

    void addTile(const int &x, const int &y, const int &tile_idx, const std::unique_ptr<sf::VertexArray> &vertices,
                 const sf::Vector2f &offset);

    bool intersects(const sf::FloatRect &rect);


};


#endif //GAME_TILEMAP_HPP
