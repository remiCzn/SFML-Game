#include "TilemapComponent.hpp"

enum Groups {
    Graphics = 0,
    Physics = 1
};

const std::string CHUNKS = "chunks";
const std::string LAYERS = "layers";

TilemapComponent::TilemapComponent(Object *owner) : Component(owner) {

}

void TilemapComponent::load(const std::string &mapString) {
    std::fstream f(mapString);
    Json::Value map;
    f >> map;
    Json::Value graphicsLayers = map[LAYERS][Graphics][LAYERS];
    size_t layer_idx = 0;
    for (auto &layer: graphicsLayers) {
        Json::Value cks = layer[CHUNKS];
        for (auto &chunk: cks) {
            addGraphicChunk(chunk);
        }
        layer_idx++;
    }

    Json::Value collision = map[LAYERS][Physics][LAYERS][0][CHUNKS];
    for (auto &chunk: collision) {
        this->addCollisionChunk(chunk);
    }
}

void TilemapComponent::addGraphicChunk(Json::Value chunk) {
    int chunkX = chunk["x"].asInt();
    int chunkY = chunk["y"].asInt();

    for (size_t i = 0; i < chunk["data"].size(); i++) {
        int x = (int) i % TilemapConsts::CHUNK_SIZE;
        int y = (int) i / TilemapConsts::CHUNK_SIZE;
        this->chunks[chunkX][chunkY][x][y].textureLayers.push_back(chunk["data"][i].asInt());
    }
}

void TilemapComponent::addCollisionChunk(Json::Value chunk) {
    int chunkX = chunk["x"].asInt();
    int chunkY = chunk["y"].asInt();

    for (size_t i = 0; i < chunk["data"].size(); i++) {
        int x = (int) i % TilemapConsts::CHUNK_SIZE;
        int y = (int) i / TilemapConsts::CHUNK_SIZE;
        this->chunks[chunkX][chunkY][x][y].collision = (chunk["data"][i].asInt() == 1);
    }
}

const Chunk &TilemapComponent::getChunk(int x, int y) {
    return this->chunks[x][y];
}

const Map<Chunk> &TilemapComponent::getChunks() {
    return this->chunks;
}
