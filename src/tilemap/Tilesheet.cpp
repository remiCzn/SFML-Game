#include "Tilesheet.hpp"

Tilesheet::Tilesheet(const std::string &tmj_path, const std::string &png_path) {
    if (!this->texture.loadFromFile(png_path)) {
        std::cout << "Can't load texture for tilesheet" << std::endl;
    }
    std::fstream f(tmj_path);
    Json::Value tilesheet;
    f >> tilesheet;
    this->margin = tilesheet["margin"].asInt() / TILE_SIZE;
    this->sheetWidth = tilesheet["imagewidth"].asInt() / TILE_SIZE - this->margin;
}

const sf::Texture &Tilesheet::getTexture() const {
    return this->texture;
}

sf::Vector2f Tilesheet::getTextureCoord(const int &idx) const {
    return {
            static_cast<float>(idx % this->sheetWidth + this->margin - 1),
            static_cast<float>(idx / this->sheetWidth + this->margin)
    };
}
