#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H

#include "defines.h"
#include "Tilesheet.h"

const int TILEMAP_SIZE = 16;

class Tilemap {
public:
    Tilemap();

    void render(const std::shared_ptr<sf::RenderTarget> &target);

    void addTile(const int &x, const int &y, const int &tile_idx);

private:
    sf::VertexArray vertices;
    Tilesheet &tileSheet;
};


#endif //GAME_TILEMAP_H
