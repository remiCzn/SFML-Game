#include "Game.hpp"
#include "scene/SceneIntroScreen.hpp"
#include "scene/SceneGame.hpp"

Game::Game() : window("Game") {
    std::shared_ptr<SceneIntroScreen> introScreen = std::make_shared<SceneIntroScreen>(sceneStateMachine, window);
    std::shared_ptr<SceneGame> sceneGame = std::make_shared<SceneGame>(window);

    unsigned int introScrennId = sceneStateMachine.add(introScreen);
    unsigned int gameScreenId = sceneStateMachine.add(sceneGame);

    introScreen->setSwitchToScene(gameScreenId);
    sceneStateMachine.switchTo(introScrennId);

    this->dt = clock.restart().asSeconds();
}

void Game::update() {
    window.update();
    sceneStateMachine.update(this->dt);
}

void Game::lateUpdate() {
    sceneStateMachine.lateUpdate(this->dt);
}

void Game::draw() {
    window.beginDraw();
    sceneStateMachine.draw(window);
    window.endDraw();
}

bool Game::isRunning() const {
    return window.isOpen();
}

void Game::updateDt() {
    this->dt = clock.restart().asSeconds();
}

void Game::updateInput() {
    sceneStateMachine.updateInput();
}
