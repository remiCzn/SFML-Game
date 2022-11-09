#ifndef GAME_PLAYERANIMATIONCOMPONENT_H
#define GAME_PLAYERANIMATIONCOMPONENT_H

#include "../GraphicsComponent.h"

enum Direction {
    Up,
    Down,
    Left,
    Right
};

enum State {
    Idle
};

class PlayerAnimationComponent : public GraphicsComponent {
public:
    explicit PlayerAnimationComponent(std::shared_ptr<PhysicsComponent> physics);

    void update(const float &dt) override;

    void setTexture(int x, int y);

    void setDirection(const Direction &direction);

    void render(const std::shared_ptr<sf::RenderTarget> &target) override;

private:
    void updateDirection();

    Direction direction;
    std::unordered_map<Direction, sf::Vector2i> animations;
};


#endif //GAME_PLAYERANIMATIONCOMPONENT_H
