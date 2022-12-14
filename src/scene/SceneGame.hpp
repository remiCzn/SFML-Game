#ifndef GAME_SCENEGAME_HPP
#define GAME_SCENEGAME_HPP


#include "Scene.hpp"
#include "../objects/Object.hpp"
#include "../utils/Input.hpp"
#include "../component/SpriteComponent.hpp"
#include "defines.hpp"
#include "../utils/ResourceManager.hpp"
#include "../objects/ObjectCollection.hpp"
#include "constants.hpp"
#include "../objects/Tilemap.hpp"
#include "../objects/Player.hpp"

class SceneGame : public Scene {
public:
    explicit SceneGame(Window &window, ResourceManager<sf::Texture> &textureAllocator);

    void onCreate() override;

    void onDestroy() override;

    void onActivate() override;

    void onDeactivate() override;

    void update(const float &dt) override;

    void lateUpdate(const float &dt) override;

    void draw() override;

private:
    std::shared_ptr<Object> player;

    ResourceManager<sf::Texture> &textureAllocator;
    ObjectCollection objects;

};


#endif //GAME_SCENEGAME_HPP
