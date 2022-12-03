#ifndef GAME_SCENESTATEMACHINE_HPP
#define GAME_SCENESTATEMACHINE_HPP

#include "defines.hpp"
#include "Scene.hpp"


class SceneStateMachine {
public:
    SceneStateMachine();

    void updateInput();

    void update(const float &dt);

    void lateUpdate(const float &dt);

    void draw();

    unsigned int add(std::shared_ptr<Scene> scene);

    void switchTo(unsigned int id);

    void remove(unsigned int id);

private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> curScene;
    unsigned int insertedSceneID;
};


#endif //GAME_SCENESTATEMACHINE_HPP
