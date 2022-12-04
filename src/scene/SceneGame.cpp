#include "SceneGame.hpp"
#include "../objects/Chest.hpp"

SceneGame::SceneGame(Window &window, ResourceManager<sf::Texture> &textureAllocator)
        : Scene(window), textureAllocator(textureAllocator) {}

void SceneGame::onActivate() {
    this->window.setScale(5);
}

void SceneGame::onDeactivate() {
    this->window.setScale(1);
}

void SceneGame::onCreate() {
    player = std::make_shared<Player>(textureAllocator, input);
    std::shared_ptr<Object> tilemap = std::make_shared<Tilemap>();
    auto chest = std::make_shared<Chest>(textureAllocator);
    objects.add(tilemap);
    objects.add(chest);
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

void SceneGame::draw() {
    objects.draw(window);
    window.setCenter(player->transform->getPosition() +
                     sf::Vector2f(GraphcisConsts::PLAYER_DIM.x, GraphcisConsts::PLAYER_DIM.y) / 2.f);
}

void SceneGame::lateUpdate(const float &dt) {
    objects.lateUpdate(dt);
}
