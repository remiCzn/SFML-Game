#ifndef GAME_PLAYERANIMATIONCOMPONENT_H
#define GAME_PLAYERANIMATIONCOMPONENT_H

#include "../GraphicsComponent.h"
#include "../Animation.h"

using namespace GraphcisConsts;

enum Direction {
    Up,
    Down,
    Left,
    Right
};

enum State {
    Idle,
    Walk
};

class PlayerAnimationComponent : public GraphicsComponent {
public:
    explicit PlayerAnimationComponent(std::shared_ptr<PhysicsComponent> physics);
    
    void initAnimation(Direction direction, State state, const std::vector<sf::Vector2i> &frames, float delay);

    void update(const float &dt) override;

    void setTexture(const int &x, const int &y);

    void setDirection(const Direction &direction);

    void render(const std::shared_ptr<sf::RenderTarget> &target) override;

private:
    void updateDirection();

    Direction direction;
    State state;
    std::unordered_map<Direction, std::unordered_map<State, std::unique_ptr<Animation<sf::Vector2i>>>> animations;
};

#endif //GAME_PLAYERANIMATIONCOMPONENT_H
