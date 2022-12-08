#include "Tilemap.hpp"
#include "../component/tilemap/TilemapComponent.hpp"
#include "../component/tilemap/TilemapDrawableComponent.hpp"
#include "../component/tilemap/TilemapColliderComponent.hpp"

Tilemap::Tilemap() : Object() {
    this->addComponent<TilemapComponent>();
    this->addComponent<TilemapDrawableComponent>();
    this->addComponent<TilemapColliderComponent>();
    this->getComponent<TilemapComponent>()->load("assets/maps/test_map.tmj");
    this->getComponent<TilemapDrawableComponent>()->load("assets/tilesheet/main_sheet.tsj",
                                                         "assets/tilesheet/main_sheet.png");
}
