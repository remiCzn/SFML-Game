#ifndef GAME_QUADTREE_HPP
#define GAME_QUADTREE_HPP

#include "defines.hpp"
#include "../component/collider/BoxColliderComponent.hpp"

using Colliders = std::vector<std::shared_ptr<BoxColliderComponent>>;

class Quadtree {
public:
    Quadtree();

    Quadtree(int maxObjects, int maxLevels, int level, sf::FloatRect bounds, Quadtree *parent);

    void drawDebug();

    void insert(const std::shared_ptr<BoxColliderComponent> &object);

    void remove(const std::shared_ptr<BoxColliderComponent> &object);

    void clear();

    void updatePosition(const std::shared_ptr<BoxColliderComponent> &object);

    Colliders search(const sf::FloatRect &area);

    const sf::FloatRect &getBounds();

private:

    void search(const sf::FloatRect &area, Colliders &overlappingObjects);

    int getChildIndexForObject(const sf::FloatRect &objectBounds) const;

    void split();

    static const int thisTree = -1;
    static const int childNE = 0;
    static const int childNW = 1;
    static const int childSW = 2;
    static const int childSE = 3;

    size_t maxObjects;
    size_t maxLevels;

    Quadtree *parent;
    std::shared_ptr<Quadtree> children[4];

    std::vector<std::shared_ptr<BoxColliderComponent>> objects;

    size_t level;

    sf::FloatRect bounds;
};


#endif //GAME_QUADTREE_HPP
