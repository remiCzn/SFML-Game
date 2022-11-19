//
// Created by cazin on 19/11/2022.
//

#include "SceneIntroScreen.hpp"

SceneIntroScreen::SceneIntroScreen(SceneStateMachine &sceneStateMachine, Window &window)
        : window(window),
          stateMachine(
                  sceneStateMachine),
          currentTime(0),
          showForSeconds(3),
          nextState(0) {}

void SceneIntroScreen::onCreate() {
    this->logoTexture.loadFromFile("assets/UI/logo.jpg");
    this->logoSprite.setTexture(logoTexture);

    const sf::FloatRect spriteSize = logoSprite.getGlobalBounds();
    logoSprite.setOrigin(spriteSize.width / 2.f, spriteSize.height / 2.f);
    logoSprite.setScale(0.5f, 0.5f);

    sf::Vector2u wCenter = window.getCenter();
    logoSprite.setPosition(wCenter.x, wCenter.y);

    this->background.setFillColor(sf::Color(126, 199, 175));
    this->background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
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

void SceneIntroScreen::draw(Window &window) {
    window.draw(this->background);
    window.draw(this->logoSprite);
}

void SceneIntroScreen::setSwitchToScene(unsigned int id) {
    this->nextState = id;
}
