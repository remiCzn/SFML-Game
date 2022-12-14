#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : scenes(0), curScene(nullptr), insertedSceneID(0) {

}

void SceneStateMachine::update(const float &dt) {
    if (curScene) {
        curScene->update(dt);
    }
}

void SceneStateMachine::lateUpdate(const float &dt) {
    if (curScene) {
        curScene->lateUpdate(dt);
    }
}

void SceneStateMachine::draw() {
    if (curScene) {
        curScene->draw();
    }
}

unsigned int SceneStateMachine::add(std::shared_ptr<Scene> scene) {
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
    inserted.first->second->onCreate();
    return insertedSceneID++;
}

void SceneStateMachine::switchTo(unsigned int id) {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (curScene) {
            curScene->onDeactivate();
        }

        curScene = it->second;
        curScene->onActivate();
    }
}

void SceneStateMachine::remove(unsigned int id) {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (curScene == it->second) {
            curScene = nullptr;
        }

        it->second->onDestroy();
        scenes.erase(it);
    }
}
