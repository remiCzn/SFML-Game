#ifndef GAME_GRAPHICSCOMPONENT_H
#define GAME_GRAPHICSCOMPONENT_H

#include "defines.h"
#include "PhysicsComponent.h"

class GraphicsComponent {
public:
    GraphicsComponent(const std::string &asset_path, sf::IntRect intrect, std::shared_ptr<PhysicsComponent> physics);

    virtual ~GraphicsComponent() = default;

    virtual void update();

    virtual void render(const std::shared_ptr<sf::RenderTarget> &target);

private:
    sf::Sprite sprite;
    sf::IntRect texture_rect;
    sf::Texture texture;
    std::shared_ptr<PhysicsComponent> _physics;
};


#endif //GAME_GRAPHICSCOMPONENT_H
