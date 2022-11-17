#include "Tilemap.hpp"

void Tilemap::render(const std::shared_ptr<sf::RenderTarget> &target) {
    for (auto &chunk_row: this->chunks) {
        for (auto &chunk: chunk_row.second) {
            for (auto &layer: chunk.second) {
                target->draw(*layer.second, &this->tileSheet.getTexture());
            }
        }
    }
}

Tilemap::Tilemap() : tileSheet(*new Tilesheet("assets/tilesheet/main_sheet.tsj", "assets/tilesheet/main_sheet.png")) {
    std::fstream f("assets/maps/test_map.tmj");
    Json::Value map;
    f >> map;
    Json::Value layers = map["layers"][0]["layers"];
    size_t layer_idx = 0;
    for (auto &layer: layers) {
        Json::Value cks = layer["chunks"];
        for (auto &chunk: cks) {
            this->addChunk(chunk, layer_idx);
        }
        layer_idx++;
    }

    Json::Value collision = map["layers"][1]["layers"][0]["chunks"];
    for (auto &chunk: collision) {
        this->addCollisionChunk(chunk);
    }
}

void Tilemap::addCollisionChunk(Json::Value chunk) {
    int chunkX = chunk["x"].asInt();
    int chunkY = chunk["y"].asInt();
    for (size_t i = 0; i < chunk["data"].size(); ++i) {
        int x = i % CHUNK_SIZE;
        int y = i / CHUNK_SIZE;
        this->collisionChunks[chunkX][chunkY][x][y] = (chunk["data"][i].asInt() == 1);
    }
}

void Tilemap::addChunk(Json::Value chunk, size_t &layer_idx) {
    sf::VertexArray vertices;
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(CHUNK_SIZE * CHUNK_SIZE * 4);
    int chunkX = chunk["x"].asInt();
    int chunkY = chunk["y"].asInt();


    this->chunks[chunkX][chunkY][layer_idx] = std::make_unique<sf::VertexArray>(vertices);

    size_t idx = 0;
    for (const auto &t: chunk["data"]) {
        addTile((int) idx % CHUNK_SIZE, (int) idx / CHUNK_SIZE, t.asInt(), this->chunks[chunkX][chunkY][layer_idx],
                sf::Vector2f((float) chunkX, (float) chunkY));
        idx++;
    }
}


void Tilemap::addTile(const int &x, const int &y, const int &tile_idx, const std::unique_ptr<sf::VertexArray> &vertices,
                      const sf::Vector2f &offset) {
    float realTileSize = CHUNK_SIZE;
    sf::Vertex *quad = &(*vertices)[(x + y * CHUNK_SIZE) * 4];

    quad[0].position = realTileSize * (sf::Vector2f((float) x, (float) y) + offset);
    quad[1].position = realTileSize * (sf::Vector2f((float) x + 1, (float) y) + offset);
    quad[2].position = realTileSize * (sf::Vector2f((float) x + 1, (float) y + 1) + offset);
    quad[3].position = realTileSize * (sf::Vector2f((float) x, (float) y + 1) + offset);

    quad[0].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(0, 0));
    quad[1].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(1, 0));
    quad[2].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(1, 1));
    quad[3].texCoords = (float) TILE_SIZE * (this->tileSheet.getTextureCoord(tile_idx) + sf::Vector2f(0, 1));
}

bool Tilemap::intersects(const sf::FloatRect &rect) {
    return false;
}


