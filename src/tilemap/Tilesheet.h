#ifndef GAME_TILESHEET_H
#define GAME_TILESHEET_H

#include "defines.h"
#include "constants.h"

using TilemapConsts::TILE_SIZE;

class Tilesheet {
public:
    explicit Tilesheet(const std::string &tmj_path, const std::string &png_path);

    const sf::Texture &getTexture() const;

    sf::Vector2f getTextureCoord(const int &idx) const;

private:
    sf::Texture texture;
    int sheetWidth;
    int margin;
};


#endif //GAME_TILESHEET_H
