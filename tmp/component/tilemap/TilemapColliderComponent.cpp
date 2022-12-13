#include "TilemapColliderComponent.hpp";
#include "../collider/BoxColliderComponent.hpp"
#include "../../utils/Debug.hpp"

bool TilemapColliderComponent::intersects(std::shared_ptr<ColliderComponent> other) {
    /**
     * Not used in practice, because tilemap is static
     */
    std::shared_ptr<BoxColliderComponent> boxCollider = std::dynamic_pointer_cast<BoxColliderComponent>(other);
    if (boxCollider) {
        const sf::FloatRect &rect2 = boxCollider->getCollidable();
        if (this->intersects(rect2)) {
            return true;
        }
    }

    return false;
}

TilemapColliderComponent::TilemapColliderComponent(Object *owner) : ColliderComponent(owner) {}

bool TilemapColliderComponent::intersects(const sf::FloatRect &other) {
    this->collidingTiles.clear();
    int pX = other.left / TilemapConsts::TILE_SIZE;
    int pY = other.top / TilemapConsts::TILE_SIZE;
    for (int x = pX - 2; x < pX + 3; x++) {
        for (int y = pY - 2; y < pY + 3; y++) {
            if (this->collision_map[x][y]) {
                this->collidingTiles.emplace_back(
                        x * TilemapConsts::TILE_SIZE,
                        y * TilemapConsts::TILE_SIZE,
                        TilemapConsts::TILE_SIZE,
                        TilemapConsts::TILE_SIZE);
            }
        }
    }
    for (auto &collidable: this->collidingTiles) {
        if (other.intersects(collidable)) {
            return true;
        }
    }
    return false;
}

const sf::FloatRect &TilemapColliderComponent::getCollidable() {
    return this->AABB;
}

void TilemapColliderComponent::load() {
    for (auto &chunk_row: this->owner->getComponent<TilemapComponent>()->getChunks()) {
        for (auto &chunk: chunk_row.second) {
            int chunkX = chunk_row.first;
            int chunkY = chunk.first;
            Map<TileInfo> ck = chunk.second;

            for (int x = 0; x < TilemapConsts::CHUNK_SIZE; x++) {
                for (int y = 0; y < TilemapConsts::CHUNK_SIZE; y++) {
                    this->collision_map[chunkX + x][chunkY + y] = ck[x][y].collision;
                }
            }
        }
    }
}

void TilemapColliderComponent::drawDebug() {
    for (auto &tile: this->collidingTiles) {
        Debug::drawRect(tile, sf::Color::Red);
    }
}

TilemapColliderComponent::~TilemapColliderComponent() = default;
