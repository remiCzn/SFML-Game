#ifndef GAME_MAINMENUSCENE_HPP
#define GAME_MAINMENUSCENE_HPP

#include "../Scene.hpp"
#include "../SceneStateMachine.hpp"
#include "../../utils/Input.hpp"
#include "defines.hpp"
#include "../../UI/Text.hpp"
#include "../../UI/Button.hpp"

class MainMenuScene : public Scene {
public:
    explicit MainMenuScene(SceneStateMachine &sceneStateMachine, Window &window);

    void update(const float &dt) override;

    void draw() override;

    void onCreate() override;

    void onDestroy() override;

    void onActivate() override;

    void onDeactivate() override;


    void setGameState(unsigned int id);

    void setSettingsState(unsigned int id);

private:
    SceneStateMachine &stateMachine;

    unsigned int gameState;
    unsigned int settingsState;

    Text title;
    Button startButton;
    Button settingsButton;
    Button quitMenu;
};


#endif //GAME_MAINMENUSCENE_HPP
