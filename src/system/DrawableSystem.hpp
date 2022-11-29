#ifndef GAME_DRAWABLESYSTEM_HPP
#define GAME_DRAWABLESYSTEM_HPP

#include "defines.hpp"
#include "../objects/Object.hpp"

class DrawableSystem {
public:
    void add(std::vector<std::shared_ptr<Object>> &objects);

    void processRemovals();

    void draw(Window &window);

private:
    void add(std::shared_ptr<Object> object);

    void sort();

    std::vector<std::shared_ptr<Object>> drawables;
};


#endif //GAME_DRAWABLESYSTEM_HPP
