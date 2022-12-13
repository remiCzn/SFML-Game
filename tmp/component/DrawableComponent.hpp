#ifndef GAME_DRAWABLECOMPONENT_HPP
#define GAME_DRAWABLECOMPONENT_HPP

#include "defines.hpp"
#include "../utils/Window.hpp"

class DrawableComponent {
public:
    DrawableComponent();

    virtual ~DrawableComponent();

    virtual void draw(Window &window) = 0;

    void setOrder(int order);

    int getSortOrder() const;

private:
    int sortOrder;
};


#endif //GAME_DRAWABLECOMPONENT_HPP
