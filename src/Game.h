#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "gameobject/Player.h"
#include "tilemap/Tilemap.h"
#include "state/Mainstate.h"

class Game {
private:
    std::shared_ptr<sf::RenderWindow> window;
    Mainstate mainstate;

    float dt;
    sf::Clock dtClock;

public:
    Game();

    virtual ~Game() = default;

    void handeEvent();

    void update();

    void render();

    void run();
};


#endif //GAME_GAME_H
