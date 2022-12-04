#include "Quadtree.hpp"

Quadtree::Quadtree() : Quadtree(10, 5, 0, {0, 0, defaultWidth, defaultHeight}, nullptr) {}

Quadtree::Quadtree(int maxObjects, int maxLevels, int level, sf::FloatRect bounds, Quadtree *parent)
        : maxObjects(maxObjects), maxLevels(maxLevels), level(level), bounds(bounds), parent(parent) {}

void Quadtree::insert(const std::shared_ptr<BoxColliderComponent> &object) {
    if (children[0] != nullptr) {
        int indexToPlaceObject = getChildIndexRectangleBelongsIn(object->getCollidable());

        if (indexToPlaceObject != thisTree) {
            children[indexToPlaceObject]->insert(object);
            return;
        }
    }
    objects.emplace_back(object);

    if (objects.size() > maxObjects && level < maxLevels) {
        split();

        size_t i = 0;
        while (i < objects.size()) {
            int indexToPlaceObject = getChildIndexRectangleBelongsIn(objects.at(i)->getCollidable());

            if (indexToPlaceObject != thisTree) {
                children[indexToPlaceObject]->insert(objects.at(i));
                objects.erase(objects.begin() + i);
            } else {
                i++;
            }
        }
    }
}

void Quadtree::remove(std::shared_ptr<BoxColliderComponent> object) {
    int index = getChildIndexRectangleBelongsIn(object->getCollidable());
    if (index == thisTree || children[index] == nullptr) {
        for (size_t i = 0; i < objects.size(); i++) {
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

Colliders Quadtree::search(const sf::FloatRect &area, Colliders overlappingObjects) {
    overlappingObjects.insert(overlappingObjects.end(), objects.begin(), objects.end());

    int index = getChildIndexRectangleBelongsIn(area);

    if (index == thisTree || children[0] == nullptr) {
        if (children[0] != nullptr) {
            for (int i = 0; i < 4; i++) {
                if (children[i]->getBounds().intersects(area)) {
                    children[i]->search(area, overlappingObjects);
                }
            }
        }
    } else if (children[index] != nullptr) {
        children[index]->search(area, overlappingObjects);
    }
    return overlappingObjects;
}

Colliders Quadtree::search(const sf::FloatRect &area) {
    Colliders returnList;
    Colliders possibleOverlaps = this->search(area, Colliders());

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


int Quadtree::getChildIndexRectangleBelongsIn(const sf::FloatRect &objectBounds) const {
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
