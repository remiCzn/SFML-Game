#include "Animation.h"

template<typename T>
Animation<T>::Animation(std::vector<T> frames, float delay) {
    this->time_counter = 0;
    this->current_frame = 0;
    this->frames = frames;
    this->delay = delay;
}

template<typename T>
const T &Animation<T>::getFrame() {
    return this->frames.at(this->current_frame);
}

template<typename T>
bool Animation<T>::tick(const float &dt) {
    this->time_counter += dt;
    if (this->time_counter > this->delay) {
        this->time_counter = 0;
        this->current_frame = (this->current_frame + 1) % this->frames.size();
        return true;
    }
    return false;
}
