#include "Tilemap.hpp"
#include "../component/tilemap/TilemapComponent.hpp"
#include "../component/tilemap/TilemapDrawableComponent.hpp"

Tilemap::Tilemap() : Object() {
    this->addComponent<TilemapComponent>();
    this->addComponent<TilemapDrawableComponent>();
    this->getComponent<TilemapComponent>()->load("assets/maps/test_map.tmj");
    this->getComponent<TilemapDrawableComponent>()->load("assets/tilesheet/main_sheet.tsj",
                                                         "assets/tilesheet/main_sheet.png");
}
