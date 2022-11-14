#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include "gameobject/Player.hpp"
#include "tilemap/Tilemap.hpp"
#include "state/Mainstate.hpp"

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


#endif //GAME_GAME_HPP
