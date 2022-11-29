#include "TilemapDrawableComponent.hpp"
#include "TilemapComponent.hpp"

TilemapDrawableComponent::Tilesheet::Tilesheet(const std::string &tmj_path, const std::string &png_path) {
    if (!this->texture.loadFromFile(png_path)) {
        std::cout << "Can't load texture for tilesheet" << std::endl;
    }

    std::fstream f(tmj_path);
    Json::Value tilesheet;
    f >> tilesheet;
    this->margin = tilesheet["margin"].asInt() / TILE_SIZE;
    this->sheetWidth = tilesheet["imagewidth"].asInt() / TILE_SIZE - this->margin;
}

const sf::Texture &TilemapDrawableComponent::Tilesheet::getTexture() const {
    return this->texture;
}

sf::Vector2f TilemapDrawableComponent::Tilesheet::getTextureCoord(const int &idx) const {
    return {
            static_cast<float>(idx % this->sheetWidth + this->margin - 1),
            static_cast<float>(idx / this->sheetWidth + this->margin)
    };
}

void TilemapDrawableComponent::draw(Window &window) {
    for (auto &chunk_row: this->vertices) {
        for (auto &chunk: chunk_row.second) {
            window.draw(chunk.second, &this->tileSheet->getTexture());
        }
    }
}

void TilemapDrawableComponent::load(const std::string &tilesheet_file, const std::string &tilesheet_picture) {
    this->tileSheet = std::make_shared<Tilesheet>(tilesheet_file, tilesheet_picture);
    for (auto &chunk_row: this->owner->getComponent<TilemapComponent>()->getChunks()) {
        for (auto &chunk: chunk_row.second) {
            int chunkX = chunk_row.first;
            int chunkY = chunk.first;
            sf::VertexArray &vertexArray = this->vertices[chunkX][chunkY];
            vertexArray.setPrimitiveType(sf::Quads);
            vertexArray.resize(CHUNK_SIZE * CHUNK_SIZE * 4 * 2);

            Map<TileInfo> ck = chunk.second;

            for (int x = 0; x < CHUNK_SIZE; x++) {
                for (int y = 0; y < CHUNK_SIZE; y++) {
                    for (int i = 0; i < 2; i++) {
                        //TODO: refactor this way of drawing layers
                        if (ck[x][y].textureLayers.size() <= i) {
                            continue;
                        } else {
                            int idx = ck[x][y].textureLayers.at(i);
                            sf::Vertex *quad = &vertexArray[(x + y * CHUNK_SIZE + i * CHUNK_SIZE * CHUNK_SIZE) * 4];
                            quad[0].position = (float) TILE_SIZE * (sf::Vector2f((float) x, (float) y) +
                                                                    sf::Vector2f((float) chunkX, (float) chunkY));
                            quad[1].position = (float) TILE_SIZE * (sf::Vector2f((float) x + 1, (float) y) +
                                                                    sf::Vector2f((float) chunkX, (float) chunkY));
                            quad[2].position = (float) TILE_SIZE * (sf::Vector2f((float) x + 1, (float) y + 1) +
                                                                    sf::Vector2f((float) chunkX, (float) chunkY));
                            quad[3].position = (float) TILE_SIZE * (sf::Vector2f((float) x, (float) y + 1) +
                                                                    sf::Vector2f((float) chunkX, (float) chunkY));
                            sf::Vector2f textureCoord = this->tileSheet->getTextureCoord(idx);
                            quad[0].texCoords = (float) TILE_SIZE * textureCoord;
                            quad[1].texCoords = (float) TILE_SIZE * (textureCoord + sf::Vector2f(1, 0));
                            quad[2].texCoords = (float) TILE_SIZE * (textureCoord + sf::Vector2f(1, 1));
                            quad[3].texCoords = (float) TILE_SIZE * (textureCoord + sf::Vector2f(0, 1));
                        }
                    }
                }
            }
        }
    }
}

TilemapDrawableComponent::TilemapDrawableComponent(Object *owner) : Component(owner) {

}
