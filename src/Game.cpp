#include "Game.hpp"
#include "scene/SceneIntroScreen.hpp"
#include "scene/SceneGame.hpp"
#include "scene/SceneMenu.hpp"

Game::Game() : window("Game") {
    std::shared_ptr<SceneIntroScreen> introScreen = std::make_shared<SceneIntroScreen>(sceneStateMachine, window);
    std::shared_ptr<SceneGame> sceneGame = std::make_shared<SceneGame>(window, this->textureAllocator);

    std::shared_ptr<SceneMenu> sceneMenu = std::make_shared<SceneMenu>(sceneStateMachine, window);

    unsigned int introScrennId = sceneStateMachine.add(introScreen);
    unsigned int menuScrenId = sceneStateMachine.add(sceneMenu);
    unsigned int gameScreenId = sceneStateMachine.add(sceneGame);

    sceneMenu->setNextState(gameScreenId);
    introScreen->setSwitchToScene(menuScrenId);
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
    sceneStateMachine.draw();
    window.endDraw();
}

bool Game::isRunning() const {
    return window.isOpen();
}

void Game::updateDt() {
    this->dt = clock.restart().asSeconds();
}
