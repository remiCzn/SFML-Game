#ifndef GAME_ANIMATIONCOMPONENT_HPP
#define GAME_ANIMATIONCOMPONENT_HPP

#include "Component.hpp"
#include "SpriteComponent.hpp"

enum class AnimationState {
    None,
    Idle,
    Walk
};

enum FacingDirection {
    Left,
    Right,
    Up,
    Down
};


class AnimationComponent : public Component {
public:
    class Animation {
    public:
        struct Frame {
            int x;
            int y;
            int width;
            int height;
            float duration;
        };

        Animation();

        void addFrame(int x, int y, int width, int height, float frameTime);

        void load(const Json::Value &frameList);

        const Frame *getCurrentFrame();

        bool update(const float &dt);

        void reset();

    private:
        void increment_frame();

        std::vector<Frame> frames;
        int currentFrameIndex;
        float currentFrameTime;
    };

    AnimationComponent(Object *owner);

    void awake() override;

    void update(const float &dt) override;

    void addAnimation(AnimationState state, FacingDirection direction,
                      const std::shared_ptr<Animation> &animation);

    void setAnimation(AnimationState state);

    void setDirection(FacingDirection direction);

    void load(const std::string &asset_path);

    void loadAnimation(FacingDirection direction, AnimationState state, const std::string &raw_dir,
                       const std::string &raw_state, Json::Value &animation_sheet);

    const AnimationState &getAnimationState() const;

private:
    void update_frame();

    std::shared_ptr<SpriteComponent> sprite;
    std::unordered_map<AnimationState, std::map<FacingDirection, std::shared_ptr<Animation>>> animations;
    AnimationState currentState;
    FacingDirection currentDirection;
    std::shared_ptr<Animation> currentAnimation;

};


#endif //GAME_ANIMATIONCOMPONENT_HPP
