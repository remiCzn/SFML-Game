#include "SceneGame.hpp"
#include "constants.hpp"
#include "../component/InputMovement.hpp"

SceneGame::SceneGame() = default;

void SceneGame::onCreate() {
    player = std::make_shared<Object>();
    auto sprite = player->addComponent<Sprite>();
    sprite->load("assets/character/chara1.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));

    auto movement = player->addComponent<InputMovement>();
    movement->setInput(&input);
}

void SceneGame::onDestroy() {

}

void SceneGame::updateInput() {
    this->input.update();
}

void SceneGame::update(const float &dt) {
    this->player->update(dt);
}

void SceneGame::draw(Window &window) {
    player->draw(window);
}

void SceneGame::lateUpdate(const float &dt) {
    player->lateUpdate(dt);
}
