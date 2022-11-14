#ifndef GAME_PLAYERANIMATIONCOMPONENT_HPP
#define GAME_PLAYERANIMATIONCOMPONENT_HPP

#include "../GraphicsComponent.hpp"
#include "../Animation.hpp"

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

    void initAnimation(Direction _direction, State _state, const std::vector<sf::Vector2i> &_frames, float _delay);

    void update(const float &dt) override;

    void setTexture(const int &x, const int &y);

    void setDirection(const Direction &direction);

    void setState(const State &state);

    void render(const std::shared_ptr<sf::RenderTarget> &target) override;

private:
    void updateDirectionAndState();

    Direction direction;
    State state;
    bool changingTexture;
    std::unordered_map<Direction, std::unordered_map<State, std::unique_ptr<Animation<sf::Vector2i>>>> animations;
};

#endif //GAME_PLAYERANIMATIONCOMPONENT_HPP
