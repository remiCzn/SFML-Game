#ifndef GAME_SCENEINTROSCREEN_HPP
#define GAME_SCENEINTROSCREEN_HPP


#include "SceneStateMachine.hpp"
#include "../utils/ResourceManager.hpp"

class SceneIntroScreen : public Scene {
public:
    SceneIntroScreen(SceneStateMachine &sceneStateMachine, Window &window,
                     ResourceManager<sf::Texture> &textureAllocator);

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

    ResourceManager<sf::Texture> &textureAllocator;
};


#endif //GAME_SCENEINTROSCREEN_HPP
