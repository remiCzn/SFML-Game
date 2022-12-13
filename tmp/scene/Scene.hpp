#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP


#include "../utils/Window.hpp"

class Scene {
public:
    explicit Scene(Window &window) : window(window) {}

    virtual void onCreate() = 0;

    virtual void onDestroy() = 0;

    virtual void onActivate() {};

    virtual void onDeactivate() {};

    virtual void update(const float &dt) {};

    virtual void lateUpdate(const float &dt) {};

    virtual void draw() {};
protected:
    Window &window;
};


#endif //GAME_SCENE_HPP
