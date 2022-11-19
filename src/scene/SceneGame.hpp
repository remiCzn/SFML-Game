#ifndef GAME_SCENEGAME_HPP
#define GAME_SCENEGAME_HPP


#include "Scene.hpp"
#include "../utils/Input.hpp"

class SceneGame : public Scene {
public:
    SceneGame();

    void onCreate() override;

    void onDestroy() override;

    void updateInput() override;

    void update(const float &dt) override;

    void draw(Window &window) override;

private:
    sf::Texture testTexture;
    sf::Sprite testSprite;

    Input input;
};


#endif //GAME_SCENEGAME_HPP
