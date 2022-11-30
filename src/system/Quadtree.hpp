#ifndef GAME_QUADTREE_HPP
#define GAME_QUADTREE_HPP

#include "defines.hpp"
#include "../component/collider/BoxColliderComponent.hpp"

class Quadtree {
public:
    Quadtree();

    Quadtree(int maxObjects, int maxLevels, int level, sf::FloatRect bounds, Quadtree *parent);

    void insert(const std::shared_ptr<BoxColliderComponent> &object);

    void remove(std::shared_ptr<BoxColliderComponent> object);

    void clear();

    std::vector<std::shared_ptr<BoxColliderComponent>> search(const sf::FloatRect &area);

    const sf::FloatRect &getBounds();

private:
    void search(const sf::FloatRect &area, std::vector<std::shared_ptr<BoxColliderComponent>> &overlappingObjects);

    int getChildIndexForObject(const sf::FloatRect &objectBounds) const;

    void split();

    static const int thisTree = -1;
    static const int childNE = 0;
    static const int childNW = 1;
    static const int childSW = 2;
    static const int childSE = 3;

    int maxObjects;
    int maxLevels;

    Quadtree *parent;
    std::shared_ptr<Quadtree> children[4];

    std::vector<std::shared_ptr<BoxColliderComponent>> objects;

    int level;

    sf::FloatRect bounds;
};


#endif //GAME_QUADTREE_HPP
