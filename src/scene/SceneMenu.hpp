#ifndef GAME_SCENEMENU_HPP
#define GAME_SCENEMENU_HPP

#include "Scene.hpp"
#include "SceneStateMachine.hpp"
#include "../utils/Input.hpp"
#include "defines.hpp"

class SceneMenu : public Scene {
public:
    explicit SceneMenu(SceneStateMachine &sceneStateMachine, Window &window);

    void update(const float &dt) override;

    void draw() override;

    void onCreate() override;

    void onActivate() override;

    void onDeactivate() override;

    void onDestroy() override;

    void setNextState(unsigned int id);

private:
    SceneStateMachine &stateMachine;

    unsigned int nextState;

    Input input;

    sf::Font font;
    sf::Text title;
    tgui::Button::Ptr startButton;
    tgui::Button::Ptr quitMenu;
};


#endif //GAME_SCENEMENU_HPP
