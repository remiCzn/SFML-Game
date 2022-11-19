#include "SceneGame.hpp"
#include "constants.hpp"

SceneGame::SceneGame() = default;

void SceneGame::onCreate() {
    testTexture.loadFromFile("assets/character/chara1.png");
    testSprite.setTexture(testTexture);
    testSprite.setTextureRect(sf::IntRect(
            0,
            0,
            GraphcisConsts::PLAYER_DIM.x,
            GraphcisConsts::PLAYER_DIM.y
    ));
}

void SceneGame::onDestroy() {

}

void SceneGame::updateInput() {
    this->input.update();
}

void SceneGame::update(const float &dt) {
    if (this->input.isKeyPressed(Input::Key::Left)) {
        const sf::Vector2f &spritePos = testSprite.getPosition();
        this->testSprite.setPosition(spritePos.x + 100 * dt, spritePos.y);
    }
}

void SceneGame::draw(Window &window) {
    window.draw(testSprite);
}
