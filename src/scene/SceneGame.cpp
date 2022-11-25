#include "SceneGame.hpp"
#include "constants.hpp"
#include "../component/InputComponent.hpp"
#include "../component/AnimationComponent.hpp"

SceneGame::SceneGame(Window &window, ResourceManager<sf::Texture> &textureAllocator)
        : window(window), textureAllocator(textureAllocator) {}

void SceneGame::onActivate() {
    this->window.setScale(5);
}

void SceneGame::onDeactivate() {
    this->window.setScale(1);
}

void SceneGame::onCreate() {
    player = std::make_shared<Object>();
    auto sprite = player->addComponent<SpriteComponent>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load("assets/character/chara1.png");
    sprite->setTextureRect(sf::IntRect(0, 0, GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y));

    auto movement = player->addComponent<InputComponent>();
    movement->setInput(&input);

    auto animation = player->addComponent<AnimationComponent>();
    animation->load("assets/character/animations.json");

    player->transform->setPosition(-8 * TILE_SIZE, -10 * TILE_SIZE);

    objects.add(std::make_shared<Tilemap>());
    objects.add(player);
}

void SceneGame::onDestroy() {

}

void SceneGame::updateInput() {
    this->input.update();
}

void SceneGame::update(const float &dt) {
    objects.processRemovals();
    objects.processNewObjects();
    objects.update(dt);
}

void SceneGame::draw(Window &window) {
    objects.draw(window);
    window.setCenter(player->transform->getPosition());
}

void SceneGame::lateUpdate(const float &dt) {
    objects.lateUpdate(dt);
}
