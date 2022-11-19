#include "SceneGame.hpp"
#include "constants.hpp"

SceneGame::SceneGame() = default;

void SceneGame::onCreate() {
    player = std::make_shared<Object>();
    auto sprite = player->addComponent<Sprite>();
    sprite->load("assets/character/chara1.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));
}

void SceneGame::onDestroy() {

}

void SceneGame::updateInput() {
    this->input.update();
}

void SceneGame::update(const float &dt) {

}

void SceneGame::draw(Window &window) {
    player->draw(window);
}
