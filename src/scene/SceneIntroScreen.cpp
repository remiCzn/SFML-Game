#include "SceneIntroScreen.hpp"

SceneIntroScreen::SceneIntroScreen(SceneStateMachine &sceneStateMachine, Window &window,
                                   ResourceManager<sf::Texture> &textureAllocator)
        : Scene(window),
          stateMachine(
                  sceneStateMachine),
          currentTime(0),
          showForSeconds(0.5),
          nextState(0),
          textureAllocator(textureAllocator) {}

void SceneIntroScreen::onCreate() {

    int textureId = textureAllocator.add("assets/UI/logo.jpg");
    if (textureId >= 0) {
        std::shared_ptr<sf::Texture> texture = textureAllocator.get(textureId);
        this->logoSprite.setTexture(logoTexture);

        const sf::FloatRect spriteSize = logoSprite.getGlobalBounds();
        logoSprite.setOrigin(spriteSize.width / 2.f, spriteSize.height / 2.f);
        logoSprite.setScale(0.5f, 0.5f);

        sf::Vector2u wCenter = window.getCenter();
        logoSprite.setPosition(
                static_cast<float>(wCenter.x),
                static_cast<float>(wCenter.y)
        );

        this->background.setFillColor(sf::Color(126, 199, 175));
        this->background.setSize(sf::Vector2f(
                static_cast<float>(window.getSize().x),
                static_cast<float>(window.getSize().y)
        ));

    }
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
    window.draw(this->background);
    window.draw(this->logoSprite);
}

void SceneIntroScreen::setSwitchToScene(unsigned int id) {
    this->nextState = id;
}
