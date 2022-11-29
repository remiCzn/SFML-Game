#include "Quadtree.hpp"

Quadtree::Quadtree() : Quadtree(5, 5, 0, {0, 0, 800, 600}, nullptr) {}

Quadtree::Quadtree(int maxObjects, int maxLevels, int level, sf::FloatRect bounds, Quadtree *parent)
        : maxObjects(maxObjects), maxLevels(maxLevels), level(level), bounds(bounds), parent(parent) {}

void Quadtree::insert(const std::shared_ptr<BoxColliderComponent> &object) {
    if (!bounds.intersects(object->getCollidable())) {
        return;
    }

    if (children[0] != nullptr) {
        int indexToPlaceObject = getChildIndexForObject(object->getCollidable());

        if (indexToPlaceObject != thisTree) {
            children[indexToPlaceObject]->insert(object);
            return;
        }

        objects.emplace_back(object);

        if (objects.size() > maxObjects && level < maxLevels && children[0] == nullptr) {
            split();
            auto objIterator = objects.begin();
            while (objIterator != objects.end()) {
                auto obj = *objIterator;
                int indexToPlaceObject = getChildIndexForObject(obj->getCollidable());

                if (indexToPlaceObject != thisTree) {
                    children[indexToPlaceObject]->insert(obj);
                    objIterator = objects.erase(objIterator);
                } else {
                    objIterator++;
                }
            }
        }
    }
}

void Quadtree::remove(std::shared_ptr<BoxColliderComponent> object) {
    int index = getChildIndexForObject(object->getCollidable());
    if (index == thisTree || children[index] == nullptr) {
        for (int i = 0; i < objects.size(); i++) {
            if (objects.at(i)->owner->instanceID.get() == object->owner->instanceID.get()) {
                objects.erase(objects.begin() + i);
                break;
            }
        }
    } else {
        return children[index]->remove(object);
    }
}

void Quadtree::clear() {
    objects.clear();
    for (auto &i: children) {
        if (i != nullptr) {
            i->clear();
            i = nullptr;
        }
    }
}

std::vector<std::shared_ptr<BoxColliderComponent>> Quadtree::search(const sf::FloatRect &area) {
    std::vector<std::shared_ptr<BoxColliderComponent>> possibleOverlaps;
    search(area, possibleOverlaps);

    std::vector<std::shared_ptr<BoxColliderComponent>> returnList;

    for (const auto &collider: possibleOverlaps) {
        if (area.intersects(collider->getCollidable())) {
            returnList.emplace_back(collider);
        }
    }

    return returnList;
}

const sf::FloatRect &Quadtree::getBounds() {
    return bounds;
}

void
Quadtree::search(const sf::FloatRect &area, std::vector<std::shared_ptr<BoxColliderComponent>> &overlappingObjects) {
    overlappingObjects.insert(overlappingObjects.end(), objects.begin(), objects.end());

    if (children[0] != nullptr) {
        int index = getChildIndexForObject(area);
        if (index == thisTree) {
            for (auto &i: children) {
                if (i->getBounds().intersects(area)) {
                    i->search(area, overlappingObjects);
                }
            }
        } else {
            children[index]->search(area, overlappingObjects);
        }
    }
}

int Quadtree::getChildIndexForObject(const sf::FloatRect &objectBounds) const {
    int index = -1;
    double verticalDividingLine = bounds.left + bounds.width / 2.f;
    double horizontalDividingLine = bounds.top + bounds.height / 2.f;

    bool north = objectBounds.top < horizontalDividingLine &&
                 (objectBounds.height + objectBounds.top < horizontalDividingLine);
    bool south = objectBounds.top > horizontalDividingLine;
    bool west =
            objectBounds.left < verticalDividingLine && (objectBounds.left + objectBounds.width < verticalDividingLine);
    bool east = objectBounds.left > verticalDividingLine;

    if (east) {
        if (north) {
            index = childNE;
        } else if (south) {
            index = childSE;
        }
    } else if (west) {
        if (north) {
            index = childNW;
        } else if (south) {
            index = childSW;
        }
    }

    return index;
}

void Quadtree::split() {
    float childWidth = bounds.width / 2;
    float childHeight = bounds.height / 2;

    children[childNE] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
                                                   sf::FloatRect(bounds.left + childWidth, bounds.top, childWidth,
                                                                 childHeight), this);
    children[childNW] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
                                                   sf::FloatRect(bounds.left, bounds.top, childWidth, childHeight),
                                                   this);
    children[childSW] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
                                                   sf::FloatRect(bounds.left, bounds.top + childHeight, childWidth,
                                                                 childHeight), this);
    children[childSE] = std::make_shared<Quadtree>(maxObjects, maxLevels, level + 1,
                                                   sf::FloatRect(bounds.left + childWidth, bounds.top + childHeight,
                                                                 childWidth, childHeight), this);
}
