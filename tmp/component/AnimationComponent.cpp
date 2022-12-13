#include "AnimationComponent.hpp"

AnimationComponent::Animation::Animation() : frames(0), currentFrameIndex(0), currentFrameTime(0) {

}

void AnimationComponent::Animation::addFrame(int x, int y, int width, int height, float frameTime) {
    Frame frame{};
    frame.x = x;
    frame.y = y;
    frame.width = width;
    frame.height = height;
    frame.duration = frameTime;
    this->frames.push_back(frame);
}

const AnimationComponent::Animation::Frame *AnimationComponent::Animation::getCurrentFrame() {
    if (!this->frames.empty()) {
        return &this->frames[this->currentFrameIndex];
    }

    return nullptr;
}

bool AnimationComponent::Animation::update(const float &dt) {
    if (frames.size() > 0) {
        this->currentFrameTime += dt;
        if (this->currentFrameTime > this->getCurrentFrame()->duration) {
            this->increment_frame();
            this->currentFrameTime = 0;
            return true;
        }
    }
    return false;
}

void AnimationComponent::Animation::reset() {
    this->currentFrameIndex = 0;
    this->currentFrameTime = 0;
}

void AnimationComponent::Animation::increment_frame() {
    currentFrameIndex = (currentFrameIndex + 1) % this->frames.size();
}

void AnimationComponent::Animation::load(const Json::Value &frameList) {
    for (auto &frame: frameList) {
        this->addFrame(
                frame["x"].asInt(),
                frame["y"].asInt(),
                frame["width"].asInt(),
                frame["height"].asInt(),
                frame["duration"].asFloat()
        );
    }
}

void AnimationComponent::load(const std::string &asset_path) {
    std::fstream f(asset_path);
    Json::Value animation_sheet;
    f >> animation_sheet;

    this->loadAnimation(FacingDirection::Down, AnimationState::Walk, "down", "walk", animation_sheet);
    this->loadAnimation(FacingDirection::Down, AnimationState::Idle, "down", "idle", animation_sheet);
    this->loadAnimation(FacingDirection::Up, AnimationState::Walk, "up", "walk", animation_sheet);
    this->loadAnimation(FacingDirection::Up, AnimationState::Idle, "up", "idle", animation_sheet);
    this->loadAnimation(FacingDirection::Left, AnimationState::Walk, "left", "walk", animation_sheet);
    this->loadAnimation(FacingDirection::Left, AnimationState::Idle, "left", "idle", animation_sheet);
    this->loadAnimation(FacingDirection::Right, AnimationState::Walk, "right", "walk", animation_sheet);
    this->loadAnimation(FacingDirection::Right, AnimationState::Idle, "right", "idle", animation_sheet);
}

AnimationComponent::AnimationComponent(Object *owner) : Component(owner),
                                                        currentAnimation(nullptr),
                                                        currentDirection(FacingDirection::Down),
                                                        currentState(AnimationState::None) {}

void AnimationComponent::awake() {
    this->sprite = this->owner->getComponent<SpriteComponent>();
}

void AnimationComponent::update(const float &dt) {
    if (currentState != AnimationState::None) {
        bool newFrame = this->currentAnimation->update(dt);
        if (newFrame) {
            this->update_frame();
        }
    }
}

void AnimationComponent::addAnimation(AnimationState state, FacingDirection direction,
                                      const std::shared_ptr<Animation> &animation) {
    auto inserted = this->animations[state][direction] = animation;

    if (currentState == AnimationState::None) {
        this->setAnimation(state);
    }
}

void AnimationComponent::setAnimation(AnimationState state) {
    if (currentState == state) {
        return;
    }

    auto new_animation = this->animations[state][currentDirection];
    if (new_animation != nullptr) {
        this->currentAnimation = new_animation;
        this->currentState = state;
        this->currentAnimation->reset();
        this->update_frame();
    }
}

void AnimationComponent::setDirection(FacingDirection direction) {
    if (direction == this->currentDirection) {
        return;
    }

    auto new_animation = this->animations[currentState][direction];
    if (new_animation != nullptr) {
        this->currentAnimation = new_animation;
        this->currentDirection = direction;
        this->currentAnimation->reset();
        this->update_frame();
    }
}

const AnimationState &AnimationComponent::getAnimationState() const {
    return this->currentState;
}

void AnimationComponent::update_frame() {
    if (this->sprite != nullptr) {
        const Animation::Frame *frame = this->currentAnimation->getCurrentFrame();
        this->sprite->setTextureRect(sf::IntRect(frame->x, frame->y, frame->width, frame->height));
    }
}

void AnimationComponent::loadAnimation(FacingDirection direction, AnimationState state, const std::string &raw_dir,
                                       const std::string &raw_state, Json::Value &animation_sheet) {
    std::shared_ptr<Animation> anim = std::make_shared<Animation>();
    anim->load(animation_sheet[raw_dir][raw_state]);
    this->addAnimation(state, direction, anim);
}
