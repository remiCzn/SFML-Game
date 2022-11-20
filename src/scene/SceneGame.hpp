#ifndef GAME_SCENEGAME_HPP
#define GAME_SCENEGAME_HPP


#include "Scene.hpp"
#include "../component/Object.hpp"
#include "../utils/Input.hpp"
#include "../component/Sprite.hpp"
#include "defines.hpp"

class SceneGame : public Scene {
public:
    SceneGame();

    void onCreate() override;

    void onDestroy() override;

    void updateInput() override;

    void update(const float &dt) override;

    void lateUpdate(const float &dt) override;

    void draw(Window &window) override;

private:
    sf::Texture testTexture;
    sf::Sprite testSprite;

    std::shared_ptr<Object> player;

    Input input;
};


#endif //GAME_SCENEGAME_HPP
