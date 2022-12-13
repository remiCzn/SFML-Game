#ifndef GAME_TILEMAP_HPP
#define GAME_TILEMAP_HPP


#include "Object.hpp"

class Tilemap : public Object {
public:
    Tilemap();

    void draw(Window &window) override;
};


#endif //GAME_TILEMAP_HPP
