#include "SceneGame.hpp"
#include "../objects/Chest.hpp"
#include "../utils/Debug.hpp"

SceneGame::SceneGame(Window &window, ResourceManager<sf::Texture> &textureAllocator)
        : Scene(window), textureAllocator(textureAllocator) {}

void SceneGame::onActivate() {
    this->window.setScale(5);
}

void SceneGame::onDeactivate() {
    this->window.setScale(1);
}

void SceneGame::onCreate() {
    player = std::make_shared<Player>(textureAllocator);
    std::shared_ptr<Object> tilemap = std::make_shared<Tilemap>();
    auto chest = std::make_shared<Chest>(textureAllocator);
    auto chest2 = std::make_shared<Chest>(textureAllocator);
    auto chest3 = std::make_shared<Chest>(textureAllocator);
    chest2->transform->setPosition(-5 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);
    chest->transform->setPosition(-6 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);
    chest3->transform->setPosition(-4 * TilemapConsts::TILE_SIZE, -10 * TilemapConsts::TILE_SIZE);

    objects.add(tilemap);
    objects.add(chest);
    objects.add(chest2);
    objects.add(chest3);
    objects.add(player);
}

void SceneGame::onDestroy() {

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
    Debug::draw(window);
}

void SceneGame::lateUpdate(const float &dt) {
    objects.lateUpdate(dt);
}
