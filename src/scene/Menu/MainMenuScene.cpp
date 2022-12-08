#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene(SceneStateMachine &sceneStateMachine, Window &window) : Scene(window),
                                                                                     stateMachine(sceneStateMachine),
                                                                                     gameState(-1),
                                                                                     settingsState(-1) {
}

void MainMenuScene::update(const float &dt) {
    Scene::update(dt);
    if (this->startButton.isMouseDown()) {
        stateMachine.switchTo(this->gameState);
    } else if (this->settingsButton.isMouseDown()) {
        stateMachine.switchTo(this->settingsState);
    } else if (this->quitMenu.isMouseDown()) {
        window.get().close();
    }
}

void MainMenuScene::setGameState(unsigned int id) {
    this->gameState = id;
}

void MainMenuScene::setSettingsState(unsigned int id) {
    this->settingsState = id;
}

void MainMenuScene::onCreate() {
    this->title.setPosition(sf::Vector2f(100, 100));
    this->title.setString("The Game");
    this->title.setFillColor(sf::Color::White);

    this->window.gui().setFont("assets/UI/dogicapixel.ttf");

    this->startButton.setText("Start");
    this->startButton.setPosition(100, 175);

    this->settingsButton.setPosition(100, 250);
    this->settingsButton.setText("Settings");

    this->quitMenu.setText("Quit");
    this->quitMenu.setPosition(100, 325);
}

void MainMenuScene::draw() {
    window.gui().draw();
    window.draw(this->title);
}

void MainMenuScene::onActivate() {
    window.gui().add(this->startButton.get());
    window.gui().add(this->settingsButton.get());
    window.gui().add(this->quitMenu.get());
}

void MainMenuScene::onDeactivate() {
    window.gui().remove(this->startButton.get());
    window.gui().remove(this->settingsButton.get());
    window.gui().remove(this->quitMenu.get());
}

void MainMenuScene::onDestroy() {

}
