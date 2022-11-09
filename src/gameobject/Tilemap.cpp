#include "Tilemap.h"

void Tilemap::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->draw(vertices, &texture);
}

Tilemap::Tilemap() {
    if (!this->texture.loadFromFile("assets/tilesheet/main_sheet.png")) {
        std::cout << "Can't load tilemap texture" << std::endl;
    }
    this->vertices.setPrimitiveType(sf::Quads);
    this->vertices.resize(TILEMAP_SIZE * TILEMAP_SIZE * 4);
    addTile(0, 0, 51);
    addTile(0, 1, 56);
}

void Tilemap::addTile(const int &x, const int &y, const int &tile_idx) {
    float tileSize = 16;
    float realTileSize = 80;
    float tile_x = (tile_idx % 50) + 1; // 1 = margin / tileheight
    float tile_y = (tile_idx / 50) + 1;
    sf::Vertex *quad = &this->vertices[(x + y * TILEMAP_SIZE) * 4];

    quad[0].position = sf::Vector2f(x * realTileSize, y * realTileSize);
    quad[1].position = sf::Vector2f((x + 1) * realTileSize, y * realTileSize);
    quad[2].position = sf::Vector2f((x + 1) * realTileSize, (y + 1) * realTileSize);
    quad[3].position = sf::Vector2f(x * realTileSize, (y + 1) * realTileSize);

    quad[0].texCoords = sf::Vector2f(tile_x * tileSize, tile_y * tileSize);
    quad[1].texCoords = sf::Vector2f((tile_x + 1) * tileSize, tile_y * tileSize);
    quad[2].texCoords = sf::Vector2f((tile_x + 1) * tileSize, (tile_y + 1) * tileSize);
    quad[3].texCoords = sf::Vector2f(tile_x * tileSize, (tile_y + 1) * tileSize);
}
