#ifndef GAME_SETTINGSMENUSCENE_HPP
#define GAME_SETTINGSMENUSCENE_HPP


#include "../SceneStateMachine.hpp"
#include "../../UI/Button.hpp"

class SettingsMenuScene : public Scene {
public:
    SettingsMenuScene(SceneStateMachine &sceneStateMachine, Window &window);

    void update(const float &dt) override;

    void draw() override;

    void onCreate() override;

    void onActivate() override;

    void onDeactivate() override;

    void onDestroy() override;

    void setMainMenuState(unsigned int id);

private:
    SceneStateMachine &stateMachine;
    unsigned int mainMenuState;

    Button backButton;

};


#endif //GAME_SETTINGSMENUSCENE_HPP
