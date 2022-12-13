#include "SettingsMenuScene.hpp"

SettingsMenuScene::SettingsMenuScene(SceneStateMachine &sceneStateMachine, Window &window)
        : Scene(window), stateMachine(sceneStateMachine), mainMenuState(-1) {

}

void SettingsMenuScene::update(const float &dt) {
    Scene::update(dt);
    if (this->backButton.isMouseDown()) {
        stateMachine.switchTo(this->mainMenuState);
    }
}

void SettingsMenuScene::draw() {
    Scene::draw();
    window.gui().draw();
}

void SettingsMenuScene::onCreate() {
    this->backButton.setPosition(100, 100);
    this->backButton.setText("Back to Main Menu");
}

void SettingsMenuScene::onActivate() {
    Scene::onActivate();
    window.gui().add(this->backButton.get());
}

void SettingsMenuScene::onDeactivate() {
    Scene::onDeactivate();
    window.gui().remove(this->backButton.get());
}

void SettingsMenuScene::setMainMenuState(unsigned int id) {
    this->mainMenuState = id;
}

void SettingsMenuScene::onDestroy() {

}
