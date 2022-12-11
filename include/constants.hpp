#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "defines.hpp"

namespace TilemapConsts {
    const int CHUNK_SIZE = 16;
    const int TILE_SIZE = 16;
}

namespace GraphcisConsts {
    const float SCALE = 5;
    const sf::Vector2i PLAYER_DIM = sf::Vector2i(16, 32);
}

namespace PhysicsConsts {
    const float PLAYER_SPEED_FLOAT = 80.0;
}

namespace WindowConsts {
    const sf::Vector2f WINDOW_SIZE = sf::Vector2f(1280, 720);
}

#endif //GAME_CONSTANTS_H
