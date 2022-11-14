#ifndef GAME_ANIMATION_HPP
#define GAME_ANIMATION_HPP

#include "defines.h"

template<class T>
class Animation {
private:
    std::vector<T> frames;
    float delay{};
    float time_counter{};
    size_t current_frame{};
public:
    Animation(std::vector<T> frames, float delay) {
        this->time_counter = 0;
        this->current_frame = 0;
        this->frames = frames;
        this->delay = delay;
    };

    bool tick(const float &dt) { // return true if we go to the next frame
        this->time_counter += dt;
        if (this->time_counter > this->delay) {
            this->time_counter = 0;
            this->current_frame = (this->current_frame + 1) % this->frames.size();
            return true;
        }
        return false;
    }

    const T &getFrame() {
        return this->frames.at(this->current_frame);
    };
};


#endif //GAME_ANIMATION_HPP
