#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP


#include <SFML/System/Clock.hpp>
#include "ecs/SharedContext.hpp"
#include "ecs/state/StateManager.hpp"

class Game {
public:
    Game();

    ~Game();

    void update();

    void render();

    void lateUpdate();

    float getDt();

private:
    ECS::SharedContext context;
    ECS::StateManager stateManager;

    sf::Clock clock;
    float dt{};

    void restartClock();
};


#endif //GAME_GAME_HPP
