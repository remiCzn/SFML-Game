#ifndef GAME_SCENEGAME_HPP
#define GAME_SCENEGAME_HPP


#include "Scene.hpp"
#include "../objects/Object.hpp"
#include "../utils/Input.hpp"
#include "../component/SpriteComponent.hpp"
#include "defines.hpp"
#include "../objects/Tilemap.hpp"

class SceneGame : public Scene {
public:
    explicit SceneGame(Window &window);

    void onCreate() override;

    void onDestroy() override;

    void onActivate() override;

    void onDeactivate() override;

    void updateInput() override;

    void update(const float &dt) override;

    void lateUpdate(const float &dt) override;

    void draw(Window &window) override;

private:
    sf::Texture testTexture;
    sf::Sprite testSprite;

    std::shared_ptr<Object> player;
    Window &window;

    std::shared_ptr<Tilemap> tilemap;

    Input input;
};


#endif //GAME_SCENEGAME_HPP
