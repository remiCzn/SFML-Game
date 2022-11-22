#include "SceneGame.hpp"
#include "constants.hpp"
#include "../component/InputComponent.hpp"
#include "../component/AnimationComponent.hpp"

SceneGame::SceneGame(Window &window) : window(window) {}

void SceneGame::onActivate() {
    this->window.setScale(5);
    this->player->awake();
}

void SceneGame::onDeactivate() {
    this->window.setScale(1);
}

void SceneGame::onCreate() {
    player = std::make_shared<Object>();
    auto sprite = player->addComponent<SpriteComponent>();
    sprite->load("assets/character/chara1.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));

    auto movement = player->addComponent<InputComponent>();
    movement->setInput(&input);

    auto animation = player->addComponent<AnimationComponent>();
    animation->load("assets/character/animations.json");

    tilemap = std::make_shared<Tilemap>();
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
    tilemap->draw(window);
    player->draw(window);
    window.setCenter(player->transform->getPosition());
}

void SceneGame::lateUpdate(const float &dt) {
    player->lateUpdate(dt);
}
