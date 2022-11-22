#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP


#include "../utils/Window.hpp"

class Scene {
public:
    virtual void onCreate() = 0;

    virtual void onDestroy() = 0;

    virtual void onActivate() {};

    virtual void onDeactivate() {};

    virtual void updateInput() {};

    virtual void update(const float &dt) {};

    virtual void lateUpdate(const float &dt) {};

    virtual void draw(Window &window) {};
};


#endif //GAME_SCENE_HPP