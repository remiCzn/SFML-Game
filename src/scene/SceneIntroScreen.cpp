#include "SceneIntroScreen.hpp"

SceneIntroScreen::SceneIntroScreen(SceneStateMachine &sceneStateMachine, Window &window)
        : Scene(window),
          stateMachine(
                  sceneStateMachine),
          currentTime(0),
          showForSeconds(2),
          nextState(0) {}

void SceneIntroScreen::onCreate() {
    this->text.setCharacterSize(18);
    this->text.setString(" remiCzn \r\n\r\npresents");
    this->text.setPosition(
            this->window.getCenter().x - this->text.getGlobalBounds().width / 2,
            this->window.getCenter().y - this->text.getGlobalBounds().height / 2
    );
}

void SceneIntroScreen::onDestroy() {

}

void SceneIntroScreen::onActivate() {
    currentTime = 0;
}

void SceneIntroScreen::update(const float &dt) {
    currentTime += dt;

    if (currentTime >= showForSeconds) {
        this->stateMachine.switchTo(this->nextState);
    }
}

void SceneIntroScreen::draw() {
    window.draw(this->text);
}

void SceneIntroScreen::setSwitchToScene(unsigned int id) {
    this->nextState = id;
}
