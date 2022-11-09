#include "Tilemap.h"

void Tilemap::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->draw(vertices, &this->tileSheet.getTexture());
}

Tilemap::Tilemap() : tileSheet(*new Tilesheet("assets/tilesheet/main_sheet.tsj", "assets/tilesheet/main_sheet.png")) {
    this->vertices.setPrimitiveType(sf::Quads);
    this->vertices.resize(TILEMAP_SIZE * TILEMAP_SIZE * 4);

    std::fstream f("assets/maps/test_map.tmj");
    Json::Value map;
    f >> map;

    Json::Value a = map["layers"][0]["layers"][0]["chunks"][0]["data"];

    size_t idx = 0;
    for (const auto &t: a) {
        addTile(idx % CHUNK_SIZE, idx / CHUNK_SIZE, t.asInt());
        idx++;
    }
}

void Tilemap::addTile(const int &x, const int &y, const int &tile_idx) {
    float realTileSize = TILEMAP_SIZE * 4;
    sf::Vertex *quad = &this->vertices[(x + y * TILEMAP_SIZE) * 4];

    quad[0].position = realTileSize * sf::Vector2f(x, y);
    quad[1].position = realTileSize * sf::Vector2f(x + 1, y);
    quad[2].position = realTileSize * sf::Vector2f(x + 1, y + 1);
    quad[3].position = realTileSize * sf::Vector2f(x, y + 1);

    quad[0].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(0, 0));
    quad[1].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(1, 0));
    quad[2].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(1, 1));
    quad[3].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(0, 1));
}
