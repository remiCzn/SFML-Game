#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP


#include "utils/Window.hpp"
#include "constants.hpp"
#include "utils/Input.hpp"
#include "Scene/SceneStateMachine.hpp"
#include "utils/ResourceManager.hpp"

class Game {
public:
    Game();

    void updateInput();

    void update();

    void lateUpdate();

    void draw();

    void updateDt();

    bool isRunning() const;

private:
    Window window;

    sf::Clock clock;
    float dt;

    SceneStateMachine sceneStateMachine;
    ResourceManager <sf::Texture> textureAllocator;
};


#endif //GAME_GAME_HPP
