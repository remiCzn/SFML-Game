#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H

#include "defines.h"
#include "Tilesheet.h"

template<typename T>
using Map = std::unordered_map<int, std::unordered_map<int, std::unordered_map<size_t, T>>>;

const int TILEMAP_SIZE = 16;

class Tilemap {
public:
    Tilemap();

    void render(const std::shared_ptr<sf::RenderTarget> &target);

private:

    Map<std::unique_ptr<sf::VertexArray>> chunks;

    Tilesheet &tileSheet;

    void addChunk(Json::Value chunk, size_t &layer_idx);

    void addTile(const int &x, const int &y, const int &tile_idx, const std::unique_ptr<sf::VertexArray> &vertices,
                 const sf::Vector2f &offset);
};


#endif //GAME_TILEMAP_H
