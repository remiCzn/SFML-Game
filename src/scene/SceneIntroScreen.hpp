#ifndef GAME_SCENEINTROSCREEN_HPP
#define GAME_SCENEINTROSCREEN_HPP


#include "SceneStateMachine.hpp"
#include "../utils/ResourceManager.hpp"
#include "../UI/Text.hpp"

class SceneIntroScreen : public Scene {
public:
    SceneIntroScreen(SceneStateMachine &sceneStateMachine, Window &window);

    void onCreate() override;

    void onDestroy() override;

    void onActivate() override;

    void update(const float &dt) override;

    void draw() override;

    void setSwitchToScene(unsigned int id);

private:
    Text text;

    SceneStateMachine &stateMachine;

    float showForSeconds;
    float currentTime;

    unsigned int nextState;
};


#endif //GAME_SCENEINTROSCREEN_HPP
