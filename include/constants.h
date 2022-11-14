#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

namespace TilemapConsts {
    const int CHUNK_SIZE = 16;
    const int TILE_SIZE = 16;
}

namespace GraphcisConsts {
    const float SCALE = 5;
    const sf::Vector2i PLAYER_DIM = sf::Vector2i(19, 27);
}

namespace PhysicsConsts {
    const float PLAYER_SPEED_FLOAT = 400.0;
}

namespace WindowConsts {
    const sf::Vector2f WINDOW_SIZE = sf::Vector2f(1280, 720);
}

#endif //GAME_CONSTANTS_H
