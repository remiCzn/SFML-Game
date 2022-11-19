#ifndef GAME_SCENEINTROSCREEN_HPP
#define GAME_SCENEINTROSCREEN_HPP


#include "SceneStateMachine.hpp"

class SceneIntroScreen : public Scene {
public:
    SceneIntroScreen(SceneStateMachine &sceneStateMachine, Window &window);

    void onCreate() override;

    void onDestroy() override;

    void onActivate() override;

    void update(const float &dt) override;

    void draw(Window &window) override;

    void setSwitchToScene(unsigned int id);

private:
    sf::Texture logoTexture;
    sf::Sprite logoSprite;

    sf::RectangleShape background;

    SceneStateMachine &stateMachine;
    Window &window;

    float showForSeconds;
    float currentTime;

    unsigned int nextState;
};


#endif //GAME_SCENEINTROSCREEN_HPP
